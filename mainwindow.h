#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QTableWidgetItem>
#include <QStandardItemModel>
#include <QFileInfo>
#include <QDir>
#include "mdichild.h"

class MdiChild;
class IssueManager;
struct RequireNote;
QT_BEGIN_NAMESPACE
class QAction;
class QMenu;
class QMdiArea;
class QMdiSubWindow;
class QGridLayout;
QT_END_NAMESPACE

//项目目录下的子目录名可以根据需求更改
extern const QString srcDir;
extern const QString headDir;

extern const QStringList LanguageSet;

namespace Ui{
    class MainWindow;
}

class projectTree{

public:
    QString projectName;
    QString projectPath;
    QString specificationPath;
    QString cmakeFile;
    QStringList sourceFiles;
    QStringList headerFiles;

    //当前项目对应的informal spec
    QHash<QString, QString> proInformalSpec;

    projectTree(QString proName, QString proPath, QString specPath){
        projectName = proName;
        projectPath = proPath;
        specificationPath = specPath;
        cmakeFile = "CMakeLists.txt";
        sourceFiles.append("main.cpp");
    }
    projectTree(){}
};



class QErrorMessage;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();

    bool openFile(const QString &fileName);
    double screenFactor = 0;

    double getScreenFactor();

    void setToolBarLayout();

    bool createProject(const QString &proName, const QString &proDir, const QString &specDir, const QString &targetLang);

    bool addFileToProject(const projectTree* pro, QString fileName);


    void initCMakeFile(const projectTree *pro);

    //当新添加类时，修改CmakeFile，添加类的源文件
    bool addFileStrToCmakeFile(const QString& fileName);

    //读取打开的项目信息，主要是IncludedClass和Specification Path
    bool readProjectInfoFromCmakeFile(const projectTree* pro, QStringList& includedClass);

    //写入项目信息
    bool writeProjectInfoIntoCmakeFile(const projectTree* pro, const QStringList& includedClass);

    //展示Class封装问题的面板
    void showClassEncapsulateIssueTab();

    //返回对应类名的类信息
    ClassInfo getProClassInfo(QString className);

    //设定对应类名的类信息
    void setProClassInfo(QString className, const ClassInfo &info);

    //同步项目中的和文件对应的类信息
    void synchronizeClassInfoFromProToFile(QString className);

    //删除和新增头文件中对应的类成员
    bool ReplaceAndAddInfoInClassSourceFile(const QList<std::pair<QString, QString>>& replaceInfo, const ClassInfo &addInfo, QString className);

    //清空类的源文件并重写类函数信息
    bool clearAndModifyClassSourceFile(const ClassInfo &info, QString className);

    //从非正式规格书中读取数据
    void readContentFromInformalSpecification(const QString &filePath);

    //将ChatGPT的回答分割为三部分
    void separateText(const QString &fullText, QString &problemPart, QString &codePart, QString &conclusionPart);


public slots:

    //点击Issue时跳转到对应行
    void setCursorToIssueLine(QTableWidgetItem *item);

    //展示实例类名未定义的问题
    void showClassUndefinedSyntaxIssue(const QList<ClassUndefinedSyntaxIssue> &list);

    //UNSPECIFIED type 问题
    void showClassUnspecifiedTypeIssue();

    //获取向导中打开的文件信息
    void receiveGuideWizardFileInfo(bool createNewFlag, const QString &proName, const QString &proDir,
                                    const QString specDir, const QString &targetLang);

    //获取新项目的信息并准备创建
    void getNewProjectInfo();

    //更新文件名对应的notes
    void updateFileToDoRequireNotes(const QString& filePath, const QVector<RequireNote *> &notes);

    //更新文件对应的自然语言描述规格的位置
    void updateInformalSpecs(const QString& filePath, const QList<InformalSpecInfo>& informalSpecInfos);

    //为当前项目导入规格书
    void importSpecificationForCurrentPro();

    //根据规格书构建项目文件
    void buildFilesFromSpecification();

    //调出ChatGPT对话
    void startChatGPTDialog(QString text);

    //利用ChatGPT修改代码
    void fixCodeByChatGPT(QString text);

    //查询类对象类型
    QString findClassMemberType(QString className, QString expression);

    //导入Bug Report 文件
    void loadBugReportFile(QString bugReportFilePath);

    //开始复盘代码模式
    void reviewMethodCode(QString methodName);

    void setCscrToolMethodNameToCode(const QHash<QString, QString> &value);

protected:
    void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;    //指定重载符

private slots:
    void newFile();
    MdiChild* newReviewCodeFile(QString fileName = "");
    void open();
    void save();
    void saveAs();
    void updateRecentFileActions();
    void openRecentFile();
#ifndef QT_NO_CLIPBOARD
    void cut();
    void copy();
    void paste();
#endif
    void about();
    void aboutDeveloper();
    void updateMenus();
    void updateWindowMenu();
    MdiChild *createMdiChild();
    void switchLayoutDirection();

    void configCodeAnalysis();
    void managePropertySet();
    void showAllRuleDescript();
    void updateProgressBar();

    void setCursorToFaultLine(QTableWidgetItem *);

    void showHMPPView();
    void showProjectView();
    void showFixedCodeView();
    void showCSCRTool();
    void showSCMFaultTab(int);
    void lineEditPrompt();
    void doubleClickedProjectTree(const QModelIndex &index);
    void doubleClickedSpecificationView(const QModelIndex &index);
    void doubleClickedToDoTableView(const QModelIndex &index);

    //void updateSpecificationModel();
    void completeSpecification(const QModelIndex &index);

    void updateToDoListModel();
    void clearToDoListModel();
    void completeToDoNote(const QModelIndex &index);


    //设置目标语言
    void setTargetLangToCplus();
    void setTargetLangToJava();
    void setTargetLangToCsharp();

    //更新项目的类信息
    void updateProjectClassInfo(QString filePath, QHash<QString, ClassInfo>& newClassInfoHash);

    //插入新的类信息
    void insertProjectClassInfo(const QList<ClassInfo>& insertClassInfos);

    void on_copyCodeButton_clicked();
    void on_copyFixedCodeButton_clicked();

    //测试用槽函数
    void testSlot();

    //项目视图右键出现菜单
    void projectViewMenuRequest(const QPoint& pos);

    //展示用
    void showDemoSCM();

private:
    enum { MaxRecentFiles = 5 };

    void createActions();
    void createStatusBar();
    void createDockWindows();
    void readSettings();
    void writeSettings();
    bool loadFile(const QString &fileName);
    static bool hasRecentFiles();
    void prependToRecentFiles(const QString &fileName);
    void setRecentFilesVisible(bool visible);

    //当更新项目的类信息后，添加类的头文件和源文件
    bool createNewClassFiles(const QString& className);
    MdiChild *activeMdiChild() const;
    QMdiSubWindow *findMdiChild(const QString &fileName) const;

    //初始化成员变量
    void init();

    Ui::MainWindow* ui;

    QMenu *windowMenu;

    QAction *recentFileActs[MaxRecentFiles];
    QAction *recentFileSeparator;
    QAction *recentFileSubMenuAct;

    QTimer *timer;

    projectTree* currentPro;

    IssueManager* proIssueManager;


    Highlighter* fixedCodeHighlighter;

    Highlighter* hmppCodeHighlighter;

    //保存已打开的项目
    QMultiHash<QString, projectTree*> projects;

    QStandardItemModel* projectModel;

    QStandardItemModel* todoListModel;

    QStandardItemModel* specificationModel;

    //当前文件的类信息汇总
    QHash<QString, ClassInfo> proClassInfoHash;   //key = 类名，value = 类信息

    //每个文件对应的类信息汇总， key = 文件名， value = 类名 + 类信息
    QHash<QString, QHash<QString, ClassInfo>> fileClassInfoHash;

    //每个文件对应的todo requirement notes, key = 文件名
    QHash<QString, QVector<RequireNote*>> fileToDoRequireNotes;

    QHash<QString, QList<InformalSpecInfo>> fileInformalSpecs;

    QHash<QString, QString> cscrToolMethodNameToCode;

    //include文件中包含的类
    QStringList includedClass;

    QErrorMessage *errordlg;

    //本工具所在的目录
    QDir appDir;

    //当前项目使用的目标语言
    QString targetLanginCurrentPro;

    bool loadProject(const QString &fileName, const QString &specDir);
    void initProjectModel(projectTree *newPro);

    void clearSpecificationModel();
    void updateSpecificationModel(const QHash<QString, QString>& informalSpec);

    //初始化项目信息
    void initProjectInfo();

    //寻找Model中符合特定条件的项

    QModelIndex findModelItem(const QString &searchString, const QModelIndex &parentIndex, QStandardItemModel *model, int role);

    //为新创建的类的头文件，添加类的成员变量和函数信息
    bool clearAndModifyClassHeaderFile(const ClassInfo &info, QString className);

    //在类的头文件中删除对应信息
    //bool deleteInfoInClassFile(const ClassInfo &info, QString className);

    //在QStandardItemModel中删除指定节点及其所有子节点
    void removeNodeAndChildrenInModel(QStandardItemModel *model, const QModelIndex &index);

    //关闭项目
    void closeProject(projectTree* pro);

};

#endif
