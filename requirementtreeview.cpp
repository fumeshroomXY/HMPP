#include "requirementtreeview.h"
#include <QMenu>
#include <QAction>

RequirementTreeView::RequirementTreeView(QWidget *parent) : QTreeView(parent)
{
    setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, &RequirementTreeView::customContextMenuRequested, this, &RequirementTreeView::showContextMenu);
}

void RequirementTreeView::showContextMenu(const QPoint &pos)
{
    QModelIndex index = indexAt(pos);
    if (index.isValid()) {
        QMenu menu(this);
        QAction *action1 = menu.addAction("Complete the Requirement");

        QAction *selectedAction = menu.exec(viewport()->mapToGlobal(pos));
        if (selectedAction == action1) {
            // 执行 Action 相应的动作
            emit complete(index);
        }
    }
}

RequirementTreeView::~RequirementTreeView()
{

}
