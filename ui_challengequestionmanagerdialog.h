/********************************************************************************
** Form generated from reading UI file 'challengequestionmanagerdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHALLENGEQUESTIONMANAGERDIALOG_H
#define UI_CHALLENGEQUESTIONMANAGERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_ChallengeQuestionManagerDialog
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEditQuestionList;
    QPushButton *buttonLoad;
    QPushButton *buttonSave;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QComboBox *comboBoxCategory;
    QPushButton *buttonAddQuestion;
    QPushButton *buttonRemoveQuestion;
    QListWidget *listWidgetQuestion;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *buttonApply;
    QPushButton *buttonClose;

    void setupUi(QDialog *ChallengeQuestionManagerDialog)
    {
        if (ChallengeQuestionManagerDialog->objectName().isEmpty())
            ChallengeQuestionManagerDialog->setObjectName(QStringLiteral("ChallengeQuestionManagerDialog"));
        ChallengeQuestionManagerDialog->resize(400, 300);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ChallengeQuestionManagerDialog->sizePolicy().hasHeightForWidth());
        ChallengeQuestionManagerDialog->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(ChallengeQuestionManagerDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(ChallengeQuestionManagerDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEditQuestionList = new QLineEdit(ChallengeQuestionManagerDialog);
        lineEditQuestionList->setObjectName(QStringLiteral("lineEditQuestionList"));

        horizontalLayout->addWidget(lineEditQuestionList);

        buttonLoad = new QPushButton(ChallengeQuestionManagerDialog);
        buttonLoad->setObjectName(QStringLiteral("buttonLoad"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(buttonLoad->sizePolicy().hasHeightForWidth());
        buttonLoad->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(buttonLoad);

        buttonSave = new QPushButton(ChallengeQuestionManagerDialog);
        buttonSave->setObjectName(QStringLiteral("buttonSave"));
        sizePolicy1.setHeightForWidth(buttonSave->sizePolicy().hasHeightForWidth());
        buttonSave->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(buttonSave);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(ChallengeQuestionManagerDialog);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        comboBoxCategory = new QComboBox(ChallengeQuestionManagerDialog);
        comboBoxCategory->setObjectName(QStringLiteral("comboBoxCategory"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(comboBoxCategory->sizePolicy().hasHeightForWidth());
        comboBoxCategory->setSizePolicy(sizePolicy2);

        horizontalLayout_2->addWidget(comboBoxCategory);

        buttonAddQuestion = new QPushButton(ChallengeQuestionManagerDialog);
        buttonAddQuestion->setObjectName(QStringLiteral("buttonAddQuestion"));

        horizontalLayout_2->addWidget(buttonAddQuestion);

        buttonRemoveQuestion = new QPushButton(ChallengeQuestionManagerDialog);
        buttonRemoveQuestion->setObjectName(QStringLiteral("buttonRemoveQuestion"));

        horizontalLayout_2->addWidget(buttonRemoveQuestion);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        listWidgetQuestion = new QListWidget(ChallengeQuestionManagerDialog);
        listWidgetQuestion->setObjectName(QStringLiteral("listWidgetQuestion"));
        listWidgetQuestion->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        listWidgetQuestion->setResizeMode(QListView::Fixed);

        gridLayout->addWidget(listWidgetQuestion, 2, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        buttonApply = new QPushButton(ChallengeQuestionManagerDialog);
        buttonApply->setObjectName(QStringLiteral("buttonApply"));

        horizontalLayout_3->addWidget(buttonApply);

        buttonClose = new QPushButton(ChallengeQuestionManagerDialog);
        buttonClose->setObjectName(QStringLiteral("buttonClose"));

        horizontalLayout_3->addWidget(buttonClose);


        gridLayout->addLayout(horizontalLayout_3, 3, 0, 1, 1);


        retranslateUi(ChallengeQuestionManagerDialog);

        QMetaObject::connectSlotsByName(ChallengeQuestionManagerDialog);
    } // setupUi

    void retranslateUi(QDialog *ChallengeQuestionManagerDialog)
    {
        ChallengeQuestionManagerDialog->setWindowTitle(QApplication::translate("ChallengeQuestionManagerDialog", "Dialog", 0));
        label_2->setText(QApplication::translate("ChallengeQuestionManagerDialog", "Current List:", 0));
        buttonLoad->setText(QApplication::translate("ChallengeQuestionManagerDialog", "Load", 0));
        buttonSave->setText(QApplication::translate("ChallengeQuestionManagerDialog", "Save", 0));
        label->setText(QApplication::translate("ChallengeQuestionManagerDialog", "Category:", 0));
        buttonAddQuestion->setText(QApplication::translate("ChallengeQuestionManagerDialog", "Add Question", 0));
        buttonRemoveQuestion->setText(QApplication::translate("ChallengeQuestionManagerDialog", "Remove Question", 0));
        buttonApply->setText(QApplication::translate("ChallengeQuestionManagerDialog", "Apple", 0));
        buttonClose->setText(QApplication::translate("ChallengeQuestionManagerDialog", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class ChallengeQuestionManagerDialog: public Ui_ChallengeQuestionManagerDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHALLENGEQUESTIONMANAGERDIALOG_H
