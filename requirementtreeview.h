#ifndef REQUIREMENTTREEVIEW_H
#define REQUIREMENTTREEVIEW_H
#include <QTreeView>


class RequirementTreeView : public QTreeView
{
    Q_OBJECT
public:
    RequirementTreeView(QWidget *parent = 0);
    ~RequirementTreeView();


protected:
    void showContextMenu(const QPoint &pos);

signals:
    void complete(const QModelIndex &index);

};

#endif // TREEVIEW_H
