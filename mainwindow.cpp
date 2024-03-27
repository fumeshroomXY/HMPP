#include <QtWidgets>
#include <QStackedWidget>
#include <QTreeView>
#include <QFileDialog>
#include <QInputDialog>
#include <QErrorMessage>
#include <QStandardItemModel>

#include "mainwindow.h"
#include "mdichild.h"
#include "ui_mainwindow.h"
#include "allruledescriptdialog.h"
#include "codeanalyzeconfigdialog.h"
#include "managepropertysetdialog.h"
#include "ruledescriptdialog.h"
#include "highlighter.h"
#include "faultlinehighlighter.h"

const QString iconFilePath = "/images/toolbar_images";

MainWindow::MainWindow()
    : ui(new Ui::MainWindow)   //mdiArea = new QMdiArea, ui = new Ui::MainWindow
{

//    createDockWindows();
//    createLayout();
    ui->setupUi(this);
    createActions();
    createStatusBar();
    ui->mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    //setCentralWidget(mdiArea);
    connect(ui->mdiArea, &QMdiArea::subWindowActivated,   //每当更换活动子窗口时，都会更新菜单状态
            this, &MainWindow::updateMenus);

    ui->mdiArea->setViewMode(QMdiArea::TabbedView);
    updateMenus();

    readSettings();

    setWindowTitle(tr("HMPP supporting tool demo"));
    setUnifiedTitleAndToolBarOnMac(true);

    //setToolBarLayout();
    //先隐藏问题面板，需要调试或代码分析时再唤出

    ui->tabProgramOutput->hide();
    ui->progressBar->hide();
    //调整Fault Report区的行列长度
    ui->tableWidgetReport->verticalHeader()->sectionResizeMode(QHeaderView::Stretch);
    ui->tableWidgetReport->verticalHeader()->sectionResizeMode(QHeaderView::ResizeToContents);

    ui->tableWidgetReport->horizontalHeader()->sectionResizeMode(QHeaderView::Stretch);
    ui->tableWidgetReport->horizontalHeader()->sectionResizeMode(QHeaderView::ResizeToContents);


    screenFactor = getScreenFactor();

    connect(ui->projectShowAct, &QAction::triggered, this, &MainWindow::setPage1);
    connect(ui->hmppAct, &QAction::triggered, this, &MainWindow::setPage2);

    connect(ui->tableWidgetReport, SIGNAL(itemDoubleClicked(QTableWidgetItem*)), this, SLOT(setCursorToFaultLine(QTableWidgetItem*)));


    //设置lineEdit的灰色提示文本
    ui->lineEdit->setPlaceholderText("Ask anything about programming");
    ui->lineEdit->setStyleSheet("QLineEdit { color: gray; }");

    // 连接信号和槽，实现提示文字的显示和隐藏
    connect(ui->lineEdit, &QLineEdit::textChanged, this, &MainWindow::lineEditPrompt);

    //openFile(QString("./document1.txt"));

    connect(ui->newProjectAct, &QAction::triggered, this, &MainWindow::createProject);  //todo：实现菜单栏创建项目动作

    errordlg = new QErrorMessage(this);


    //项目栏Model初始化设置
    projectModel.setColumnCount(1);
    projectModel.setHeaderData(0, Qt::Horizontal, " Projects");

    ui->projectTreeView->setModel(&projectModel);

    // 设置项不可编辑
    ui->projectTreeView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    // 获取QHeaderView
    QHeaderView *projectHeader = ui->projectTreeView->header();

    // 设置Header的样式
//    QString styleSheet = "QHeaderView::section { background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, "
//                         "stop:0 #E0E0E0, stop:1 #F0F0F0); border: 1px solid gray; }";
//    header->setStyleSheet(styleSheet);

    projectHeader->setStyleSheet("QHeaderView::section { background-color: rgb(242, 242, 242); border: 1px solid gray; }");

    //需求栏Model初始化设置
    requirementModel.setColumnCount(1);
    requirementModel.setHeaderData(0, Qt::Horizontal, " Requirements");

    ui->requirementView->setModel(&requirementModel);
    ui->requirementView->expandAll();   //自动展开所有项

    // 设置项不可编辑
    ui->requirementView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    // 获取QHeaderView
    QHeaderView *requirementHeader = ui->requirementView->header();

    // 设置Header的样式
    requirementHeader->setStyleSheet("QHeaderView::section { background-color: rgb(242, 242, 242); border: 1px solid gray; }");

    connect(ui->requirementView, &RequirementTreeView::complete, this, &MainWindow::completeRequirement);

    appDir = QDir(QCoreApplication::applicationDirPath());  //保存项目工作目录
    appDir.cdUp();

    //测试新创建一个类cpp和h文件
    connect(ui->testCreateClassAct, &QAction::triggered, this, &MainWindow::createNewClass);

    connect(ui->projectTreeView, &QTreeView::doubleClicked, this, &MainWindow::doubleClickedProjectTree);
    connect(ui->requirementView, &QTreeView::doubleClicked, this, &MainWindow::doubleClickedRequirementView);

    // 连接每个QTextEdit的textChanged()信号到槽函数
    connect(ui->mdiArea, &QMdiArea::subWindowActivated, [this](QMdiSubWindow *subWindow) {
        if (subWindow) {
            QTextEdit *textEdit = subWindow->findChild<QTextEdit *>();
            if (textEdit) {
                connect(textEdit, &QTextEdit::textChanged, [this]() {
                    // 在这里可以向主窗口的其他子部件发送信号或执行其他操作
                    updateRequirementModel();
                });
            }
        }
    });
    connect(ui->mdiArea, &QMdiArea::subWindowActivated, this, &MainWindow::updateRequirementModel);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::doubleClickedProjectTree(const QModelIndex &index)
{
    // 处理双击事件，打开对应文件
    //QStandardItem* item = model.itemFromIndex(index);
    QString filePath = projectModel.data(index, Qt::ToolTipRole).toString();
    QString fileName = projectModel.data(index, Qt::DisplayRole).toString();
    QFileInfo fileInfo(fileName);
    QString suf = fileInfo.suffix().toLower();
    if(suf == "h" || suf == "txt" || suf == "cpp"){
        openFile(filePath);
        qDebug() << "file opened:" << filePath;
    }
}

void MainWindow::updateRequireNotes(MdiChild *child)
{
    //先在projectTree中找到child对应的文件
}

void MainWindow::setPage1()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::setPage2()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::createNewClass()
{
    QString curFile = activeMdiChild()->currentFile();
    QDir curDir = QDir(curFile);
    curDir.cdUp();
    curFile = curDir.absolutePath();
    projectTree* curPro = nullptr;
    for(int i = 0; i < projects.size(); i++){   //查找当前项目的指针
        if(projects.at(i)->projectPath == curFile){
            curPro = projects.at(i);
            break;
        }
    }
    if(curPro == nullptr){
        qDebug() << "Cannot find the project:" << curFile;
    }
    addFileToProject(curPro, "student.cpp");
    addFileToProject(curPro, "student.h");
}

void MainWindow::createProject()
{
    QString proDir = QFileDialog::getExistingDirectory(this, tr("Open Directory"), QDir::currentPath(),
                                                       QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    bool ok;
    QString proName = QInputDialog::getText(this, tr("Create a project"),
                                         tr("Project Name:"), QLineEdit::Normal,
                                         tr("untitled"), &ok);
    if (ok && !proName.isEmpty()){
        if(QDir::setCurrent(proDir)){
            if(QDir::current().mkdir(proName)){
                //qDebug() << QDir::currentPath();
                proDir =  QDir::current().filePath(proName);
                QDir::setCurrent(proDir);
            }else{
                errordlg->setWindowTitle(tr("Error Message"));
                errordlg->showMessage(tr("Failed to create a project directory!"));
                return;
            }
        }else{
            errordlg->setWindowTitle(tr("Error Message"));
            errordlg->showMessage(tr("Failed to change directory when creating a project!"));
            return;
        }
    }else{
        errordlg->setWindowTitle(tr("Error Message"));
        errordlg->showMessage(tr("Failed to create a project!"));
        return;
    }
    qDebug() << proName;
    projectTree* newPro = new projectTree(proName, proDir);
    projects.append(newPro);

    QFile mainCpp("main.cpp");
    if(!mainCpp.open(QIODevice::ReadWrite | QIODevice::Text))
        qDebug() << mainCpp.errorString();
    mainCpp.close();

    bool flag = openFile("main.cpp");
    if(!flag){
        errordlg->setWindowTitle(tr("Error Message"));
        errordlg->showMessage(tr("Failed to open main.cpp"));
    }
    QFile cmakeFile("CMakeList.txt");
    if(!cmakeFile.open(QIODevice::ReadWrite | QIODevice::Text))
        qDebug() << cmakeFile.errorString();
    cmakeFile.close();
    QFileInfo mainInfo(mainCpp);
    qDebug() << QObject::tr("absolute path:") << mainInfo.absoluteFilePath();

    initCMakeFile(newPro);

    //获取项目工作目录
    QString resFilePath = appDir.absolutePath() + "/images/toolbar_images";


    //创建一个新项目后修改model
    QStandardItem *parentItem = projectModel.invisibleRootItem();
    QStandardItem* itemProject = new QStandardItem;
    itemProject->setData(newPro->projectName, Qt::DisplayRole);
    itemProject->setData(newPro->projectPath, Qt::ToolTipRole);
    itemProject->setData(QIcon(resFilePath + "/folder.png"), Qt::DecorationRole);
    parentItem->appendRow(itemProject);

    QStandardItem* itemCmakeFile = new QStandardItem;
    itemCmakeFile->setData(newPro->cmakeFile, Qt::DisplayRole);
    itemCmakeFile->setData(QIcon(resFilePath + "/txt.svg"), Qt::DecorationRole);
    itemCmakeFile->setData(newPro->projectPath + "/CMakeList.txt", Qt::ToolTipRole);

    QStandardItem* itemHeaders = new QStandardItem;
    itemHeaders->setData("Headers", Qt::DisplayRole);
    itemHeaders->setData(QIcon(resFilePath + "/folder.png"), Qt::DecorationRole);

    QStandardItem* itemSources = new QStandardItem;
    itemSources->setData("Sources", Qt::DisplayRole);
    itemSources->setData(QIcon(resFilePath + "/folder.png"), Qt::DecorationRole);

    itemProject->appendRow(itemCmakeFile);
    itemProject->appendRow(itemHeaders);
    itemProject->appendRow(itemSources);

    QStandardItem* itemMainCpp = new QStandardItem;
    itemMainCpp->setData("main.cpp", Qt::DisplayRole);
    itemMainCpp->setData(QIcon(resFilePath + "/cpp.svg"), Qt::DecorationRole);
    itemMainCpp->setData(newPro->projectPath + "/main.cpp", Qt::ToolTipRole);
    itemSources->appendRow(itemMainCpp);

}

void MainWindow::initCMakeFile(const projectTree* pro)
{
    QDir::setCurrent(pro->projectPath);
    QFile cmakeFile(pro->cmakeFile);
    if(!cmakeFile.open(QIODevice::WriteOnly | QIODevice::Text))
        qDebug() << cmakeFile.errorString();
    QTextStream stream(&cmakeFile);

    stream << QString("project(%1)").arg(pro->projectName);
    stream << "\n";
    stream << "\nset(CMAKE_CXX_STANDARD 11)";
    stream << "\n";
    stream << "\nset(CMAKE_CXX_STANDARD_REQUIRED ON)";
    stream << "\n";
    stream << QString("\nadd_executable(%1 main.cpp)").arg(pro->projectName);
    cmakeFile.close();
}

bool MainWindow::addFileToProject(const projectTree *pro, QString fileName)
{
    QDir proDir = QDir(pro->projectPath);
    if(proDir.exists(fileName)){
        qDebug() << fileName + "already exists in" + pro->projectPath;
        return false;
    }else{
        QString filePath = pro->projectPath + "/" + fileName;
        QFile file(filePath);

        // Check if the file can be opened for writing
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {

            //演示用，后续需要更改
            QTextStream stream(&file);
            stream << "class Student{\n\n}";

            // Close the file
            file.close();
            QModelIndexList matchedIndexes = projectModel.match(projectModel.index(0, 0),   //找到和项目路径相同的model中的index
                                             Qt::ToolTipRole, QVariant::fromValue(pro->projectPath), 1, Qt::MatchExactly);
            QModelIndex index = matchedIndexes.at(0);

            //获取项目工作目录
            QString resFilePath = appDir.absolutePath() + iconFilePath;

            QFileInfo fileInfo(fileName);
            QStandardItem* itemNewFile = new QStandardItem;
            itemNewFile->setData(fileName, Qt::DisplayRole);
            itemNewFile->setData(pro->projectPath + "/" + fileName, Qt::ToolTipRole);

            if(fileInfo.suffix().toLower() == "cpp"){  //区分要添加的文件是cpp还是h
                itemNewFile->setData(QIcon(resFilePath + "/cpp.svg"), Qt::DecorationRole);
                QModelIndex sourceIndex = index.child(2, 0);
                QStandardItem* parent = projectModel.itemFromIndex(sourceIndex);
                parent->appendRow(itemNewFile);
            }else if(fileInfo.suffix().toLower() == "h"){
                itemNewFile->setData(QIcon(resFilePath + "/header.svg"), Qt::DecorationRole);
                QModelIndex headerIndex = index.child(1, 0);
                QStandardItem* parent = projectModel.itemFromIndex(headerIndex);
                parent->appendRow(itemNewFile);
            }

            projectModel.sort(0);  //model第一列排序
            return true;
        }else{
            qDebug() << "Failed to create the file at:" << filePath;
            return false;
        }
    }
}

void MainWindow::updateProjectModel()
{
    if(projects.isEmpty()) return;
    QStandardItem *parentItem = projectModel.invisibleRootItem();
    foreach(projectTree* pro, projects){
        QStandardItem* itemProject = new QStandardItem;
        itemProject->setData(pro->projectName, Qt::DisplayRole);
        parentItem->appendRow(itemProject);
        QStandardItem* itemCmakeFile = new QStandardItem;
        itemCmakeFile->setData(pro->cmakeFile, Qt::DisplayRole);
        QStandardItem* itemSources = new QStandardItem;
        itemSources->setData("Sources", Qt::DisplayRole);
        QStandardItem* itemHeaders = new QStandardItem;
        itemHeaders->setData("Headers", Qt::DisplayRole);
        itemProject->appendRow(itemCmakeFile);
        itemProject->appendRow(itemSources);
        itemProject->appendRow(itemHeaders);

        pro->headerFiles.sort();
        foreach(const QString &headerFile, pro->headerFiles){
            QStandardItem* itemHeaderFile = new QStandardItem;
            itemHeaderFile->setData(headerFile, Qt::DisplayRole);
            itemHeaders->appendRow(itemHeaderFile);
        }

        pro->sourceFiles.sort();
        foreach(const QString &sourceFile, pro->sourceFiles){
            QStandardItem* itemSourceFile = new QStandardItem;
            itemSourceFile->setData(sourceFile, Qt::DisplayRole);
            itemSources->appendRow(itemSourceFile);
        }
    }
}

void MainWindow::updateRequirementModel()
{

    //ui->requirementView->expandAll();   //自动展开所有项

    //这里只获取了当前一个文件的requirements
    QVector<RequireNote*> requirements = activeMdiChild()->getRequireNotes();
    if(requirements.empty()){
        return;
    }
    requirementModel.clear();
    QStandardItem *parentItem = requirementModel.invisibleRootItem();
    for(auto level1 : requirements){   //最多三级需求，需求节点深度最大为3
        if(!level1->isRoot) continue;   //如果不是顶级需求，即根节点，直接跳过
        QStandardItem* itemLevel1 = new QStandardItem;
        itemLevel1->setData(level1->note, Qt::DisplayRole);
        itemLevel1->setData(level1->filePath + ":line" + QString::number(level1->startLine), Qt::ToolTipRole);
        parentItem->appendRow(itemLevel1);
        for(auto level2: level1->children){
            QStandardItem* itemLevel2 = new QStandardItem;
            itemLevel2->setData(level2->note, Qt::DisplayRole);
            itemLevel2->setData(level2->filePath + ":line" + QString::number(level2->startLine), Qt::ToolTipRole);
            itemLevel1->appendRow(itemLevel2);
            for(auto level3: level2->children){
                QStandardItem* itemLevel3 = new QStandardItem;
                itemLevel3->setData(level3->note, Qt::DisplayRole);
                itemLevel3->setData(level3->filePath + ":line" + QString::number(level3->startLine), Qt::ToolTipRole);
                itemLevel2->appendRow(itemLevel3);
            }
        }
    }
    requirementModel.setHeaderData(0, Qt::Horizontal, " Requirements");
    ui->requirementView->expandAll();

}

void MainWindow::doubleClickedRequirementView(const QModelIndex &index)
{
    // 处理双击事件，打开对应文件
    //QStandardItem* item = model.itemFromIndex(index);
    QString pos = requirementModel.data(index, Qt::ToolTipRole).toString();
    QString filePath = pos.left(pos.indexOf(":line"));
    int lineNumber = pos.mid((pos.indexOf(":line")) + QString(":line").length()).toInt();
    QFileInfo fileInfo(filePath);
    //openFile(filePath);
}

void MainWindow::completeRequirement(const QModelIndex &index)
{
    qDebug() << "completeRequirement";
    QStandardItem *item = requirementModel.itemFromIndex(index);  // 获取 QModelIndex 对应的项
    if (item) {
        //获取文件位置以及行号
        QString pos = item->data(Qt::ToolTipRole).toString();
        QString filePath = pos.left(pos.indexOf(":line"));
        int lineNumber = pos.mid((pos.indexOf(":line")) + QString(":line").length()).toInt();

        bool hasChildren = item->hasChildren();  // 判断该项是否有子项
        if (hasChildren) {   //提示信息
            int ret = QMessageBox::warning(this, tr("Complete the Requirement?"),
                                           tr("This requirement includes some sub-requirements. \n"
                                              "If you click Apply, all sub-requirements it includes will also be completed. \n"
                                              "Are you sure you want to click Apply?"), QMessageBox::Apply, QMessageBox::Cancel);
            if(ret == QMessageBox::Apply){
                if(openFile(filePath)){
                    MdiChild* child = activeMdiChild();
                    child->changeRequirementToNote(lineNumber);
                }
            }else if(ret == QMessageBox::Cancel){
                return;
            }
        } else {
            if(openFile(filePath)){
                MdiChild* child = activeMdiChild();
                child->changeRequirementToNote(lineNumber);
            }
        }
    } else {
        // 无效的 QModelIndex，对应的项不存在
    }
}

void MainWindow::setToolBarLayout()
{
    QVBoxLayout *toolBarLayout = new QVBoxLayout;
//    toolBarLayout->addAction(ui->projectShowAct);
//    toolBarLayout->addAction(ui->runDebugAct);
//    toolBarLayout->addAction(ui->codeAnalysisAct);
//    toolBarLayout->addAction(ui->hmppAct);
    ui->toolBar->setLayout(toolBarLayout);
}

void MainWindow::lineEditPrompt()
{
    // 根据用户输入是否为空设置文本颜色
    if (ui->lineEdit->text().isEmpty()) {
        ui->lineEdit->setStyleSheet("QLineEdit { color: gray; }");
    } else {
        ui->lineEdit->setStyleSheet("QLineEdit { color: black; }");
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    ui->mdiArea->closeAllSubWindows();
    if (ui->mdiArea->currentSubWindow()) {
        event->ignore();
    } else {
        writeSettings();
        event->accept();
    }
}

void MainWindow::newFile()
{
    MdiChild *child = createMdiChild();
    child->newFile();
    child->show();
}

void MainWindow::open()
{
    const QString fileName = QFileDialog::getOpenFileName(this);    //打开文件对话框
    if (!fileName.isEmpty())
        openFile(fileName);
}

bool MainWindow::openFile(const QString &fileName)
{
    if (QMdiSubWindow *existing = findMdiChild(fileName)) {  //
        ui->mdiArea->setActiveSubWindow(existing);
        return true;
    }
    const bool succeeded = loadFile(fileName);
    if (succeeded)
        ui->statusbar->showMessage(tr("File loaded"), 2000);
    return succeeded;
}

bool MainWindow::loadFile(const QString &fileName)
{
    MdiChild *child = createMdiChild();
    const bool succeeded = child->loadFile(fileName);
    if (succeeded)
        child->show();
    else
        child->close();
    MainWindow::prependToRecentFiles(fileName);
    return succeeded;
}

static inline QString recentFilesKey() { return QStringLiteral("recentFileList"); }
static inline QString fileKey() { return QStringLiteral("file"); }

static QStringList readRecentFiles(QSettings &settings)
{
    QStringList result;
    const int count = settings.beginReadArray(recentFilesKey());
    for (int i = 0; i < count; ++i) {
        settings.setArrayIndex(i);
        result.append(settings.value(fileKey()).toString());
    }
    settings.endArray();
    return result;
}

static void writeRecentFiles(const QStringList &files, QSettings &settings)
{
    const int count = files.size();
    settings.beginWriteArray(recentFilesKey());
    for (int i = 0; i < count; ++i) {
        settings.setArrayIndex(i);
        settings.setValue(fileKey(), files.at(i));
    }
    settings.endArray();
}

bool MainWindow::hasRecentFiles()
{
    QSettings settings(QCoreApplication::organizationName(), QCoreApplication::applicationName());
    const int count = settings.beginReadArray(recentFilesKey());
    settings.endArray();
    return count > 0;
}

void MainWindow::prependToRecentFiles(const QString &fileName)
{
    QSettings settings(QCoreApplication::organizationName(), QCoreApplication::applicationName());

    const QStringList oldRecentFiles = readRecentFiles(settings);
    QStringList recentFiles = oldRecentFiles;
    recentFiles.removeAll(fileName);
    recentFiles.prepend(fileName);
    if (oldRecentFiles != recentFiles)
        writeRecentFiles(recentFiles, settings);

    setRecentFilesVisible(!recentFiles.isEmpty());
}

void MainWindow::setRecentFilesVisible(bool visible)
{
    recentFileSubMenuAct->setVisible(visible);
    recentFileSeparator->setVisible(visible);
}


void MainWindow::updateRecentFileActions()
{
    QSettings settings(QCoreApplication::organizationName(), QCoreApplication::applicationName());

    const QStringList recentFiles = readRecentFiles(settings);
    const int count = qMin(int(MaxRecentFiles), recentFiles.size());
    int i = 0;
    for ( ; i < count; ++i) {
        const QString fileName = QFileInfo(recentFiles.at(i)).fileName();
        recentFileActs[i]->setText(tr("&%1 %2").arg(i + 1).arg(fileName));
        recentFileActs[i]->setData(recentFiles.at(i));
        recentFileActs[i]->setVisible(true);
    }
    for ( ; i < MaxRecentFiles; ++i)
        recentFileActs[i]->setVisible(false);
}

void MainWindow::openRecentFile()
{
    if (const QAction *action = qobject_cast<const QAction *>(sender()))
        openFile(action->data().toString());
}

void MainWindow::save()
{
    if (activeMdiChild() && activeMdiChild()->save())
        ui->statusbar->showMessage(tr("File saved"), 2000);
}

void MainWindow::saveAs()
{
    MdiChild *child = activeMdiChild();
    if (child && child->saveAs()) {
        ui->statusbar->showMessage(tr("File saved"), 2000);
        MainWindow::prependToRecentFiles(child->currentFile());
    }
}

#ifndef QT_NO_CLIPBOARD
void MainWindow::cut()
{
    if (activeMdiChild())
        activeMdiChild()->cut();
}

void MainWindow::copy()
{
    if (activeMdiChild())
        activeMdiChild()->copy();
}

void MainWindow::paste()
{
    if (activeMdiChild())
        activeMdiChild()->paste();
}
#endif

void MainWindow::about()
{
   QMessageBox::about(this, tr("About DEMO"),
            tr("This is a demo for HMPP supporting tool"));
}

void MainWindow::aboutDeveloper()
{
   QMessageBox::about(this, tr("About Developer"),
            tr("Hiroshima University, Graduate School of Science and Engineering, Dependable System"));
}

void MainWindow::updateMenus()
{
    bool hasMdiChild = (activeMdiChild() != 0);   //根据是否有活动窗口来设置各个动作是否可用
    ui->saveAct->setEnabled(hasMdiChild);
    ui->saveAsAct->setEnabled(hasMdiChild);
#ifndef QT_NO_CLIPBOARD
    ui->pasteAct->setEnabled(hasMdiChild);
#endif
    ui->closeAct->setEnabled(hasMdiChild);
    ui->closeAllAct->setEnabled(hasMdiChild);
    ui->tileAct->setEnabled(hasMdiChild);
    ui->cascadeAct->setEnabled(hasMdiChild);
    ui->nextAct->setEnabled(hasMdiChild);
    ui->previousAct->setEnabled(hasMdiChild);
    //windowMenuSeparatorAct->setVisible(hasMdiChild);

#ifndef QT_NO_CLIPBOARD
    bool hasSelection = (activeMdiChild() &&
                         activeMdiChild()->textCursor().hasSelection());
    ui->cutAct->setEnabled(hasSelection);
    ui->copyAct->setEnabled(hasSelection);
#endif
}

class ActiveMdiSubWindowFunctor {
public:
    explicit ActiveMdiSubWindowFunctor(QMdiArea *mdiArea, QMdiSubWindow *activeWindow) : m_mdiArea(mdiArea), m_activeWindow(activeWindow) {}
    void operator()() const { m_mdiArea->setActiveSubWindow(m_activeWindow); }

private:
    QMdiArea *m_mdiArea;
    QMdiSubWindow *m_activeWindow;
};

void MainWindow::updateWindowMenu()
{
    ui->menuWindow->clear();
    ui->menuWindow->addAction(ui->closeAct);
    ui->menuWindow->addAction(ui->closeAllAct);
    ui->menuWindow->addSeparator();
    ui->menuWindow->addAction(ui->tileAct);
    ui->menuWindow->addAction(ui->cascadeAct);
    ui->menuWindow->addSeparator();
    ui->menuWindow->addAction(ui->nextAct);
    ui->menuWindow->addAction(ui->previousAct);
    //ui->menuWindow->addAction(windowMenuSeparatorAct);

    QList<QMdiSubWindow *> windows = ui->mdiArea->subWindowList();
    //windowMenuSeparatorAct->setVisible(!windows.isEmpty());

    for (int i = 0; i < windows.size(); ++i) {  //遍历各个子窗口
        QMdiSubWindow *mdiSubWindow = windows.at(i);
        MdiChild *child = qobject_cast<MdiChild *>(mdiSubWindow->widget());

        QString text;
        if (i < 9) {  //如果窗口数小于9，则设置编号为快捷键
            text = tr("&%1 %2").arg(i + 1)
                               .arg(child->userFriendlyCurrentFile());
        } else {
            text = tr("%1 %2").arg(i + 1)
                              .arg(child->userFriendlyCurrentFile());
        }
        QAction *action = ui->menuWindow->addAction(text, mdiSubWindow, ActiveMdiSubWindowFunctor(ui->mdiArea, mdiSubWindow));  //添加动作到菜单
        action->setCheckable(true);  //设置动作可以选择
        action ->setChecked(child == activeMdiChild());  //设置当前活动窗口动作为选中状态
    }
}

MdiChild *MainWindow::createMdiChild()
{
    QFont font;
    font.setFamily("Courier");
    font.setFixedPitch(true);
    font.setPointSize(10);

    //editor = new QTextEdit;
    //editor->setFont(font);

    //highlighter = new Highlighter(editor->document());
    MdiChild *child = new MdiChild();

    child->setFont(font);

    //FaultLineHighlighter *faultHighlighter = new FaultLineHighlighter(child->document());
    Highlighter *highlighter = new Highlighter(child->document());
    connect(highlighter, &Highlighter::findFault, child, &MdiChild::faultLinePaint);
    connect(highlighter, &Highlighter::faultInfo, child, &MdiChild::setFixText);
    //connect(child, &MdiChild::hideProblemTab, highlighter, &Highlighter::changeFaultRule);


    ui->mdiArea->addSubWindow(child);   //向多文档区域添加子窗口，child为中心部件

#ifndef QT_NO_CLIPBOARD
    connect(child, &QTextEdit::copyAvailable, ui->cutAct, &QAction::setEnabled);
    connect(child, &QTextEdit::copyAvailable, ui->copyAct, &QAction::setEnabled);
#endif
    connect(child, &MdiChild::showProblemTab, this, &MainWindow::showProgramOutput);
    //connect(child, &MdiChild::showProblemTab, ui->tabProgramOutput, &QWidget::show);//当收到展示问题面板信号时，展示问题面板
    connect(child, &MdiChild::hideProblemTab, ui->tabProgramOutput, &QWidget::hide);
    return child;
}

void MainWindow::showProgramOutput(int faultLineNumber){
    if(faultLineNumber == -1) return;
    QString line = "line " + QString::number(faultLineNumber + 1);
    QTableWidgetItem *item = new QTableWidgetItem(line);
    ui->tableWidgetReport->setItem(0, 1, item);
    ui->tabProgramOutput->show();
//    ui->mdiArea->setFocus();
}

void MainWindow::createActions()
{
    //QMenu *fileMenu = menuBar()->addMenu(tr("&File"));   //菜单栏的"文件"
    //QToolBar *fileToolBar = addToolBar(tr("File"));      //工具栏的"icon"

    //const QIcon newIcon = QIcon::fromTheme("document-new", QIcon(":/images/toolbar_images/new.png"));
    //Returns the QIcon corresponding to name in the current icon theme.
    //If no such icon is found in the current theme, QIcon(fallback) is returned instead.
//    newAct = new QAction(newIcon, tr("&New"), this);
//    newAct->setShortcuts(QKeySequence::New);
//    newAct->setStatusTip(tr("Create a new file"));
    connect(ui->newAct, &QAction::triggered, this, &MainWindow::newFile);
//    fileMenu->addAction(newAct);
//    fileToolBar->addAction(newAct);

//    const QIcon openIcon = QIcon::fromTheme("document-open", QIcon(":/images/toolbar_images/open.png"));
//    QAction *openAct = new QAction(openIcon, tr("&Open..."), this);
//    openAct->setShortcuts(QKeySequence::Open);
//    openAct->setStatusTip(tr("Open an existing file"));
    connect(ui->openAct, &QAction::triggered, this, &MainWindow::open);
//    fileMenu->addAction(openAct);
//    fileToolBar->addAction(openAct);

//    const QIcon saveIcon = QIcon::fromTheme("document-save", QIcon(":/images/toolbar_images/save.png"));
//    saveAct = new QAction(saveIcon, tr("&Save"), this);
//    saveAct->setShortcuts(QKeySequence::Save);
//    saveAct->setStatusTip(tr("Save the document to disk"));
    connect(ui->saveAct, &QAction::triggered, this, &MainWindow::save);
//    fileToolBar->addAction(saveAct);

//    const QIcon saveAsIcon = QIcon::fromTheme("document-save-as");
//    saveAsAct = new QAction(saveAsIcon, tr("Save &As..."), this);
//    saveAsAct->setShortcuts(QKeySequence::SaveAs);
//    saveAsAct->setStatusTip(tr("Save the document under a new name"));
    connect(ui->saveAsAct, &QAction::triggered, this, &MainWindow::saveAs);
//    fileMenu->addAction(saveAsAct);

//    fileMenu->addSeparator();    //菜单栏加一个分隔线

    QMenu *recentMenu = ui->menuFile->addMenu(tr("Recent..."));
    connect(recentMenu, &QMenu::aboutToShow, this, &MainWindow::updateRecentFileActions);
    recentFileSubMenuAct = recentMenu->menuAction();     //？

    for (int i = 0; i < MaxRecentFiles; ++i) {
        recentFileActs[i] = recentMenu->addAction(QString(), this, &MainWindow::openRecentFile);
        recentFileActs[i]->setVisible(false);
        //If visible is true the action can be seen (e.g. in menus and toolbars) and chosen by the user;
        //if visible is false the action cannot be seen or chosen by the user.
    }

    recentFileSeparator = ui->menuFile->addSeparator();

    setRecentFilesVisible(MainWindow::hasRecentFiles());

    ui->menuFile->addAction(tr("Switch layout direction"), this, &MainWindow::switchLayoutDirection);

    ui->menuFile->addSeparator();

//! [0]
//    const QIcon exitIcon = QIcon::fromTheme("application-exit");
//    QAction *exitAct = fileMenu->addAction(exitIcon, tr("E&xit"), qApp, &QApplication::closeAllWindows);
//    exitAct->setShortcuts(QKeySequence::Quit);
//    exitAct->setStatusTip(tr("Exit the application"));
//    fileMenu->addAction(exitAct);
    connect(ui->exitAct, &QAction::triggered, qApp, &QApplication::closeAllWindows);
//! [0]

#ifndef QT_NO_CLIPBOARD
//    QMenu *editMenu = menuBar()->addMenu(tr("&Edit"));
//    QToolBar *editToolBar = addToolBar(tr("Edit"));

//    const QIcon cutIcon = QIcon::fromTheme("edit-cut", QIcon(":/images/toolbar_images/cut.png"));
//    cutAct = new QAction(cutIcon, tr("Cu&t"), this);
//    cutAct->setShortcuts(QKeySequence::Cut);
//    cutAct->setStatusTip(tr("Cut the current selection's contents to the "
//                            "clipboard"));
    connect(ui->cutAct, &QAction::triggered, this, &MainWindow::cut);
//    editMenu->addAction(cutAct);
//    editToolBar->addAction(cutAct);

//    const QIcon copyIcon = QIcon::fromTheme("edit-copy", QIcon(":/images/toolbar_images/copy.png"));
//    copyAct = new QAction(copyIcon, tr("&Copy"), this);
//    copyAct->setShortcuts(QKeySequence::Copy);
//    copyAct->setStatusTip(tr("Copy the current selection's contents to the "
//                             "clipboard"));
    connect(ui->copyAct, &QAction::triggered, this, &MainWindow::copy);
//    editMenu->addAction(copyAct);
//    editToolBar->addAction(copyAct);

//    const QIcon pasteIcon = QIcon::fromTheme("edit-paste", QIcon(":/images/toolbar_images/paste.png"));
//    pasteAct = new QAction(pasteIcon, tr("&Paste"), this);
//    pasteAct->setShortcuts(QKeySequence::Paste);
//    pasteAct->setStatusTip(tr("Paste the clipboard's contents into the current "
//                              "selection"));
    connect(ui->pasteAct, &QAction::triggered, this, &MainWindow::paste);
//    editMenu->addAction(pasteAct);
//    editToolBar->addAction(pasteAct);
#endif

    //windowMenu = menuBar()->addMenu(tr("&Window"));
    connect(ui->menuWindow, &QMenu::aboutToShow, this, &MainWindow::updateWindowMenu);

//    closeAct = new QAction(tr("Cl&ose"), this);
//    closeAct->setStatusTip(tr("Close the active window"));
    connect(ui->closeAct, &QAction::triggered,
            ui->mdiArea, &QMdiArea::closeActiveSubWindow);

//    closeAllAct = new QAction(tr("Close &All"), this);
//    closeAllAct->setStatusTip(tr("Close all the windows"));
    connect(ui->closeAllAct, &QAction::triggered, ui->mdiArea, &QMdiArea::closeAllSubWindows);

//    tileAct = new QAction(tr("&Tile"), this);
//    tileAct->setStatusTip(tr("Tile the windows"));
    connect(ui->tileAct, &QAction::triggered, ui->mdiArea, &QMdiArea::tileSubWindows);

//    cascadeAct = new QAction(tr("&Cascade"), this);
//    cascadeAct->setStatusTip(tr("Cascade the windows"));
    connect(ui->cascadeAct, &QAction::triggered, ui->mdiArea, &QMdiArea::cascadeSubWindows);

//    nextAct = new QAction(tr("Ne&xt"), this);
//    nextAct->setShortcuts(QKeySequence::NextChild);
//    nextAct->setStatusTip(tr("Move the focus to the next window"));
    connect(ui->nextAct, &QAction::triggered, ui->mdiArea, &QMdiArea::activateNextSubWindow);

//    previousAct = new QAction(tr("Pre&vious"), this);
//    previousAct->setShortcuts(QKeySequence::PreviousChild);
//    previousAct->setStatusTip(tr("Move the focus to the previous "
//                                 "window"));
    connect(ui->previousAct, &QAction::triggered, ui->mdiArea, &QMdiArea::activatePreviousSubWindow);

//    windowMenuSeparatorAct = new QAction(this);
//    windowMenuSeparatorAct->setSeparator(true);

    updateWindowMenu();

//    menuBar()->addSeparator();

    //QMenu *helpMenu = menuBar()->addMenu(tr("&Help"));
    connect(ui->aboutAct, &QAction::triggered, this, &MainWindow::about);

    connect(ui->aboutDeveloperAct, &QAction::triggered, this, &MainWindow::aboutDeveloper);
//    QAction *aboutAct = helpMenu->addAction(tr("&About"), this, &MainWindow::about);
    //aboutAct->setStatusTip(tr("Show the demo's About box"));

//    QAction *aboutQtAct = helpMenu->addAction(tr("About &Creator"), qApp, &QApplication::aboutQt);
    //aboutQtAct->setStatusTip(tr("Show the creator's About box"));
    connect(ui->codeAnalysisAct, &QAction::triggered, this, &MainWindow::configCodeAnalysis);

    connect(ui->manageSetAct, &QAction::triggered, this, &MainWindow::managePropertySet);

    connect(ui->allRuleDescriptAct, &QAction::triggered, this, &MainWindow::showAllRuleDescript);


}

void MainWindow::createStatusBar()
{
    ui->statusbar->showMessage(tr("Ready"));
}

void MainWindow::createDockWindows()
{
//    dockProject = new QDockWidget(tr("Projects"), this);

//    dockProject->setAllowedAreas(Qt::LeftDockWidgetArea);
//    addDockWidget(Qt::LeftDockWidgetArea, dockProject);
//    dockProject->resize(60, 1);
//    qDebug() << dockProject->size();
//    windowMenu->addAction(dockProject->toggleViewAction());

//    dockProblemPanel = new QDockWidget(tr("Problem Panel"), this);
//    dockProblemPanel->setAllowedAreas(Qt::BottomDockWidgetArea);
//    addDockWidget(Qt::BottomDockWidgetArea, dockProblemPanel);
//    windowMenu->addAction(dockProblemPanel->toggleViewAction());
}

void MainWindow::readSettings()
{
    QSettings settings(QCoreApplication::organizationName(), QCoreApplication::applicationName());
    const QByteArray geometry = settings.value("geometry", QByteArray()).toByteArray();
    if (geometry.isEmpty()) {
        const QRect availableGeometry = QApplication::desktop()->availableGeometry(this);
        resize(availableGeometry.width() / 3, availableGeometry.height() / 2);
        move((availableGeometry.width() - width()) / 2,
             (availableGeometry.height() - height()) / 2);
    } else {
        restoreGeometry(geometry);
    }
}

void MainWindow::writeSettings()
{
    QSettings settings(QCoreApplication::organizationName(), QCoreApplication::applicationName());
    settings.setValue("geometry", saveGeometry());
}

MdiChild *MainWindow::activeMdiChild() const
{
    if (QMdiSubWindow *activeSubWindow = ui->mdiArea->activeSubWindow())   //如果有活动窗口，则将其内的中心部件转换为MdiChild类型，否则返回0
        return qobject_cast<MdiChild *>(activeSubWindow->widget());
    return 0;
}

QMdiSubWindow *MainWindow::findMdiChild(const QString &fileName) const   //查找子窗口
{
    QString canonicalFilePath = QFileInfo(fileName).canonicalFilePath();
    //利用foreach语句遍历子窗口列表，如果其文件路径和要查找的路径相同，则返回该窗口
    foreach (QMdiSubWindow *window, ui->mdiArea->subWindowList()) {
        MdiChild *mdiChild = qobject_cast<MdiChild *>(window->widget());
        if (mdiChild->currentFile() == canonicalFilePath)
            return window;
    }
    return 0;
}

void MainWindow::switchLayoutDirection()
{
    if (layoutDirection() == Qt::LeftToRight)
        QGuiApplication::setLayoutDirection(Qt::RightToLeft);
    else
        QGuiApplication::setLayoutDirection(Qt::LeftToRight);
}

//void MainWindow::createLayout()
//{
//    mainLayout = new QGridLayout;
//    mainLayout->addWidget(dockProject);
//    //mainLayout->addWidget(mdiArea);
//    mainLayout->addWidget(dockProblemPanel);
//    mdiArea->setLayout(mainLayout);
//}

void MainWindow::configCodeAnalysis()
{
    CodeAnalyzeConfigDialog* analyzeConfig = new CodeAnalyzeConfigDialog(this);
    analyzeConfig->resize(analyzeConfig->width() * screenFactor, analyzeConfig->height() * screenFactor);

    analyzeConfig->show();

    if(analyzeConfig->exec() == QDialog::Accepted){
        qDebug() << "---";
        ui->progressBar->show();
        // 创建一个定时器，每隔100毫秒更新一次进度条
        timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &MainWindow::updateProgressBar);
        timer->start(100);
        //qDebug() << "---";
        //while(ui->progressBar->value() < 100);
        //qDebug() << "---";

//        ui->tabProgramOutput->show();
//        ui->progressBar->hide();
    }
    //connect(ui->tableWidgetReport, &QTableWidgetItem::Clicked, this, &MainWindow::setCursorToFaultLine);

    //connect(analyzeConfig->ui->manageButton, &QPushButton::clicked, this, &MainWindow::managePropertySet);
}

void MainWindow::updateProgressBar()
{
    int value = ui->progressBar->value();
    if(value < 100){
        value++;
        ui->progressBar->setValue(value);
    }else{
        ui->tabProgramOutput->show();
        ui->progressBar->hide();
    }
}

void MainWindow::setCursorToFaultLine(QTableWidgetItem *item)
{
    int lineNumber = 0;
    MdiChild *mdiChild = activeMdiChild();
    if(mdiChild == NULL) return;
    QTextCursor tc = mdiChild->textCursor();
    QString itemText = item->text();

    // 使用正则表达式提取数字部分
    QRegExp regex("\\b(\\d+)\\b");
    if( regex.indexIn(itemText) >= 0 ){
        // 获取第一个捕获组的匹配结果，即数字部分
        QString numberString = regex.cap(1);

        // 将字符串转换为整数
        lineNumber = numberString.toInt();
    }


    //int lineNumber = 13;    //这里把跳转行固定了，可以注销掉此行
    int position = mdiChild->document()->findBlockByNumber (lineNumber - 1).position();
    tc.setPosition(position,QTextCursor::MoveAnchor);
    mdiChild->setTextCursor(tc);

    //tudo;
}

void MainWindow::managePropertySet()
{
    ManagePropertySetDialog* manageSet = new ManagePropertySetDialog(this);
    manageSet->setModal(true);
    //auto screenFactor = getScreenFactor();
    manageSet->resize(manageSet->width() * screenFactor, manageSet->height() * screenFactor);
    manageSet->show();
}

void MainWindow::showAllRuleDescript()
{
    AllRuleDescriptDialog* allRuleDescript = new AllRuleDescriptDialog(this);
    allRuleDescript->resize(allRuleDescript->width() * screenFactor, allRuleDescript->height() * screenFactor);
    allRuleDescript->show();
}

double MainWindow::getScreenFactor()
{
    //获取屏幕缩放倍数
    QScreen *screen = qApp->primaryScreen();
    const int baseValue = 96;     //100%时为96
    qreal dpiVal = screen->logicalDotsPerInch();
    qreal ratioVal = screen->devicePixelRatio();


    return dpiVal * ratioVal / baseValue;
}
