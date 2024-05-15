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

const QString srcDir = "src";
const QString headDir = "include";

MainWindow::MainWindow()
    : ui(new Ui::MainWindow)   //mdiArea = new QMdiArea, ui = new Ui::MainWindow
{
    qDebug() << "1";
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

    projectModel = new QStandardItemModel(this);

    //项目栏Model初始化设置
    projectModel->setColumnCount(1);
    projectModel->setHeaderData(0, Qt::Horizontal, " Projects");
    ui->projectTreeView->setModel(projectModel);

    requirementModel = new QStandardItemModel(this);

    //需求栏Model初始化设置
    requirementModel->setColumnCount(1);
    requirementModel->setHeaderData(0, Qt::Horizontal, " Requirements");

    ui->requirementView->setModel(requirementModel);

    // 设置项不可编辑
    ui->projectTreeView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    // 获取QHeaderView
    QHeaderView *projectHeader = ui->projectTreeView->header();

    // 设置Header的样式
//    QString styleSheet = "QHeaderView::section { background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, "
//                         "stop:0 #E0E0E0, stop:1 #F0F0F0); border: 1px solid gray; }";
//    header->setStyleSheet(styleSheet);

    projectHeader->setStyleSheet("QHeaderView::section { background-color: rgb(242, 242, 242); border: 1px solid gray; }");

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
    connect(ui->requirementView, &RequirementTreeView::clicked, this, &MainWindow::doubleClickedRequirementView);

    // 连接每个QTextEdit的textChanged()信号到槽函数，先不用这个函数，20240412
//    connect(ui->mdiArea, &QMdiArea::subWindowActivated, [this](QMdiSubWindow *subWindow) {
//        if (subWindow) {
//            QTextEdit *textEdit = subWindow->findChild<QTextEdit *>();
//            if (textEdit) {
//                connect(textEdit, &QTextEdit::textChanged, [this]() {
//                    // 在这里可以向主窗口的其他子部件发送信号或执行其他操作
//                    updateRequirementModel();
//                });
//            }
//        }
//    });

//  connect(ui->mdiArea, &QMdiArea::subWindowActivated, this, &MainWindow::updateRequirementModel);
    qDebug() << "1";
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::doubleClickedProjectTree(const QModelIndex &index)
{
    qDebug() << "2";
    // 处理双击事件，打开对应文件
    //QStandardItem* item = model.itemFromIndex(index);
    QString filePath = projectModel->data(index, Qt::ToolTipRole).toString();
    QString fileName = projectModel->data(index, Qt::DisplayRole).toString();
    QFileInfo fileInfo(fileName);
    QString suf = fileInfo.suffix().toLower();
    if(suf == "h" || suf == "txt" || suf == "cpp"){
        openFile(filePath);
        qDebug() << "file opened:" << filePath;
    }
    qDebug() << "2";
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
    qDebug() << "3";
    if(MdiChild* child = activeMdiChild()){
        addFileToProject(currentPro, "student.cpp");
        addFileToProject(currentPro, "student.h");\
        qDebug() << "3";
        return;
    }else{
        qDebug() << "3";
        return;
    }
}

void MainWindow::createProject()
{
    qDebug() << "4";
    QString proDir = QFileDialog::getExistingDirectory(this, tr("Open Directory"), QDir::currentPath(),
                                                       QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    bool ok;
    QString proName = QInputDialog::getText(this, tr("Create a project"),
                                         tr("Project Name:"), QLineEdit::Normal,
                                         tr("untitled"), &ok);
    if (ok && !proName.isEmpty()){
        if(QDir::setCurrent(proDir)){   //设置打开目录为当前文件夹
            if(QDir::current().mkdir(proName)){   //在打开目录下创建一个项目名为名的文件夹
                proDir =  QDir::current().filePath(proName);
                QDir::setCurrent(proDir);    //更换到项目文件夹下
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
    projectTree* newPro = new projectTree(proName, proDir);
    currentPro = newPro;

    QFile cmakeFile("CMakeLists.txt");
    if(!cmakeFile.open(QIODevice::ReadWrite | QIODevice::Text))
        qDebug() << cmakeFile.errorString();
    cmakeFile.close();



    if(QDir::current().mkdir("src") && QDir::current().mkdir("include")){
        QDir::setCurrent(QDir::current().filePath("src"));    //更换到src文件夹下
        qDebug() << "currentDir:" << QDir::current();
        QFile mainCpp("main.cpp");
        if(!mainCpp.open(QIODevice::ReadWrite | QIODevice::Text))
            qDebug() << mainCpp.errorString();

        mainCpp.close();

        bool flag = openFile("main.cpp");
        if(!flag){
            errordlg->setWindowTitle(tr("Error Message"));
            errordlg->showMessage(tr("Failed to open main.cpp"));
        }
        initCMakeFile(newPro);   //更改CMakeList文件内容，初始化
        QDir::setCurrent(proDir);    //更换回项目文件夹下
    }
//    QFileInfo mainInfo(mainCpp);
//    qDebug() << QObject::tr("absolute path:") << mainInfo.absoluteFilePath();

    initProjectModel(newPro);
    qDebug() << "4";
}

void MainWindow::initProjectModel(projectTree* newPro)
{
    qDebug() << "5";
    //获取项目工作目录下的资源目录
    QString resFilePath = appDir.absolutePath() + "/images/toolbar_images";

    qDebug() << "newPro->proPath: " << newPro->projectPath;
    //创建一个新项目后修改model
    QStandardItem *parentItem = projectModel->invisibleRootItem();
    QStandardItem* itemProject = new QStandardItem;
    itemProject->setData(newPro->projectName, Qt::DisplayRole);
    itemProject->setData(newPro->projectPath, Qt::ToolTipRole);
    itemProject->setData(QIcon(resFilePath + "/folder.png"), Qt::DecorationRole);
    parentItem->appendRow(itemProject);


    QStandardItem* itemCmakeFile = new QStandardItem;
    itemCmakeFile->setData(newPro->cmakeFile, Qt::DisplayRole);
    itemCmakeFile->setData(QIcon(resFilePath + "/txt.svg"), Qt::DecorationRole);
    itemCmakeFile->setData(newPro->projectPath + "/CMakeLists.txt", Qt::ToolTipRole);

    QStandardItem* itemHeaders = new QStandardItem;
    itemHeaders->setData("Headers", Qt::DisplayRole);
    itemHeaders->setData(QIcon(resFilePath + "/folder.png"), Qt::DecorationRole);
    itemHeaders->setData(newPro->projectPath + "/" + headDir, Qt::ToolTipRole);
    qDebug() << "Header: " << itemHeaders->data(Qt::ToolTipRole).toString();

    QStandardItem* itemSources = new QStandardItem;
    itemSources->setData("Sources", Qt::DisplayRole);
    itemSources->setData(QIcon(resFilePath + "/folder.png"), Qt::DecorationRole);
    itemSources->setData(newPro->projectPath + "/" + srcDir, Qt::ToolTipRole);
    qDebug() << "Source: " << itemSources->data(Qt::ToolTipRole).toString();

    itemProject->appendRow(itemCmakeFile);
    itemProject->appendRow(itemHeaders);
    itemProject->appendRow(itemSources);

    newPro->headerFiles.sort();
    foreach(const QString &headerFile, newPro->headerFiles){
        QStandardItem* itemHeaderFile = new QStandardItem;
        itemHeaderFile->setData(headerFile, Qt::DisplayRole);
        itemHeaderFile->setData(QIcon(resFilePath + "/header.svg"), Qt::DecorationRole);
        itemHeaderFile->setData(newPro->projectPath + "/" + headDir + "/" + headerFile, Qt::ToolTipRole);
        itemHeaders->appendRow(itemHeaderFile);
    }

    newPro->sourceFiles.sort();
    foreach(const QString &sourceFile, newPro->sourceFiles){
        QStandardItem* itemSourceFile = new QStandardItem;
        itemSourceFile->setData(sourceFile, Qt::DisplayRole);
        itemSourceFile->setData(QIcon(resFilePath + "/cpp.svg"), Qt::DecorationRole);
        itemSourceFile->setData(newPro->projectPath + "/" + srcDir + "/" + sourceFile, Qt::ToolTipRole);
        itemSources->appendRow(itemSourceFile);
    }

    //projectModel->appendRow(itemProject);

    qDebug() << "modelRow: " << projectModel->rowCount();
    qDebug() << "modelCol: " << projectModel->columnCount();

    for (int row = 0; row < projectModel->rowCount(); ++row) {
        for (int column = 0; column < projectModel->columnCount(); ++column) {
            QStandardItem *item = projectModel->item(row, column);
            if (item) {
                QVariant tooltip = item->data(Qt::ToolTipRole);
                qDebug() << "Row:" << row << ", Column:" << column << ", Tooltip:" << tooltip.toString();
            }
        }
    }

    qDebug() << "5";
}

void MainWindow::initCMakeFile(const projectTree* pro)
{
    qDebug() << "6";
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
    stream << "\ninclude_directories(include)";
    stream << "\n";
    stream << "\nset(SOURCE_FILES src/main.cpp)";
    stream << "\n";
    stream << "\nset(HEADER_FILES)";
    stream << "\n";
    stream << QString("\nadd_executable(${PROJECT_NAME} ${SOURCE_FILES})");
    stream << "\n";
    cmakeFile.close();
    qDebug() << "6";
}

bool MainWindow::addFileToProject(const projectTree *pro, QString fileName)
{
    qDebug() << "7";
    if(!pro){
        qDebug() << "pro is null";
        qDebug() << "7";
        return false;
    }
    QDir proDir = QDir(pro->projectPath);
    QString suffix = fileName.section('.', -1);   //获取文件名后缀
    QString filePath;   //新文件路径
    QString dirPath;    //保存新文件的上级目录
    if(suffix == "cpp"){
        QDir temp = proDir;
        filePath = pro->projectPath + "/" + srcDir + "/" + fileName;
        dirPath = pro->projectPath + "/" + srcDir;
        if(temp.cd(srcDir) && temp.exists(fileName)){
            qDebug() << fileName + "already exists in" + pro->projectPath;
            qDebug() << "7";
            return false;
        }
    }else if(suffix == "h"){
        QDir temp = proDir;
        filePath = pro->projectPath + "/" + headDir + "/" + fileName;
        dirPath = pro->projectPath + "/" + headDir;
        if(temp.cd(headDir) && temp.exists(fileName)){
            qDebug() << fileName + "already exists in" + pro->projectPath;
            qDebug() << "7";
            return false;
        }
    }

    QFile file(filePath);

    // Check if the file can be opened for writing
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {

        // Close the file
        file.close();

        //找到和项目路径相同的model中的index
        QModelIndex index = findModelItem(dirPath, projectModel->index(0, 0), projectModel, Qt::ToolTipRole);

        if(!index.isValid()){  //
            qDebug() << "empty list";
            qDebug() << "7";
            return false;
        }

        //获取项目工作目录下的资源文件目录
        QString resFilePath = appDir.absolutePath() + iconFilePath;

        QFileInfo fileInfo(fileName);
        QStandardItem* itemNewFile = new QStandardItem;
        itemNewFile->setData(fileName, Qt::DisplayRole);
        itemNewFile->setData(filePath, Qt::ToolTipRole);

        if(suffix == "cpp"){  //区分要添加的文件是cpp还是h
            itemNewFile->setData(QIcon(resFilePath + "/cpp.svg"), Qt::DecorationRole);
            QStandardItem* parent = projectModel->itemFromIndex(index);
            parent->appendRow(itemNewFile);
        }else if(suffix == "h"){
            itemNewFile->setData(QIcon(resFilePath + "/header.svg"), Qt::DecorationRole);
            QStandardItem* parent = projectModel->itemFromIndex(index);
            parent->appendRow(itemNewFile);
        }

        projectModel->sort(0);  //model第一列排序
        qDebug() << "7";
        return true;
    }else{
        qDebug() << "Failed to create the file at:" << filePath;
        qDebug() << "7";
        return false;
    }

}

QModelIndex MainWindow::findModelItem(const QString &searchString, const QModelIndex &parentIndex, QStandardItemModel *model, int role)
{
    // 获取指定父索引下的所有子项的数量
    int rowCount = model->rowCount(parentIndex);
    int columnCount = model->columnCount(parentIndex);

    // 遍历每个子项
    for (int row = 0; row < rowCount; ++row) {
        for (int column = 0; column < columnCount; ++column) {
            // 获取子项的索引
            QModelIndex index = model->index(row, column, parentIndex);

            // 获取子项的数据
            QVariant data = index.data(role);

            // 如果子项数据与搜索字符串匹配，则打印并处理
            if (data.toString() == searchString) {
                qDebug() << "Found matching item at index:" << index << "with data:" << data.toString();
                return index;
                // 如果需要，可以在此处执行其他操作
            }

            // 如果子项有子项，则递归调用自身以处理子项的子项
            if (model->hasChildren(index)) {
                QModelIndex res = findModelItem(searchString, index, model, role);
                if(res.isValid()){
                    return res;
                }
            }
        }
    }
    return QModelIndex();
}


void MainWindow::updateRequirementModel()
{
    qDebug() << "8";
    //ui->requirementView->expandAll();   //自动展开所有项

    //这里只获取了当前一个文件的requirements
    QVector<RequireNote*> requirements;
    if(MdiChild* child = activeMdiChild()){
       requirements = child->getRequireNotes();
    }else{
        qDebug() << "8";
        return;
    }

    if(requirements.empty()){
        qDebug() << "8";
        return;
    }
    requirementModel->clear();
    QStandardItem *parentItem = requirementModel->invisibleRootItem();
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
    requirementModel->setHeaderData(0, Qt::Horizontal, " Requirements");
    ui->requirementView->expandAll();


    qDebug() << "8";
}

void MainWindow::doubleClickedRequirementView(const QModelIndex &index)
{
    qDebug() << "9";
    // 处理双击事件，打开对应文件
    //QStandardItem* item = model.itemFromIndex(index);
    QString pos = requirementModel->data(index, Qt::ToolTipRole).toString();
    QString filePath = pos.left(pos.indexOf(":line"));
    int lineNumber = pos.mid((pos.indexOf(":line")) + QString(":line").length()).toInt();

    if(openFile(filePath)){
        if(activeMdiChild()){
           activeMdiChild()->goToLine(lineNumber);
           qDebug() << "expand1";
        }

        ui->requirementView->expandAll();
        qDebug()  << "expand2";
    }
    qDebug() << "9";
}

void MainWindow::completeRequirement(const QModelIndex &index)
{
    qDebug() << "10";
    qDebug() << "completeRequirement";
    QStandardItem *item = requirementModel->itemFromIndex(index);  // 获取 QModelIndex 对应的项
    if (item) {
        //获取文件位置以及行号
        QString pos = item->data(Qt::ToolTipRole).toString();
        QString filePath = pos.left(pos.indexOf(":line"));
        int lineNumber = pos.mid((pos.indexOf(":line")) + QString(":line").length()).toInt();

        bool hasChildren = item->hasChildren();  // 判断该项是否有子项
        if (hasChildren) {   //提示信息
            int ret = QMessageBox::warning(this, tr("Complete the Requirement?"),
                                           tr("This requirement includes some sub-requirements. \n"
                                              "If you click Yes, all sub-requirements it includes will also be completed. \n"
                                              "Are you sure you want to complete?"), QMessageBox::Yes, QMessageBox::Cancel);
            if(ret == QMessageBox::Apply){
                if(openFile(filePath)){
                    if(activeMdiChild()) activeMdiChild()->changeRequirementToNote(lineNumber);
                }
            }else if(ret == QMessageBox::Cancel){
                qDebug() << "10";
                return;
            }
        } else {
            if(openFile(filePath)){
                if(activeMdiChild()) activeMdiChild()->changeRequirementToNote(lineNumber);
            }
        }
    } else {
        // 无效的 QModelIndex，对应的项不存在
    }
    qDebug() << "10";
}

void MainWindow::updateProjectClass(QHash<QString, ClassInfo>* classInfoHash)
{
    //根据类的信息，对照原来的类信息，更新类文件及其内容
    qDebug() << "MainWindow::updateProjectClass";
}

void MainWindow::setToolBarLayout()
{
    qDebug() << "11";
    QVBoxLayout *toolBarLayout = new QVBoxLayout;
//    toolBarLayout->addAction(ui->projectShowAct);
//    toolBarLayout->addAction(ui->runDebugAct);
//    toolBarLayout->addAction(ui->codeAnalysisAct);
//    toolBarLayout->addAction(ui->hmppAct);
    ui->toolBar->setLayout(toolBarLayout);
    qDebug() << "11";
}

void MainWindow::lineEditPrompt()
{
    qDebug() << "12";
    // 根据用户输入是否为空设置文本颜色
    if (ui->lineEdit->text().isEmpty()) {
        ui->lineEdit->setStyleSheet("QLineEdit { color: gray; }");
    } else {
        ui->lineEdit->setStyleSheet("QLineEdit { color: black; }");
    }
    qDebug() << "12";
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    qDebug() << "13";
    ui->mdiArea->closeAllSubWindows();
    if (ui->mdiArea->currentSubWindow()) {
        event->ignore();
    } else {
        writeSettings();
        event->accept();
    }
    qDebug() << "13";
}

void MainWindow::newFile()
{
    qDebug() << "14";
    MdiChild *child = createMdiChild();
    child->newFile();
    child->show();
    qDebug() << "14";
}

void MainWindow::open()
{
    qDebug() << "15";
    const QString fileName = QFileDialog::getOpenFileName(this);    //打开文件对话框
    if (!fileName.isEmpty()){
        openFile(fileName);
        loadProject(fileName);
    }
    qDebug() << "15";

}

bool MainWindow::openFile(const QString &fileName)
{
    qDebug() << "16";
    if (QMdiSubWindow *existing = findMdiChild(fileName)) {  //
        ui->mdiArea->setActiveSubWindow(existing);
        qDebug() << "16";
        return true;
    }
    const bool succeeded = loadFile(fileName);
    if (succeeded)
        ui->statusbar->showMessage(tr("File loaded"), 2000);
    qDebug() << "16";
    return succeeded;
}

bool MainWindow::loadFile(const QString &fileName)
{
    qDebug() << "17";
    MdiChild *child = createMdiChild();
    qDebug() << "loadFile: " << fileName;
    const bool succeeded = child->loadFile(fileName);
    if (succeeded){
        child->show();
        //loadProject(fileName);
    }else
        child->close();
    MainWindow::prependToRecentFiles(fileName);
    qDebug() << "17";
    return succeeded;
}

bool MainWindow::loadProject(const QString &fileName)
{
    qDebug() << "18";
    //判断是否是CMakeList.txt，判断文件格式是否符合CMakeList
    QString suffix = "/CMakeLists.txt";
    if (fileName.endsWith(suffix)) {
        // 如果末尾是指定字符串
        QString proPath = fileName.left(fileName.length() - suffix.length());
        qDebug() << "loadProject: " << proPath;
        QDir directory(proPath);

        if(!directory.exists()){
            qDebug() << "loadProject:Directory not exists:" << proPath;
            qDebug() << "18";
            return false;
        }

        QStringList sourceFiles;
        QStringList filters;
        filters << "*.cpp";

        if(directory.cd("src")){   //如果存在src子目录
            // 获取所有 .cpp 文件
            QStringList fileList = directory.entryList(filters, QDir::Files);
            for (const QString &fileName : fileList) {
                sourceFiles.append(fileName);
            }
        }

        directory.cdUp();
        QStringList headerFiles;
        filters.clear();
        filters << "*.h";

        if(directory.cd("include")){   //如果存在include子目录
            // 获取所有 .h 文件
            QStringList fileList = directory.entryList(filters, QDir::Files);
            for (const QString &fileName : fileList) {
                headerFiles.append(fileName);
            }
        }

        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qDebug() << "无法打开文件:" << fileName;
            qDebug() << "18";
            return false;
        }

        QString projectName = "";

        QTextStream in(&file);
        while (!in.atEnd()) {    //获取项目名
            QString line = in.readLine();
            if (line.startsWith("project(") && line.endsWith(")")) {
                projectName =  line.mid(line.indexOf("(") + 1, line.indexOf(")") - line.indexOf("(") - 1).trimmed();
                break;
            }
        }
        file.close();
        if(projectName == "") return false;    //如果没找到项目名

        projectTree* pro = new projectTree(projectName, proPath);
        pro->headerFiles = headerFiles;
        pro->sourceFiles = sourceFiles;
        initProjectModel(pro);
        currentPro = pro;
        qDebug() << "18";
        return true;

    } else {
        // 如果末尾不是指定字符串
        qDebug() << "末尾不是指定字符串";
        qDebug() << "18";
        return false;
    }
}

static inline QString recentFilesKey() { return QStringLiteral("recentFileList"); }
static inline QString fileKey() { return QStringLiteral("file"); }

static QStringList readRecentFiles(QSettings &settings)
{
    qDebug() << "19";
    QStringList result;
    const int count = settings.beginReadArray(recentFilesKey());
    for (int i = 0; i < count; ++i) {
        settings.setArrayIndex(i);
        result.append(settings.value(fileKey()).toString());
    }
    settings.endArray();
    qDebug() << "19";
    return result;
}

static void writeRecentFiles(const QStringList &files, QSettings &settings)
{
    qDebug() << "20";
    const int count = files.size();
    settings.beginWriteArray(recentFilesKey());
    for (int i = 0; i < count; ++i) {
        settings.setArrayIndex(i);
        settings.setValue(fileKey(), files.at(i));
    }
    settings.endArray();
    qDebug() << "20";
}

bool MainWindow::hasRecentFiles()
{
    qDebug() << "21";
    QSettings settings(QCoreApplication::organizationName(), QCoreApplication::applicationName());
    const int count = settings.beginReadArray(recentFilesKey());
    settings.endArray();
    qDebug() << "21";
    return count > 0;

}

void MainWindow::prependToRecentFiles(const QString &fileName)
{
    qDebug() << "22";
    QSettings settings(QCoreApplication::organizationName(), QCoreApplication::applicationName());

    const QStringList oldRecentFiles = readRecentFiles(settings);
    QStringList recentFiles = oldRecentFiles;
    recentFiles.removeAll(fileName);
    recentFiles.prepend(fileName);
    if (oldRecentFiles != recentFiles)
        writeRecentFiles(recentFiles, settings);

    setRecentFilesVisible(!recentFiles.isEmpty());
    qDebug() << "22";
}

void MainWindow::setRecentFilesVisible(bool visible)
{
    qDebug() << "23";
    recentFileSubMenuAct->setVisible(visible);
    recentFileSeparator->setVisible(visible);
    qDebug() << "23";
}


void MainWindow::updateRecentFileActions()
{
    qDebug() << "24";
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
    qDebug() << "24";
}

void MainWindow::openRecentFile()
{
    qDebug() << "25";
    if (const QAction *action = qobject_cast<const QAction *>(sender()))
        openFile(action->data().toString());
    qDebug() << "25";
}

void MainWindow::save()
{
    qDebug() << "26";
    if (activeMdiChild() && activeMdiChild()->save())
        ui->statusbar->showMessage(tr("File saved"), 2000);
    qDebug() << "26";
}

void MainWindow::saveAs()
{
    qDebug() << "27";
    MdiChild *child = activeMdiChild();
    if (child && child->saveAs()) {
        ui->statusbar->showMessage(tr("File saved"), 2000);
        MainWindow::prependToRecentFiles(child->currentFile());
    }
    qDebug() << "27";
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
    qDebug() << "28";
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
    qDebug() << "28";
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
    qDebug() << "29";
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
    qDebug() << "29";
}

MdiChild *MainWindow::createMdiChild()
{
    qDebug() << "30";
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

    //根据源文件类信息，更新类文件
    connect(child, &MdiChild::updateClassFiles, this, &MainWindow::updateProjectClass);
    qDebug() << "30";
    return child;
}

void MainWindow::showProgramOutput(int faultLineNumber){
    qDebug() << "31";
    if(faultLineNumber == -1) return;
    QString line = "line " + QString::number(faultLineNumber + 1);
    QTableWidgetItem *item = new QTableWidgetItem(line);
    ui->tableWidgetReport->setItem(0, 1, item);
    ui->tabProgramOutput->show();
    qDebug() << "31";
//    ui->mdiArea->setFocus();
}

void MainWindow::createActions()
{
    qDebug() << "32";
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

    qDebug() << "32";
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
    qDebug() << "33";
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
    qDebug() << "33";
}

void MainWindow::writeSettings()
{
    qDebug() << "34";
    QSettings settings(QCoreApplication::organizationName(), QCoreApplication::applicationName());
    settings.setValue("geometry", saveGeometry());
    qDebug() << "34";
}

MdiChild *MainWindow::activeMdiChild() const
{
    qDebug() << "35";
    if (QMdiSubWindow *activeSubWindow = ui->mdiArea->activeSubWindow()){   //如果有活动窗口，则将其内的中心部件转换为MdiChild类型，否则返回0
        qDebug() << "35";
        return qobject_cast<MdiChild *>(activeSubWindow->widget());
    }
    qDebug() << "35";
    return 0;
}

QMdiSubWindow *MainWindow::findMdiChild(const QString &fileName) const   //查找子窗口
{
    qDebug() << "36";
    QString canonicalFilePath = QFileInfo(fileName).canonicalFilePath();
    //利用foreach语句遍历子窗口列表，如果其文件路径和要查找的路径相同，则返回该窗口
    foreach (QMdiSubWindow *window, ui->mdiArea->subWindowList()) {
        MdiChild *mdiChild = qobject_cast<MdiChild *>(window->widget());
        if (mdiChild->currentFile() == canonicalFilePath){
            qDebug() << "36";
            return window;
        }
    }
    qDebug() << "36";
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
    qDebug() << "37";
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
    qDebug() << "37";
    //connect(ui->tableWidgetReport, &QTableWidgetItem::Clicked, this, &MainWindow::setCursorToFaultLine);

    //connect(analyzeConfig->ui->manageButton, &QPushButton::clicked, this, &MainWindow::managePropertySet);
}

void MainWindow::updateProgressBar()
{
    qDebug() << "38";
    int value = ui->progressBar->value();
    if(value < 100){
        value++;
        ui->progressBar->setValue(value);
    }else{
        ui->tabProgramOutput->show();
        ui->progressBar->hide();
    }
    qDebug() << "38";
}

void MainWindow::setCursorToFaultLine(QTableWidgetItem *item)
{
    qDebug() << "39";
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

    qDebug() << "39";
    //tudo;
}

void MainWindow::managePropertySet()
{
    qDebug() << "40";
    ManagePropertySetDialog* manageSet = new ManagePropertySetDialog(this);
    manageSet->setModal(true);
    //auto screenFactor = getScreenFactor();
    manageSet->resize(manageSet->width() * screenFactor, manageSet->height() * screenFactor);
    manageSet->show();
    qDebug() << "40";
}

void MainWindow::showAllRuleDescript()
{
    qDebug() << "41";
    AllRuleDescriptDialog* allRuleDescript = new AllRuleDescriptDialog(this);
    allRuleDescript->resize(allRuleDescript->width() * screenFactor, allRuleDescript->height() * screenFactor);
    allRuleDescript->show();
    qDebug() << "41";
}

double MainWindow::getScreenFactor()
{
    qDebug() << "42";
    //获取屏幕缩放倍数
    QScreen *screen = qApp->primaryScreen();
    const int baseValue = 96;     //100%时为96
    qreal dpiVal = screen->logicalDotsPerInch();
    qreal ratioVal = screen->devicePixelRatio();

    qDebug() << "42";
    return dpiVal * ratioVal / baseValue;
}
