/********************************************************************************
** Form generated from reading UI file 'selectnewclassdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTNEWCLASSDIALOG_H
#define UI_SELECTNEWCLASSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SelectNewClassDialog
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QListWidget *newListWidget;
    QLabel *label_2;
    QListWidget *preListWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okButton;

    void setupUi(QDialog *SelectNewClassDialog)
    {
        if (SelectNewClassDialog->objectName().isEmpty())
            SelectNewClassDialog->setObjectName(QStringLiteral("SelectNewClassDialog"));
        SelectNewClassDialog->resize(400, 300);
        gridLayout = new QGridLayout(SelectNewClassDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(SelectNewClassDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setWordWrap(true);

        verticalLayout->addWidget(label);

        newListWidget = new QListWidget(SelectNewClassDialog);
        newListWidget->setObjectName(QStringLiteral("newListWidget"));

        verticalLayout->addWidget(newListWidget);

        label_2 = new QLabel(SelectNewClassDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        preListWidget = new QListWidget(SelectNewClassDialog);
        preListWidget->setObjectName(QStringLiteral("preListWidget"));

        verticalLayout->addWidget(preListWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okButton = new QPushButton(SelectNewClassDialog);
        okButton->setObjectName(QStringLiteral("okButton"));

        horizontalLayout->addWidget(okButton);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(SelectNewClassDialog);

        QMetaObject::connectSlotsByName(SelectNewClassDialog);
    } // setupUi

    void retranslateUi(QDialog *SelectNewClassDialog)
    {
        SelectNewClassDialog->setWindowTitle(QApplication::translate("SelectNewClassDialog", "Select Classes You Have Defined", 0));
        label->setText(QApplication::translate("SelectNewClassDialog", "The tool has found the following new classes. Please check the class you want to define to generate class files.", 0));
        label_2->setText(QApplication::translate("SelectNewClassDialog", "These classes are defined in the #include files:", 0));
        okButton->setText(QApplication::translate("SelectNewClassDialog", "OK", 0));
    } // retranslateUi

};

namespace Ui {
    class SelectNewClassDialog: public Ui_SelectNewClassDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTNEWCLASSDIALOG_H
