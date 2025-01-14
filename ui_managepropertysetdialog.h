/********************************************************************************
** Form generated from reading UI file 'managepropertysetdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGEPROPERTYSETDIALOG_H
#define UI_MANAGEPROPERTYSETDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ManagePropertySetDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *propertySetBox;
    QPushButton *createButton;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QTreeWidget *ruleTree;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *applyButton;
    QPushButton *closeButton;

    void setupUi(QDialog *ManagePropertySetDialog)
    {
        if (ManagePropertySetDialog->objectName().isEmpty())
            ManagePropertySetDialog->setObjectName(QStringLiteral("ManagePropertySetDialog"));
        ManagePropertySetDialog->resize(600, 700);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ManagePropertySetDialog->sizePolicy().hasHeightForWidth());
        ManagePropertySetDialog->setSizePolicy(sizePolicy);
        ManagePropertySetDialog->setMinimumSize(QSize(600, 700));
        verticalLayout_2 = new QVBoxLayout(ManagePropertySetDialog);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(ManagePropertySetDialog);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        propertySetBox = new QComboBox(ManagePropertySetDialog);
        propertySetBox->setObjectName(QStringLiteral("propertySetBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(propertySetBox->sizePolicy().hasHeightForWidth());
        propertySetBox->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(propertySetBox);


        horizontalLayout_2->addLayout(horizontalLayout);

        createButton = new QPushButton(ManagePropertySetDialog);
        createButton->setObjectName(QStringLiteral("createButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(createButton->sizePolicy().hasHeightForWidth());
        createButton->setSizePolicy(sizePolicy2);

        horizontalLayout_2->addWidget(createButton);

        horizontalLayout_2->setStretch(0, 5);
        horizontalLayout_2->setStretch(1, 1);

        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_2 = new QLabel(ManagePropertySetDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        ruleTree = new QTreeWidget(ManagePropertySetDialog);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(ruleTree);
        __qtreewidgetitem->setCheckState(0, Qt::PartiallyChecked);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(__qtreewidgetitem);
        __qtreewidgetitem1->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsTristate);
        __qtreewidgetitem1->setCheckState(0, Qt::Checked);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem(__qtreewidgetitem);
        __qtreewidgetitem2->setCheckState(0, Qt::Unchecked);
        QTreeWidgetItem *__qtreewidgetitem3 = new QTreeWidgetItem(__qtreewidgetitem);
        __qtreewidgetitem3->setCheckState(0, Qt::Checked);
        QTreeWidgetItem *__qtreewidgetitem4 = new QTreeWidgetItem(ruleTree);
        __qtreewidgetitem4->setCheckState(0, Qt::PartiallyChecked);
        QTreeWidgetItem *__qtreewidgetitem5 = new QTreeWidgetItem(__qtreewidgetitem4);
        __qtreewidgetitem5->setCheckState(0, Qt::Checked);
        QTreeWidgetItem *__qtreewidgetitem6 = new QTreeWidgetItem(__qtreewidgetitem4);
        __qtreewidgetitem6->setCheckState(0, Qt::Unchecked);
        QTreeWidgetItem *__qtreewidgetitem7 = new QTreeWidgetItem(ruleTree);
        __qtreewidgetitem7->setCheckState(0, Qt::PartiallyChecked);
        QTreeWidgetItem *__qtreewidgetitem8 = new QTreeWidgetItem(__qtreewidgetitem7);
        __qtreewidgetitem8->setCheckState(0, Qt::Checked);
        QTreeWidgetItem *__qtreewidgetitem9 = new QTreeWidgetItem(__qtreewidgetitem7);
        __qtreewidgetitem9->setCheckState(0, Qt::Unchecked);
        ruleTree->setObjectName(QStringLiteral("ruleTree"));

        verticalLayout->addWidget(ruleTree);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        applyButton = new QPushButton(ManagePropertySetDialog);
        applyButton->setObjectName(QStringLiteral("applyButton"));

        horizontalLayout_3->addWidget(applyButton);

        closeButton = new QPushButton(ManagePropertySetDialog);
        closeButton->setObjectName(QStringLiteral("closeButton"));

        horizontalLayout_3->addWidget(closeButton);


        verticalLayout_2->addLayout(horizontalLayout_3);


        retranslateUi(ManagePropertySetDialog);

        applyButton->setDefault(false);


        QMetaObject::connectSlotsByName(ManagePropertySetDialog);
    } // setupUi

    void retranslateUi(QDialog *ManagePropertySetDialog)
    {
        ManagePropertySetDialog->setWindowTitle(QApplication::translate("ManagePropertySetDialog", "Manage Property Sets", 0));
        label->setText(QApplication::translate("ManagePropertySetDialog", "Choose a property set:", 0));
        propertySetBox->clear();
        propertySetBox->insertItems(0, QStringList()
         << QApplication::translate("ManagePropertySetDialog", "Default property set", 0)
         << QApplication::translate("ManagePropertySetDialog", "rule set 1", 0)
         << QApplication::translate("ManagePropertySetDialog", "rule set 2", 0)
         << QApplication::translate("ManagePropertySetDialog", "rule set 3", 0)
        );
        createButton->setText(QApplication::translate("ManagePropertySetDialog", "Create...", 0));
        label_2->setText(QApplication::translate("ManagePropertySetDialog", "Manage the rules of the property set:", 0));
        QTreeWidgetItem *___qtreewidgetitem = ruleTree->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("ManagePropertySetDialog", "Property Rules", 0));

        const bool __sortingEnabled = ruleTree->isSortingEnabled();
        ruleTree->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = ruleTree->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QApplication::translate("ManagePropertySetDialog", "NullPointerException", 0));
        QTreeWidgetItem *___qtreewidgetitem2 = ___qtreewidgetitem1->child(0);
        ___qtreewidgetitem2->setText(0, QApplication::translate("ManagePropertySetDialog", "Rule 1", 0));
        QTreeWidgetItem *___qtreewidgetitem3 = ___qtreewidgetitem1->child(1);
        ___qtreewidgetitem3->setText(0, QApplication::translate("ManagePropertySetDialog", "Rule 2", 0));
        QTreeWidgetItem *___qtreewidgetitem4 = ___qtreewidgetitem1->child(2);
        ___qtreewidgetitem4->setText(0, QApplication::translate("ManagePropertySetDialog", "Rule 3", 0));
        QTreeWidgetItem *___qtreewidgetitem5 = ruleTree->topLevelItem(1);
        ___qtreewidgetitem5->setText(0, QApplication::translate("ManagePropertySetDialog", "IndexOutOfBoundsException", 0));
        QTreeWidgetItem *___qtreewidgetitem6 = ___qtreewidgetitem5->child(0);
        ___qtreewidgetitem6->setText(0, QApplication::translate("ManagePropertySetDialog", "Thrown to indicate that an index of some sort  such as to an array, to a string, or to a vector is out of range", 0));
        QTreeWidgetItem *___qtreewidgetitem7 = ___qtreewidgetitem5->child(1);
        ___qtreewidgetitem7->setText(0, QApplication::translate("ManagePropertySetDialog", "Rule 5", 0));
        QTreeWidgetItem *___qtreewidgetitem8 = ruleTree->topLevelItem(2);
        ___qtreewidgetitem8->setText(0, QApplication::translate("ManagePropertySetDialog", "NumberFormatException", 0));
        QTreeWidgetItem *___qtreewidgetitem9 = ___qtreewidgetitem8->child(0);
        ___qtreewidgetitem9->setText(0, QApplication::translate("ManagePropertySetDialog", "Rule 6", 0));
        QTreeWidgetItem *___qtreewidgetitem10 = ___qtreewidgetitem8->child(1);
        ___qtreewidgetitem10->setText(0, QApplication::translate("ManagePropertySetDialog", "Rule 7", 0));
        ruleTree->setSortingEnabled(__sortingEnabled);

        applyButton->setText(QApplication::translate("ManagePropertySetDialog", "Apply", 0));
        closeButton->setText(QApplication::translate("ManagePropertySetDialog", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class ManagePropertySetDialog: public Ui_ManagePropertySetDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGEPROPERTYSETDIALOG_H
