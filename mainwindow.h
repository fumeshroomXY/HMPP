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
    QString cmakeFile;
    QStringList sourceFiles;
    QStringList headerFiles;

    projectTree(QString proName, QString proPath){
        projectName = proName;
        projectPath = proPath;
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

    void createProject();

    bool addFileToProject(const projectTree* pro, QString fileName);


    void initCMakeFile(const projectTree *pro);

    //当新添加类时，修改CmakeFile，添加类的源文件
    bool addFileStrToCmakeFile(const QString& fileName);


    //展示Class封装问题的面板
    void showClassEncapsulateIssueTab();

    //返回对应类名的类信息
    ClassInfo getProClassInfo(QString className);

    //设定对应类名的类信息
    void setProClassInfo(QString className, const ClassInfo &info);

    //同步项目中的和文件对应的类信息
    void synchronizeClassInfoFromProToFile(QString className);

    //删除和新增头文件中对应的类成员
    bool delAndAddInfoInClassHeaderFile(const ClassInfo &delInfo, const ClassInfo &addInfo, QString className);

    //清空类的源文件并重写类函数信息
    bool clearAndModifyClassSourceFile(const ClassInfo &info, QString className);

public slots:

    //点击Issue时跳转到对应行
    void setCursorToIssueLine(QTableWidgetItem *item);

    //展示实例类名未定义的问题
    void showClassUndefinedSyntaxIssue(const QList<ClassUndefinedSyntaxIssue> &list);

    //UNSPECIFIED type 问题
    void showClassUnspecifiedTypeIssue();

protected:
    void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;    //指定重载符

private slots:
    void newFile();
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
    void showSCMFaultTab(int);
    void lineEditPrompt();
    void doubleClickedProjectTree(const QModelIndex &index);
    void doubleClickedRequirementView(const QModelIndex &index);

    void updateRequireNotes(MdiChild* child);
    void updateRequirementModel();
    void completeRequirement(const QModelIndex &index);


    //设置目标语言
    void setTargetLangToCplus();
    void setTargetLangToJava();
    void setTargetLangToCsharp();

    //更新项目的类信息
    void updateProjectClassInfo(QString filePath, QHash<QString, ClassInfo>& newClassInfoHash);

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

    //保存已打开的项目
    QMultiHash<QString, projectTree*> projects;

    QStandardItemModel* projectModel;

    QStandardItemModel* requirementModel;

    //当前文件的类信息汇总
    QHash<QString, ClassInfo> proClassInfoHash;   //key = 类名，value = 类信息

    //每个文件对应的类信息汇总， key = 文件名， value = 类名 + 类信息
    QHash<QString, QHash<QString, ClassInfo>> fileClassInfoHash;

    //include文件中包含的类
    QStringList includedClass;

    QErrorMessage *errordlg;

    //本工具所在的目录
    QDir appDir;

    //当前项目使用的目标语言
    QString targetLanginCurrentPro;

    bool loadProject(const QString &fileName);
    void initProjectModel(projectTree *newPro);

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
    void closeProject(QString proName, QString proPath);
};

#endif
