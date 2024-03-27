#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QTableWidgetItem>
#include <QStandardItemModel>
#include <QFileInfo>
#include <QDir>

class MdiChild;
struct RequireNote;
QT_BEGIN_NAMESPACE
class QAction;
class QMenu;
class QMdiArea;
class QMdiSubWindow;
class QGridLayout;
QT_END_NAMESPACE

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
        cmakeFile = "CMakeList.txt";
        sourceFiles.append("main.cpp");
    }
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

    void updateProjectModel();

    void initCMakeFile(const projectTree *pro);

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

    void setPage2();
    void setPage1();
    void showProgramOutput(int);
    void lineEditPrompt();
    void doubleClickedProjectTree(const QModelIndex &index);
    void doubleClickedRequirementView(const QModelIndex &index);

    void updateRequireNotes(MdiChild* child);
    void updateRequirementModel();
    void completeRequirement(const QModelIndex &index);

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

    void createNewClass();
    MdiChild *activeMdiChild() const;
    QMdiSubWindow *findMdiChild(const QString &fileName) const;

    Ui::MainWindow* ui;

    QMenu *windowMenu;

    QAction *recentFileActs[MaxRecentFiles];
    QAction *recentFileSeparator;
    QAction *recentFileSubMenuAct;

    QTimer *timer;

    QList<projectTree*> projects;

    QStandardItemModel projectModel;

    QStandardItemModel requirementModel;

    QErrorMessage *errordlg;

    QDir appDir;

};

#endif
