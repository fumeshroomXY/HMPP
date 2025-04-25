#ifndef REQUIREMENTTREEVIEW_H
#define REQUIREMENTTREEVIEW_H
#include <QTreeView>
#include <QMouseEvent>
#include <QTableView>

#include <QDialog>
#include <QTreeWidget>
#include <QPushButton>
#include <QHash>
#include <QStringList>
#include <QListWidget>
#include <QButtonGroup>  // Include QButtonGroup


#include <mdichild.h>

//在这里有许多自定义widget的类定义



class RequirementTreeView : public QTreeView
{
    Q_OBJECT
public:
    RequirementTreeView(QWidget *parent = 0);
    ~RequirementTreeView();


protected:
    void showContextMenu(const QPoint &pos);

private:
    //想实现双击时该项如果是折叠的就保持折叠，如果是展开的就保持展开，但是好像有问题
    void mouseDoubleClickEvent(QMouseEvent *event);

signals:
    void complete(const QModelIndex &index);

};

/**
 * @brief todo requirement
 *
 */
class ToDoTableView : public QTableView
{
    Q_OBJECT
public:
    ToDoTableView(QWidget *parent = 0);
    ~ToDoTableView();

protected:
    void showContextMenu(const QPoint &pos);

signals:
    void complete(const QModelIndex &index);

};

/**
 * @brief generate the source and header files based on the sub titles of the specification
 *
 */
class BuildProFromSpecDialog : public QDialog {
    Q_OBJECT

public:
    BuildProFromSpecDialog(const QHash<QString, QString>& hashValues, const QStringList& stringList, QWidget* parent = nullptr);
    const QString classUserRole = "class";
    const QString classFunctionUserRole = "function";
    const QString globalFunctionUserRole = "GlobalFunction";


private:
    QTreeWidget* treeWidget;
    QStringList existingClassList;

    void addItemsFromHash(const QHash<QString, QString>& hashValues);
    void addItemsFromStringList(const QStringList& stringList);
    bool isItemFromExistingClassList(QTreeWidgetItem* item);
    void demoteToIndependentFunction();
    void demoteToClassFunction();
    void promoteToClass();
    void createNewClass();
    void renameItem(QTreeWidgetItem* item, int column);
    void deleteSelectedItem();
    QList<QTreeWidgetItem*> getClassItems();

    QList<ClassInfo> getClassStructure();

signals:
    // Signal to pass the tree structure as a QList of QHash items when "OK" is clicked
    void treeStructureReady(const QList<ClassInfo>& treeStructure);

private slots:
    void onOkClicked();
    void onCancelClicked();
};


class SameNameMethodHandleDialog : public QDialog {
    Q_OBJECT

public:
    struct DialogResult {
        QString buttonClicked;
        int indexA;
        int indexB;
    };

    explicit SameNameMethodHandleDialog(const QStringList& oldMethodList,
                                        const QStringList& newMethodList,
                                        QWidget* parent = nullptr);

    DialogResult getResult() const;

private slots:
    void onReplaceClicked();
    void onAddNewClicked();
    void onCancelClicked();

private:
    void saveResult(const QString& buttonClicked);

    QListWidget* listA;
    QListWidget* listB;
    DialogResult resultData{"Cancel", 0, 0}; // Initialize indices to -1 (no selection)
};

namespace Ui {
    class cscrtooldialog;  // Matches the name of the .ui file
}

class CscrToolDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CscrToolDialog(QWidget *parent = nullptr, const QList<QString> & methods = QList<QString>());
    ~CscrToolDialog();

signals:
    void loadBugReportFile(QString);
    void reviewMethod(QString);

private slots:
    void handleOptionChanged(int id);  // Slot to handle the selection change
    void onOkClicked();

private:
    Ui::cscrtooldialog *ui;
    QButtonGroup *buttonGroup;  // Pointer to the QButtonGroup
    QString bugReportFilePath;

};




#endif // TREEVIEW_H
