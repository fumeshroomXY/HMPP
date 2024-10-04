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

class BuildProFromSpecDialog : public QDialog {
    Q_OBJECT

public:
    BuildProFromSpecDialog(const QHash<QString, QString>& hashValues, const QStringList& stringList, QWidget* parent = nullptr);

private:
    QTreeWidget* treeWidget;
    QStringList originalList;

    void addItemsFromHash(const QHash<QString, QString>& hashValues);
    void addItemsFromStringList(const QStringList& stringList);
    void demoteToFunctionRoot();
    void demoteToClassFunction();
    void promoteToClassRoot();
    void createNewClassRoot();
    void renameItem(QTreeWidgetItem* item, int column);
    QList<QTreeWidgetItem*> getClassItems();

private slots:
    void onOkClicked();
    void onCancelClicked();
};


#endif // TREEVIEW_H
