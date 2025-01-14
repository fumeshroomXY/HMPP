/********************************************************************************
** Form generated from reading UI file 'allruledescriptdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALLRULEDESCRIPTDIALOG_H
#define UI_ALLRULEDESCRIPTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AllRuleDescriptDialog
{
public:
    QAction *actionTest;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *comboBox_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_2;
    QTableWidget *tableWidget;
    QTreeWidget *treeWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;

    void setupUi(QDialog *AllRuleDescriptDialog)
    {
        if (AllRuleDescriptDialog->objectName().isEmpty())
            AllRuleDescriptDialog->setObjectName(QStringLiteral("AllRuleDescriptDialog"));
        AllRuleDescriptDialog->resize(800, 700);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AllRuleDescriptDialog->sizePolicy().hasHeightForWidth());
        AllRuleDescriptDialog->setSizePolicy(sizePolicy);
        AllRuleDescriptDialog->setMinimumSize(QSize(800, 700));
        actionTest = new QAction(AllRuleDescriptDialog);
        actionTest->setObjectName(QStringLiteral("actionTest"));
        verticalLayout_3 = new QVBoxLayout(AllRuleDescriptDialog);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetMinimumSize);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(AllRuleDescriptDialog);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(AllRuleDescriptDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(AllRuleDescriptDialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);


        horizontalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        lineEdit = new QLineEdit(AllRuleDescriptDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        verticalLayout_2->addWidget(lineEdit);

        comboBox = new QComboBox(AllRuleDescriptDialog);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setContextMenuPolicy(Qt::DefaultContextMenu);

        verticalLayout_2->addWidget(comboBox);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        comboBox_2 = new QComboBox(AllRuleDescriptDialog);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboBox_2->sizePolicy().hasHeightForWidth());
        comboBox_2->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(comboBox_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        pushButton_2 = new QPushButton(AllRuleDescriptDialog);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy2);

        horizontalLayout_2->addWidget(pushButton_2);


        verticalLayout_2->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_3);

        tableWidget = new QTableWidget(AllRuleDescriptDialog);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        if (tableWidget->rowCount() < 8)
            tableWidget->setRowCount(8);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(6, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(7, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        __qtablewidgetitem12->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 0, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        __qtablewidgetitem13->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 1, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        __qtablewidgetitem14->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(0, 2, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget->setItem(0, 3, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        __qtablewidgetitem16->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(1, 2, __qtablewidgetitem16);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setDragEnabled(false);
        tableWidget->setAlternatingRowColors(true);
        tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(true);
        tableWidget->horizontalHeader()->setStretchLastSection(true);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setCascadingSectionResizes(false);
        tableWidget->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget->verticalHeader()->setStretchLastSection(false);

        verticalLayout_3->addWidget(tableWidget);

        treeWidget = new QTreeWidget(AllRuleDescriptDialog);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(treeWidget);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(treeWidget);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem(treeWidget);
        new QTreeWidgetItem(__qtreewidgetitem2);
        new QTreeWidgetItem(__qtreewidgetitem2);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));

        verticalLayout_3->addWidget(treeWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(AllRuleDescriptDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout_3->addLayout(horizontalLayout);

        verticalLayout_3->setStretch(1, 1);
        verticalLayout_3->setStretch(2, 3);

        retranslateUi(AllRuleDescriptDialog);

        comboBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(AllRuleDescriptDialog);
    } // setupUi

    void retranslateUi(QDialog *AllRuleDescriptDialog)
    {
        AllRuleDescriptDialog->setWindowTitle(QApplication::translate("AllRuleDescriptDialog", "Property Rule Description", 0));
        actionTest->setText(QApplication::translate("AllRuleDescriptDialog", "test", 0));
        label->setText(QApplication::translate("AllRuleDescriptDialog", "Keyword:", 0));
        label_2->setText(QApplication::translate("AllRuleDescriptDialog", "Fault type:", 0));
        label_3->setText(QApplication::translate("AllRuleDescriptDialog", "Severity:", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("AllRuleDescriptDialog", "All type", 0)
         << QApplication::translate("AllRuleDescriptDialog", "NullPointerException", 0)
         << QApplication::translate("AllRuleDescriptDialog", "IndexOutOfBoundsException", 0)
         << QApplication::translate("AllRuleDescriptDialog", "NumberFormatException", 0)
        );
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("AllRuleDescriptDialog", "All type", 0)
         << QApplication::translate("AllRuleDescriptDialog", "Critical", 0)
         << QApplication::translate("AllRuleDescriptDialog", "Warning", 0)
         << QApplication::translate("AllRuleDescriptDialog", "Fatal", 0)
        );
        pushButton_2->setText(QApplication::translate("AllRuleDescriptDialog", "Search", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("AllRuleDescriptDialog", "Code", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("AllRuleDescriptDialog", "Fault type", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("AllRuleDescriptDialog", "Severity", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("AllRuleDescriptDialog", "Rule Keyword", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem4->setText(QApplication::translate("AllRuleDescriptDialog", "1", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem5->setText(QApplication::translate("AllRuleDescriptDialog", "2", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem6->setText(QApplication::translate("AllRuleDescriptDialog", "3", 0));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem7->setText(QApplication::translate("AllRuleDescriptDialog", "4", 0));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem8->setText(QApplication::translate("AllRuleDescriptDialog", "5", 0));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->verticalHeaderItem(5);
        ___qtablewidgetitem9->setText(QApplication::translate("AllRuleDescriptDialog", "6", 0));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->verticalHeaderItem(6);
        ___qtablewidgetitem10->setText(QApplication::translate("AllRuleDescriptDialog", "7", 0));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->verticalHeaderItem(7);
        ___qtablewidgetitem11->setText(QApplication::translate("AllRuleDescriptDialog", "8", 0));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->item(0, 0);
        ___qtablewidgetitem12->setText(QApplication::translate("AllRuleDescriptDialog", "113", 0));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->item(0, 1);
        ___qtablewidgetitem13->setText(QApplication::translate("AllRuleDescriptDialog", "IndexOutOfBoundsException", 0));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->item(0, 2);
        ___qtablewidgetitem14->setText(QApplication::translate("AllRuleDescriptDialog", "Critical", 0));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->item(0, 3);
        ___qtablewidgetitem15->setText(QApplication::translate("AllRuleDescriptDialog", "Thrown to indicate that an index of some sort  such as to an array, to a string, or to a vector is out of range", 0));
        tableWidget->setSortingEnabled(__sortingEnabled);

        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("AllRuleDescriptDialog", "Property Rules", 0));

        const bool __sortingEnabled1 = treeWidget->isSortingEnabled();
        treeWidget->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidget->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QApplication::translate("AllRuleDescriptDialog", "NullPointerException", 0));
        QTreeWidgetItem *___qtreewidgetitem2 = ___qtreewidgetitem1->child(0);
        ___qtreewidgetitem2->setText(0, QApplication::translate("AllRuleDescriptDialog", "Rule 1", 0));
        QTreeWidgetItem *___qtreewidgetitem3 = ___qtreewidgetitem1->child(1);
        ___qtreewidgetitem3->setText(0, QApplication::translate("AllRuleDescriptDialog", "Rule 2", 0));
        QTreeWidgetItem *___qtreewidgetitem4 = ___qtreewidgetitem1->child(2);
        ___qtreewidgetitem4->setText(0, QApplication::translate("AllRuleDescriptDialog", "Rule 3", 0));
        QTreeWidgetItem *___qtreewidgetitem5 = treeWidget->topLevelItem(1);
        ___qtreewidgetitem5->setText(0, QApplication::translate("AllRuleDescriptDialog", "IndexOutOfBoundsException", 0));
        QTreeWidgetItem *___qtreewidgetitem6 = ___qtreewidgetitem5->child(0);
        ___qtreewidgetitem6->setText(0, QApplication::translate("AllRuleDescriptDialog", "113: Thrown to indicate that an index of some sort  such as to an array, to a string, or to a vector is out of range", 0));
        QTreeWidgetItem *___qtreewidgetitem7 = ___qtreewidgetitem5->child(1);
        ___qtreewidgetitem7->setText(0, QApplication::translate("AllRuleDescriptDialog", "Rule 5", 0));
        QTreeWidgetItem *___qtreewidgetitem8 = treeWidget->topLevelItem(2);
        ___qtreewidgetitem8->setText(0, QApplication::translate("AllRuleDescriptDialog", "NumberFormatException", 0));
        QTreeWidgetItem *___qtreewidgetitem9 = ___qtreewidgetitem8->child(0);
        ___qtreewidgetitem9->setText(0, QApplication::translate("AllRuleDescriptDialog", "Rule 6", 0));
        QTreeWidgetItem *___qtreewidgetitem10 = ___qtreewidgetitem8->child(1);
        ___qtreewidgetitem10->setText(0, QApplication::translate("AllRuleDescriptDialog", "Rule 7", 0));
        treeWidget->setSortingEnabled(__sortingEnabled1);

        pushButton->setText(QApplication::translate("AllRuleDescriptDialog", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class AllRuleDescriptDialog: public Ui_AllRuleDescriptDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALLRULEDESCRIPTDIALOG_H
