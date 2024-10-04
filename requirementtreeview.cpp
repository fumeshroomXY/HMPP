#include "requirementtreeview.h"
#include <QMenu>
#include <QAction>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QInputDialog>
#include <QFont>

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

void RequirementTreeView::mouseDoubleClickEvent(QMouseEvent *event)
{
    QModelIndex index = indexAt(event->pos());
    if (index.isValid()) {
        if (isExpanded(index)) {
            expand(index);
        }else{
            collapse(index);
        }
    }
    QTreeView::mouseDoubleClickEvent(event);
}

ToDoTableView::ToDoTableView(QWidget *parent) : QTableView(parent)
{
    setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, &ToDoTableView::customContextMenuRequested, this, &ToDoTableView::showContextMenu);
    //horizontalHeader()->setVisible(true);
}

ToDoTableView::~ToDoTableView()
{

}

void ToDoTableView::showContextMenu(const QPoint &pos)
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

// Constructor
BuildProFromSpecDialog::BuildProFromSpecDialog(const QHash<QString, QString>& hashValues, const QStringList& stringList, QWidget* parent)
    : QDialog(parent) {

    // Tree widget setup
    treeWidget = new QTreeWidget(this);
    treeWidget->setColumnCount(1);
    treeWidget->setHeaderHidden(true);

    // Add root nodes from QHash and QStringList
    addItemsFromHash(hashValues);
    addItemsFromStringList(stringList);

    // Buttons
    QPushButton* btn1 = new QPushButton("Demote to Function Root", this);
    QPushButton* btn2 = new QPushButton("Demote to Class Function", this);
    QPushButton* btn3 = new QPushButton("Promote to Class Root", this);
    QPushButton* btn4 = new QPushButton("New Class Root", this);
    QPushButton* okButton = new QPushButton("OK", this);
    QPushButton* cancelButton = new QPushButton("Cancel", this);

    // Layout setup
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    QHBoxLayout* buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(btn1);
    buttonLayout->addWidget(btn2);
    buttonLayout->addWidget(btn3);
    buttonLayout->addWidget(btn4);
    mainLayout->addWidget(treeWidget);
    mainLayout->addLayout(buttonLayout);
    mainLayout->addWidget(okButton);
    mainLayout->addWidget(cancelButton);

    // Signals and Slots
    connect(btn1, &QPushButton::clicked, this, &BuildProFromSpecDialog::demoteToFunctionRoot);
    connect(btn2, &QPushButton::clicked, this, &BuildProFromSpecDialog::demoteToClassFunction);
    connect(btn3, &QPushButton::clicked, this, &BuildProFromSpecDialog::promoteToClassRoot);
    connect(btn4, &QPushButton::clicked, this, &BuildProFromSpecDialog::createNewClassRoot);
    connect(treeWidget, &QTreeWidget::itemDoubleClicked, this, &BuildProFromSpecDialog::renameItem);
    connect(okButton, &QPushButton::clicked, this, &BuildProFromSpecDialog::onOkClicked);
    connect(cancelButton, &QPushButton::clicked, this, &BuildProFromSpecDialog::onCancelClicked);
}

// Add items from QHash
void BuildProFromSpecDialog::addItemsFromHash(const QHash<QString, QString>& hashValues) {
    for (const QString& key : hashValues.keys()) {
        QTreeWidgetItem* classItem = new QTreeWidgetItem(treeWidget);
        classItem->setText(0, hashValues[key]);
        classItem->setIcon(0, QIcon(":/icons/class.png"));
        classItem->setData(0, Qt::UserRole, "class");
    }
}

// Add items from QStringList
void BuildProFromSpecDialog::addItemsFromStringList(const QStringList& stringList) {
    originalList = stringList;
    for (const QString& str : stringList) {
        QTreeWidgetItem* funcItem = new QTreeWidgetItem(treeWidget);
        funcItem->setText(0, str);
        funcItem->setIcon(0, QIcon(":/icons/function.png"));
        funcItem->setData(0, Qt::UserRole, "function");
    }
}

// Demote the selected item to a function root
void BuildProFromSpecDialog::demoteToFunctionRoot() {
    QTreeWidgetItem* currentItem = treeWidget->currentItem();
    if (currentItem && currentItem->data(0, Qt::UserRole).toString() == "class") {
        currentItem->setData(0, Qt::UserRole, "function");
        currentItem->setIcon(0, QIcon(":/icons/function.png"));
    }
}

// Demote the selected item to a function under a class
void BuildProFromSpecDialog::demoteToClassFunction() {
    QTreeWidgetItem* currentItem = treeWidget->currentItem();
    if (currentItem && currentItem->data(0, Qt::UserRole).toString() == "function") {
        QList<QTreeWidgetItem*> classItems = getClassItems();
        bool ok;
        QString className = QInputDialog::getItem(this, "Select Class", "Class:", classItems, 0, false, &ok);
        if (ok) {
            for (QTreeWidgetItem* classItem : classItems) {
                if (classItem->text(0) == className) {
                    currentItem->setIcon(0, QIcon(":/icons/function.png"));
                    classItem->addChild(currentItem);
                    break;
                }
            }
        }
    }
}

// Promote the selected item to a class root
void BuildProFromSpecDialog::promoteToClassRoot() {
    QTreeWidgetItem* currentItem = treeWidget->currentItem();
    if (currentItem && currentItem->data(0, Qt::UserRole).toString() == "function") {
        treeWidget->takeTopLevelItem(treeWidget->indexOfTopLevelItem(currentItem));
        currentItem->setIcon(0, QIcon(":/icons/class.png"));
        currentItem->setData(0, Qt::UserRole, "class");
        treeWidget->addTopLevelItem(currentItem);
    }
}

// Create a new class root
void BuildProFromSpecDialog::createNewClassRoot() {
    bool ok;
    QString className = QInputDialog::getText(this, "New Class", "Class Name:", QLineEdit::Normal, "", &ok);
    if (ok && !className.isEmpty()) {
        QTreeWidgetItem* newItem = new QTreeWidgetItem(treeWidget);
        newItem->setText(0, className);
        newItem->setIcon(0, QIcon(":/icons/class.png"));
        newItem->setData(0, Qt::UserRole, "class");
    }
}

// Rename the selected item
void BuildProFromSpecDialog::renameItem(QTreeWidgetItem* item, int column) {
    if (!originalList.contains(item->text(0))) {
        bool ok;
        QString newName = QInputDialog::getText(this, "Rename Item", "New Name:", QLineEdit::Normal, item->text(column), &ok);
        if (ok && !newName.isEmpty()) {
            item->setText(0, newName);
            QFont font = item->font(0);
            font.setBold(true);
            item->setFont(0, font);
        }
    }
}

// Get all class items from the tree
QList<QTreeWidgetItem*> BuildProFromSpecDialog::getClassItems() {
    QList<QTreeWidgetItem*> classItems;
    for (int i = 0; i < treeWidget->topLevelItemCount(); ++i) {
        QTreeWidgetItem* item = treeWidget->topLevelItem(i);
        if (item->data(0, Qt::UserRole).toString() == "class") {
            classItems.append(item);
        }
    }
    return classItems;
}

// OK button clicked
void BuildProFromSpecDialog::onOkClicked() {
    // Here you can return the modified tree structure
    // Example: emit a signal with the tree structure
    accept();
}

// Cancel button clicked
void BuildProFromSpecDialog::onCancelClicked() {
    reject();
}
