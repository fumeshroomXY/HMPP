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
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "requirementtreeview.h"

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
    QAction *actionCplus;
    QAction *actionJava;
    QAction *actionCsharp;
    QAction *codePredictAct;
    QAction *testAct;
    QAction *SCMDemoAct;
    QAction *importSpecAct;
    QAction *specBuildAct;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QStackedWidget *stackedWidget;
    QWidget *pageProject;
    QVBoxLayout *verticalLayout_2;
    ToDoTableView *toDoTableView;
    QTreeView *projectTreeView;
    RequirementTreeView *specificationView;
    QTreeWidget *treeClassView;
    QProgressBar *progressBar;
    QWidget *pageRunDebug;
    QGridLayout *gridLayout_4;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *pushButton_5;
    QLabel *label;
    QPushButton *waitingChatGPTReplyButton;
    QPushButton *copyFixedCodeButton;
    QLabel *label_3;
    QScrollArea *scrollArea_3;
    QWidget *scrollAreaWidgetContents_3;
    QVBoxLayout *verticalLayout_6;
    QTextBrowser *fixedCodeProblemBrowser;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_4;
    QVBoxLayout *verticalLayout_7;
    QTextEdit *fixedCodeTextEdit;
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
    QPushButton *hmppIconButton;
    QSpacerItem *verticalSpacer_3;
    QLabel *label3;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *copyCodeButton;
    QTextBrowser *codeBrowser;
    QVBoxLayout *verticalLayout;
    QMdiArea *mdiArea;
    QTabWidget *tabProgramOutput;
    QWidget *tabDebug;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayoutIssue;
    QTableWidget *tableIssueWidget;
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
    QMenu *menuChooseTargetLanguage;
    QMenu *menuTools_T;
    QMenu *menuTest;
    QMenu *menuDemo;
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
        icon15.addFile(QStringLiteral(":/images/toolbar_images/codepredict.png"), QSize(), QIcon::Normal, QIcon::Off);
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
        actionCplus = new QAction(MainWindow);
        actionCplus->setObjectName(QStringLiteral("actionCplus"));
        actionCplus->setCheckable(true);
        actionJava = new QAction(MainWindow);
        actionJava->setObjectName(QStringLiteral("actionJava"));
        actionJava->setCheckable(true);
        actionCsharp = new QAction(MainWindow);
        actionCsharp->setObjectName(QStringLiteral("actionCsharp"));
        actionCsharp->setCheckable(true);
        codePredictAct = new QAction(MainWindow);
        codePredictAct->setObjectName(QStringLiteral("codePredictAct"));
        QIcon icon17;
        icon17.addFile(QStringLiteral(":/images/toolbar_images/codeanalysis.png"), QSize(), QIcon::Normal, QIcon::Off);
        codePredictAct->setIcon(icon17);
        testAct = new QAction(MainWindow);
        testAct->setObjectName(QStringLiteral("testAct"));
        SCMDemoAct = new QAction(MainWindow);
        SCMDemoAct->setObjectName(QStringLiteral("SCMDemoAct"));
        importSpecAct = new QAction(MainWindow);
        importSpecAct->setObjectName(QStringLiteral("importSpecAct"));
        specBuildAct = new QAction(MainWindow);
        specBuildAct->setObjectName(QStringLiteral("specBuildAct"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setLineWidth(0);
        stackedWidget->setMidLineWidth(0);
        pageProject = new QWidget();
        pageProject->setObjectName(QStringLiteral("pageProject"));
        verticalLayout_2 = new QVBoxLayout(pageProject);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        toDoTableView = new ToDoTableView(pageProject);
        toDoTableView->setObjectName(QStringLiteral("toDoTableView"));
        toDoTableView->horizontalHeader()->setVisible(false);
        toDoTableView->horizontalHeader()->setStretchLastSection(true);
        toDoTableView->verticalHeader()->setVisible(false);

        verticalLayout_2->addWidget(toDoTableView);

        projectTreeView = new QTreeView(pageProject);
        projectTreeView->setObjectName(QStringLiteral("projectTreeView"));
        projectTreeView->header()->setStretchLastSection(true);

        verticalLayout_2->addWidget(projectTreeView);

        specificationView = new RequirementTreeView(pageProject);
        specificationView->setObjectName(QStringLiteral("specificationView"));

        verticalLayout_2->addWidget(specificationView);

        treeClassView = new QTreeWidget(pageProject);
        QIcon icon18;
        icon18.addFile(QStringLiteral(":/images/toolbar_images/folder.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon19;
        icon19.addFile(QStringLiteral(":/images/toolbar_images/class.svg"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon20;
        icon20.addFile(QStringLiteral(":/images/toolbar_images/memberfunc.svg"), QSize(), QIcon::Normal, QIcon::Off);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(treeClassView);
        __qtreewidgetitem->setIcon(0, icon18);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem(__qtreewidgetitem);
        __qtreewidgetitem2->setIcon(0, icon19);
        QTreeWidgetItem *__qtreewidgetitem3 = new QTreeWidgetItem(__qtreewidgetitem2);
        __qtreewidgetitem3->setIcon(0, icon20);
        QTreeWidgetItem *__qtreewidgetitem4 = new QTreeWidgetItem(__qtreewidgetitem2);
        __qtreewidgetitem4->setIcon(0, icon20);
        QTreeWidgetItem *__qtreewidgetitem5 = new QTreeWidgetItem(__qtreewidgetitem2);
        __qtreewidgetitem5->setIcon(0, icon20);
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
        gridLayout_4 = new QGridLayout(pageRunDebug);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(pageRunDebug);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setStyleSheet(QLatin1String("\n"
"    font-family: 'Verdana', sans-serif; /* Font type */\n"
"    font-size: 12px; /* Font size */\n"
"    color: #333333; /* Text color */\n"
"    font-weight: bold; /* Make the text bold */"));

        gridLayout_4->addWidget(label_4, 4, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        pushButton_5 = new QPushButton(pageRunDebug);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy);
        pushButton_5->setBaseSize(QSize(16, 16));
        pushButton_5->setIcon(icon17);

        horizontalLayout_7->addWidget(pushButton_5);

        label = new QLabel(pageRunDebug);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QLatin1String("\n"
"    font-family: 'Verdana', sans-serif; /* Font type */\n"
"    font-size: 12px; /* Font size */\n"
"    color: #333333; /* Text color */\n"
"    font-weight: bold; /* Make the text bold */"));

        horizontalLayout_7->addWidget(label);


        gridLayout_4->addLayout(horizontalLayout_7, 0, 0, 1, 1);

        waitingChatGPTReplyButton = new QPushButton(pageRunDebug);
        waitingChatGPTReplyButton->setObjectName(QStringLiteral("waitingChatGPTReplyButton"));
        waitingChatGPTReplyButton->setEnabled(true);
        waitingChatGPTReplyButton->setStyleSheet(QLatin1String("    color: #333333; /* Text color */\n"
"    font-weight: bold; /* Make the text bold */"));

        gridLayout_4->addWidget(waitingChatGPTReplyButton, 1, 0, 1, 1);

        copyFixedCodeButton = new QPushButton(pageRunDebug);
        copyFixedCodeButton->setObjectName(QStringLiteral("copyFixedCodeButton"));
        copyFixedCodeButton->setIcon(icon8);

        gridLayout_4->addWidget(copyFixedCodeButton, 6, 0, 1, 1);

        label_3 = new QLabel(pageRunDebug);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font;
        font.setFamily(QStringLiteral("Verdana,sans-serif"));
        font.setBold(true);
        font.setWeight(75);
        label_3->setFont(font);
        label_3->setStyleSheet(QLatin1String("\n"
"    font-family: 'Verdana', sans-serif; /* Font type */\n"
"    font-size: 12px; /* Font size */\n"
"    color: #333333; /* Text color */\n"
"    font-weight: bold; /* Make the text bold */"));
        label_3->setLineWidth(1);

        gridLayout_4->addWidget(label_3, 2, 0, 1, 1);

        scrollArea_3 = new QScrollArea(pageRunDebug);
        scrollArea_3->setObjectName(QStringLiteral("scrollArea_3"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(scrollArea_3->sizePolicy().hasHeightForWidth());
        scrollArea_3->setSizePolicy(sizePolicy1);
        scrollArea_3->setStyleSheet(QStringLiteral("    border-radius: 5px; /* Rounded corners */"));
        scrollArea_3->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QStringLiteral("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 251, 192));
        verticalLayout_6 = new QVBoxLayout(scrollAreaWidgetContents_3);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        fixedCodeProblemBrowser = new QTextBrowser(scrollAreaWidgetContents_3);
        fixedCodeProblemBrowser->setObjectName(QStringLiteral("fixedCodeProblemBrowser"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(fixedCodeProblemBrowser->sizePolicy().hasHeightForWidth());
        fixedCodeProblemBrowser->setSizePolicy(sizePolicy2);
        fixedCodeProblemBrowser->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        fixedCodeProblemBrowser->setStyleSheet(QLatin1String("    background-color: #ffffff; /* White background */\n"
"    border: 2px solid #007BFF; /* Blue border */\n"
"    border-radius: 5px; /* Rounded corners */\n"
"    padding: 1px; /* Inner padding */\n"
"    font-family: Arial, sans-serif; /* Font type */\n"
"    font-size: 14px; /* Font size */\n"
"    color: #555555; /* Text color */\n"
"    line-height: 1.5; /* Line height */"));
        fixedCodeProblemBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        fixedCodeProblemBrowser->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        fixedCodeProblemBrowser->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);

        verticalLayout_6->addWidget(fixedCodeProblemBrowser);

        scrollArea_3->setWidget(scrollAreaWidgetContents_3);

        gridLayout_4->addWidget(scrollArea_3, 3, 0, 1, 1);

        scrollArea_2 = new QScrollArea(pageRunDebug);
        scrollArea_2->setObjectName(QStringLiteral("scrollArea_2"));
        scrollArea_2->setStyleSheet(QStringLiteral("    border-radius: 5px; /* Rounded corners */"));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_4 = new QWidget();
        scrollAreaWidgetContents_4->setObjectName(QStringLiteral("scrollAreaWidgetContents_4"));
        scrollAreaWidgetContents_4->setGeometry(QRect(0, 0, 251, 242));
        verticalLayout_7 = new QVBoxLayout(scrollAreaWidgetContents_4);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        fixedCodeTextEdit = new QTextEdit(scrollAreaWidgetContents_4);
        fixedCodeTextEdit->setObjectName(QStringLiteral("fixedCodeTextEdit"));
        fixedCodeTextEdit->setStyleSheet(QLatin1String("    background-color: #ffffff; /* White background */\n"
"    border: 2px solid #007BFF; /* Blue border */\n"
"    border-radius: 5px; /* Rounded corners */\n"
"    padding: 2px; /* Inner padding */\n"
"    font-family: Arial, sans-serif; /* Font type */\n"
"    font-size: 14px; /* Font size */\n"
"    color: #555555; /* Text color */\n"
"    line-height: 1.5; /* Line height */"));
        fixedCodeTextEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        fixedCodeTextEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        verticalLayout_7->addWidget(fixedCodeTextEdit);

        scrollArea_2->setWidget(scrollAreaWidgetContents_4);

        gridLayout_4->addWidget(scrollArea_2, 5, 0, 1, 1);

        stackedWidget->addWidget(pageRunDebug);
        pageCodeAnalysis = new QWidget();
        pageCodeAnalysis->setObjectName(QStringLiteral("pageCodeAnalysis"));
        stackedWidget->addWidget(pageCodeAnalysis);
        pageHMPP = new QWidget();
        pageHMPP->setObjectName(QStringLiteral("pageHMPP"));
        gridLayout_2 = new QGridLayout(pageHMPP);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton_2 = new QPushButton(pageHMPP);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        pushButton_2->setBaseSize(QSize(16, 16));
        QIcon icon21;
        icon21.addFile(QStringLiteral(":/images/toolbar_images/robot16.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon21);

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
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 249, 511));
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
        pushButton_3->setIcon(icon21);

        verticalLayout_3->addWidget(pushButton_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        horizontalLayout_3->addLayout(verticalLayout_3);

        label1 = new QLabel(scrollAreaWidgetContents);
        label1->setObjectName(QStringLiteral("label1"));
        label1->setAutoFillBackground(false);
        label1->setStyleSheet(QLatin1String("background-color: rgb(120, 180, 210);\n"
"padding: 10px"));
        label1->setWordWrap(true);

        horizontalLayout_3->addWidget(label1);


        verticalLayout_8->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label2 = new QLabel(scrollAreaWidgetContents);
        label2->setObjectName(QStringLiteral("label2"));
        label2->setStyleSheet(QLatin1String("background-color: rgb(251, 200, 150);\n"
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
        QIcon icon22;
        icon22.addFile(QStringLiteral(":/images/toolbar_images/user.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon22);

        verticalLayout_4->addWidget(pushButton_4);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);


        horizontalLayout_4->addLayout(verticalLayout_4);


        verticalLayout_8->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        hmppIconButton = new QPushButton(scrollAreaWidgetContents);
        hmppIconButton->setObjectName(QStringLiteral("hmppIconButton"));
        sizePolicy.setHeightForWidth(hmppIconButton->sizePolicy().hasHeightForWidth());
        hmppIconButton->setSizePolicy(sizePolicy);
        hmppIconButton->setIcon(icon21);

        verticalLayout_5->addWidget(hmppIconButton);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_3);


        horizontalLayout_5->addLayout(verticalLayout_5);

        label3 = new QLabel(scrollAreaWidgetContents);
        label3->setObjectName(QStringLiteral("label3"));
        label3->setStyleSheet(QLatin1String("background-color: rgb(120, 180, 210);\n"
"padding: 10px"));
        label3->setWordWrap(true);

        horizontalLayout_5->addWidget(label3);


        verticalLayout_8->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));

        verticalLayout_8->addLayout(horizontalLayout_6);

        copyCodeButton = new QPushButton(scrollAreaWidgetContents);
        copyCodeButton->setObjectName(QStringLiteral("copyCodeButton"));
        copyCodeButton->setIcon(icon8);

        verticalLayout_8->addWidget(copyCodeButton);

        codeBrowser = new QTextBrowser(scrollAreaWidgetContents);
        codeBrowser->setObjectName(QStringLiteral("codeBrowser"));
        codeBrowser->setStyleSheet(QStringLiteral(""));
        codeBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        codeBrowser->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        codeBrowser->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        codeBrowser->setLineWrapMode(QTextEdit::NoWrap);

        verticalLayout_8->addWidget(codeBrowser);

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
        gridLayoutIssue = new QGridLayout();
        gridLayoutIssue->setObjectName(QStringLiteral("gridLayoutIssue"));
        tableIssueWidget = new QTableWidget(tabDebug);
        tableIssueWidget->setObjectName(QStringLiteral("tableIssueWidget"));
        tableIssueWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        tableIssueWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableIssueWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableIssueWidget->setShowGrid(false);
        tableIssueWidget->horizontalHeader()->setVisible(false);
        tableIssueWidget->verticalHeader()->setVisible(false);

        gridLayoutIssue->addWidget(tableIssueWidget, 0, 0, 1, 1);


        gridLayout_3->addLayout(gridLayoutIssue, 1, 0, 1, 1);

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
        QIcon icon23;
        icon23.addFile(QStringLiteral(":/images/toolbar_images/error.png"), QSize(), QIcon::Normal, QIcon::Off);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem4->setIcon(icon23);
        tableWidgetReport->setItem(0, 0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setTextAlignment(Qt::AlignCenter);
        tableWidgetReport->setItem(0, 1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidgetReport->setItem(0, 2, __qtablewidgetitem6);
        tableWidgetReport->setObjectName(QStringLiteral("tableWidgetReport"));
        QSizePolicy sizePolicy3(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(tableWidgetReport->sizePolicy().hasHeightForWidth());
        tableWidgetReport->setSizePolicy(sizePolicy3);
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
        menuChooseTargetLanguage = new QMenu(menuConfiguration);
        menuChooseTargetLanguage->setObjectName(QStringLiteral("menuChooseTargetLanguage"));
        menuTools_T = new QMenu(menubar);
        menuTools_T->setObjectName(QStringLiteral("menuTools_T"));
        menuTest = new QMenu(menubar);
        menuTest->setObjectName(QStringLiteral("menuTest"));
        menuDemo = new QMenu(menubar);
        menuDemo->setObjectName(QStringLiteral("menuDemo"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(255);
        sizePolicy4.setHeightForWidth(statusbar->sizePolicy().hasHeightForWidth());
        statusbar->setSizePolicy(sizePolicy4);
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(toolBar->sizePolicy().hasHeightForWidth());
        toolBar->setSizePolicy(sizePolicy5);
        toolBar->setMinimumSize(QSize(0, 0));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(8);
        font1.setBold(false);
        font1.setWeight(50);
        toolBar->setFont(font1);
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
        menubar->addAction(menuConfiguration->menuAction());
        menubar->addAction(menuTools_T->menuAction());
        menubar->addAction(menuDemo->menuAction());
        menubar->addAction(menuTest->menuAction());
        menubar->addAction(menuHelp->menuAction());
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
        menuConfiguration->addAction(menuChooseTargetLanguage->menuAction());
        menuConfiguration->addAction(importSpecAct);
        menuChooseTargetLanguage->addAction(actionCplus);
        menuChooseTargetLanguage->addAction(actionJava);
        menuChooseTargetLanguage->addAction(actionCsharp);
        menuTools_T->addAction(runDebugAct);
        menuTools_T->addAction(codeAnalysisAct);
        menuTools_T->addAction(hmppAct);
        menuTools_T->addAction(specBuildAct);
        menuTest->addAction(testAct);
        menuDemo->addAction(SCMDemoAct);
        toolBar->addAction(projectShowAct);
        toolBar->addSeparator();
        toolBar->addAction(runDebugAct);
        toolBar->addSeparator();
        toolBar->addAction(codeAnalysisAct);
        toolBar->addSeparator();
        toolBar->addAction(codePredictAct);
        toolBar->addSeparator();
        toolBar->addAction(hmppAct);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(3);
        tabProgramOutput->setCurrentIndex(0);


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
        openAct->setText(QApplication::translate("MainWindow", "Open project(&O)", 0));
#ifndef QT_NO_TOOLTIP
        openAct->setToolTip(QApplication::translate("MainWindow", "Open an existing project", 0));
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
        actionCplus->setText(QApplication::translate("MainWindow", "C++", 0));
        actionJava->setText(QApplication::translate("MainWindow", "Java", 0));
        actionCsharp->setText(QApplication::translate("MainWindow", "C#", 0));
        codePredictAct->setText(QApplication::translate("MainWindow", "Smart Fix", 0));
#ifndef QT_NO_TOOLTIP
        codePredictAct->setToolTip(QApplication::translate("MainWindow", "Predict code", 0));
#endif // QT_NO_TOOLTIP
        testAct->setText(QApplication::translate("MainWindow", "testAction", 0));
        SCMDemoAct->setText(QApplication::translate("MainWindow", "SCM Demo", 0));
        importSpecAct->setText(QApplication::translate("MainWindow", "Import Specification", 0));
#ifndef QT_NO_TOOLTIP
        importSpecAct->setToolTip(QApplication::translate("MainWindow", "Import Specification for Current Project", 0));
#endif // QT_NO_TOOLTIP
        specBuildAct->setText(QApplication::translate("MainWindow", "Build Project From Specification", 0));
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

        label_4->setText(QApplication::translate("MainWindow", "Fixed Code:", 0));
        pushButton_5->setText(QString());
        label->setText(QApplication::translate("MainWindow", "The fixed code is as follows:", 0));
#ifndef QT_NO_WHATSTHIS
        waitingChatGPTReplyButton->setWhatsThis(QApplication::translate("MainWindow", "Waiting for ChatGPT reply...", 0));
#endif // QT_NO_WHATSTHIS
        waitingChatGPTReplyButton->setText(QApplication::translate("MainWindow", "Select the code and send it to ChatGPT", 0));
        copyFixedCodeButton->setText(QApplication::translate("MainWindow", "Copy the code", 0));
        label_3->setText(QApplication::translate("MainWindow", "Problem:", 0));
        fixedCodeTextEdit->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Arial,sans-serif'; font-size:14px; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14px;\">#include &lt;iostream&gt; </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14px;\">#include &lt;stdexcept&gt; // for std::invalid_argument </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14px;\">double divide(double numerator, double denominator) { </span></p>\n"
"<p style=\" margin-top:0px; margin-"
                        "bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14px;\">    if (denominator == 0) { </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14px;\">        throw std::invalid_argument(&quot;Denominator cannot be zero&quot;); </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14px;\">    } </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14px;\">    return numerator / denominator; </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14px;\">}</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bo"
                        "ttom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS UI Gothic'; font-size:9pt;\"><br /></p></body></html>", 0));
        pushButton_2->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "Ask anything about programming", 0));
        lineEdit->setInputMask(QString());
        lineEdit->setText(QString());
        pushButton_3->setText(QString());
        label1->setText(QApplication::translate("MainWindow", "Great! How can I assist you today? Do you have any code-related questions or problems that I can help you with?", 0));
        label2->setText(QApplication::translate("MainWindow", "create a calculate class", 0));
        pushButton_4->setText(QString());
        hmppIconButton->setText(QString());
        label3->setText(QApplication::translate("MainWindow", "<html><head/><body><p>The code you provided has some problems. Here is the modified version. If you want me to explain further, feel free to ask any question. </p></body></html>", 0));
        copyCodeButton->setText(QApplication::translate("MainWindow", "Copy code", 0));
        codeBrowser->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS UI Gothic'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun';\">#include &quot;Camera.h&quot;</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun';\">#include &quot;EncryptionModule.h&quot;</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'SimSun';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -"
                        "qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun';\">int main() {</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun';\">    std::string storagePath = &quot;./encrypted_videos&quot;;</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun';\">    EncryptionModule encryptionModule;</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'SimSun';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun';\">    // Create storage directory if it doesn't exist</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:"
                        "0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun';\">    std::system((&quot;mkdir -p &quot; + storagePath).c_str());</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'SimSun';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun';\">    // Initialize Camera</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun';\">    Camera camera(storagePath, encryptionModule);</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'SimSun';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-"
                        "left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun';\">    // Simulate a video file path</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun';\">    std::string videoFilePath = &quot;./sample_video.mp4&quot;;</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'SimSun';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun';\">    // Encrypt and store the video</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun';\">    camera.encryptAndStoreVideo(videoFilePath);</span></p>\n"
"<p style=\"-qt-"
                        "paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'SimSun';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun';\">    return 0;</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun';\">}</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'SimSun';\"><br /></p></body></html>", 0));
        tabProgramOutput->setTabText(tabProgramOutput->indexOf(tabDebug), QApplication::translate("MainWindow", "Issue Report", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetReport->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Locate", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetReport->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Line Number", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetReport->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Fault Information", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetReport->verticalHeaderItem(0);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "1", 0));

        const bool __sortingEnabled1 = tableWidgetReport->isSortingEnabled();
        tableWidgetReport->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem4 = tableWidgetReport->item(0, 0);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "codeeditor.cpp", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidgetReport->item(0, 1);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "line 13", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidgetReport->item(0, 2);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "The exception that is thrown when there is an attempt to divide an integral or Decimal value by zero.", 0));
        tableWidgetReport->setSortingEnabled(__sortingEnabled1);

        tabProgramOutput->setTabText(tabProgramOutput->indexOf(tabFaultReport), QApplication::translate("MainWindow", "Fault Report", 0));
        tabProgramOutput->setTabText(tabProgramOutput->indexOf(tabAppOutput), QApplication::translate("MainWindow", "Application Output", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File(&F)", 0));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit(&E)", 0));
        menuWindow->setTitle(QApplication::translate("MainWindow", "Window(&W)", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help(&H)", 0));
        menuConfiguration->setTitle(QApplication::translate("MainWindow", "Configuration(&I)", 0));
        menuChooseTargetLanguage->setTitle(QApplication::translate("MainWindow", "Choose Target Language", 0));
        menuTools_T->setTitle(QApplication::translate("MainWindow", "Tools(&T)", 0));
        menuTest->setTitle(QApplication::translate("MainWindow", "Test(&S)", 0));
        menuDemo->setTitle(QApplication::translate("MainWindow", "Demo(&D)", 0));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
