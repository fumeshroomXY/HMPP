#include "requirementtreeview.h"
#include "syntaxrule.h"
#include <QMenu>
#include <QAction>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QInputDialog>
#include <QFileDialog>
#include <QFont>
#include <QMessageBox>
#include <QLabel>
#include "ui_cscrtooldialog.h"

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


    setWindowTitle("Build Class from Specification");
    setMinimumSize(600, 400);  // Example: Set minimum width to 600, height to 400
    // Tree widget setup
    treeWidget = new QTreeWidget(this);
    treeWidget->setColumnCount(1);
    treeWidget->setHeaderHidden(true);

    // Set size policies to ensure the tree widget expands
    treeWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    // Add root nodes from QHash and QStringList
    addItemsFromHash(hashValues);
    addItemsFromStringList(stringList);

    // Buttons
    QPushButton* btn1 = new QPushButton("Demote to Global Method", this);
    QPushButton* btn2 = new QPushButton("Demote to Class Method", this);
    QPushButton* btn3 = new QPushButton("Promote", this);
    QPushButton* btn4 = new QPushButton("New...", this);
    QPushButton* btn5 = new QPushButton("Delete", this);
    QPushButton* okButton = new QPushButton("OK", this);
    QPushButton* cancelButton = new QPushButton("Cancel", this);

    // Layout setup
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    QHBoxLayout* buttonLayout = new QHBoxLayout;
    QHBoxLayout* buttonLayout2 = new QHBoxLayout;
    buttonLayout->addWidget(btn1);
    buttonLayout->addWidget(btn2);
    buttonLayout->addWidget(btn3);
    buttonLayout->addWidget(btn4);
    buttonLayout->addWidget(btn5);
    buttonLayout2->addStretch();
    buttonLayout2->addWidget(okButton);
    buttonLayout2->addWidget(cancelButton);
    mainLayout->addWidget(treeWidget);
    mainLayout->addLayout(buttonLayout);
    mainLayout->addLayout(buttonLayout2);


    // Signals and Slots
    connect(btn1, &QPushButton::clicked, this, &BuildProFromSpecDialog::demoteToIndependentFunction);
    connect(btn2, &QPushButton::clicked, this, &BuildProFromSpecDialog::demoteToClassFunction);
    connect(btn3, &QPushButton::clicked, this, &BuildProFromSpecDialog::promoteToClass);
    connect(btn4, &QPushButton::clicked, this, &BuildProFromSpecDialog::createNewClass);
    connect(btn5, &QPushButton::clicked, this, &BuildProFromSpecDialog::deleteSelectedItem);
    connect(treeWidget, &QTreeWidget::itemDoubleClicked, this, &BuildProFromSpecDialog::renameItem);
    connect(okButton, &QPushButton::clicked, this, &BuildProFromSpecDialog::onOkClicked);
    connect(cancelButton, &QPushButton::clicked, this, &BuildProFromSpecDialog::onCancelClicked);
}

// Add items from QHash
void BuildProFromSpecDialog::addItemsFromHash(const QHash<QString, QString>& hashValues) {
    for (const QString& key : hashValues.keys()) {
        QTreeWidgetItem* classItem = new QTreeWidgetItem(treeWidget);
        classItem->setText(0, toUpperCamelCase(hashValues[key].left(hashValues[key].indexOf('\n'))));
        classItem->setIcon(0, QIcon(":/images/toolbar_images/class.svg"));
        classItem->setData(0, Qt::UserRole, classUserRole);
        classItem->setData(0, Qt::UserRole + 1, false);  // Mark as modifiable
    }
}

// Add items from QStringList
void BuildProFromSpecDialog::addItemsFromStringList(const QStringList& stringList) {
    existingClassList = stringList;
    for (const QString& str : stringList) {
        QTreeWidgetItem* funcItem = new QTreeWidgetItem(treeWidget);
        funcItem->setText(0, str);
        funcItem->setIcon(0, QIcon(":/images/toolbar_images/class.svg"));
        funcItem->setData(0, Qt::UserRole, classUserRole);
        funcItem->setData(0, Qt::UserRole + 1, true);  // Mark as non-modifiable (from QStringList)
    }
}

// Check if the item is from QStringList
bool BuildProFromSpecDialog::isItemFromExistingClassList(QTreeWidgetItem* item) {
    return item->data(0, Qt::UserRole + 1).toBool();
}

// Demote the selected item to a function root
void BuildProFromSpecDialog::demoteToIndependentFunction() {
    QTreeWidgetItem* currentItem = treeWidget->currentItem();
    if (!currentItem || isItemFromExistingClassList(currentItem)) {
        return;  // Do nothing if the item is from QStringList
    }
    if (currentItem->data(0, Qt::UserRole).toString() == classUserRole) {
        currentItem->setText(0, toLowerCamelCase(currentItem->text(0)));
        currentItem->setData(0, Qt::UserRole, globalFunctionUserRole);
        currentItem->setIcon(0, QIcon(":/images/toolbar_images/memberfunc.svg"));
    }else if(currentItem->data(0, Qt::UserRole).toString() == classFunctionUserRole){
        // Ensure the current item is removed from its current position if necessary
        QTreeWidgetItem* parentItem = currentItem->parent();
        if (parentItem) {
            parentItem->removeChild(currentItem);  // Remove it from its current parent
        } else {
            int index = treeWidget->indexOfTopLevelItem(currentItem);
            if (index != -1) {
                treeWidget->takeTopLevelItem(index);  // Remove from top-level if it is a root item
            }
        }
        currentItem->setIcon(0, QIcon(":/images/toolbar_images/memberfunc.svg"));
        currentItem->setData(0, Qt::UserRole, globalFunctionUserRole);
        treeWidget->addTopLevelItem(currentItem);
    }
    treeWidget->setCurrentItem(currentItem);
}

// Demote the selected item to a function under a class
void BuildProFromSpecDialog::demoteToClassFunction() {
    QTreeWidgetItem* currentItem = treeWidget->currentItem();
    if (!currentItem || isItemFromExistingClassList(currentItem)) {
        return;  // Do nothing if the item is from QStringList
    }

    QList<QTreeWidgetItem*> classItems = getClassItems();
    QStringList classItemTexts;

    // Loop through each QTreeWidgetItem and get its text
    for (QTreeWidgetItem* item : classItems) {
        classItemTexts.append(item->text(0));  // Assuming the text is in the first column
    }

    bool ok;
    QString className = QInputDialog::getItem(this, "Select Class", "Class:", classItemTexts, 0, false, &ok);
    if (ok) {
        for (QTreeWidgetItem* classItem : classItems) {
            if (currentItem->text(0) == className) break;
            if (classItem->text(0) == className) {

                // Ensure the current item is removed from its current position if necessary
                QTreeWidgetItem* parentItem = currentItem->parent();
                if (parentItem) {
                    parentItem->removeChild(currentItem);  // Remove it from its current parent
                } else {
                    int index = treeWidget->indexOfTopLevelItem(currentItem);
                    if (index != -1) {
                        treeWidget->takeTopLevelItem(index);  // Remove from top-level if it is a root item
                    }
                }
                currentItem->setText(0, toLowerCamelCase(currentItem->text(0)));
                currentItem->setIcon(0, QIcon(":/images/toolbar_images/memberfunc.svg"));
                currentItem->setData(0, Qt::UserRole, classFunctionUserRole);
                classItem->addChild(currentItem);
                break;
            }
        }
        treeWidget->setCurrentItem(currentItem);
    }

}

// Promote the selected item to a class root
void BuildProFromSpecDialog::promoteToClass() {
    QTreeWidgetItem* currentItem = treeWidget->currentItem();
    if (!currentItem || isItemFromExistingClassList(currentItem)) {
        return;  // Do nothing if the item is from QStringList
    }

    if (currentItem->data(0, Qt::UserRole).toString() != classUserRole) {
        // Ensure the current item is removed from its current position if necessary
        QTreeWidgetItem* parentItem = currentItem->parent();
        if (parentItem) {
            parentItem->removeChild(currentItem);  // Remove it from its current parent
            currentItem->setText(0, toUpperCamelCase(currentItem->text(0)));
            currentItem->setIcon(0, QIcon(":/images/toolbar_images/class.svg"));
            currentItem->setData(0, Qt::UserRole, classUserRole);
            treeWidget->addTopLevelItem(currentItem);
        } else {
            int index = treeWidget->indexOfTopLevelItem(currentItem);
            if (index != -1) {
                currentItem->setText(0, toUpperCamelCase(currentItem->text(0)));
                currentItem->setIcon(0, QIcon(":/images/toolbar_images/class.svg"));
                currentItem->setData(0, Qt::UserRole, classUserRole);
            }
        }
    }
    treeWidget->setCurrentItem(currentItem);
}

// Create a new class root
void BuildProFromSpecDialog::createNewClass() {
    bool ok;
    QString className = QInputDialog::getText(this, "New Class", "Class Name:", QLineEdit::Normal, "", &ok);
    if (ok && !className.isEmpty()) {
        QTreeWidgetItem* newItem = new QTreeWidgetItem(treeWidget);
        newItem->setText(0, className);
        newItem->setIcon(0, QIcon(":/images/toolbar_images/class.svg"));
        newItem->setData(0, Qt::UserRole, classUserRole);
        newItem->setData(0, Qt::UserRole + 1, false);  // Mark as modifiable
        treeWidget->setCurrentItem(newItem);
    }
}

// Rename the selected item
void BuildProFromSpecDialog::renameItem(QTreeWidgetItem* item, int column) {
    if (!item || isItemFromExistingClassList(item)) {
        return;  // Do nothing if the item is from QStringList
    }

    bool ok;
    QString newName = QInputDialog::getText(this, "Rename Item", "New Name:", QLineEdit::Normal, item->text(column), &ok);
    if (ok && !newName.isEmpty()) {
        item->setText(0, newName);
        QFont font = item->font(0);
        //font.setBold(true);
        item->setFont(0, font);
        treeWidget->setCurrentItem(item);
    }
}

void BuildProFromSpecDialog::deleteSelectedItem() {
    QTreeWidgetItem* selectedItem = treeWidget->currentItem();
    if (!selectedItem) {
        QMessageBox::information(this, "No Selection", "Please select an item to delete.");
        return;
    }

    QTreeWidgetItem* parentItem = selectedItem->parent();
    if (parentItem) {
        // If the item has a parent, remove it from its parent
        parentItem->removeChild(selectedItem);
    } else {
        // If the item is a top-level item, remove it from the tree widget
        int index = treeWidget->indexOfTopLevelItem(selectedItem);
        if (index != -1) {
            treeWidget->takeTopLevelItem(index);
        }
    }

    // Delete the selected item and its children
    delete selectedItem;  // Deleting the item automatically deletes all its children
}

// Get all class items from the tree
QList<QTreeWidgetItem*> BuildProFromSpecDialog::getClassItems() {
    QList<QTreeWidgetItem*> classItems;
    for (int i = 0; i < treeWidget->topLevelItemCount(); ++i) {
        QTreeWidgetItem* item = treeWidget->topLevelItem(i);
        if (item->data(0, Qt::UserRole).toString() == classUserRole) {
            classItems.append(item);
        }
    }
    return classItems;
}

// Collect the tree structure as a QList of QHash values
QList<ClassInfo> BuildProFromSpecDialog::getClassStructure() {
    QList<ClassInfo> treeStructure;
    for (int i = 0; i < treeWidget->topLevelItemCount(); ++i) {
        QTreeWidgetItem* item = treeWidget->topLevelItem(i);
        if(item->data(0, Qt::UserRole + 1).toBool() == true) continue;
        if(item->data(0, Qt::UserRole).toString() == classUserRole){
            ClassInfo info(item->text(0));
            for (int i = 0; i < item->childCount(); ++i) {
                QTreeWidgetItem* child = item->child(i);
                Method m(child->text(0), item->text(0));
                info.methods->append(m);
            }
            treeStructure.append(info);
        }else if (item->data(0, Qt::UserRole).toString() == globalFunctionUserRole){
            //independent function to do:
        }
    }
    return treeStructure;
}

// OK button clicked
void BuildProFromSpecDialog::onOkClicked() {
    // Here you can return the modified tree structure
    // Example: emit a signal with the tree structure
    QList<ClassInfo> treeStructure = getClassStructure();
    emit treeStructureReady(treeStructure);  // Emit the tree structure to the caller
    accept();
}

// Cancel button clicked
void BuildProFromSpecDialog::onCancelClicked() {
    reject();
}

SameNameMethodHandleDialog::SameNameMethodHandleDialog(const QStringList& oldMethodList,
                                                       const QStringList& newMethodList,
                                                       QWidget* parent)
    : QDialog(parent) {
    setWindowTitle("Handle the methods with the same name");

    // Create UI components
    QLabel* lblOriginalMethods = new QLabel("The original methods are as follows:", this);
    listA = new QListWidget(this);
    QLabel* lblNewMethod = new QLabel("The new method is:", this);
    listB = new QListWidget(this);

    QPushButton* btnReplace = new QPushButton("Replace", this);
    QPushButton* btnAddNew = new QPushButton("Add New", this);
    QPushButton* btnCancel = new QPushButton("Cancel", this);

    // Layout setup
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    QHBoxLayout* buttonLayout = new QHBoxLayout;

    // Add components to layout
    mainLayout->addWidget(lblOriginalMethods);
    mainLayout->addWidget(listA);
    mainLayout->addWidget(lblNewMethod);
    mainLayout->addWidget(listB);

    buttonLayout->addWidget(btnReplace);
    buttonLayout->addWidget(btnAddNew);
    buttonLayout->addWidget(btnCancel);

    mainLayout->addLayout(buttonLayout);

    // Populate lists with provided data
    listA->addItems(oldMethodList);
    listB->addItems(newMethodList);

    // Connect signals to slots
    connect(btnReplace, &QPushButton::clicked, this, &SameNameMethodHandleDialog::onReplaceClicked);
    connect(btnAddNew, &QPushButton::clicked, this, &SameNameMethodHandleDialog::onAddNewClicked);
    connect(btnCancel, &QPushButton::clicked, this, &SameNameMethodHandleDialog::onCancelClicked);
}

SameNameMethodHandleDialog::DialogResult SameNameMethodHandleDialog::getResult() const {
    return resultData;
}

void SameNameMethodHandleDialog::onReplaceClicked() {
    saveResult("Replace");
    accept();
}

void SameNameMethodHandleDialog::onAddNewClicked() {
    saveResult("Add New");
    accept();
}

void SameNameMethodHandleDialog::onCancelClicked() {
    saveResult("Cancel");
    reject();
}

void SameNameMethodHandleDialog::saveResult(const QString& buttonClicked) {
    resultData.buttonClicked = buttonClicked;
    resultData.indexA = listA->currentRow() < 0 ? 0 : listA->currentRow();
    resultData.indexB = listB->currentRow() < 0 ? 0 : listB->currentRow();
}

CscrToolDialog::CscrToolDialog(QWidget *parent, const QList<QString> & methods)
    : QDialog(parent),
      ui(new Ui::cscrtooldialog),  // Initialize with the lowercase UI class name
      buttonGroup(new QButtonGroup(this))  // Initialize the QButtonGroup
{
    ui->setupUi(this);  // Link the UI to the dialog
    ui->stackedWidget->setCurrentIndex(0);
    // Add radio buttons to the button group
    buttonGroup->addButton(ui->reviewButton, 1);  // ID = 1
    buttonGroup->addButton(ui->loadButton, 2);  // ID = 2
    ui->reviewButton->setChecked(true); // Set default selection

    ui->methodComboBox->addItems(methods);

    // Connect the button group signal to the slot
    connect(buttonGroup, SIGNAL(buttonClicked(int)), this, SLOT(handleOptionChanged(int)));

    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &CscrToolDialog::onOkClicked);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);

    //QString filePath;  // Variable to hold the file path

    // Connect the button to the lambda and pass filePath as reference
    connect(ui->loadFileButton, &QPushButton::clicked, [this]() {
        QString selectedFilePath = QFileDialog::getOpenFileName(
            this,
            tr("Select a Bug Report File"),
            QString(),
            tr("Text Files (*.txt)")
        );
        ui->lineEdit->setText(selectedFilePath);

        if (!selectedFilePath.isEmpty()) {
            this->bugReportFilePath = selectedFilePath;
            qDebug() << "Selected file path:" << selectedFilePath;
        } else {
            qDebug() << "No file selected.";
        }
    });
}

CscrToolDialog::~CscrToolDialog()
{
    delete ui;  // Clean up the UI
}

void CscrToolDialog::onOkClicked()
{
    if (ui->loadButton->isChecked()) {
        emit loadBugReportFile(bugReportFilePath);
    } else if (ui->reviewButton->isChecked()) {
        emit reviewMethod(ui->methodComboBox->currentText());
    }
    accept();
}

void CscrToolDialog::handleOptionChanged(int id)
{
    if (id == 1) {
        ui->stackedWidget->show();
        ui->stackedWidget->setCurrentIndex(0);
    } else if (id == 2) {
        ui->stackedWidget->show();
        ui->stackedWidget->setCurrentIndex(1);
    }
}
