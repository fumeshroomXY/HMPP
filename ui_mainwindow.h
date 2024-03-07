/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *newAct;
    QAction *openAct;
    QAction *saveAct;
    QAction *saveAsAct;
    QAction *exitAct;
    QAction *undoAct;
    QAction *redoAct;
    QAction *cutAct;
    QAction *copyAct;
    QAction *pasteAct;
    QAction *closeAct;
    QAction *closeAllAct;
    QAction *tileAct;
    QAction *cascadeAct;
    QAction *nextAct;
    QAction *previousAct;
    QAction *aboutAct;
    QAction *aboutDeveloperAct;
    QAction *projectShowAct;
    QAction *runDebugAct;
    QAction *codeAnalysisAct;
    QAction *hmppAct;
    QAction *manageSetAct;
    QAction *allRuleDescriptAct;
    QAction *newProjectAct;
    QAction *testCreateClassAct;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QStackedWidget *stackedWidget;
    QWidget *pageProject;
    QVBoxLayout *verticalLayout_2;
    QTreeView *projectTreeView;
    QTreeWidget *treeClassView;
    QProgressBar *progressBar;
    QWidget *pageRunDebug;
    QWidget *pageCodeAnalysis;
    QWidget *pageHMPP;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_2;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton_3;
    QSpacerItem *verticalSpacer;
    QLabel *label1;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label2;
    QVBoxLayout *verticalLayout_4;
    QPushButton *pushButton_4;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_5;
    QPushButton *pushButton_5;
    QSpacerItem *verticalSpacer_3;
    QLabel *label3;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label4;
    QVBoxLayout *verticalLayout_7;
    QPushButton *pushButton_6;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_6;
    QPushButton *pushButton_7;
    QSpacerItem *verticalSpacer_4;
    QLabel *label5;
    QPushButton *pushButton;
    QTextBrowser *textBrowser;
    QVBoxLayout *verticalLayout;
    QMdiArea *mdiArea;
    QTabWidget *tabProgramOutput;
    QWidget *tabDebug;
    QGridLayout *gridLayout_3;
    QListWidget *listWidget;
    QWidget *tabFaultReport;
    QGridLayout *gridLayout;
    QTableWidget *tableWidgetReport;
    QWidget *tabAppOutput;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuWindow;
    QMenu *menuHelp;
    QMenu *menuConfiguration;
    QMenu *menuTools_T;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(964, 630);
        newAct = new QAction(MainWindow);
        newAct->setObjectName(QStringLiteral("newAct"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/toolbar_images/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        newAct->setIcon(icon);
        openAct = new QAction(MainWindow);
        openAct->setObjectName(QStringLiteral("openAct"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/toolbar_images/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        openAct->setIcon(icon1);
        saveAct = new QAction(MainWindow);
        saveAct->setObjectName(QStringLiteral("saveAct"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/toolbar_images/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveAct->setIcon(icon2);
        saveAsAct = new QAction(MainWindow);
        saveAsAct->setObjectName(QStringLiteral("saveAsAct"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/toolbar_images/saveAs.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveAsAct->setIcon(icon3);
        exitAct = new QAction(MainWindow);
        exitAct->setObjectName(QStringLiteral("exitAct"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/toolbar_images/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        exitAct->setIcon(icon4);
        undoAct = new QAction(MainWindow);
        undoAct->setObjectName(QStringLiteral("undoAct"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/images/toolbar_images/undo.png"), QSize(), QIcon::Normal, QIcon::Off);
        undoAct->setIcon(icon5);
        redoAct = new QAction(MainWindow);
        redoAct->setObjectName(QStringLiteral("redoAct"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/images/toolbar_images/redo.png"), QSize(), QIcon::Normal, QIcon::Off);
        redoAct->setIcon(icon6);
        cutAct = new QAction(MainWindow);
        cutAct->setObjectName(QStringLiteral("cutAct"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/images/toolbar_images/cut.png"), QSize(), QIcon::Normal, QIcon::Off);
        cutAct->setIcon(icon7);
        copyAct = new QAction(MainWindow);
        copyAct->setObjectName(QStringLiteral("copyAct"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/images/toolbar_images/copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        copyAct->setIcon(icon8);
        pasteAct = new QAction(MainWindow);
        pasteAct->setObjectName(QStringLiteral("pasteAct"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/images/toolbar_images/paste.png"), QSize(), QIcon::Normal, QIcon::Off);
        pasteAct->setIcon(icon9);
        closeAct = new QAction(MainWindow);
        closeAct->setObjectName(QStringLiteral("closeAct"));
        closeAllAct = new QAction(MainWindow);
        closeAllAct->setObjectName(QStringLiteral("closeAllAct"));
        tileAct = new QAction(MainWindow);
        tileAct->setObjectName(QStringLiteral("tileAct"));
        cascadeAct = new QAction(MainWindow);
        cascadeAct->setObjectName(QStringLiteral("cascadeAct"));
        nextAct = new QAction(MainWindow);
        nextAct->setObjectName(QStringLiteral("nextAct"));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/images/toolbar_images/next.png"), QSize(), QIcon::Normal, QIcon::Off);
        nextAct->setIcon(icon10);
        previousAct = new QAction(MainWindow);
        previousAct->setObjectName(QStringLiteral("previousAct"));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/images/toolbar_images/previous.png"), QSize(), QIcon::Normal, QIcon::Off);
        previousAct->setIcon(icon11);
        aboutAct = new QAction(MainWindow);
        aboutAct->setObjectName(QStringLiteral("aboutAct"));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/images/toolbar_images/about.png"), QSize(), QIcon::Normal, QIcon::Off);
        aboutAct->setIcon(icon12);
        aboutDeveloperAct = new QAction(MainWindow);
        aboutDeveloperAct->setObjectName(QStringLiteral("aboutDeveloperAct"));
        projectShowAct = new QAction(MainWindow);
        projectShowAct->setObjectName(QStringLiteral("projectShowAct"));
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/images/toolbar_images/project.png"), QSize(), QIcon::Normal, QIcon::Off);
        projectShowAct->setIcon(icon13);
        runDebugAct = new QAction(MainWindow);
        runDebugAct->setObjectName(QStringLiteral("runDebugAct"));
        QIcon icon14;
        icon14.addFile(QStringLiteral(":/images/toolbar_images/rundebug.png"), QSize(), QIcon::Normal, QIcon::Off);
        runDebugAct->setIcon(icon14);
        codeAnalysisAct = new QAction(MainWindow);
        codeAnalysisAct->setObjectName(QStringLiteral("codeAnalysisAct"));
        QIcon icon15;
        icon15.addFile(QStringLiteral(":/images/toolbar_images/codeanalysis.png"), QSize(), QIcon::Normal, QIcon::Off);
        codeAnalysisAct->setIcon(icon15);
        hmppAct = new QAction(MainWindow);
        hmppAct->setObjectName(QStringLiteral("hmppAct"));
        QIcon icon16;
        icon16.addFile(QStringLiteral(":/images/toolbar_images/hmpp.png"), QSize(), QIcon::Normal, QIcon::Off);
        hmppAct->setIcon(icon16);
        manageSetAct = new QAction(MainWindow);
        manageSetAct->setObjectName(QStringLiteral("manageSetAct"));
        allRuleDescriptAct = new QAction(MainWindow);
        allRuleDescriptAct->setObjectName(QStringLiteral("allRuleDescriptAct"));
        newProjectAct = new QAction(MainWindow);
        newProjectAct->setObjectName(QStringLiteral("newProjectAct"));
        testCreateClassAct = new QAction(MainWindow);
        testCreateClassAct->setObjectName(QStringLiteral("testCreateClassAct"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        pageProject = new QWidget();
        pageProject->setObjectName(QStringLiteral("pageProject"));
        verticalLayout_2 = new QVBoxLayout(pageProject);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        projectTreeView = new QTreeView(pageProject);
        projectTreeView->setObjectName(QStringLiteral("projectTreeView"));

        verticalLayout_2->addWidget(projectTreeView);

        treeClassView = new QTreeWidget(pageProject);
        QIcon icon17;
        icon17.addFile(QStringLiteral(":/images/toolbar_images/folder.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon18;
        icon18.addFile(QStringLiteral(":/images/toolbar_images/class.svg"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon19;
        icon19.addFile(QStringLiteral(":/images/toolbar_images/memberfunc.svg"), QSize(), QIcon::Normal, QIcon::Off);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(treeClassView);
        __qtreewidgetitem->setIcon(0, icon17);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem(__qtreewidgetitem);
        __qtreewidgetitem2->setIcon(0, icon18);
        QTreeWidgetItem *__qtreewidgetitem3 = new QTreeWidgetItem(__qtreewidgetitem2);
        __qtreewidgetitem3->setIcon(0, icon19);
        QTreeWidgetItem *__qtreewidgetitem4 = new QTreeWidgetItem(__qtreewidgetitem2);
        __qtreewidgetitem4->setIcon(0, icon19);
        QTreeWidgetItem *__qtreewidgetitem5 = new QTreeWidgetItem(__qtreewidgetitem2);
        __qtreewidgetitem5->setIcon(0, icon19);
        new QTreeWidgetItem(__qtreewidgetitem2);
        new QTreeWidgetItem(__qtreewidgetitem2);
        new QTreeWidgetItem(__qtreewidgetitem2);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        treeClassView->setObjectName(QStringLiteral("treeClassView"));

        verticalLayout_2->addWidget(treeClassView);

        progressBar = new QProgressBar(pageProject);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(0);

        verticalLayout_2->addWidget(progressBar);

        stackedWidget->addWidget(pageProject);
        pageRunDebug = new QWidget();
        pageRunDebug->setObjectName(QStringLiteral("pageRunDebug"));
        stackedWidget->addWidget(pageRunDebug);
        pageCodeAnalysis = new QWidget();
        pageCodeAnalysis->setObjectName(QStringLiteral("pageCodeAnalysis"));
        stackedWidget->addWidget(pageCodeAnalysis);
        pageHMPP = new QWidget();
        pageHMPP->setObjectName(QStringLiteral("pageHMPP"));
        gridLayout_2 = new QGridLayout(pageHMPP);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton_2 = new QPushButton(pageHMPP);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        pushButton_2->setBaseSize(QSize(16, 16));
        QIcon icon20;
        icon20.addFile(QStringLiteral(":/images/toolbar_images/robot16.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon20);

        horizontalLayout_2->addWidget(pushButton_2);

        label_2 = new QLabel(pageHMPP);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);


        gridLayout_2->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        lineEdit = new QLineEdit(pageHMPP);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setInputMethodHints(Qt::ImhNone);

        gridLayout_2->addWidget(lineEdit, 2, 0, 1, 1);

        scrollArea = new QScrollArea(pageHMPP);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 172, 900));
        verticalLayout_8 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        pushButton_3 = new QPushButton(scrollAreaWidgetContents);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);
        pushButton_3->setIcon(icon20);

        verticalLayout_3->addWidget(pushButton_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        horizontalLayout_3->addLayout(verticalLayout_3);

        label1 = new QLabel(scrollAreaWidgetContents);
        label1->setObjectName(QStringLiteral("label1"));
        label1->setAutoFillBackground(false);
        label1->setStyleSheet(QLatin1String("background-color: rgb(255, 240, 66);\n"
"padding: 10px"));
        label1->setWordWrap(true);

        horizontalLayout_3->addWidget(label1);


        verticalLayout_8->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label2 = new QLabel(scrollAreaWidgetContents);
        label2->setObjectName(QStringLiteral("label2"));
        label2->setStyleSheet(QLatin1String("background-color: rgb(52, 130, 255);\n"
"padding: 10px"));
        label2->setWordWrap(true);

        horizontalLayout_4->addWidget(label2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        pushButton_4 = new QPushButton(scrollAreaWidgetContents);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        sizePolicy.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy);
        pushButton_4->setBaseSize(QSize(16, 16));
        QIcon icon21;
        icon21.addFile(QStringLiteral(":/images/toolbar_images/user.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon21);

        verticalLayout_4->addWidget(pushButton_4);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);


        horizontalLayout_4->addLayout(verticalLayout_4);


        verticalLayout_8->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        pushButton_5 = new QPushButton(scrollAreaWidgetContents);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        sizePolicy.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy);
        pushButton_5->setIcon(icon20);

        verticalLayout_5->addWidget(pushButton_5);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_3);


        horizontalLayout_5->addLayout(verticalLayout_5);

        label3 = new QLabel(scrollAreaWidgetContents);
        label3->setObjectName(QStringLiteral("label3"));
        label3->setStyleSheet(QLatin1String("background-color: rgb(255, 240, 66);\n"
"padding: 10px"));
        label3->setWordWrap(true);

        horizontalLayout_5->addWidget(label3);


        verticalLayout_8->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label4 = new QLabel(scrollAreaWidgetContents);
        label4->setObjectName(QStringLiteral("label4"));
        label4->setStyleSheet(QLatin1String("background-color: rgb(52, 130, 255);\n"
"padding: 10px"));
        label4->setWordWrap(true);

        horizontalLayout_6->addWidget(label4);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        pushButton_6 = new QPushButton(scrollAreaWidgetContents);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        sizePolicy.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy);
        pushButton_6->setBaseSize(QSize(16, 16));
        pushButton_6->setIcon(icon21);

        verticalLayout_7->addWidget(pushButton_6);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_5);


        horizontalLayout_6->addLayout(verticalLayout_7);


        verticalLayout_8->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        pushButton_7 = new QPushButton(scrollAreaWidgetContents);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        sizePolicy.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy);
        pushButton_7->setIcon(icon20);

        verticalLayout_6->addWidget(pushButton_7);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_4);


        horizontalLayout_7->addLayout(verticalLayout_6);

        label5 = new QLabel(scrollAreaWidgetContents);
        label5->setObjectName(QStringLiteral("label5"));
        label5->setStyleSheet(QLatin1String("background-color: rgb(255, 240, 66);\n"
"padding: 10px"));
        label5->setWordWrap(true);

        horizontalLayout_7->addWidget(label5);


        verticalLayout_8->addLayout(horizontalLayout_7);

        pushButton = new QPushButton(scrollAreaWidgetContents);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setIcon(icon8);

        verticalLayout_8->addWidget(pushButton);

        textBrowser = new QTextBrowser(scrollAreaWidgetContents);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setStyleSheet(QStringLiteral(""));

        verticalLayout_8->addWidget(textBrowser);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_2->addWidget(scrollArea, 1, 0, 1, 1);

        stackedWidget->addWidget(pageHMPP);

        horizontalLayout->addWidget(stackedWidget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        mdiArea = new QMdiArea(centralwidget);
        mdiArea->setObjectName(QStringLiteral("mdiArea"));
        mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        mdiArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        mdiArea->setBackground(brush);
        mdiArea->setActivationOrder(QMdiArea::ActivationHistoryOrder);
        mdiArea->setViewMode(QMdiArea::TabbedView);
        mdiArea->setDocumentMode(true);
        mdiArea->setTabsClosable(true);
        mdiArea->setTabsMovable(true);

        verticalLayout->addWidget(mdiArea);

        tabProgramOutput = new QTabWidget(centralwidget);
        tabProgramOutput->setObjectName(QStringLiteral("tabProgramOutput"));
        tabDebug = new QWidget();
        tabDebug->setObjectName(QStringLiteral("tabDebug"));
        gridLayout_3 = new QGridLayout(tabDebug);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(1, 1, 1, 1);
        listWidget = new QListWidget(tabDebug);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        gridLayout_3->addWidget(listWidget, 1, 0, 1, 1);

        tabProgramOutput->addTab(tabDebug, QString());
        tabFaultReport = new QWidget();
        tabFaultReport->setObjectName(QStringLiteral("tabFaultReport"));
        gridLayout = new QGridLayout(tabFaultReport);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(1, 1, 1, 1);
        tableWidgetReport = new QTableWidget(tabFaultReport);
        if (tableWidgetReport->columnCount() < 3)
            tableWidgetReport->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetReport->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidgetReport->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidgetReport->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        if (tableWidgetReport->rowCount() < 1)
            tableWidgetReport->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidgetReport->setVerticalHeaderItem(0, __qtablewidgetitem3);
        QIcon icon22;
        icon22.addFile(QStringLiteral(":/images/toolbar_images/error.png"), QSize(), QIcon::Normal, QIcon::Off);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem4->setIcon(icon22);
        tableWidgetReport->setItem(0, 0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setTextAlignment(Qt::AlignCenter);
        tableWidgetReport->setItem(0, 1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidgetReport->setItem(0, 2, __qtablewidgetitem6);
        tableWidgetReport->setObjectName(QStringLiteral("tableWidgetReport"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tableWidgetReport->sizePolicy().hasHeightForWidth());
        tableWidgetReport->setSizePolicy(sizePolicy1);
        tableWidgetReport->setFrameShape(QFrame::NoFrame);
        tableWidgetReport->setLineWidth(0);
        tableWidgetReport->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        tableWidgetReport->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidgetReport->setAlternatingRowColors(false);
        tableWidgetReport->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidgetReport->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidgetReport->setShowGrid(false);
        tableWidgetReport->setGridStyle(Qt::NoPen);
        tableWidgetReport->setWordWrap(true);
        tableWidgetReport->setCornerButtonEnabled(true);
        tableWidgetReport->horizontalHeader()->setVisible(false);
        tableWidgetReport->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidgetReport->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidgetReport->horizontalHeader()->setStretchLastSection(true);
        tableWidgetReport->verticalHeader()->setVisible(false);

        gridLayout->addWidget(tableWidgetReport, 0, 0, 1, 1);

        tabProgramOutput->addTab(tabFaultReport, QString());
        tabAppOutput = new QWidget();
        tabAppOutput->setObjectName(QStringLiteral("tabAppOutput"));
        tabProgramOutput->addTab(tabAppOutput, QString());

        verticalLayout->addWidget(tabProgramOutput);

        verticalLayout->setStretch(1, 1);

        horizontalLayout->addLayout(verticalLayout);

        horizontalLayout->setStretch(0, 3);
        horizontalLayout->setStretch(1, 7);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 964, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuWindow = new QMenu(menubar);
        menuWindow->setObjectName(QStringLiteral("menuWindow"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menuConfiguration = new QMenu(menubar);
        menuConfiguration->setObjectName(QStringLiteral("menuConfiguration"));
        menuTools_T = new QMenu(menubar);
        menuTools_T->setObjectName(QStringLiteral("menuTools_T"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(255);
        sizePolicy2.setHeightForWidth(statusbar->sizePolicy().hasHeightForWidth());
        statusbar->setSizePolicy(sizePolicy2);
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(toolBar->sizePolicy().hasHeightForWidth());
        toolBar->setSizePolicy(sizePolicy3);
        toolBar->setMinimumSize(QSize(0, 0));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(8);
        font.setBold(false);
        font.setWeight(50);
        toolBar->setFont(font);
        toolBar->setAcceptDrops(false);
        toolBar->setLayoutDirection(Qt::RightToLeft);
        toolBar->setAutoFillBackground(true);
        toolBar->setMovable(true);
        toolBar->setAllowedAreas(Qt::LeftToolBarArea);
        toolBar->setOrientation(Qt::Vertical);
        toolBar->setIconSize(QSize(96, 96));
        toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        toolBar->setFloatable(false);
        MainWindow->addToolBar(Qt::LeftToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuWindow->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menubar->addAction(menuConfiguration->menuAction());
        menubar->addAction(menuTools_T->menuAction());
        menuFile->addAction(newAct);
        menuFile->addAction(newProjectAct);
        menuFile->addAction(openAct);
        menuFile->addAction(saveAct);
        menuFile->addAction(saveAsAct);
        menuFile->addSeparator();
        menuFile->addAction(exitAct);
        menuEdit->addAction(cutAct);
        menuEdit->addAction(copyAct);
        menuEdit->addAction(pasteAct);
        menuEdit->addSeparator();
        menuEdit->addAction(undoAct);
        menuEdit->addAction(redoAct);
        menuEdit->addAction(testCreateClassAct);
        menuWindow->addAction(closeAct);
        menuWindow->addAction(closeAllAct);
        menuWindow->addSeparator();
        menuWindow->addAction(tileAct);
        menuWindow->addAction(cascadeAct);
        menuWindow->addSeparator();
        menuWindow->addAction(previousAct);
        menuWindow->addAction(nextAct);
        menuHelp->addAction(aboutAct);
        menuHelp->addAction(aboutDeveloperAct);
        menuConfiguration->addAction(manageSetAct);
        menuConfiguration->addAction(allRuleDescriptAct);
        menuTools_T->addAction(runDebugAct);
        menuTools_T->addAction(codeAnalysisAct);
        menuTools_T->addAction(hmppAct);
        toolBar->addAction(projectShowAct);
        toolBar->addSeparator();
        toolBar->addAction(runDebugAct);
        toolBar->addSeparator();
        toolBar->addAction(codeAnalysisAct);
        toolBar->addSeparator();
        toolBar->addAction(hmppAct);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);
        tabProgramOutput->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        newAct->setText(QApplication::translate("MainWindow", "New File(&N)", 0));
#ifndef QT_NO_TOOLTIP
        newAct->setToolTip(QApplication::translate("MainWindow", "Create a new file", 0));
#endif // QT_NO_TOOLTIP
        newAct->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", 0));
        openAct->setText(QApplication::translate("MainWindow", "Open(&O)", 0));
#ifndef QT_NO_TOOLTIP
        openAct->setToolTip(QApplication::translate("MainWindow", "Open an existing file", 0));
#endif // QT_NO_TOOLTIP
        openAct->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0));
        saveAct->setText(QApplication::translate("MainWindow", "Save(&s)", 0));
#ifndef QT_NO_TOOLTIP
        saveAct->setToolTip(QApplication::translate("MainWindow", "Save the document", 0));
#endif // QT_NO_TOOLTIP
        saveAct->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0));
        saveAsAct->setText(QApplication::translate("MainWindow", "Save As(&A)", 0));
#ifndef QT_NO_TOOLTIP
        saveAsAct->setToolTip(QApplication::translate("MainWindow", "Save the document under a new name", 0));
#endif // QT_NO_TOOLTIP
        saveAsAct->setShortcut(QApplication::translate("MainWindow", "Ctrl+A", 0));
        exitAct->setText(QApplication::translate("MainWindow", "Exit(&X)", 0));
#ifndef QT_NO_TOOLTIP
        exitAct->setToolTip(QApplication::translate("MainWindow", "Exit the application", 0));
#endif // QT_NO_TOOLTIP
        undoAct->setText(QApplication::translate("MainWindow", "Undo(&U)", 0));
        undoAct->setShortcut(QApplication::translate("MainWindow", "Ctrl+Z", 0));
        redoAct->setText(QApplication::translate("MainWindow", "Redo(&R)", 0));
        redoAct->setShortcut(QApplication::translate("MainWindow", "Ctrl+Y", 0));
        cutAct->setText(QApplication::translate("MainWindow", "Cut(&T)", 0));
#ifndef QT_NO_TOOLTIP
        cutAct->setToolTip(QApplication::translate("MainWindow", "Cut the selected contents to the clipboard", 0));
#endif // QT_NO_TOOLTIP
        cutAct->setShortcut(QApplication::translate("MainWindow", "Ctrl+X", 0));
        copyAct->setText(QApplication::translate("MainWindow", "Copy(&C)", 0));
#ifndef QT_NO_TOOLTIP
        copyAct->setToolTip(QApplication::translate("MainWindow", "Copy the selected contentes to the clipboard", 0));
#endif // QT_NO_TOOLTIP
        copyAct->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", 0));
        pasteAct->setText(QApplication::translate("MainWindow", "Paste(&P)", 0));
#ifndef QT_NO_TOOLTIP
        pasteAct->setToolTip(QApplication::translate("MainWindow", "Paste the clipboard's contents into the current selection", 0));
#endif // QT_NO_TOOLTIP
        pasteAct->setShortcut(QApplication::translate("MainWindow", "Ctrl+V", 0));
        closeAct->setText(QApplication::translate("MainWindow", "Close(&O)", 0));
#ifndef QT_NO_TOOLTIP
        closeAct->setToolTip(QApplication::translate("MainWindow", "Close the active window", 0));
#endif // QT_NO_TOOLTIP
        closeAllAct->setText(QApplication::translate("MainWindow", "CloseAll(&A)", 0));
#ifndef QT_NO_TOOLTIP
        closeAllAct->setToolTip(QApplication::translate("MainWindow", "Close all the windows", 0));
#endif // QT_NO_TOOLTIP
        tileAct->setText(QApplication::translate("MainWindow", "Tile(&T)", 0));
#ifndef QT_NO_TOOLTIP
        tileAct->setToolTip(QApplication::translate("MainWindow", "Tile the windows", 0));
#endif // QT_NO_TOOLTIP
        cascadeAct->setText(QApplication::translate("MainWindow", "Cascade(&C)", 0));
#ifndef QT_NO_TOOLTIP
        cascadeAct->setToolTip(QApplication::translate("MainWindow", "Cascade the windows", 0));
#endif // QT_NO_TOOLTIP
        nextAct->setText(QApplication::translate("MainWindow", "Next(&X)", 0));
#ifndef QT_NO_TOOLTIP
        nextAct->setToolTip(QApplication::translate("MainWindow", "Move the focus to the next window", 0));
#endif // QT_NO_TOOLTIP
        nextAct->setShortcut(QApplication::translate("MainWindow", "Ctrl+Tab", 0));
        previousAct->setText(QApplication::translate("MainWindow", "Previous(&V)", 0));
#ifndef QT_NO_TOOLTIP
        previousAct->setToolTip(QApplication::translate("MainWindow", "Move the focus to the previous window", 0));
#endif // QT_NO_TOOLTIP
        previousAct->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+Backtab", 0));
        aboutAct->setText(QApplication::translate("MainWindow", "About(&A)", 0));
#ifndef QT_NO_TOOLTIP
        aboutAct->setToolTip(QApplication::translate("MainWindow", "Show the demo's information box", 0));
#endif // QT_NO_TOOLTIP
        aboutDeveloperAct->setText(QApplication::translate("MainWindow", "About Software Developer(&Q)", 0));
#ifndef QT_NO_TOOLTIP
        aboutDeveloperAct->setToolTip(QApplication::translate("MainWindow", "Show the developer's information box", 0));
#endif // QT_NO_TOOLTIP
        projectShowAct->setText(QApplication::translate("MainWindow", "Project", 0));
#ifndef QT_NO_TOOLTIP
        projectShowAct->setToolTip(QApplication::translate("MainWindow", "Show the project framework", 0));
#endif // QT_NO_TOOLTIP
        runDebugAct->setText(QApplication::translate("MainWindow", "Run and Debug", 0));
#ifndef QT_NO_TOOLTIP
        runDebugAct->setToolTip(QApplication::translate("MainWindow", "Run and Debug", 0));
#endif // QT_NO_TOOLTIP
        codeAnalysisAct->setText(QApplication::translate("MainWindow", "SCM Configure", 0));
#ifndef QT_NO_TOOLTIP
        codeAnalysisAct->setToolTip(QApplication::translate("MainWindow", "Analyze code and identify faults", 0));
#endif // QT_NO_TOOLTIP
        hmppAct->setText(QApplication::translate("MainWindow", "HMPP", 0));
#ifndef QT_NO_TOOLTIP
        hmppAct->setToolTip(QApplication::translate("MainWindow", "Human Machine Pair Programming", 0));
#endif // QT_NO_TOOLTIP
        manageSetAct->setText(QApplication::translate("MainWindow", "Manage property rule sets(&M)", 0));
#ifndef QT_NO_TOOLTIP
        manageSetAct->setToolTip(QApplication::translate("MainWindow", "Manage the rules of property sets", 0));
#endif // QT_NO_TOOLTIP
        allRuleDescriptAct->setText(QApplication::translate("MainWindow", "All Rules Description(&D)", 0));
#ifndef QT_NO_TOOLTIP
        allRuleDescriptAct->setToolTip(QApplication::translate("MainWindow", "Show the detailed description of all rules", 0));
#endif // QT_NO_TOOLTIP
        newProjectAct->setText(QApplication::translate("MainWindow", "New Project", 0));
#ifndef QT_NO_TOOLTIP
        newProjectAct->setToolTip(QApplication::translate("MainWindow", "Create a new project", 0));
#endif // QT_NO_TOOLTIP
        testCreateClassAct->setText(QApplication::translate("MainWindow", "Create a class", 0));
        QTreeWidgetItem *___qtreewidgetitem = treeClassView->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindow", "Class View", 0));

        const bool __sortingEnabled = treeClassView->isSortingEnabled();
        treeClassView->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = treeClassView->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QApplication::translate("MainWindow", "TestClass", 0));
        QTreeWidgetItem *___qtreewidgetitem2 = ___qtreewidgetitem1->child(0);
        ___qtreewidgetitem2->setText(0, QApplication::translate("MainWindow", "gender", 0));
        QTreeWidgetItem *___qtreewidgetitem3 = ___qtreewidgetitem2->child(0);
        ___qtreewidgetitem3->setText(0, QApplication::translate("MainWindow", "FEMALE int", 0));
        QTreeWidgetItem *___qtreewidgetitem4 = ___qtreewidgetitem2->child(1);
        ___qtreewidgetitem4->setText(0, QApplication::translate("MainWindow", "MALE int", 0));
        QTreeWidgetItem *___qtreewidgetitem5 = ___qtreewidgetitem1->child(1);
        ___qtreewidgetitem5->setText(0, QApplication::translate("MainWindow", "Student", 0));
        QTreeWidgetItem *___qtreewidgetitem6 = ___qtreewidgetitem5->child(0);
        ___qtreewidgetitem6->setText(0, QApplication::translate("MainWindow", "Student(std::string, int)", 0));
        QTreeWidgetItem *___qtreewidgetitem7 = ___qtreewidgetitem5->child(1);
        ___qtreewidgetitem7->setText(0, QApplication::translate("MainWindow", "calculateAgerage() const", 0));
        QTreeWidgetItem *___qtreewidgetitem8 = ___qtreewidgetitem5->child(2);
        ___qtreewidgetitem8->setText(0, QApplication::translate("MainWindow", "displayInfo() const", 0));
        QTreeWidgetItem *___qtreewidgetitem9 = ___qtreewidgetitem5->child(3);
        ___qtreewidgetitem9->setText(0, QApplication::translate("MainWindow", "age int", 0));
        QTreeWidgetItem *___qtreewidgetitem10 = ___qtreewidgetitem5->child(4);
        ___qtreewidgetitem10->setText(0, QApplication::translate("MainWindow", "grades double[]", 0));
        QTreeWidgetItem *___qtreewidgetitem11 = ___qtreewidgetitem5->child(5);
        ___qtreewidgetitem11->setText(0, QApplication::translate("MainWindow", "name std::string", 0));
        QTreeWidgetItem *___qtreewidgetitem12 = ___qtreewidgetitem1->child(2);
        ___qtreewidgetitem12->setText(0, QApplication::translate("MainWindow", "initialize(StringList<Student>)", 0));
        QTreeWidgetItem *___qtreewidgetitem13 = ___qtreewidgetitem1->child(3);
        ___qtreewidgetitem13->setText(0, QApplication::translate("MainWindow", "main()", 0));
        QTreeWidgetItem *___qtreewidgetitem14 = ___qtreewidgetitem1->child(4);
        ___qtreewidgetitem14->setText(0, QApplication::translate("MainWindow", "studentNum const int", 0));
        treeClassView->setSortingEnabled(__sortingEnabled);

        pushButton_2->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "Ask anything about programming", 0));
        lineEdit->setInputMask(QString());
        lineEdit->setText(QString());
        pushButton_3->setText(QString());
        label1->setText(QApplication::translate("MainWindow", "Great! How can I assist you today? Do you have any code-related questions or problems that I can help you with?", 0));
        label2->setText(QApplication::translate("MainWindow", "create a calculate class", 0));
        pushButton_4->setText(QString());
        pushButton_5->setText(QString());
        label3->setText(QApplication::translate("MainWindow", "Sure! I can help you create a Calculate class. Could you please provide more details about what functionality or methods you would like the class to have?", 0));
        label4->setText(QApplication::translate("MainWindow", "the class can achieve add, sub, multiply, divide", 0));
        pushButton_6->setText(QString());
        pushButton_7->setText(QString());
        label5->setText(QApplication::translate("MainWindow", "Got it! Here's an example of a Calculate class that has methods for addition, subtraction, multiplication, and division:", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Copy code", 0));
        textBrowser->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:19px; background-color:#1f1f1f;\"><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#569cd6;\">class</span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#cccccc;\"> </span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#4ec9b0;\">Calculate</span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#cccccc;\"> {</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0;"
                        " text-indent:0px;\"><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#569cd6;\">public:</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#cccccc;\">\302\240 \302\240 </span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#569cd6;\">int</span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#cccccc;\"> </span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#dcdcaa;\">add</span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#cccccc;\">(</span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#569cd6;\">int</span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#cccccc;\"> </span><span style=\" font-family:'Consolas,C"
                        "ourier New,monospace'; font-size:8pt; color:#9cdcfe;\">a</span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#cccccc;\">, </span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#569cd6;\">int</span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#cccccc;\"> </span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#9cdcfe;\">b</span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#cccccc;\">) {</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#cccccc;\">\302\240 \302\240 \302\240 \302\240 </span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#c586c0;\">return</span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; colo"
                        "r:#cccccc;\"> </span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#9cdcfe;\">a</span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#cccccc;\"> </span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#d4d4d4;\">+</span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#cccccc;\"> </span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#9cdcfe;\">b</span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#cccccc;\">;</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#cccccc;\">\302\240 \302\240 }</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font"
                        "-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#cccccc;\"><br /></span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#cccccc;\">\302\240 \302\240 </span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#569cd6;\">int</span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#cccccc;\"> </span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#dcdcaa;\">subtract</span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#cccccc;\">(</span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#569cd6;\">int</span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#cccccc;\"> </span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8p"
                        "t; color:#9cdcfe;\">a</span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#cccccc;\">, </span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#569cd6;\">int</span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#cccccc;\"> </span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#9cdcfe;\">b</span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#cccccc;\">) {</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#cccccc;\">\302\240 \302\240 \302\240 \302\240 </span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#c586c0;\">return</span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#cccccc;\"> </span><span style=\""
                        " font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#9cdcfe;\">a</span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#cccccc;\"> </span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#d4d4d4;\">-</span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#cccccc;\"> </span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#9cdcfe;\">b</span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#cccccc;\">;</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#cccccc;\">\302\240 \302\240 }</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Consolas,Courier New,monos"
                        "pace'; font-size:8pt; color:#cccccc;\"><br /></span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#cccccc;\">\302\240 \302\240 </span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#569cd6;\">int</span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#cccccc;\"> </span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#dcdcaa;\">multiply</span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#cccccc;\">(</span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#569cd6;\">int</span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#cccccc;\"> </span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#9cdcfe;\">a</span><span s"
                        "tyle=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#cccccc;\">, </span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#569cd6;\">int</span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#cccccc;\"> </span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#9cdcfe;\">b</span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#cccccc;\">) {</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#cccccc;\">\302\240 \302\240 \302\240 \302\240 </span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#c586c0;\">return</span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#cccccc;\"> </span><span style=\" font-family:'Consolas,Courier New,"
                        "monospace'; font-size:8pt; color:#9cdcfe;\">a</span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#cccccc;\"> </span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#d4d4d4;\">*</span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#cccccc;\"> </span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#9cdcfe;\">b</span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#cccccc;\">;</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#cccccc;\">\302\240 \302\240 }</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#cccccc"
                        ";\"><br /></span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#cccccc;\">\302\240 \302\240 </span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#569cd6;\">double</span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#cccccc;\"> </span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#dcdcaa;\">divide</span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#cccccc;\">(</span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#569cd6;\">int</span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#cccccc;\"> </span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#9cdcfe;\">a</span><span style=\" font-family:'Consolas,Cour"
                        "ier New,monospace'; font-size:8pt; color:#cccccc;\">, </span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#569cd6;\">int</span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#cccccc;\"> </span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#9cdcfe;\">b</span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#cccccc;\">) {</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#cccccc;\">\302\240 \302\240 \302\240 \302\240 </span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#c586c0;\">if</span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#cccccc;\"> (</span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#9cd"
                        "cfe;\">b</span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#cccccc;\"> </span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#d4d4d4;\">!=</span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#cccccc;\"> </span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#b5cea8;\">0</span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#cccccc;\">) {</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#cccccc;\">\302\240 \302\240 \302\240 \302\240 \302\240 \302\240 </span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#c586c0;\">return</span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#cccccc;\"> </span><span style"
                        "=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#569cd6;\">static_cast</span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#d4d4d4;\">&lt;</span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#569cd6;\">double</span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#d4d4d4;\">&gt;</span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#cccccc;\">(</span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#9cdcfe;\">a</span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#cccccc;\">) </span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#d4d4d4;\">/</span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#cccccc;\"> </span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#9cdcfe;\">b</span><spa"
                        "n style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#cccccc;\">;</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#cccccc;\">\302\240 \302\240 \302\240 \302\240 } </span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#c586c0;\">else</span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#cccccc;\"> {</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#cccccc;\">\302\240 \302\240 \302\240 \302\240 \302\240 \302\240 </span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#c586c0;\">throw</span><span style=\" font-family:'Consolas,Courier New,monospace'; font"
                        "-size:8pt; color:#cccccc;\"> </span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#4ec9b0;\">std</span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#cccccc;\">::</span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#dcdcaa;\">runtime_error</span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#cccccc;\">(</span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#ce9178;\">&quot;Cannot divide by zero.&quot;</span><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#cccccc;\">);</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#cccccc;\">\302\240 \302\240 \302\240 \302\240 }</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left"
                        ":0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#cccccc;\">\302\240 \302\240 }</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Consolas,Courier New,monospace'; font-size:8pt; color:#cccccc;\">};</span></p></body></html>", 0));

        const bool __sortingEnabled1 = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("MainWindow", "warning1", 0));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("MainWindow", "warning2", 0));
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("MainWindow", "error1", 0));
        QListWidgetItem *___qlistwidgetitem3 = listWidget->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("MainWindow", "error2", 0));
        listWidget->setSortingEnabled(__sortingEnabled1);

        tabProgramOutput->setTabText(tabProgramOutput->indexOf(tabDebug), QApplication::translate("MainWindow", "Debug", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetReport->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Locate", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetReport->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Line Number", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetReport->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Fault Information", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetReport->verticalHeaderItem(0);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "1", 0));

        const bool __sortingEnabled2 = tableWidgetReport->isSortingEnabled();
        tableWidgetReport->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem4 = tableWidgetReport->item(0, 0);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "codeeditor.cpp", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidgetReport->item(0, 1);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "line 13", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidgetReport->item(0, 2);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "The exception that is thrown when there is an attempt to divide an integral or Decimal value by zero.", 0));
        tableWidgetReport->setSortingEnabled(__sortingEnabled2);

        tabProgramOutput->setTabText(tabProgramOutput->indexOf(tabFaultReport), QApplication::translate("MainWindow", "Fault Report", 0));
        tabProgramOutput->setTabText(tabProgramOutput->indexOf(tabAppOutput), QApplication::translate("MainWindow", "Application Output", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File(&F)", 0));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit(&E)", 0));
        menuWindow->setTitle(QApplication::translate("MainWindow", "Window(&W)", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help(&H)", 0));
        menuConfiguration->setTitle(QApplication::translate("MainWindow", "Configuration(&I)", 0));
        menuTools_T->setTitle(QApplication::translate("MainWindow", "Tools(&T)", 0));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
