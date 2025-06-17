#include <QtWidgets>
#include <QStackedWidget>
#include <QTreeView>
#include <QFileDialog>
#include <QInputDialog>
#include <QErrorMessage>
#include <QStringList>
#include <QStandardItemModel>
#include <QMessageBox>
#include <algorithm>
#include <utility>

#include "mainwindow.h"
#include "mdichild.h"
#include "ui_mainwindow.h"
#include "allruledescriptdialog.h"
#include "codeanalyzeconfigdialog.h"
#include "managepropertysetdialog.h"
#include "ruledescriptdialog.h"
#include "highlighter.h"
#include "faultlinehighlighter.h"
#include "selectnewclassdialog.h"
#include "syntaxrule.h"
#include "issuemanager.h"
#include "screenfactor.h"
#include "chatgptclient.h"
#include "requirementtreeview.h"
#include "utils.h"
#include "cscrtoolchallengerquestion.h"

const QString iconFilePath = "/images/toolbar_images";

const QString srcDir = "src";
const QString headDir = "include";

const QStringList  LanguageSet = {"C++", "Java", "C#"};



MainWindow::MainWindow()
    : ui(new Ui::MainWindow)   //mdiArea = new QMdiArea, ui = new Ui::MainWindow
{
    qDebug() << "1";
//    createDockWindows();
//    createLayout();
    ui->setupUi(this);
    //初始化
    init();
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

    ui->comboBoxBugNature->addItems(bugNatureList);

    //setToolBarLayout();
    //先隐藏问题面板，需要调试或代码分析时再唤出

    ui->tabProgramOutput->hide();
    ui->progressBar->hide();
    //调整Fault Report区的行列长度
    ui->tableWidgetReport->verticalHeader()->sectionResizeMode(QHeaderView::Stretch);
    ui->tableWidgetReport->verticalHeader()->sectionResizeMode(QHeaderView::ResizeToContents);

    ui->tableWidgetReport->horizontalHeader()->sectionResizeMode(QHeaderView::Stretch);
    ui->tableWidgetReport->horizontalHeader()->sectionResizeMode(QHeaderView::ResizeToContents);

    //调整Issue Report区的行列长度
    ui->tableIssueWidget->verticalHeader()->sectionResizeMode(QHeaderView::Stretch);
    ui->tableIssueWidget->verticalHeader()->sectionResizeMode(QHeaderView::ResizeToContents);

    ui->tableIssueWidget->horizontalHeader()->sectionResizeMode(QHeaderView::Stretch);
    ui->tableIssueWidget->horizontalHeader()->sectionResizeMode(QHeaderView::ResizeToContents);

    connect(ui->actionCplus, &QAction::triggered, this, &MainWindow::setTargetLangToCplus);
    connect(ui->actionJava, &QAction::triggered, this, &MainWindow::setTargetLangToJava);
    connect(ui->actionCsharp, &QAction::triggered, this, &MainWindow::setTargetLangToCsharp);

    connect(ui->importSpecAct, &QAction::triggered, this, &MainWindow::importSpecificationForCurrentPro);
    connect(ui->specBuildAct, &QAction::triggered, this, &MainWindow::buildFilesFromSpecification);

    screenFactor = getScreenFactor();

    connect(ui->projectShowAct, &QAction::triggered, this, &MainWindow::showProjectView);
    connect(ui->hmppAct, &QAction::triggered, this, &MainWindow::showHMPPView);
    connect(ui->codePredictAct, &QAction::triggered, this, &MainWindow::showFixedCodeView);
    connect(ui->cscrToolAct, &QAction::triggered, this, &MainWindow::showCSCRTool);

    connect(ui->tableWidgetReport, SIGNAL(itemDoubleClicked(QTableWidgetItem*)), this, SLOT(setCursorToFaultLine(QTableWidgetItem*)));

    connect(ui->tableIssueWidget, SIGNAL(itemDoubleClicked(QTableWidgetItem*)), this, SLOT(setCursorToIssueLine(QTableWidgetItem*)));

    //设置lineEdit的灰色提示文本
    ui->lineEdit->setPlaceholderText("Ask anything about programming");
    ui->lineEdit->setStyleSheet("QLineEdit { color: gray; }");

    // 连接信号和槽，实现提示文字的显示和隐藏
    connect(ui->lineEdit, &QLineEdit::textChanged, this, &MainWindow::lineEditPrompt);

    //openFile(QString("./document1.txt"));

    connect(ui->newProjectAct, &QAction::triggered, this, &MainWindow::getNewProjectInfo);  //todo：实现菜单栏创建项目动作

    connect(ui->copyCodeButton, &QPushButton::clicked, this, &MainWindow::on_copyCodeButton_clicked);

    connect(ui->copyFixedCodeButton, &QPushButton::clicked, this, &MainWindow::on_copyFixedCodeButton_clicked);

    errordlg = new QErrorMessage(this);

    projectModel = new QStandardItemModel(this);

    todoListModel = new QStandardItemModel(this);

    fixedCodeHighlighter = new Highlighter(ui->fixedCodeTextEdit->document());

    hmppCodeHighlighter = new Highlighter(ui->codeBrowser->document());

    initProjectInfo();


    //这里先把ClassView给隐藏起来
    ui->treeClassView->hide();

    //项目栏Model初始化设置
    projectModel->setColumnCount(1);
    projectModel->setHeaderData(0, Qt::Horizontal, " Projects");
    ui->projectTreeView->setModel(projectModel);
    ui->projectTreeView->setContextMenuPolicy(Qt::CustomContextMenu);


    //to-do List初始化设置
    todoListModel->setColumnCount(1);
    todoListModel->setHeaderData(0, Qt::Horizontal, " To-do List");
    ui->toDoTableView->setModel(todoListModel);
    ui->toDoTableView->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->toDoTableView->horizontalHeader()->setVisible(true);


    specificationModel = new QStandardItemModel(this);

    //需求栏Model初始化设置
    specificationModel->setColumnCount(1);
    specificationModel->setHeaderData(0, Qt::Horizontal, " Specification");

    ui->specificationView->setModel(specificationModel);

    // 设置项不可编辑
    ui->projectTreeView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->toDoTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // 初始化bug description部分
    ui->labelCurrentLine->clear();
    ui->comboBoxBugNature->setCurrentIndex(-1);
    ui->lineEditBugName->clear();
    ui->textEditBugDescription->clear();


    // 获取QHeaderView
    QHeaderView *projectHeader = ui->projectTreeView->header();

    projectHeader->setStyleSheet("QHeaderView::section { background-color: rgb(242, 242, 242); border: 1px solid gray; }");

    QHeaderView *todoListHeader = ui->toDoTableView->horizontalHeader();

    todoListHeader->setStyleSheet("QHeaderView::section { background-color: rgb(242, 242, 242); border: 1px solid gray; }");

    todoListHeader->setDefaultAlignment(Qt::AlignLeft);

    ui->specificationView->expandAll();   //自动展开所有项

    // 设置项不可编辑
    ui->specificationView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    // 获取QHeaderView
    QHeaderView *requirementHeader = ui->specificationView->header();

    // 设置Header的样式
    requirementHeader->setStyleSheet("QHeaderView::section { background-color: rgb(242, 242, 242); border: 1px solid gray; }");

    connect(ui->specificationView, &RequirementTreeView::complete, this, &MainWindow::completeSpecification);
    connect(ui->toDoTableView, &ToDoTableView::complete, this, &MainWindow::completeToDoNote);

    appDir = QDir(QCoreApplication::applicationDirPath());  //保存项目工作目录
    appDir.cdUp();


    connect(ui->projectTreeView, &QTreeView::doubleClicked, this, &MainWindow::doubleClickedProjectTree);
    connect(ui->projectTreeView, &QTreeView::customContextMenuRequested, this, &MainWindow::projectViewMenuRequest);
    connect(ui->specificationView, &RequirementTreeView::clicked, this, &MainWindow::doubleClickedSpecificationView);
    connect(ui->toDoTableView, &QTableView::doubleClicked, this, &MainWindow::doubleClickedToDoTableView);

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
    //测试用动作
    connect(ui->testAct, &QAction::triggered, this, &MainWindow::testSlot);
    connect(ui->SCMDemoAct, &QAction::triggered, this, &MainWindow::showDemoSCM);

    qDebug() << "1";
}

MainWindow::~MainWindow()
{
    closeProject(currentPro);
    delete ui;
}

void MainWindow::insertProjectClassInfo(const QList<ClassInfo>& insertClassInfos)
{
    QHash<QString, ClassInfo> insertClassInfoHash;
    for(ClassInfo info : insertClassInfos){
        insertClassInfoHash.insert(info.name, info);
    }

    QStringList newClassNames = insertClassInfoHash.uniqueKeys();
    for(QString& name: newClassNames){
        name = name.trimmed();
        if(includedClass.contains(name) || name.isEmpty()){
            newClassNames.removeOne(name);
        }
    }

    //includedClass = includedClass + newClassNames;

    //1. 新类要创建头文件和源文件，更改项目文件
    for(auto className : newClassNames){
        if(proClassInfoHash.isEmpty() || !proClassInfoHash.contains(className)){  //项目原来的类信息不包括新类名
            if(createNewClassFiles(className)){  //为新类创建类文件
                addFileStrToCmakeFile(className + ".cpp");
                ClassInfo newInfo = insertClassInfoHash.value(className);
                proClassInfoHash.insert(className, newInfo);
                clearAndModifyClassHeaderFile(newInfo, className);
                clearAndModifyClassSourceFile(newInfo, className);
                includedClass.append(className);
            }else{
                qDebug() << "updateProjectClassInfo: failed to create a new class: " << className;
            }
        }
    }
    includedClass.removeDuplicates();
    showClassUnspecifiedTypeIssue();

}

void MainWindow::updateProjectClassInfo(QString filePath, QHash<QString, ClassInfo>& updateClassInfoHash)
{
    //includedClass: included files里面非用户定义的类； 用户在本项目中定义的类
    //proClassInfoHash: 用户在本项目中定义的类
    qDebug() << "MainWindow::updateProjectClassInfo";
    QStringList newClassNames = QStringList();;
    if(updateClassInfoHash.isEmpty()){
        qDebug() << "updateClassInfoHash is empty!";
    }else{
        newClassNames = updateClassInfoHash.uniqueKeys();
    }

    QStringList proClassNames = (proClassInfoHash.isEmpty()) ? QStringList() : proClassInfoHash.uniqueKeys();

    QStringList updateClassNames;   //需要更新类信息的类名
    QStringList removeList;
    for(QString& name: newClassNames){
        name = name.trimmed();
        qDebug() << "newClassNames: " << name;
        if(includedClass.contains(name) || name.isEmpty()){
            removeList.append(name);
        }
        if(proClassNames.contains(name) && !name.isEmpty()){
            updateClassNames.append(name);
        }
    }

    for(QString name: removeList){
        newClassNames.removeOne(name);
    }

    //类名分为：
    //1. include中定义的，但是tool还不知道的（uncheckedItems）
    //2. include中定义的，但是tool已经知道的（includedClass)
    //3. 用户定义的，但是tool已经知道的(updateClassNames)，此时应该更新类文件
    //4. 用户想定义的，且tool不知道的(checkedItems)，此时应该创建类文件
    //新来的类信息，由用户定义哪些类是新的
    //对话框，由用户勾选项的信息
    QStringList checkedItems, uncheckedItems;
    includedClass.removeAll(UNSPECIFIED);
    newClassNames.removeAll(UNSPECIFIED);
    SelectNewClassDialog dialog(newClassNames, includedClass, this);
    if (dialog.exec() == QDialog::Accepted) {
        checkedItems = dialog.checkedItems();
        uncheckedItems = dialog.uncheckedItems();

        QString message = "Checked Items:" + checkedItems.join(", ") +
                          "\nUnchecked Items:" + uncheckedItems.join(", ");
        qDebug() << message;
    }

    includedClass = includedClass + uncheckedItems;

    //1. 新类要创建头文件和源文件，更改项目文件
    for(auto className : checkedItems){
        if(proClassInfoHash.isEmpty() || !proClassInfoHash.contains(className)){  //项目原来的类信息不包括新类名
            if(createNewClassFiles(className)){  //为新类创建类文件
                addFileStrToCmakeFile(className + ".cpp");
                ClassInfo newInfo = updateClassInfoHash.value(className);
                proClassInfoHash.insert(className, newInfo);
                clearAndModifyClassHeaderFile(newInfo, className);
                clearAndModifyClassSourceFile(newInfo, className);
                includedClass.append(className);
            }else{
                qDebug() << "updateProjectClassInfo: failed to create a new class: " << className;
            }
        }
    }
    includedClass.removeDuplicates();

    //从对应文件取出preClassInfoHash
    //从proClassInfoHash删除原来的preClassInfoHash，加入新的updateClassInfoHash
    //再根据proClassInfoHash的信息重写头文件
    qDebug() << "fileClassInfoHash: " << fileClassInfoHash.isEmpty();
    QHash<QString, ClassInfo> preClassInfoHash = fileClassInfoHash.contains(filePath) ?
               fileClassInfoHash[filePath] : QHash<QString, ClassInfo>();
    qDebug() << "preClassInfoHash: " << preClassInfoHash.isEmpty();

    //2. 所有用户定义的类都要更改头文件，根据原来的类信息，一一比对
    for(auto className : updateClassNames){
        qDebug() << "updateClassNames: " << className;
        ClassInfo& newInfo = updateClassInfoHash[className];
        ClassInfo& proClassInfo = proClassInfoHash[className];

        qDebug() << "**************************************";
        qDebug() << "newInfo:";
        for(int j = 0; j < newInfo.vars->size(); j++){
            qDebug() << newInfo.vars->at(j).type << " " <<
                        newInfo.vars->at(j).className << "::" <<newInfo.vars->at(j).name;
        }

        for(int j = 0; j < newInfo.methods->size(); j++){
            qDebug() << newInfo.methods->at(j).returnType << " "
                     << newInfo.methods->at(j).className << "::" <<newInfo.methods->at(j).name
                     << "(" << newInfo.methods->at(j).paramStr << ")";
        }

        qDebug() << "**************************************";
        qDebug() << "proClassInfo:";
        for(int j = 0; j < proClassInfo.vars->size(); j++){
            qDebug() << proClassInfo.vars->at(j).type << " " <<
                        proClassInfo.vars->at(j).className << "::" <<proClassInfo.vars->at(j).name;
        }

        qDebug() << "Methods:";
        for(int j = 0; j < proClassInfo.methods->size(); j++){
            qDebug() << proClassInfo.methods->at(j).returnType << " "
                     << proClassInfo.methods->at(j).className << "::" <<proClassInfo.methods->at(j).name
                     << "(" << proClassInfo.methods->at(j).paramStr << ")";
        }


        //这里有几种情况
        //1. 在原来同一个函数的基础上做了改动，比如参数或返回类型改变
        //2. 删除了原来的同名函数
        //4. 新增了函数（包括同名函数）


        QList<std::pair<QString, QString>> replaceInfo;

        ClassInfo addInfo = ClassInfo();
        addInfo.name = newInfo.name;
        for(int i = 0; i < newInfo.methods->size(); i++){
            Method& m = (*newInfo.methods)[i];
            qDebug() << "newInfo: parameters: " << m.parameters;
            qDebug() << "newInfo: paramStr: " << m.paramStr;
            QList<Method> oldMethodList = QList<Method>();
            QList<Method> newMethodList = QList<Method>();
            if(!proClassInfo.methods->contains(m)){   //如果旧信息中没有新信息同样的函数，说明需要添加
                for(int j = 0; j < proClassInfo.methods->size(); j++){
                    if(m.name == proClassInfo.methods->at(j).name) {
                        if(m >= proClassInfo.methods->at(j)){
                            (*proClassInfo.methods)[j] = m;
                            qDebug() << "newInfo > proClassInfo";
                            qDebug() << "proInfo: " << proClassInfo.methods->at(j).parameters;
                            qDebug() << "newInfo: " << m.parameters;
                            break;
                        }else if (proClassInfo.methods->at(j) >= m){  //将新信息中类型更全的函数更新到旧信息中
                            m = proClassInfo.methods->at(j);
                            qDebug() << "newInfo < proClassInfo";
                            qDebug() << "proInfo: " << proClassInfo.methods->at(j).parameters;
                            qDebug() << "newInfo: " << m.parameters;
                            break;
                        }else{
                            if(!oldMethodList.contains(proClassInfo.methods->at(j))){
                                oldMethodList.append(proClassInfo.methods->at(j));
                            }
                            if(!newMethodList.contains(m)){
                                newMethodList.append(m);
                            }
                        }
                    }
                }
            }

            if(!oldMethodList.isEmpty()){
                QStringList oldMethodStringList, newMethodStringList;
                for(auto m : oldMethodList){
                    QString str = m.returnType + " " + m.className + "::" + m.name
                            + "(" + m.paramStr + ")";
                    oldMethodStringList.append(str);
                }
                for(auto m : newMethodList){
                    QString str = m.returnType + " " + m.className + "::" + m.name
                            + "(" + m.paramStr + ")";
                    newMethodStringList.append(str);
                }

                SameNameMethodHandleDialog dialog(oldMethodStringList, newMethodStringList, this);
                if (dialog.exec() == QDialog::Accepted) {
                    SameNameMethodHandleDialog::DialogResult result = dialog.getResult();
                    if(result.buttonClicked == "Replace"){
                        qDebug() << "Selected index in oldMethodList (A):" << result.indexA;
                        qDebug() << "Selected index in newMethodList (B):" << result.indexB;
                        Method oldMethod = oldMethodList.at(result.indexA);
                        Method newMethod = newMethodList.at(result.indexB);
                        if(!proClassInfo.methods->contains(newMethod)
                                &&proClassInfo.methods->contains(oldMethod)){
                            proClassInfo.methods->removeOne(oldMethod);
                            proClassInfo.methods->append(newMethod);
                            replaceInfo.append(std::make_pair(oldMethodStringList.at(result.indexA),
                                                              newMethodStringList.at(result.indexB)));
                        }
                    }else if (result.buttonClicked == "Add New"){
                        qDebug() << "Selected index in oldMethodList (A):" << result.indexA;
                        qDebug() << "Selected index in newMethodList (B):" << result.indexB;
                        Method newMethod = newMethodList.at(result.indexB);
                        if(!proClassInfo.methods->contains(newMethod)){
                            proClassInfo.methods->append(newMethod);
                            addInfo.methods->append(newMethod);
                        }
                    }else if (result.buttonClicked == "Cancel"){
                        // do nothing
                    }
                }
            }

            if(!proClassInfo.methods->contains(m)){
                proClassInfo.methods->append(m);
                addInfo.methods->append(m);
            }
        }

        for(int i = 0; i < newInfo.vars->size(); i++){
            Variable& v = (*newInfo.vars)[i];
            if(!proClassInfo.vars->contains(v)){   //如果旧信息中没有新信息同样的函数，说明需要添加
                for(int j = 0; j < proClassInfo.vars->size(); j++){
                    if(v.name == proClassInfo.vars->at(j).name) {
                        if(v >= proClassInfo.vars->at(j)){
                            (*proClassInfo.vars)[j] = v;
                            break;
                        }else if (proClassInfo.vars->at(j) >= v){  //将新信息中类型更全的函数更新到旧信息中
                            v = proClassInfo.vars->at(j);
                            break;
                        }
                    }
                }
            }
            if(!proClassInfo.vars->contains(v)){
                proClassInfo.vars->append(v);
                addInfo.vars->append(v);
            }
        }

        qDebug() << "**************************************";
        qDebug() << "addInfo name: " << addInfo.name;
        qDebug() << "Methods:";
        for(int j = 0; j < addInfo.methods->size(); j++){
            qDebug() << addInfo.methods->at(j).returnType << " "
                     << addInfo.methods->at(j).className << "::" << addInfo.methods->at(j).name
                     << "(" << addInfo.methods->at(j).paramStr << ")";
        }

        qDebug() << "proClassInfo name:" << proClassInfo.name;
        qDebug() << "Methods:";
        for(int j = 0; j < proClassInfo.vars->size(); j++){
            qDebug() << proClassInfo.vars->at(j).type << " " <<
                        proClassInfo.vars->at(j).className << "::" <<proClassInfo.vars->at(j).name;
        }

        qDebug() << "Methods:";
        for(int j = 0; j < proClassInfo.methods->size(); j++){
            qDebug() << proClassInfo.methods->at(j).returnType << " "
                     << proClassInfo.methods->at(j).className << "::" <<proClassInfo.methods->at(j).name
                     << "(" << proClassInfo.methods->at(j).paramStr << ")";
        }

        //由于情况复杂，这里直接粗暴的重写对应文件
        //如果遇到那种改动很小的情况，这种粗暴的方式不一定很高效
        clearAndModifyClassHeaderFile(proClassInfo, className);

        ReplaceAndAddInfoInClassSourceFile(replaceInfo, addInfo, className);

    }

    fileClassInfoHash[filePath] = updateClassInfoHash;
    qDebug() << "fileClassInfoHash: " << fileClassInfoHash.isEmpty();
    showClassUnspecifiedTypeIssue();

    //3. 消失的类要删除头文件，更改项目文件
    //此项情况暂时不处理
    qDebug() << "MainWindow::updateProjectClassInfo";
}

bool MainWindow::ReplaceAndAddInfoInClassSourceFile(const QList<std::pair<QString, QString>>& replaceInfo, const ClassInfo& addInfo, QString className)
{
    qDebug() << "ReplaceAndAddInfoInClassSourceFile";
    if(replaceInfo.isEmpty() && addInfo.methods->isEmpty() && addInfo.vars->isEmpty()) {
        qDebug() << "info is empty.";
        return false;
    }
    if(currentPro == nullptr) {
        qDebug() << "currentPro is nullptr.";
        return false;
    }
    //为指定的类的头文件中加入类的成员信息
    QString classFilePath = currentPro->projectPath + "/" + srcDir + "/" + className + ".cpp";
    QFile file(classFilePath);

    if(!QFile::exists(classFilePath) || !file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug() << file.errorString();
        return false;
    }

    QStringList lines;
    QTextStream in(&file);

    // Read the file line by line
    while (!in.atEnd()) {
        lines.append(in.readLine());
    }

    file.close();

    // Perform replacements
    for (QString& line : lines) {
        for (const auto& pair : replaceInfo) {
            if (line.contains(pair.first)) {
                line.replace(pair.first, pair.second);
            }
        }
    }

    // Write the modified content back to the file
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << file.errorString();;
        return false;
    }

    QTextStream out(&file);
    for (const QString& line : lines) {
        out << line << "\n";
    }

    file.close();


    // 添加新信息
    if(!QFile::exists(classFilePath) || !file.open(QIODevice::Text | QIODevice::ReadWrite)){
        qDebug() << file.errorString();
        return false;
    }

    QTextStream stream(&file);
    QString fileContent = stream.readAll(); // Read the entire file content

    stream.seek(file.size());
    stream << "\n\n";

    for(int i = 0; i < addInfo.methods->size(); ++i){
        const Method& method = addInfo.methods->at(i);
        QString methodBody;
        if(method.name == method.className){
            methodBody = QString("%2::%3(%4){").arg(method.className, method.name, method.paramStr);
        }else{
            methodBody = QString("%1 %2::%3(%4){").arg(method.returnType, method.className, method.name, method.paramStr);
        }
        if(!fileContent.contains(methodBody)) {
            stream << methodBody;
            stream << QString("\n" + RequireNoteStartStr + "\t%1::%2\n" + RequireNoteEndStr + "\n}").arg(method.className, method.name);
            stream << "\n\n";
        }

    }

    /*
    QRegExp privateReg(QString("\\bprivate[^\\S\n]*:\n"));
    for(int i = 0; i < addInfo.vars->size(); ++i){
        const Variable& v = addInfo.vars->at(i);
        qDebug() << "addInfo.vars: " << v.name;
        QString insertStr;
        if(v.type.contains("[")){
            QString type = v.type.left(v.type.indexOf("["));
            insertStr = QString("%1 %2[];").arg(type).arg(v.name);
        }else{
            insertStr = QString("%1 %2;").arg(v.type).arg(v.name);
        }
        int pos = 0;
        if((pos = privateReg.indexIn(content, pos)) != -1){
            qDebug() << "Matched text at position:" << pos;

            content.insert(pos + privateReg.cap(0).length(), insertStr);
        }else{
            qDebug() << "Cannot find : " << v.className << "::" << v.type << " " << v.name;
        }

    }

    QRegExp publicReg(QString("\\bpublic[^\\S\n]*:\n"));
    for(int i = 0; i < addInfo.methods->size(); ++i){
        const Method& m = addInfo.methods->at(i);
        qDebug() << "addInfo.methods: " << m.name;
        QString insertStr = QString("%1 %2(%3);").arg(m.returnType).arg(m.name).arg(m.paramStr);

        int pos = 0;
        if((pos = publicReg.indexIn(content, pos)) != -1){
            qDebug() << "Matched text at position:" << pos;

            content.insert(pos + publicReg.cap(0).length(), insertStr);
        }else{
            qDebug() << "Cannot find : " << m.className << "::" << m.returnType << " " << m.name
                     << " " << "(" << m.paramStr << ")";
        }
    }
    */


    file.close();
    openFile(classFilePath);
    qDebug() << "delAndAddInfoInClassSourceFile";
    return true;

}

void MainWindow::showClassUnspecifiedTypeIssue()
{
    qDebug() << "51";
    if(!currentPro){
        qDebug() << "showClassUnspecifiedTypeIssue : currentPro is empty.";
        return;
    }
    QList<ClassInfo> issueInfos;
    qDebug() << "find issue.";
    for (auto it = proClassInfoHash.constBegin(); it != proClassInfoHash.constEnd(); ++it) {
        //qDebug() << "Key:" << it.key() << "Value:" << it.value();
        QString className = it.key();
        ClassInfo info = it.value();
        ClassInfo issueInfo(className);
        for(int i = 0; i < info.vars->size(); i++){
            Variable v = (*info.vars)[i];
            if(v.type == UNSPECIFIED){
                issueInfo.name = className;
                issueInfo.vars->append(v);
            }
        }
        for(int i = 0; i < info.methods->size(); i++){
            Method m = (*info.methods)[i];
            if(m.returnType == UNSPECIFIED || m.parameters.contains(UNSPECIFIED)){
                issueInfo.name = className;
                issueInfo.methods->append(m);
            }
        }
        issueInfos.append(issueInfo);
    }

    for(int i = 0; i < issueInfos.size(); i++){
        ClassInfo info = issueInfos[i];
        qDebug() << info.name;
        for(int j = 0; j < info.vars->size(); j++){
            qDebug() << info.vars->at(j).name;
        }
        for(int j = 0; j < info.methods->size(); j++){
            qDebug() << info.methods->at(j).name;
        }
    }

    qDebug() << "collect issue.";

    QList<ClassMemberUnspecifiedIssue> list;
    for(auto info : issueInfos){
        QString className = info.name;
        QString filePath = currentPro->projectPath + "/" + srcDir + "/" + className + ".cpp";
        if(!openFile(filePath)){
            qDebug() << "Cannot open file : " << filePath;
        }
        MdiChild* mdiChild = activeMdiChild();
        if(!mdiChild){
            qDebug() << "Cannot find the corresponding mdichild.";
        }
        list.append(mdiChild->getUnspecifiedTypeIssueList());
    }

    qDebug() << "showClassUnspecifiedTypeIssue: UnspecifiedIssueList.size = "
             << proIssueManager->getUnspecifiedIssueList().size();
    proIssueManager->clearUnspecifiedIssueList();
    qDebug() << "showClassUnspecifiedTypeIssue: UnspecifiedIssueList.size = "
             << proIssueManager->getUnspecifiedIssueList().size();
    proIssueManager->appendUnspecifiedIssue(list);
    qDebug() << "showClassUnspecifiedTypeIssue: UnspecifiedIssueList.size = "
             << proIssueManager->getUnspecifiedIssueList().size();
    showClassEncapsulateIssueTab();
}

bool MainWindow::createProject(const QString &proName, const QString &proDir, const QString &specDir,
                               const QString &targetLang)
{
    qDebug() << "fileName:" << proName;
    qDebug() << "filePath:" << proDir;
    qDebug() << "targatLang:" << targetLang;
    if(proName.isEmpty() || proDir.isEmpty() || targetLang.isEmpty()){
        qDebug() << "project info is empty.";
        return false;
    }

    targetLanginCurrentPro = targetLang;

    if(targetLanginCurrentPro == "C++"){
        ui->actionCplus->setChecked(true);
        ui->actionJava->setChecked(false);
        ui->actionCsharp->setChecked(false);
    }else if(targetLanginCurrentPro == "Java"){
        ui->actionCplus->setChecked(false);
        ui->actionJava->setChecked(true);
        ui->actionCsharp->setChecked(false);
    }else if(targetLanginCurrentPro == "C#"){
        ui->actionCplus->setChecked(false);
        ui->actionJava->setChecked(false);
        ui->actionCsharp->setChecked(true);
    }

    projectTree* prePro = currentPro;
    if(prePro) closeProject(prePro);
    else qDebug() << "currentPro is null.";

    QString newProDir = proDir;
    if (!proName.isEmpty()){
        if(QDir::setCurrent(proDir)){   //设置打开目录为当前文件夹
            if(QDir::current().mkdir(proName)){   //在打开目录下创建一个项目名为名的文件夹
                newProDir = QDir::current().filePath(proName);
                QDir::setCurrent(newProDir);    //更换到项目文件夹下
            }else{
                errordlg->setWindowTitle(tr("Error Message"));
                errordlg->showMessage(tr("Failed to create a project directory!"));
                return false;
            }
        }else{
            errordlg->setWindowTitle(tr("Error Message"));
            errordlg->showMessage(tr("Failed to change directory when creating a project!"));
            return false;
        }
    }else{
        errordlg->setWindowTitle(tr("Error Message"));
        errordlg->showMessage(tr("Failed to create a project!"));
        return false;
    }
    projectTree* newPro = new projectTree(proName, newProDir, specDir);

    currentPro = newPro;
    if(!readProjectInfoFromCmakeFile(currentPro, includedClass)){
        qDebug() << "Error in reading Project Info From CmakeFile.";
    }

    QFile cmakeFile("CMakeLists.txt");
    if(!cmakeFile.open(QIODevice::ReadWrite | QIODevice::Text)){
        qDebug() << cmakeFile.errorString();
        return false;
    }

    cmakeFile.close();

    if(QDir::current().mkdir("src") && QDir::current().mkdir("include")){
        QDir::setCurrent(QDir::current().filePath("src"));    //更换到src文件夹下
        qDebug() << "currentDir:" << QDir::current();
        QFile mainCpp("main.cpp");
        if(!mainCpp.open(QIODevice::ReadWrite | QIODevice::Text)){
            qDebug() << mainCpp.errorString();
            return false;
        }


        mainCpp.close();

        bool flag = openFile("main.cpp");
        if(!flag){
            errordlg->setWindowTitle(tr("Error Message"));
            errordlg->showMessage(tr("Failed to open main.cpp"));
            return false;
        }
        initCMakeFile(newPro);   //更改CMakeList文件内容，初始化
        QDir::setCurrent(newProDir);    //更换回项目文件夹下
    }
//    QFileInfo mainInfo(mainCpp);
//    qDebug() << QObject::tr("absolute path:") << mainInfo.absoluteFilePath();

    initProjectModel(newPro);
    readContentFromInformalSpecification(specDir);
    return true;
}

void MainWindow::receiveGuideWizardFileInfo(bool createNewFlag, const QString &proName, const QString &proDir, const QString specDir,
                                            const QString &targetLang)
{
    if(createNewFlag){
        createProject(proName, proDir, specDir, targetLang);
    }else{
        loadProject(proDir + "/" + proName, specDir);
    }
}


bool MainWindow::clearAndModifyClassHeaderFile(const ClassInfo& info, QString className)
{
    qDebug() << "clearAndModifyClassHeaderFile";
    if(info.name.isEmpty()) {
        qDebug() << "info.name is empty.";
        return false;
    }
    if(currentPro == nullptr) {
        qDebug() << "currentPro is nullptr.";
        return false;
    }
    //为指定的类的头文件中加入类的成员信息
    QString classFilePath = currentPro->projectPath + "/" + headDir + "/" + className + ".h";
    QFile file(classFilePath);
    if(!QFile::exists(classFilePath) || !file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)){
        qDebug() << file.errorString();
        return false;
    }

    QTextStream stream(&file);
    QString upper = className.toUpper();
    stream << QString("#ifndef %1_H").arg(upper);
    stream << "\n";
    stream << QString("#define %1_H").arg(upper);
    stream << "\n\n";

    stream << QString("class %1\n{").arg(className);
    stream << "\n";
    stream << "\npublic:";
    stream << "\n";

    //依次写入函数
    for(int i = 0; i < info.methods->size(); ++i){
        Method method = info.methods->at(i);

        stream << "\t";
        if(method.name == method.className) {
            stream << QString("%2(%3);").arg(method.name, method.paramStr);
        }else {
            stream << QString("%1 %2(%3);").arg(method.returnType, method.name, method.paramStr);
        }

        stream << "\n\n";
    }
    //为变量设置set和get函数
    for(int i = 0; i < info.vars->size(); ++i){
        Variable var = info.vars->at(i);
        QString firstCapName = var.name;
        if(!firstCapName.isEmpty()) firstCapName[0] = firstCapName[0].toUpper();

        bool flag = false;   //用于标记是否已经存在set和get函数
        for(int i = 0; i < info.methods->size(); i++){
            Method method = info.methods->at(i);
            if(method.name == QString("set%1").arg(firstCapName)){
                flag = true;
                break;
            }
        }

        if(flag == false){   //不存在则写入set函数
            stream << "\t";
            stream << QString("void set%1(const %2& value){ %3 = value; }").arg(firstCapName, var.type, var.name);
            stream << "\n\n";
        }

        flag = false;   //用于标记是否已经存在set和get函数
        for(int i = 0; i < info.methods->size(); i++){
            Method method = info.methods->at(i);
            if(method.name == QString("get%1").arg(firstCapName)){
                flag = true;
                break;
            }
        }

        if(flag == false){   //不存在则写入set函数
            stream << "\t";
            stream << QString("%1 get%2() const { return %4; }").arg(var.type, firstCapName, var.name);
            stream << "\n\n";
        }

    }
    stream << "\n";
    stream << "\nprivate:";
    stream << "\n";

    //依次写入变量
    for(int i = 0; i < info.vars->size(); ++i){
        Variable var = info.vars->at(i);
        stream << "\t";
        stream << QString("%1 %2;").arg(var.type, var.name);
        stream << "\n\n";
    }

    stream << "};";
    stream << "\n";

    stream << QString("#endif //%1_H").arg(upper);
    stream << "\n";
    file.close();
    openFile(classFilePath);
    qDebug() << "clearAndModifyClassHeaderFile";
    return true;
}


bool MainWindow::clearAndModifyClassSourceFile(const ClassInfo& info, QString className)
{
    if(info.name.isEmpty()) return false;
    if(currentPro == nullptr) {
        qDebug() << "currentPro is nullptr.";
        return false;
    }
    //为指定的类的头文件中加入类的成员信息
    QString classFilePath = currentPro->projectPath + "/" + srcDir + "/" + className + ".cpp";
    QFile file(classFilePath);
    if(!QFile::exists(classFilePath) || !file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)){
        qDebug() << file.errorString();
        return false;
    }

    QTextStream stream(&file);

    // 包含类的头文件
    stream << QString("#include \"%1.h\"\n\n").arg(className);


    //依次写入函数
    for(int i = 0; i < info.methods->size(); ++i){
        const Method& method = info.methods->at(i);
        if(method.name == method.className) {
            stream << QString("%2::%3(%4){").arg(method.className, method.name, method.paramStr);
            stream << QString("\n" + RequireNoteStartStr + "\t%1::%2\n" + RequireNoteEndStr + "\n}").arg(method.className, method.name);
        }else {
            stream << QString("%1 %2::%3(%4){").arg(method.returnType, method.className, method.name, method.paramStr);
            stream << QString("\n" + RequireNoteStartStr + "\t%1::%2\n" + RequireNoteEndStr + "\n}").arg(method.className, method.name);
        }

        stream << "\n\n";
    }

    if(info.methods->size() == 0) {
        stream << QString("\n" + RequireNoteStartStr + "\twrite algorithms for %1\n" + RequireNoteEndStr + "\n").arg(className);
    }

    //为变量设置set和get函数

    file.close();
    openFile(classFilePath);
    return true;
}

void MainWindow::readContentFromInformalSpecification(const QString& filePath)
{
    if(!filePath.endsWith("txt")){
        qDebug() << "Specification read error.";
        return;
    }
    QFile file(filePath);
    QString content;

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        content = in.readAll();
        file.close();
    } else {
        qWarning() << "Failed to open file:" << file.errorString();
    }

    QHash<QString, QString> informalSpec;

    QRegularExpressionMatchIterator iterator = informalSpecSectionPattern.globalMatch(content);

    if (iterator.hasNext()) {
        // Get the start position of the first match
        QRegularExpressionMatch firstMatch = iterator.next();
        QString sectionNum = firstMatch.captured().trimmed();
        int lastPosition = firstMatch.capturedEnd(); // End position of the first match

        while (iterator.hasNext()) {
            QRegularExpressionMatch nextMatch = iterator.next();
            int currentPosition = nextMatch.capturedStart(); // Start position of the next match

            // Extract the text between the last match and the current match
            QString sectionContent = content.mid(lastPosition, currentPosition - lastPosition).trimmed();
            informalSpec.insert(sectionNum, sectionContent);
            sectionNum = nextMatch.captured().trimmed();

            lastPosition = nextMatch.capturedEnd(); // Update the last position to the end of the current match
        }

        // If needed, handle text after the last match
        // Uncomment the following lines if you want to include text after the last match
        informalSpec.insert(sectionNum, content.mid(lastPosition).trimmed());
    }

    qDebug() << "Section in spec.";
    for (auto it = informalSpec.constBegin(); it != informalSpec.constEnd(); ++it) {
        qDebug() << "Key:" << it.key();
        qDebug() << "Value:" << it.value();
    }

    currentPro->proInformalSpec = informalSpec;

    updateSpecificationModel(informalSpec);
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


void MainWindow::showProjectView()
{
    ui->stackedWidgetLeft->setCurrentIndex(0);
    ui->stackedWidgetRightDown->setCurrentIndex(0);
    ui->stackedWidgetRightDown->show();
}

void MainWindow::showHMPPView()
{
    ui->stackedWidgetLeft->setCurrentIndex(3);
    ui->stackedWidgetRightDown->hide();
}

void MainWindow::showFixedCodeView()
{
    ui->stackedWidgetLeft->setCurrentIndex(1);
    ui->stackedWidgetRightDown->hide();
}

void MainWindow::showCSCRTool()
{
    ui->stackedWidgetLeft->setCurrentIndex(2);
    //ui->verticalLayout->setStretch(0, 1);
    //ui->verticalLayout->setStretch(1, 1);
    ui->stackedWidgetRightDown->setCurrentIndex(1);
    ui->stackedWidgetRightDown->show();

    QList<QString> itemList = cscrToolMethodNameToCode.keys();
    itemList.sort();
    CscrToolDialog *cscrToolDialog = new CscrToolDialog(this, itemList);

    connect(cscrToolDialog, &CscrToolDialog::reviewMethod, this, &MainWindow::reviewMethodCode);
    connect(cscrToolDialog, &CscrToolDialog::loadBugReportFile, this, &MainWindow::loadBugReportFile);
    cscrToolDialog->exec();
    delete cscrToolDialog;  // Cleanup after execution
}

void MainWindow::loadBugReportFile(QString bugReportFilePath)
{
    QFile file(bugReportFilePath);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Failed to open file for reading: " << bugReportFilePath;
        return;
    }

    QByteArray jsonData = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(jsonData);
    if (doc.isNull() || !doc.isObject()) {
        qDebug() << "Invalid JSON file.";
        return;
    }

    QJsonObject project = doc.object();

    QString methodName = project["methodName"].toString();
    QString methodCode = project["methodCode"].toString();

    QString sanatizedMethodName = Utils::sanitizeFileName(Utils::getLeftSubstring(methodName, "("));

    // Read bugObjectList
    QList<BugObject> bugList;
    QJsonArray bugArray = project["bugObjectList"].toArray();
    for (const QJsonValue &val : bugArray) {
        bugList.append(BugObject::fromJson(val.toObject()));
    }

    // Read segmentList
    QList<int> segmentList;
    QJsonArray segmentsArray = project["segmentList"].toArray();
    for (const QJsonValue &val : segmentsArray) {
        segmentList.append(val.toInt());
    }

    // Print retrieved data
    qDebug() << "Method Name:" << methodName;
    qDebug() << "Method Code:" << methodCode;

    for (const BugObject &bug : bugList) {
        qDebug() << "BugLine:" << bug.bugLine
                 << "BugName:" << bug.bugName
                 << "BugNature:" << bug.bugNature
                 << "BugDescription:" << bug.bugDescription;
    }

    qDebug() << "Segment List:" << segmentList;

    MdiChild* cscrToolMdiChild = newReviewCodeFile("review_" + sanatizedMethodName + ".txt");
    bugSet = new CscrToolBugSet("review_" + sanatizedMethodName + ".txt");
    bugSet->setBugObjectList(bugList);
    cscrToolMdiChild->setCscrToolMode(true);
    cscrToolMdiChild->setText(methodCode);

    cscrToolMdiChild->setStructureNumberList(segmentList);

    QList<int> bugLineNumbers;
    for (const BugObject &bug : bugList) {
        bugLineNumbers.append(bug.bugLine);
    }
    cscrToolMdiChild->markBugLines(bugLineNumbers);

    ui->lineEditBugName->setReadOnly(true);
    //ui->comboBoxBugNature->setEnabled(false);
    ui->textEditBugDescription->setReadOnly(true);
    ui->buttonBugReportOK->setEnabled(false);
    ui->buttonBugReportCancel->setEnabled(false);

    // 点击按钮可以来回浏览bug set
    showReviewBugInfo(bugSet, cscrToolMdiChild);
    disconnect(ui->buttonPreviousBugDescription, nullptr, nullptr, nullptr);
    connect(ui->buttonPreviousBugDescription, &QPushButton::clicked, [this, cscrToolMdiChild](){
        if (bugSet->getCurrentIndex() != 0) {
            bugSet->setCurrentIndex(bugSet->getCurrentIndex() - 1);
        }
        showReviewBugInfo(bugSet, cscrToolMdiChild);

    });

    disconnect(ui->buttonNextBugDescription, nullptr, nullptr, nullptr);
    connect(ui->buttonNextBugDescription, &QPushButton::clicked, [this, cscrToolMdiChild](){
        if (bugSet->getCurrentIndex() != bugSet->getBugObjectList().size() - 1) {
            bugSet->setCurrentIndex(bugSet->getCurrentIndex() + 1);
        }

        showReviewBugInfo(bugSet, cscrToolMdiChild);
    });
}

void MainWindow::showReviewBugInfo(CscrToolBugSet* bugSet, MdiChild* cscrToolMdiChild)
{
    BugObject obj = bugSet->getCurrentBugObject();
    int lineNumber = obj.bugLine;
    QString bugName = obj.bugName;
    QString bugNature = obj.bugNature;
    QString bugDescription = obj.bugDescription;

    cscrToolMdiChild->goToLine(lineNumber);

    ui->labelCurrentLine->setText(QString::number(lineNumber + 1));
    ui->lineEditBugName->setText(bugName);
    int index = ui->comboBoxBugNature->findText(bugNature);
    if (index != -1) {  // Ensure the text exists in the combo box
        ui->comboBoxBugNature->setCurrentIndex(index);
    } else {
        qDebug() << "Target string not found in the combo box!";
    }
    ui->textEditBugDescription->setText(bugDescription);
}

void MainWindow::reviewMethodCode(QString methodName)
{
    ui->buttonReviewFromStart->setEnabled(false);
    ui->buttonBackToCurrent->setEnabled(false);
    ui->buttonCompleteCurrentSegment->setEnabled(false);
    ui->buttonGenerateReviewReport->setEnabled(false);
    ui->buttonPreviousBugDescription->setEnabled(false);
    ui->buttonNextBugDescription->setEnabled(false);
    ui->buttonRestartStructure->setEnabled(true);
    ui->buttonStructure->setEnabled(true);
    ui->buttonUndoStructure->setEnabled(true);
    ui->buttonDoneStructure->setEnabled(true);

    ui->lineEditBugName->setEnabled(false);
    ui->comboBoxBugNature->setEnabled(false);
    ui->textEditBugDescription->setEnabled(false);
    ui->buttonBugReportOK->setEnabled(false);
    ui->buttonBugReportCancel->setEnabled(false);

    ui->buttonBugReportOK->setFocusPolicy(Qt::NoFocus);
    ui->buttonBugReportCancel->setFocusPolicy(Qt::NoFocus);

    QString methodCode = cscrToolMethodNameToCode.value(methodName);
    QString seperatedMethodName = Utils::getLeftSubstring(methodName, "(");
    QString sanatizedMethodName = Utils::sanitizeFileName(seperatedMethodName);
    qDebug() << "reviewMethod: active: " << this->activeMdiChild();
    MdiChild* cscrToolMdiChild = newReviewCodeFile("review_" + sanatizedMethodName + ".txt");
    bugSet = new CscrToolBugSet("review_" + sanatizedMethodName + ".txt");
    qDebug() << "reviewMethod: active: " << this->activeMdiChild();
    cscrToolMdiChild->setCscrToolMode(true);
    cscrToolMdiChild->setText(methodCode);

    connect(ui->buttonRestartStructure, &QPushButton::clicked, cscrToolMdiChild, &MdiChild::clearStructureNumberList);
    connect(ui->buttonStructure, &QPushButton::clicked, cscrToolMdiChild, &MdiChild::addToStructureNumberList);
    connect(ui->buttonUndoStructure, &QPushButton::clicked, cscrToolMdiChild, &MdiChild::undoStructureNumberList);
    connect(ui->buttonDoneStructure, &QPushButton::clicked, [this, cscrToolMdiChild](){
                ui->buttonRestartStructure->setEnabled(false);
                ui->buttonStructure->setEnabled(false);
                ui->buttonUndoStructure->setEnabled(false);
                ui->buttonDoneStructure->setEnabled(false);
                ui->buttonReviewFromStart->setEnabled(true);
                ui->buttonBackToCurrent->setEnabled(true);
                ui->buttonCompleteCurrentSegment->setEnabled(true);
                ui->buttonGenerateReviewReport->setEnabled(true);
                ui->buttonPreviousBugDescription->setEnabled(true);
                ui->buttonNextBugDescription->setEnabled(true);

                ui->lineEditBugName->setEnabled(false);
                ui->comboBoxBugNature->setEnabled(false);
                ui->textEditBugDescription->setEnabled(false);
                ui->buttonBugReportOK->setEnabled(false);
                ui->buttonBugReportCancel->setEnabled(false);
                cscrToolMdiChild->startReview();
            });

    connect(ui->buttonReviewFromStart, &QPushButton::clicked, cscrToolMdiChild, &MdiChild::scrollToFirstLine);
    connect(ui->buttonBackToCurrent, &QPushButton::clicked, cscrToolMdiChild, &MdiChild::scrollToCurrentReviewLine);
    connect(ui->buttonCompleteCurrentSegment, &QPushButton::clicked, cscrToolMdiChild, &MdiChild::moveToNextReviewSegment);
    connect(cscrToolMdiChild, &MdiChild::challengeQuestionFlag, this, &MainWindow::showChallengeQuestions);

    connect(cscrToolMdiChild, &MdiChild::reportBugLine, [this, cscrToolMdiChild](int lineNumber){
        ui->lineEditBugName->setEnabled(true);
        ui->comboBoxBugNature->setEnabled(true);
        ui->textEditBugDescription->setEnabled(true);
        ui->buttonBugReportOK->setEnabled(true);
        ui->buttonBugReportCancel->setEnabled(true);
        ui->labelCurrentLine->setText(QString::number(lineNumber + 1));
        ui->lineEditBugName->clear();
        ui->comboBoxBugNature->setCurrentIndex(-1);
        ui->textEditBugDescription->clear();
    });

    // 点击按钮可以来回浏览bug set
    showReviewBugInfo(bugSet, cscrToolMdiChild);
    disconnect(ui->buttonPreviousBugDescription, nullptr, nullptr, nullptr);
    connect(ui->buttonPreviousBugDescription, &QPushButton::clicked, [this, cscrToolMdiChild](){
        if (bugSet->getCurrentIndex() != 0) {
            bugSet->setCurrentIndex(bugSet->getCurrentIndex() - 1);
        }
        showReviewBugInfo(bugSet, cscrToolMdiChild);

    });

    disconnect(ui->buttonNextBugDescription, nullptr, nullptr, nullptr);
    connect(ui->buttonNextBugDescription, &QPushButton::clicked, [this, cscrToolMdiChild](){
        if (bugSet->getCurrentIndex() != bugSet->getBugObjectList().size() - 1) {
            bugSet->setCurrentIndex(bugSet->getCurrentIndex() + 1);
        }

        showReviewBugInfo(bugSet, cscrToolMdiChild);
    });


    connect(ui->buttonBugReportOK, &QPushButton::clicked, [this, cscrToolMdiChild](){
        qDebug() << "okbutton: active: " << this->activeMdiChild();
        int lineNumber;
        if(!ui->labelCurrentLine->text().isEmpty()){
            lineNumber = ui->labelCurrentLine->text().toInt() - 1;
            QString bugName = ui->lineEditBugName->text();
            QString bugNature = ui->comboBoxBugNature->currentText();
            QString bugDescription = ui->textEditBugDescription->toPlainText();

            BugObject bugObj(lineNumber, bugName, bugNature, bugDescription);
            if(bugSet->append(cscrToolMdiChild->userFriendlyCurrentFile(), bugObj)){
                showReviewBugInfo(bugSet, cscrToolMdiChild);
            }

            ui->labelCurrentLine->clear();
            ui->lineEditBugName->clear();
            ui->comboBoxBugNature->setCurrentIndex(-1);
            ui->textEditBugDescription->clear();
            ui->lineEditBugName->setEnabled(false);
            ui->comboBoxBugNature->setEnabled(false);
            ui->textEditBugDescription->setEnabled(false);
            ui->buttonBugReportOK->setEnabled(false);
            ui->buttonBugReportCancel->setEnabled(false);


        }else{
            qDebug() << "cannot find the right lineNumber: ";
        }
        qDebug() << "okbutton: active: " << this->activeMdiChild();
    });

    connect(ui->buttonBugReportCancel, &QPushButton::clicked, [this](){
        ui->labelCurrentLine->clear();
        ui->lineEditBugName->clear();
        ui->comboBoxBugNature->setCurrentIndex(-1);
        ui->textEditBugDescription->clear();
        ui->lineEditBugName->setEnabled(false);
        ui->comboBoxBugNature->setEnabled(false);
        ui->textEditBugDescription->setEnabled(false);
        ui->buttonBugReportOK->setEnabled(false);
        ui->buttonBugReportCancel->setEnabled(false);
    });

    connect(ui->buttonAISuggestion, &QPushButton::clicked, [this, cscrToolMdiChild](){
        QMessageBox::StandardButton replyAISuggestion;
        replyAISuggestion = QMessageBox::question(this, "AI Suggestion", "Would you like to receive AI-based advice on the code being reviewed?",
                                      QMessageBox::Ok | QMessageBox::Cancel);
        if(replyAISuggestion == QMessageBox::Ok){
            ChatgptClient* client = new ChatgptClient(this);
            QString request = fixCodePrompt + cscrToolMdiChild->toPlainText();
            client->sendUserMessage(request);

            connect(client, &ChatgptClient::replyIsReady, [this, cscrToolMdiChild](const QString &reply){
                qDebug() << "AI Suggestion Reply Received:" << reply;

                // TODO:  extract the AI suggestion from the reply.
                // due to the rate limit, the api key is not available. So I just use an example to show.

                int lineNumber = 0;
                QString bugName = "Bug found by ChatGPT";
                QString bugNature = "AI Suggestion";
                QString bugDescription = "This is a bug found by ChatGPT";
                BugObject bugObj(lineNumber, bugName, bugNature, bugDescription);
                if(bugSet->append(cscrToolMdiChild->userFriendlyCurrentFile(), bugObj)){
                    showReviewBugInfo(bugSet, cscrToolMdiChild);
                }
            });

        }else{

        }
    });

//    showReviewBugInfo(bugSet);
//    connect(ui->buttonPreviousBugDescription, &QPushButton::clicked, [this](){
//        if (bugSet->getCurrentIndex() == 0) {
//            return; // Already at begin(), do nothing
//        }
//        bugSet->setCurrentIndex(bugSet->getCurrentIndex() - 1);
//        showReviewBugInfo(bugSet);

//    });

//    connect(ui->buttonNextBugDescription, &QPushButton::clicked, [this](){
//        if (bugSet->getCurrentIndex() == bugSet->getBugObjectList().size() - 1) {
//            return; // Already at end(), do nothing
//        }
//        bugSet->setCurrentIndex(bugSet->getCurrentIndex() + 1);
//        showReviewBugInfo(bugSet);
//    });

    connect(cscrToolMdiChild, &MdiChild::allSegmentsReviewComplete, [this, cscrToolMdiChild, methodName, methodCode](){
                QMessageBox::StandardButton reply;
                reply = QMessageBox::question(this, "Generate Report Confirmation", "All the segments have been review. \nDo you want to generate the corresponding review report?",
                                              QMessageBox::Ok | QMessageBox::Cancel);

                if (reply == QMessageBox::Ok) {
                    qDebug() << "User clicked OK!";
                    cscrToolMdiChild->setReviewCodeMode(false);
                    generateReviewReport(cscrToolMdiChild, methodName, methodCode);
                    QMdiSubWindow *window = ui->mdiArea->currentSubWindow();
                    if (window) {
                        window->close();  // closes the whole window that holds the QTextEdit
                    }
                    ui->lineEditSyntax->clear();
                    ui->listWidget->clear();
                    ui->labelCurrentLine->clear();
                    ui->lineEditBugName->clear();
                    ui->comboBoxBugNature->setCurrentIndex(-1);
                    ui->textEditBugDescription->clear();
                } else {
                    qDebug() << "User clicked Cancel!";
                }
            });

    connect(ui->buttonGenerateReviewReport, &QPushButton::clicked, [this, cscrToolMdiChild, methodName, methodCode](){
        bool allIsReviewed = cscrToolMdiChild->isAllSegmentsReviewed();
        QString text;
        if(allIsReviewed){
            text = "All the segments have been review. \nDo you want to generate the corresponding review report?";
        }else{
            text = "There are still some segments that have not been reviewed. \nAre you sure you want to generate the corresponding  review report?";
        }
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Generate Report Confirmation", text,
                                      QMessageBox::Ok | QMessageBox::Cancel);

        if (reply == QMessageBox::Ok) {
            qDebug() << "User clicked OK!";
            cscrToolMdiChild->setReviewCodeMode(false);
            generateReviewReport(cscrToolMdiChild, methodName, methodCode);
            QMdiSubWindow *window = ui->mdiArea->currentSubWindow();
            if (window) {
                window->close();  // closes the whole window that holds the QTextEdit
            }
            ui->lineEditSyntax->clear();
            ui->listWidget->clear();
            ui->labelCurrentLine->clear();
            ui->lineEditBugName->clear();
            ui->comboBoxBugNature->setCurrentIndex(-1);
            ui->textEditBugDescription->clear();
        } else {
            qDebug() << "User clicked Cancel!";
        }
    });
    qDebug() << "reviewMethod: active: " << this->activeMdiChild();
}

void MainWindow::generateReviewReport(MdiChild* child, QString methodName, QString methodCode)
{
    qDebug() << "generateReviewReport:";
    if(child->userFriendlyCurrentFile() != bugSet->getBugFileName()){
        qDebug() << "fileName not matches. " << child->userFriendlyCurrentFile() << " is not equal to " << bugSet->getBugFileName();
        return;
    }
    for (const BugObject &bug : bugSet->getBugObjectList()) {
        qDebug() << "BugLine:" << bug.bugLine
                 << "BugName:" << bug.bugName
                 << "BugNature:" << bug.bugNature
                 << "BugDescription:" << bug.bugDescription;
    }

    QJsonObject project;
    project["projectName"] = currentPro->projectName;
    project["projectPath"] = currentPro->projectPath;
    project["methodName"] = methodName;
    project["sourceCode"] = methodCode;

    // Convert bugObjectList to QJsonArray
    QJsonArray bugArray;
    for (const BugObject &bug : bugSet->getBugObjectList()) {
        bugArray.append(bug.toJson());
    }
    project["bugObjectList"] = bugArray;

    QJsonArray segmentsArray;
    for (int num : child->getStructureNumberList()) {
        segmentsArray.append(num);
    }
    project["segmentList"] = segmentsArray;

    child->saveReviewReport(project);

}

void MainWindow::showChallengeQuestions(QString currentStr, CodeElements elements){
//    QStringList functions;
//    QStringList variables;
//    QStringList classes;
//    QStringList loopKeywords;
//    QStringList conditionKeywords;
//    QStringList exceptionHandlingKeywords;
//    QStringList constants;
//    QStringList assignmentOps;
    ui->listWidget->clear();
    QFont font = ui->lineEditSyntax->font();
    font.setBold(true);  // Make the font bold
    ui->lineEditSyntax->setFont(font);  // Apply the font to the QLineEdit
    ui->lineEditSyntax->setText(currentStr);
    //QStringList questions;
    if(!elements.functions.isEmpty()){
        for(const QString &func : elements.functions){
            QListWidgetItem *item = new QListWidgetItem(func);
            // Set the font to bold
            QFont font = item->font();
            font.setBold(true);  // Make the font bold
            item->setFont(font);
            ui->listWidget->addItem(item);
            for (const QString &item : methodNameQuestions) {
                ui->listWidget->addItem(item);
            }
        }
    }
    if(!elements.variables.isEmpty()){
        for(const QString &func : elements.variables){
            QListWidgetItem *item = new QListWidgetItem(func);
            // Set the font to bold
            QFont font = item->font();
            font.setBold(true);  // Make the font bold
            item->setFont(font);
            ui->listWidget->addItem(item);
            for (const QString &item : varDeclarationQuestions) {
                ui->listWidget->addItem(item);
            }
        }

    }
    if(!elements.classes.isEmpty()){
        for(const QString &func : elements.classes){
            QListWidgetItem *item = new QListWidgetItem(func);
            // Set the font to bold
            QFont font = item->font();
            font.setBold(true);  // Make the font bold
            item->setFont(font);
            ui->listWidget->addItem(item);
            for (const QString &item : classNameQuestions) {
                ui->listWidget->addItem(item);
            }
        }
    }
    if(!elements.loopKeywords.isEmpty()){
        for(const QString &func : elements.loopKeywords){
            QListWidgetItem *item = new QListWidgetItem(func);
            // Set the font to bold
            QFont font = item->font();
            font.setBold(true);  // Make the font bold
            item->setFont(font);
            ui->listWidget->addItem(item);
            for (const QString &item : forLoopQuestions) {
                ui->listWidget->addItem(item);
            }
        }
    }
    if(!elements.conditionKeywords.isEmpty()){
        for(const QString &func : elements.conditionKeywords){
            QListWidgetItem *item = new QListWidgetItem(func);
            // Set the font to bold
            QFont font = item->font();
            font.setBold(true);  // Make the font bold
            item->setFont(font);
            ui->listWidget->addItem(item);
            for (const QString &item : ifElseQuestions) {
                ui->listWidget->addItem(item);
            }
        }
    }
    if(!elements.exceptionHandlingKeywords.isEmpty()){
        for(const QString &func : elements.exceptionHandlingKeywords){
            QListWidgetItem *item = new QListWidgetItem(func);
            // Set the font to bold
            QFont font = item->font();
            font.setBold(true);  // Make the font bold
            item->setFont(font);
            ui->listWidget->addItem(item);
            for (const QString &item : exceptionHandlingStatementQuestions) {
                ui->listWidget->addItem(item);
            }
        }
    }
    if(!elements.constants.isEmpty()){
        for(const QString &func : elements.constants){
            QListWidgetItem *item = new QListWidgetItem(func);
            // Set the font to bold
            QFont font = item->font();
            font.setBold(true);  // Make the font bold
            item->setFont(font);
            ui->listWidget->addItem(item);
            for (const QString &item : constantQuestions) {
                ui->listWidget->addItem(item);
            }
        }
    }
    if(!elements.assignmentOps.isEmpty()){
        for(const QString &func : elements.assignmentOps){
            QListWidgetItem *item = new QListWidgetItem(func);
            // Set the font to bold
            QFont font = item->font();
            font.setBold(true);  // Make the font bold
            item->setFont(font);
            ui->listWidget->addItem(item);
            for (const QString &item : assignmentStatementQuestions) {
                ui->listWidget->addItem(item);
            }
        }
    }
}

bool MainWindow::createNewClassFiles(const QString& className)
{
    qDebug() << "3";
    MdiChild* child = activeMdiChild();
    if(child){
        if(addFileToProject(currentPro, className + ".cpp")
                && addFileToProject(currentPro, className + ".h")) {
            currentPro->headerFiles.append(className + ".h");
            currentPro->sourceFiles.append(className + ".cpp");
            qDebug() << "3";
            return true;
        }else{
            qDebug() << "3";
            return false;
        }
    }else{
        qDebug() << "3";
        return false;
    }
}

void MainWindow::getNewProjectInfo()
{
    qDebug() << "4";
    QString proDir = QFileDialog::getExistingDirectory(this, tr("Open Directory"), QDir::currentPath(),
                                                       QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    qDebug() << "Current Dir: " << proDir;
    bool ok;
    QString proName = QInputDialog::getText(this, tr("Create a project"),
                                         tr("Project Name:"), QLineEdit::Normal,
                                         tr("untitled"), &ok);
    initProjectInfo();

    QString targetLang = QInputDialog::getItem(this, tr("Choose the target language"),
                                                   tr("Target Language:"), LanguageSet, 0, false, &ok);
    if(ok){
        createProject(proName, proDir, "", targetLang);
    }

    qDebug() << "4";
}

void MainWindow::updateFileToDoRequireNotes(const QString& filePath, const QVector<RequireNote*> &notes)
{
    fileToDoRequireNotes.insert(filePath, notes);
    updateToDoListModel();
}

void MainWindow::updateInformalSpecs(const QString& filePath, const QList<InformalSpecInfo>& informalSpecInfos)
{
    fileInformalSpecs.insert(filePath, informalSpecInfos);
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

void MainWindow::initProjectInfo()
{
    proIssueManager = new IssueManager();
    //当前文件的类信息汇总
    proClassInfoHash = QHash<QString, ClassInfo>();   //key = 类名，value = 类信息

    //每个文件对应的类信息汇总， key = 文件名， value = 类名 + 类信息
    fileClassInfoHash = QHash<QString, QHash<QString, ClassInfo>>();

    fileToDoRequireNotes = QHash<QString, QVector<RequireNote*>>();

    fileInformalSpecs = QHash<QString, QList<InformalSpecInfo>>();

    //include文件中包含的类
    includedClass = QStringList();

    targetLanginCurrentPro = QString();

//    projectModel = new QStandardItemModel(this);

//    todoListModel = new QStandardItemModel(this);

//    specificationModel = new QStandardItemModel(this);
}

void MainWindow::removeNodeAndChildrenInModel(QStandardItemModel *model, const QModelIndex &index) {
    if (!index.isValid()) return;

    QStandardItem *item = model->itemFromIndex(index);
    if (!item) return;

    // Recursively delete child items
    for (int row = item->rowCount() - 1; row >= 0; --row) {
        for (int col = item->columnCount() - 1; col >= 0; --col) {
            removeNodeAndChildrenInModel(model, item->child(row, col)->index());
        }
    }

    // Remove the item itself
    if (item->parent()) {
        item->parent()->removeRow(item->row());
    } else {
        model->removeRow(item->row());
    }
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
    stream << "# Project Info: \n";
    stream << "# IncludedClass: \n";
    stream << "# Specification Path: \n";
    stream << "\n";
    cmakeFile.close();
    qDebug() << "6";
}

bool MainWindow::addFileStrToCmakeFile(const QString &fileNameStr)
{
    QString newFileStr = srcDir + "/" + fileNameStr;
    QString cmakeFilePath;
    qDebug() << "CmakeFile: " << cmakeFilePath;
    if(currentPro) {
        cmakeFilePath = currentPro->projectPath + "/" + currentPro->cmakeFile;
    }else{
        qDebug() << "addFileToCmakeFile:Current Project is Empty!";
        return false;
    }
    QFile cmakeFile(cmakeFilePath);

    // 打开文件以读取内容
    if (!cmakeFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Cannot open cmakefile for reading:" << cmakeFile.errorString();
        return false;
    }

    // 读取文件内容到 QString
    QTextStream in(&cmakeFile);
    QString content = in.readAll();
    cmakeFile.close();

    QString target = "set(SOURCE_FILES";  //插入位置
    // 查找 target 字符串的位置
    int pos = content.indexOf(target);
    if (pos == -1) {
        qWarning() << "Target string not found in the file.";
        return false;
    }

    if(content.indexOf(newFileStr, pos) != -1){
        qDebug() << newFileStr << "already exists in the CMakeFile.";
        return true;
    }else{
        // 在 target 之后插入 str
        pos += target.length();
        content.insert(pos, " " + newFileStr);
    }

    // 重新打开文件以写入修改后的内容
    if (!cmakeFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        qWarning() << "Cannot open cmakefile for writing:" << cmakeFile.errorString();
        return false;
    }

    // 将修改后的内容写回文件
    QTextStream out(&cmakeFile);
    out << content;
    cmakeFile.close();
    return true;

}

bool MainWindow::readProjectInfoFromCmakeFile(const projectTree *pro, QStringList &includedClass)
{
    QDir::setCurrent(pro->projectPath);
    QFile cmakeFile(pro->cmakeFile);
    if(!cmakeFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug() << cmakeFile.errorString();
        return false;
    }
    // 读取文件内容到 QString
    QTextStream in(&cmakeFile);
    QString content = in.readAll();
    cmakeFile.close();

    QString target = "# IncludedClass:";  //读取位置
    // 查找 target 字符串的位置
    int pos = content.indexOf(target);
    if (pos == -1) {
        qWarning() << "Target string not found in the file.";
        return false;
    }
    pos += target.size();

    int endPos = content.indexOf("\n", pos);
    if(endPos == -1){
        qDebug() << "Error in insert target string in the file.";
        return false;
    }else{
        QString classNames = content.mid(pos, endPos - pos);
        QStringList names = classNames.split(",", QString::SkipEmptyParts);
        for(QString str : names){
            str = str.trimmed();
        }
        names.removeAll("");
        includedClass = names;
    }
    return true;
}

bool MainWindow::writeProjectInfoIntoCmakeFile(const projectTree *pro, const QStringList &includedClass)
{
    QDir::setCurrent(pro->projectPath);
    QFile cmakeFile(pro->cmakeFile);
    if(!cmakeFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug() << cmakeFile.errorString();
        return false;
    }
    // 读取文件内容到 QString
    QTextStream in(&cmakeFile);
    QString content = in.readAll();
    cmakeFile.close();

    QString target = "# IncludedClass:";  //插入位置
    // 查找 target 字符串的位置
    int pos = content.indexOf(target);
    if (pos == -1) {
        qWarning() << "Target string not found in the file.";
        return false;
    }
    pos += target.size();

    QString insertClassNames;
    for(QString str : includedClass){
        insertClassNames += (str + ",");
    }
    int endPos = content.indexOf("\n", pos);
    if(endPos == -1){
        qDebug() << "Error in insert target string in the file.";
        return false;
    }else{
        content.replace(pos, endPos - pos, insertClassNames);
    }


    // 重新打开文件以写入修改后的内容
    if (!cmakeFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        qWarning() << "Cannot open cmakefile for writing:" << cmakeFile.errorString();
        return false;
    }

    // 将修改后的内容写回文件
    QTextStream out(&cmakeFile);
    out << content;
    cmakeFile.close();
    return true;

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

    }else if(suffix == "h"){
        QDir temp = proDir;
        filePath = pro->projectPath + "/" + headDir + "/" + fileName;
        dirPath = pro->projectPath + "/" + headDir;
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
        }else if(suffix == "h"){
            itemNewFile->setData(QIcon(resFilePath + "/header.svg"), Qt::DecorationRole);
        }
        bool flag = true;
        QStandardItem* parent = projectModel->itemFromIndex(index);
        for (int i = 0; i < parent->rowCount(); ++i) {
            QStandardItem* child = parent->child(i);
            if (child->text() == itemNewFile->data(Qt::DisplayRole)) {
                flag = false;
            }
        }
        if(flag) parent->appendRow(itemNewFile);

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

    qDebug() << "searchString: " << searchString;
    // 获取指定父索引下的所有子项的数量，包括父索引本身，如果下面不加parent()，就不包括索引本身
    int rowCount = model->rowCount(parentIndex);
    int columnCount = model->columnCount(parentIndex);

    qDebug() << "rowCount: " << rowCount;
    qDebug() << "columnCount: " << columnCount;

    if(parentIndex.isValid()){
        QString str = parentIndex.data(role).toString();
        if(str == searchString) return parentIndex;
    }

    // 遍历每个子项
    for (int row = 0; row < rowCount; ++row) {
        for (int column = 0; column < columnCount; ++column) {
            // 获取子项的索引
            QModelIndex index = model->index(row, column, parentIndex);
            qDebug() << index;

            // 获取子项的数据
            QVariant data = index.data(role);
            qDebug() << data.toString();

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

//比较规格书中的章节号
bool sectionNumberCompare(const QString &a, const QString &b);

void MainWindow::clearSpecificationModel()
{
    qDebug() << "clearSpecificationModel";
    // 删除所有项而不影响 headerData
    specificationModel->removeRows(0, specificationModel->rowCount());
    specificationModel->removeColumns(0, specificationModel->columnCount());
    specificationModel->setColumnCount(1);
    specificationModel->setHeaderData(0, Qt::Horizontal, " Specification");
}

void MainWindow::updateSpecificationModel(const QHash<QString, QString>& informalSpec)
{
    // 删除所有项而不影响 headerData
    specificationModel->removeRows(0, specificationModel->rowCount());
    specificationModel->removeColumns(0, specificationModel->columnCount());
    specificationModel->setColumnCount(1);
    specificationModel->setHeaderData(0, Qt::Horizontal, " Specification");
    //todo:
    if(informalSpec.isEmpty()){
        return;
    }
    //获取项目工作目录下的资源目录
    QString resFilePath = appDir.absolutePath() + "/images/toolbar_images";

    QList<QString> sectionNumList = informalSpec.keys();
    std::sort(sectionNumList.begin(), sectionNumList.end(), sectionNumberCompare);

    //创建一个新项目后修改model
    QStandardItem *parentItem = specificationModel->invisibleRootItem();
    for(int i = 0; i < sectionNumList.size(); ++i){
        QStandardItem* newSection = new QStandardItem;
        QString secIndex = sectionNumList[i];
        QString sectionContent = informalSpec[secIndex];
        QString sectionTitle = sectionContent.left(sectionContent.indexOf('\n'));

        newSection->setData(secIndex + " " + sectionTitle, Qt::DisplayRole);
        newSection->setData(sectionContent, Qt::ToolTipRole);
        //newSection->setData(QIcon(resFilePath + "/folder.png"), Qt::DecorationRole);
        parentItem->appendRow(newSection);
    }

}

// 自定义比较函数，用于版本号的排序
bool sectionNumberCompare(const QString &a, const QString &b) {
    QStringList aParts = a.split(".");
    QStringList bParts = b.split(".");

    int maxParts = std::max(aParts.size(), bParts.size());
    for (int i = 0; i < maxParts; ++i) {
        int aPart = (i < aParts.size()) ? aParts[i].toInt() : 0;
        int bPart = (i < bParts.size()) ? bParts[i].toInt() : 0;
        if (aPart < bPart) {
            return true;
        }
        if (aPart > bPart) {
            return false;
        }
    }
    return false;
}




//void MainWindow::updateSpecificationModel()
//{
//    qDebug() << "8";
//    //ui->specificationView->expandAll();   //自动展开所有项

//    //这里只获取了当前一个文件的requirements
//    QVector<RequireNote*> requirements;
//    if(MdiChild* child = activeMdiChild()){
//       requirements = child->getRequireNotes();
//    }else{
//        qDebug() << "8";
//        return;
//    }

//    if(requirements.empty()){
//        qDebug() << "8";
//        return;
//    }
//    specificationModel->clear();
//    QStandardItem *parentItem = specificationModel->invisibleRootItem();
//    for(auto level1 : requirements){   //最多三级需求，需求节点深度最大为3
//        if(!level1->isRoot) continue;   //如果不是顶级需求，即根节点，直接跳过
//        QStandardItem* itemLevel1 = new QStandardItem;
//        itemLevel1->setData(level1->note, Qt::DisplayRole);
//        itemLevel1->setData(level1->filePath + ":line" + QString::number(level1->startLine), Qt::ToolTipRole);
//        parentItem->appendRow(itemLevel1);
//        for(auto level2: level1->children){
//            QStandardItem* itemLevel2 = new QStandardItem;
//            itemLevel2->setData(level2->note, Qt::DisplayRole);
//            itemLevel2->setData(level2->filePath + ":line" + QString::number(level2->startLine), Qt::ToolTipRole);
//            itemLevel1->appendRow(itemLevel2);
//            for(auto level3: level2->children){
//                QStandardItem* itemLevel3 = new QStandardItem;
//                itemLevel3->setData(level3->note, Qt::DisplayRole);
//                itemLevel3->setData(level3->filePath + ":line" + QString::number(level3->startLine), Qt::ToolTipRole);
//                itemLevel2->appendRow(itemLevel3);
//            }
//        }
//    }
//    specificationModel->setHeaderData(0, Qt::Horizontal, " Specification");
//    ui->specificationView->expandAll();


//    qDebug() << "8";
//}

void MainWindow::doubleClickedSpecificationView(const QModelIndex &index)
{
    qDebug() << "9";
    // 处理双击事件，打开对应文件
    //QStandardItem* item = model.itemFromIndex(index);
    QString content = specificationModel->data(index, Qt::ToolTipRole).toString();
    QString secTitle = specificationModel->data(index, Qt::DisplayRole).toString();

    //显示spec该章节对应的内容
    QDialog dialog;
    dialog.setWindowTitle("Specification");

    QLabel *label1 = new QLabel(secTitle);
    QLabel *label2 = new QLabel(content);
    QPushButton *okButton = new QPushButton("OK");
    QHBoxLayout *buttonLayout = new QHBoxLayout;

    buttonLayout->addSpacerItem(new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));
    buttonLayout->addWidget(okButton);  // 添加按钮到水平布局中

    QFont boldFont;
    boldFont.setPointSize(14);  // 设置字体大小为 20
    boldFont.setBold(true);     // 设置字体加粗

    label1->setFont(boldFont);  // 应用字体到 label2

    QFont normalFont;
    normalFont.setPointSize(12);
    label2->setFont(normalFont);
    label2->setWordWrap(true);

    // 创建布局，并将两个标签添加进去
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(label1);
    layout->addWidget(label2);
    layout->addLayout(buttonLayout);

    dialog.setLayout(layout);
    QObject::connect(okButton, &QPushButton::clicked, &dialog, &QDialog::accept);
    //ScreenFactor* factor = new ScreenFactor;
    //dialog.resize(factor->getScreenFactor() * dialog.width(), factor->getScreenFactor() * dialog.height());
    dialog.exec();
    qDebug() << "9";
}

void MainWindow::completeSpecification(const QModelIndex &index)
{
    qDebug() << "10";
    qDebug() << "completeRequirement";
    QStandardItem *item = specificationModel->itemFromIndex(index);  // 获取 QModelIndex 对应的项
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

void MainWindow::clearToDoListModel()
{
    qDebug() << "clearToDoListModel";
    todoListModel->removeRows(0, todoListModel->rowCount());
    todoListModel->removeColumns(0, todoListModel->columnCount());
    todoListModel->setColumnCount(1);
    todoListModel->setHeaderData(0, Qt::Horizontal, "  To-do List");

    fileToDoRequireNotes.clear();
}

void MainWindow::updateToDoListModel()
{
    qDebug() << "78";
    //ui->specificationView->expandAll();   //自动展开所有项
    todoListModel->removeRows(0, todoListModel->rowCount());
    todoListModel->removeColumns(0, todoListModel->columnCount());
    todoListModel->setColumnCount(1);
    todoListModel->setHeaderData(0, Qt::Horizontal, "  To-do List");

    if(fileToDoRequireNotes.empty()){
        qDebug() << "78";
        return;
    }

    QString resFilePath = appDir.absolutePath() + "/images/toolbar_images";
    QStandardItem *parentItem = todoListModel->invisibleRootItem();
    for(auto it = fileToDoRequireNotes.begin(); it != fileToDoRequireNotes.end(); ++it){
        const QVector<RequireNote*> & notes = it.value();
        for(int i = 0; i < notes.size(); ++i){
            QStandardItem* item = new QStandardItem;
            item->setData(notes[i]->note, Qt::DisplayRole);
            item->setData(QIcon(resFilePath + "/todo.svg"), Qt::DecorationRole);
            item->setData(notes[i]->filePath + ":line" + QString::number(notes[i]->startLine), Qt::ToolTipRole);
            parentItem->appendRow(item);
        }
    }

    //ui->toDoTableView->expandAll();


    qDebug() << "78";
}

void MainWindow::completeToDoNote(const QModelIndex &index)
{
    qDebug() << "10";
    qDebug() << "completeToDoNote";
    QStandardItem *item = todoListModel->itemFromIndex(index);  // 获取 QModelIndex 对应的项
    if (item) {
        //获取文件位置以及行号
        QString pos = item->data(Qt::ToolTipRole).toString();
        QString filePath = pos.left(pos.indexOf(":line"));
        int lineNumber = pos.mid((pos.indexOf(":line")) + QString(":line").length()).toInt();
        if(openFile(filePath)){
            if(activeMdiChild()) activeMdiChild()->completeToDoNote(lineNumber);
        }
    } else{
        // 无效的 QModelIndex，对应的项不存在
    }
    qDebug() << "10";
}

void MainWindow::doubleClickedToDoTableView(const QModelIndex &index)
{
    qDebug() << "9";
    // 处理双击事件，打开对应文件
    //QStandardItem* item = model.itemFromIndex(index);
    QString pos = todoListModel->data(index, Qt::ToolTipRole).toString();
    QString filePath = pos.left(pos.indexOf(":line"));
    int lineNumber = pos.mid((pos.indexOf(":line")) + QString(":line").length()).toInt();

    if(openFile(filePath)){
        if(activeMdiChild()){
           activeMdiChild()->goToLine(lineNumber);
           qDebug() << "expand1";
        }

        qDebug()  << "expand2";
    }
    qDebug() << "9";
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
    child->newFile("");
    child->show();
    qDebug() << "14";
}

MdiChild* MainWindow::newReviewCodeFile(QString fileName)
{
    qDebug() << "14";
    MdiChild *child = createMdiChild();
    child->newFile(fileName);
    child->show();
    return child;
    qDebug() << "14";
}

void MainWindow::open()
{
    qDebug() << "15";
    const QString fileName = QFileDialog::getOpenFileName(this);    //打开文件对话框
    if (!fileName.isEmpty()){
        openFile(fileName);
        loadProject(fileName, "");
    }
    qDebug() << "15";

}

bool MainWindow::openFile(const QString &fileName)
{
    qDebug() << "16";
    if (QMdiSubWindow *existing = findMdiChild(fileName)) {  //
        //ui->mdiArea->setActiveSubWindow(existing);
        ui->mdiArea->removeSubWindow(existing);
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
        child->showMaximized();
        //loadProject(fileName);
    }else
        child->close();
    MainWindow::prependToRecentFiles(fileName);
    qDebug() << "17";
    return succeeded;
}

bool MainWindow::loadProject(const QString &fileName, const QString &specDir)
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

        projectTree* prePro = currentPro;
        if(prePro) closeProject(currentPro);
        else qDebug() << "currentPro is null.";

        initProjectInfo();
        updateToDoListModel();
        if(!specDir.isEmpty()){
            readContentFromInformalSpecification(specDir);
        }else{
            updateSpecificationModel(QHash<QString, QString>());
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

        //打开main.cpp
        QString curPath = QDir::currentPath();
        qDebug() << "loadProject::currentDir: " << QDir::current();
        QDir::setCurrent(proPath + "/" + "src");    //更换到src文件夹下
        qDebug() << "loadProject::currentDir: " << QDir::current();
        QFile mainCpp("main.cpp");
        if(!mainCpp.open(QIODevice::ReadWrite | QIODevice::Text)){
            qDebug() << mainCpp.errorString();
            return false;
        }
        mainCpp.close();
        bool flag = openFile("main.cpp");
        if(!flag){
            errordlg->setWindowTitle(tr("Error Message"));
            errordlg->showMessage(tr("Failed to open main.cpp"));
            return false;
        }
        QDir::setCurrent(curPath);    //更换回项目文件夹下
        qDebug() << "loadProject::currentDir: " << QDir::current();

        if(projectName == "") return false;    //如果没找到项目名

        projectTree* pro = new projectTree(projectName, proPath, specDir);
        pro->headerFiles = headerFiles;
        pro->sourceFiles = sourceFiles;
        initProjectModel(pro);

        currentPro = pro;
        if(!readProjectInfoFromCmakeFile(currentPro, includedClass)){
            qDebug() << "Error in reading Project Info From CmakeFile.";
        }


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

    child->setMainWindowPtr(this);

    child->setFont(font);

    //将代码编辑区的字体应用到其他代码浏览区
    QTextCursor sourceCursor = child->textCursor();
    QTextBlockFormat sourceFormat = sourceCursor.blockFormat();
    qreal lineHeight = sourceFormat.lineHeight();
    QTextBlockFormat::LineHeightTypes lineHeightType = static_cast<QTextBlockFormat::LineHeightTypes>(sourceFormat.lineHeightType());

    ui->codeBrowser->setFont(font);
    QTextCursor cursor1 = ui->codeBrowser->textCursor();
    QTextBlockFormat format1 = cursor1.blockFormat();
    format1.setLineHeight(lineHeight, lineHeightType);
    cursor1.setBlockFormat(format1);

    ui->fixedCodeTextEdit->setFont(font);
    QTextCursor cursor2 = ui->fixedCodeTextEdit->textCursor();
    QTextBlockFormat format2 = cursor2.blockFormat();
    format2.setLineHeight(lineHeight, lineHeightType);
    cursor2.setBlockFormat(format2);

    //FaultLineHighlighter *faultHighlighter = new FaultLineHighlighter(child->document());
//    Highlighter *highlighter = new Highlighter(child->document());
//    connect(highlighter, &Highlighter::findFault, child, &MdiChild::faultLinePaint);
//    connect(highlighter, &Highlighter::faultInfo, child, &MdiChild::setFixText);
    //connect(child, &MdiChild::hideProblemTab, highlighter, &Highlighter::changeFaultRule);


    ui->mdiArea->addSubWindow(child);   //向多文档区域添加子窗口，child为中心部件

#ifndef QT_NO_CLIPBOARD
    connect(child, &QTextEdit::copyAvailable, ui->cutAct, &QAction::setEnabled);
    connect(child, &QTextEdit::copyAvailable, ui->copyAct, &QAction::setEnabled);
#endif
    connect(child, &MdiChild::showSCMFault, this, &MainWindow::showSCMFaultTab);
    connect(child, &MdiChild::showSCMFault, ui->tabProgramOutput, &QWidget::show);//当收到展示问题面板信号时，展示问题面板
    connect(child, &MdiChild::hideProblemTab, ui->tabProgramOutput, &QWidget::hide);

    connect(child, &MdiChild::showSourceFileIssue, this, &MainWindow::showClassUndefinedSyntaxIssue);
    connect(child, &MdiChild::showSourceFileIssue, ui->tabProgramOutput, &QWidget::show);//当收到展示问题面板信号时，展示问题面板

    connect(child, &MdiChild::showHeaderFileIssue, this, &MainWindow::showClassUnspecifiedTypeIssue);

    //根据源文件类信息，更新类文件
    connect(child, &MdiChild::updateClassFiles, this, &MainWindow::updateProjectClassInfo);

    //根据文件信息，更新todo notes
    connect(child, &MdiChild::updateToDoRequireNote, this, &MainWindow::updateFileToDoRequireNotes);

    //根据文件信息，更新自然语言规格位置
    connect(child, &MdiChild::updateInformalSpecPos, this, &MainWindow::updateInformalSpecs);

    //调出ChatGPT对话
    connect(child, &MdiChild::startChatGPTDialog, this, &MainWindow::startChatGPTDialog);

    //利用ChatGPT修正当前函数
    connect(child, &MdiChild::startChatGPTFixCode, this, &MainWindow::fixCodeByChatGPT);

    connect(child, &MdiChild::updateMethodNameToCode, this, &MainWindow::setCscrToolMethodNameToCode);

    qDebug() << "30";
    return child;
}

void MainWindow::showSCMFaultTab(int faultLineNumber){
    qDebug() << "31";
    if(faultLineNumber == -1) return;
    QString line = "line " + QString::number(faultLineNumber + 1);
    QTableWidgetItem *item = new QTableWidgetItem(line);
    ui->tableWidgetReport->setItem(0, 1, item);
    //ui->verticalLayout->setStretch(0, 0);
    //ui->verticalLayout->setStretch(1, 1);
    ui->tabProgramOutput->setCurrentIndex(1);
    ui->tabProgramOutput->show();
    qDebug() << "31";
//    ui->mdiArea->setFocus();
}

void MainWindow::showClassUndefinedSyntaxIssue(const QList<ClassUndefinedSyntaxIssue>& list)
{
    qDebug() << "showClassUndefinedSyntaxIssue: UndefinedIssueList.size = "
             << proIssueManager->getUndefinedIssueList().size();
    proIssueManager->clearUndefinedIssueList();
    qDebug() << "showClassUndefinedSyntaxIssue: UndefinedIssueList.size = "
             << proIssueManager->getUndefinedIssueList().size();
    proIssueManager->appendUndefinedIssue(list);
    qDebug() << "showClassUndefinedSyntaxIssue: UndefinedIssueList.size = "
             << proIssueManager->getUndefinedIssueList().size();
    showClassEncapsulateIssueTab();
}


void MainWindow::showClassEncapsulateIssueTab()
{
    const auto& undefinedIssueList = proIssueManager->getUndefinedIssueList();

    const auto& unspecifiedIssueList = proIssueManager->getUnspecifiedIssueList();

    qDebug() << "list1.size = " << undefinedIssueList.size();
    qDebug() << "list2.size = " << unspecifiedIssueList.size();

    if(undefinedIssueList.isEmpty() && unspecifiedIssueList.isEmpty()){
        qDebug() << "list is empty!";
        return;
    }

    ui->tableIssueWidget->clear();

    // Set number of rows and columns
    int headerSize = 4;
    ui->tableIssueWidget->setColumnCount(headerSize);
    ui->tableIssueWidget->setRowCount(undefinedIssueList.size() + unspecifiedIssueList.size());

    int i = 0;
    for(i = 0; i < undefinedIssueList.size(); i++){
        int currentRow = i;
        qDebug() << "QTableWidget: row : " << ui->tableIssueWidget->rowCount()
                 << " col: " << ui->tableIssueWidget->columnCount();
        auto issue = *undefinedIssueList[i];
        qDebug() << "showClassEncapsulateIssueTab";
        qDebug() << "curIssue: " << issue.getName() << " " << issue.getDescription() << " " << issue.getFilePath();
        QIcon icon(QPixmap::fromImage(issue.getImage()));
        QTableWidgetItem* item1 = new QTableWidgetItem(icon, issue.getName());
        ui->tableIssueWidget->setItem(currentRow, 0, item1);
        QTableWidgetItem* item2 = new QTableWidgetItem(issue.getDescription());
        ui->tableIssueWidget->setItem(currentRow, 1, item2);
        QString fileName = issue.getFilePath();
        QString filePath = fileName;
        fileName = fileName.mid(fileName.lastIndexOf('/') + 1);
        QTableWidgetItem* item3 = new QTableWidgetItem(fileName);
        item3->setData(Qt::ToolTipRole, filePath);
        ui->tableIssueWidget->setItem(currentRow, 2, item3);
        qDebug() << "lineNumber: " << issue.getIssueLineNumber() + 1;
        QTableWidgetItem* item4 = new QTableWidgetItem(QString("%1::%2").arg(issue.getIssueLineNumber() + 1)
                                                                             .arg(issue.getPosition()));
        //QTableWidgetItem* item4 = new QTableWidgetItem("test");
        ui->tableIssueWidget->setItem(currentRow, 3, item4);
    }

    for(int j = 0; j < unspecifiedIssueList.size(); j++){
        int currentRow = j + i;
        qDebug() << "QTableWidget: row : " << ui->tableIssueWidget->rowCount()
                 << " col: " << ui->tableIssueWidget->columnCount();
        auto issue = *unspecifiedIssueList[j];
        qDebug() << "showClassEncapsulateIssueTab";
        qDebug() << "curIssue: " << issue.getName() << " " << issue.getDescription() << " " << issue.getFilePath();
        QIcon icon(QPixmap::fromImage(issue.getImage()));
        QTableWidgetItem* item1 = new QTableWidgetItem(icon, issue.getName());
        ui->tableIssueWidget->setItem(currentRow, 0, item1);
        QTableWidgetItem* item2 = new QTableWidgetItem(issue.getDescription());
        ui->tableIssueWidget->setItem(currentRow, 1, item2);
        QString fileName = issue.getFilePath();
        QString filePath = fileName;
        fileName = fileName.mid(fileName.lastIndexOf('/') + 1);
        QTableWidgetItem* item3 = new QTableWidgetItem(fileName);
        item3->setData(Qt::ToolTipRole, filePath);
        ui->tableIssueWidget->setItem(currentRow, 2, item3);
        qDebug() << "lineNumber: " << issue.getIssueLineNumber() + 1;
        QTableWidgetItem* item4 = new QTableWidgetItem(QString("%1::%2").arg(issue.getIssueLineNumber() + 1)
                                                                             .arg(issue.getPosition()));
        //QTableWidgetItem* item4 = new QTableWidgetItem("test");
        ui->tableIssueWidget->setItem(currentRow, 3, item4);
    }

    // Set stretch factors for columns and rows
    for (int col = 0; col < ui->tableIssueWidget->columnCount(); ++col) {
        if(col == 1){
            ui->tableIssueWidget->horizontalHeader()->setSectionResizeMode(col, QHeaderView::Stretch);
        }else{
            ui->tableIssueWidget->horizontalHeader()->setSectionResizeMode(col, QHeaderView::ResizeToContents);
        }

    }
//    for (int row = 0; row < ui->tableIssueWidget->rowCount(); ++row) {
//        ui->tableIssueWidget->verticalHeader()->setSectionResizeMode(row, QHeaderView::Stretch);
//    }

    // Resize cells to fit content
    ui->tableIssueWidget->resizeColumnsToContents();
    ui->tableIssueWidget->resizeRowsToContents();
    if (!ui->tabProgramOutput) {
        qDebug() << "tabProgramOutput is nullptr";
        return;
    }
    qDebug() << "tabProgramOutputDebug";
    //ui->verticalLayout->setStretch(0, 0);
    //ui->verticalLayout->setStretch(1, 1);
    ui->tabProgramOutput->setCurrentIndex(0);
    ui->tabProgramOutput->show();
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

void MainWindow::init()
{
    timer = new QTimer;
    currentPro = new projectTree;

    projectModel = new QStandardItemModel;

    todoListModel = new QStandardItemModel;

    specificationModel = new QStandardItemModel;

    //当前文件的类信息汇总
    proClassInfoHash = QHash<QString, ClassInfo>();   //key = 类名，value = 类信息

    //include文件中包含的类
    includedClass = QStringList();

    errordlg = new QErrorMessage;

    appDir = QDir();

    //当前项目使用的目标语言
    targetLanginCurrentPro = QString();

    bugSet = new CscrToolBugSet;
}

void MainWindow::setCscrToolMethodNameToCode(const QHash<QString, QString> &value)
{
    cscrToolMethodNameToCode = value;
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
    ui->stackedWidgetRightDown->hide();
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
    if(mdiChild == nullptr) return;
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
    tc.setPosition(position, QTextCursor::MoveAnchor);
    mdiChild->setTextCursor(tc);
    mdiChild->highlightCurrentLine();

    qDebug() << "39";
    //tudo;
}

void MainWindow::setCursorToIssueLine(QTableWidgetItem *item)
{
    qDebug() << "setCursorToIssueLine" ;
    MdiChild *mdiChild = activeMdiChild();
    if(mdiChild == nullptr) return;
    // Get the row of the double-clicked item
    int row = item->row();

    // Retrieve all items in the current row

    QTableWidgetItem *filePathItem = ui->tableIssueWidget->item(row, 2);
    QString filePath = filePathItem->data(Qt::ToolTipRole).toString();

    if(filePath != mdiChild->currentFile()){
        if(!openFile(filePath)){
            qDebug() << "Failed to open the file: " << filePath;
        }else{
            setCursorToIssueLine(item);
        }
    }else{
        QTableWidgetItem *lineNumberWithPostionItem = ui->tableIssueWidget->item(row, 3);
        QString text = lineNumberWithPostionItem->text();
        int lineNumber = text.left(text.indexOf("::")).toInt() - 1;
        if(lineNumber >= 0){
            qDebug() << "Issue lineNumber: " << lineNumber;
            QTextCursor tc = mdiChild->textCursor();
            int position = mdiChild->document()->findBlockByNumber (lineNumber).position();
            tc.setPosition(position, QTextCursor::MoveAnchor);
            qDebug() << "cursor position: " << tc.position();
            mdiChild->setTextCursor(tc);
            mdiChild->highlightCurrentLine();
        }else{
            qDebug() << "Invalid lineNumber!";
        }
    }

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

void MainWindow::setTargetLangToCplus()
{
    targetLanginCurrentPro = "C++";
    ui->actionCplus->setChecked(true);
    ui->actionJava->setChecked(false);
    ui->actionCsharp->setChecked(false);
}

void MainWindow::setTargetLangToJava()
{
    targetLanginCurrentPro = "Java";
    ui->actionCplus->setChecked(false);
    ui->actionJava->setChecked(true);
    ui->actionCsharp->setChecked(false);
}

void MainWindow::setTargetLangToCsharp()
{
    targetLanginCurrentPro = "C#";
    ui->actionCplus->setChecked(false);
    ui->actionJava->setChecked(false);
    ui->actionCsharp->setChecked(true);
}

void MainWindow::projectViewMenuRequest(const QPoint& pos)
{
    QModelIndex index = ui->projectTreeView->indexAt(pos);
    if (index.isValid() && !index.parent().isValid()) {
        QMenu contextMenu;
        QAction *closeProAct = contextMenu.addAction("Close the project");
        QString proName = index.data(Qt::DisplayRole).toString();
        QString proPath = index.data(Qt::ToolTipRole).toString();
        connect(closeProAct, &QAction::triggered, this, [=]() {
//            if(!projects.contains(proName)){
//                qDebug() << "Failed to find the close project.";
//                return;
//            }
//            projectTree* pro = projects.value(proName);
            if(currentPro->projectPath == proPath){
                closeProject(currentPro);
            }else{
                qDebug() << "The close project path is not the same.";
                return;
            }
        });

        contextMenu.exec(ui->projectTreeView->viewport()->mapToGlobal(pos));
    }
}

void MainWindow::closeProject(projectTree* pro)
{
    qDebug() << "close project: " << pro->projectName;
    QString proPath = pro->projectPath;
    QString proName = pro->projectName;

    qDebug() << "proName: " << proName;
    qDebug() << "proPath: " << proPath;
    QModelIndex index = findModelItem(proPath, projectModel->index(0, 0), projectModel, Qt::ToolTipRole);
    qDebug() << index;
    if(index.isValid() && index.data(Qt::DisplayRole).toString() == proName){
        removeNodeAndChildrenInModel(projectModel, index);
        clearToDoListModel();
        clearSpecificationModel();
        //removeNodeAndChildrenInModel(todoListModel, index);
        //removeNodeAndChildrenInModel(specificationModel, index);
        writeProjectInfoIntoCmakeFile(pro, includedClass);
    }else{
        qDebug() << "Failed to find the close project.";
    }
}

void MainWindow::importSpecificationForCurrentPro()
{
    QString specFilePath = QFileDialog::getOpenFileName(this, tr("Import new specification for current project"));
    if(!specFilePath.isEmpty()){
        currentPro->specificationPath = specFilePath;
        readContentFromInformalSpecification(specFilePath);
    }
}

void MainWindow::buildFilesFromSpecification()
{

    //根据项目spec，生成对话框
    //对话框的内容：一个树包含类及其函数
    //操作：降级为独立函数，降级为某个类的函数，升级为类，修改项的名称
    //操作2：新建类项，
    //已创建的类的项名不能修改，修改名称的项需要特别显示
    QStringList existingClasses = proClassInfoHash.keys();
    BuildProFromSpecDialog* dialog = new BuildProFromSpecDialog(currentPro->proInformalSpec, existingClasses, this);
    ScreenFactor factor;
    dialog->resize(dialog->width() * factor.getScreenFactor(), dialog->height() * factor.getScreenFactor());
    dialog->show();
    connect(dialog, &BuildProFromSpecDialog::treeStructureReady, this, [this](const QList<ClassInfo>& structure){
        //创建文件
        //构建文件内容
        qDebug() << "print the tree structure: ";
        for (ClassInfo info : structure){
            qDebug() << "ClassName: " << info.name;
            qDebug() << "Methods:";
            for(int i = 0; i < info.methods->size(); ++i){
                qDebug() << (*info.methods)[i].name;
            }
        }
        insertProjectClassInfo(structure);

    });

}

void MainWindow::testSlot()
{
    ChatgptClient* client = new ChatgptClient(this);
    client->sendUserMessage("go language");
    qDebug() << "Chatgpt is showing.";
    //client->show();
    connect(client, &ChatgptClient::replyIsReady, [](const QString &reply){
        qDebug() << "ChatGPT Reply Received:" << reply;
    });
    //qDebug() << client->getChatgptReply();
}

//展示Software Construction Monitoring
void MainWindow::showDemoSCM()
{
    qDebug() << appDir;
    QString demoPath = appDir.path();
    demoPath += "/demo/demo.cpp";

    if(openFile(demoPath)){
        qDebug() << "Success to open demo file.";
    }

    MdiChild* child = activeMdiChild();
    if(!child){
        qDebug() << "No activeMdiChild has been found.";
        return;
    }
    QTextCharFormat format;
    format.setUnderlineColor(Qt::red);
    format.setUnderlineStyle(QTextCharFormat::WaveUnderline);

    QRegExp divisionByZero = QRegExp("([a-zA-Z_][a-zA-Z0-9_]*)\\s*/\\s*([a-zA-Z_][a-zA-Z0-9_]*)");
    QString faultName = "DivisionByZero";

    child->matchFaultPattern(divisionByZero, format, faultName);
    ui->tabProgramOutput->setCurrentIndex(1);
    ui->stackedWidgetRightDown->setCurrentIndex(0);
    ui->stackedWidgetRightDown->show();
    ui->tabProgramOutput->show();

}

ClassInfo MainWindow::getProClassInfo(QString className)
{

    if(proClassInfoHash.contains(className)){
        qDebug() << "MainWindow::getProClassInfo";
        return proClassInfoHash[className];
    }else{
        qDebug() << className << " dose not exist in the Hash.";
        ClassInfo info;
        return info;
    }
}

void MainWindow::setProClassInfo(QString className, const ClassInfo& info)
{
    qDebug() << "MainWindow::setProClassInfo";
    if(proClassInfoHash.contains(className)){
        proClassInfoHash[className] = info;
        synchronizeClassInfoFromProToFile(className);
    }

}

void MainWindow::synchronizeClassInfoFromProToFile(QString className)
{
    qDebug() << "MainWindow::synchronizeClassInfoFromProToFile";
    if(!proClassInfoHash.contains(className)){
        qDebug() << "proClassInfoHash does not contains " << className;
        return;
    }
    const ClassInfo& info = proClassInfoHash.value(className);

    for(auto it = fileClassInfoHash.begin(); it != fileClassInfoHash.end(); it++){
        QHash<QString, ClassInfo>& hash = it.value();
        qDebug() << it.key();
        if(hash.contains(className)){
            ClassInfo& oldInfo = hash[className];
            qDebug() << "oldinfo.vars.size = " << oldInfo.vars->size();
            qDebug() << "oldinfo.methods.size = " << oldInfo.methods->size();
            qDebug() << "info.vars.size = " << info.vars->size();
            qDebug() << "info.methods.size = " << info.methods->size();

            for(int i = 0; i < oldInfo.vars->size(); ++i){
                for(int j = 0; j < info.vars->size(); ++j){
                    qDebug() << "oldInfo.var:" << oldInfo.vars->at(i).name;
                    qDebug() << "info.var:" << info.vars->at(j).name;
                    if(info.vars->at(j) >= oldInfo.vars->at(i)){
                        (*oldInfo.vars)[i] = info.vars->at(j);
                        break;
                    }
                }
            }

            for(int i = 0; i < oldInfo.methods->size(); ++i){
                for(int j = 0; j < info.methods->size(); ++j){
                    qDebug() << "oldInfo.method:" << oldInfo.methods->at(i).name;
                    qDebug() << "info.method:" << info.methods->at(j).name;
                    if(info.methods->at(j) >= oldInfo.methods->at(i)){
                        (*oldInfo.methods)[i] = info.methods->at(j);
                        break;
                    }
                }
            }
        }
    }
    qDebug() << "MainWindow::synchronizeClassInfoFromProToFile";
}

void MainWindow::startChatGPTDialog(QString text)
{
    ui->copyCodeButton->setVisible(false);
    ui->codeBrowser->setVisible(false);
    ui->hmppIconButton->setVisible(false);
    ui->label3->setVisible(false);
    showHMPPView();
    ui->label2->setText(text);
    // Set up the timer to show widgets consecutively
    QTimer* timer = new QTimer(this);

    // Connect the timer timeout signal to show the next widget
    QObject::connect(timer, &QTimer::timeout, this, [this, timer]() {
        ui->hmppIconButton->setVisible(true);
        ui->label3->setVisible(true);
        ui->copyCodeButton->setVisible(true);
        ui->codeBrowser->setVisible(true);
        timer->stop();

    });

    // Start the timer to trigger every second
    timer->start(2000);  // Update every 1000 milliseconds

}

void MainWindow::fixCodeByChatGPT(QString text)
{
    ui->waitingChatGPTReplyButton->show();
    ui->stackedWidgetLeft->setCurrentIndex(1);
    // Create a timer for timeout handling
    QTimer* timeoutTimer = new QTimer(this);
    timeoutTimer->setSingleShot(true); // Ensure the timer only fires once

    int timeoutDuration = 60000; // (in milliseconds)

    // Connect timeout signal to handle timeout
    connect(timeoutTimer, &QTimer::timeout, [timeoutTimer, this]() {
        timeoutTimer->stop(); // Stop the timer
        ui->waitingChatGPTReplyButton->setText("Timeout! No response.");
        qDebug() << "Error: The request timed out.";
        QMessageBox::warning(nullptr, "Timeout", "The request to ChatGPT timed out. Please try again.");
    });


    ChatgptClient* client = new ChatgptClient(this);
    //TODO：
    QString request = "Help me fix the following C++ code, the answer should be separated into three parts: Problem: Code: Conclusion: ";
    // text = "double divide(double numerator, double denominator) {return numerator / denominator;}";
    request = request + text;
    client->sendUserMessage(request);
    // Start the timeout timer
    timeoutTimer->start(timeoutDuration);
    qDebug() << "Chatgpt is showing.";

    // Waiting effect
    ui->waitingChatGPTReplyButton->setEnabled(false); // Disable interaction
//    QTimer* waitingEffectTimer = new QTimer(this);
//    int dotCount = 0;

//    // Connect the waiting effect timer
//    connect(waitingEffectTimer, &QTimer::timeout, [&dotCount, this]() {
//        QString text = "Waiting";
//        for (int i = 0; i < dotCount; ++i) {
//            text += ".";
//        }
//        dotCount = (dotCount + 1) % 4;
//        ui->waitingChatGPTReplyButton->setText(text);
//    });

//    // Start waiting effect
//    waitingEffectTimer->start(500);

    connect(client, &ChatgptClient::replyIsReady, [timeoutTimer, this](const QString &reply){
        timeoutTimer->stop(); // Stop the timeout timer
        //waitingEffectTimer->stop(); // Stop the waiting effect
        ui->waitingChatGPTReplyButton->setText("Done"); // Indicate completion
        ui->waitingChatGPTReplyButton->hide();
        fixedCodeHighlighter = new Highlighter(ui->fixedCodeTextEdit->document());
        ui->fixedCodeTextEdit->show();
        ui->copyFixedCodeButton->show();
        qDebug() << "ChatGPT Reply Received:" << reply;
        QString codePart, problemPart, conclusionPart;
        separateText(reply, problemPart, codePart, conclusionPart);
        QString startMarker = "```cpp";
        QString endMarker = "```";

        // Find the positions of the start and end markers
        int startPos = codePart.indexOf(startMarker);
        int endPos = codePart.indexOf(endMarker, startPos + startMarker.length());

        if (startPos != -1 && endPos != -1) {
            // Extract the part between the markers
            codePart = codePart.mid(startPos + startMarker.length(), endPos - (startPos + startMarker.length()));
        } else {
            qDebug() << "Markers not found";
        }

        problemPart.remove(QRegExp("^[#*]+|[#*]+$")); // Remove '#' or spaces from both ends
        conclusionPart.remove(QRegExp("^[#*]+|[#*]+$"));
        ui->fixedCodeTextEdit->setText(codePart);
        ui->fixedCodeProblemBrowser->setText(problemPart);
        //ui->fixedCodeConclusionBrowser->setText(conclusionPart);
    });
}

// Function to separate the text into three parts: Problem, Code, Conclusion
void MainWindow::separateText(const QString &fullText, QString &problemPart, QString &codePart, QString &conclusionPart) {
    // Define regular expressions to capture each section
    QRegularExpression problemRegex("(?<=Problem:)(.*?)(?=Code:)", QRegularExpression::DotMatchesEverythingOption);
    QRegularExpression codeRegex("(?<=Code:)(.*?)(?=Conclusion:)", QRegularExpression::DotMatchesEverythingOption);
    QRegularExpression conclusionRegex("(?<=Conclusion:)(.*)", QRegularExpression::DotMatchesEverythingOption);

    // Match the problem, code, and conclusion parts
    QRegularExpressionMatch problemMatch = problemRegex.match(fullText);
    QRegularExpressionMatch codeMatch = codeRegex.match(fullText);
    QRegularExpressionMatch conclusionMatch = conclusionRegex.match(fullText);

    if (problemMatch.hasMatch()) {
        problemPart = problemMatch.captured(1).trimmed();
    }
    if (codeMatch.hasMatch()) {
        codePart = codeMatch.captured(1).trimmed();
    }
    if (conclusionMatch.hasMatch()) {
        conclusionPart = conclusionMatch.captured(1).trimmed();
    }
}

void MainWindow::on_copyCodeButton_clicked()
{
    // Get the content of QTextBrowser
    QString content = ui->codeBrowser->toPlainText();

    // Get the system clipboard
    QClipboard *clipboard = QApplication::clipboard();

    // Copy the content to clipboard
    clipboard->setText(content);
}

void MainWindow::on_copyFixedCodeButton_clicked()
{
    // Get the content of QTextBrowser
    QString content = ui->fixedCodeTextEdit->toPlainText();

    // Get the system clipboard
    QClipboard *clipboard = QApplication::clipboard();

    // Copy the content to clipboard
    clipboard->setText(content);
}



QString MainWindow::findClassMemberType(QString className, QString expression){
    if(proClassInfoHash.contains(className)){
        for(int i = 0; i < proClassInfoHash[className].methods->size(); i++){
            if(expression == proClassInfoHash[className].methods->at(i).name){
                return proClassInfoHash[className].methods->at(i).returnType;
            }
        }
        for(int i = 0; i < proClassInfoHash[className].vars->size(); i++){
            if(expression == proClassInfoHash[className].vars->at(i).name){
                return proClassInfoHash[className].vars->at(i).type;
            }
        }
    }
    return UNSPECIFIED;
}
