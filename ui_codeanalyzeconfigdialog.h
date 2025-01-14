/********************************************************************************
** Form generated from reading UI file 'codeanalyzeconfigdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CODEANALYZECONFIGDIALOG_H
#define UI_CODEANALYZECONFIGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CodeAnalyzeConfigDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *projectSelectBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *fileSelectBox;
    QFrame *line;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QComboBox *setSelectBox;
    QToolButton *manageButton;
    QTreeWidget *ruleTree;
    QFrame *line_2;
    QLabel *label_6;
    QCheckBox *checkBox;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_2;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_7;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout_7;
    QCheckBox *checkBox_4;
    QPushButton *pushButton_2;
    QFrame *line_3;
    QCheckBox *checkBox_5;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *startAnalysisButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *CodeAnalyzeConfigDialog)
    {
        if (CodeAnalyzeConfigDialog->objectName().isEmpty())
            CodeAnalyzeConfigDialog->setObjectName(QStringLiteral("CodeAnalyzeConfigDialog"));
        CodeAnalyzeConfigDialog->resize(800, 700);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CodeAnalyzeConfigDialog->sizePolicy().hasHeightForWidth());
        CodeAnalyzeConfigDialog->setSizePolicy(sizePolicy);
        CodeAnalyzeConfigDialog->setMinimumSize(QSize(800, 700));
        verticalLayout_2 = new QVBoxLayout(CodeAnalyzeConfigDialog);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_5 = new QLabel(CodeAnalyzeConfigDialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_5->setFont(font);

        verticalLayout->addWidget(label_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(CodeAnalyzeConfigDialog);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        projectSelectBox = new QComboBox(CodeAnalyzeConfigDialog);
        projectSelectBox->setObjectName(QStringLiteral("projectSelectBox"));

        horizontalLayout->addWidget(projectSelectBox);

        horizontalLayout->setStretch(0, 6);
        horizontalLayout->setStretch(1, 4);

        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(CodeAnalyzeConfigDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        fileSelectBox = new QComboBox(CodeAnalyzeConfigDialog);
        fileSelectBox->setObjectName(QStringLiteral("fileSelectBox"));

        horizontalLayout_2->addWidget(fileSelectBox);

        horizontalLayout_2->setStretch(0, 6);
        horizontalLayout_2->setStretch(1, 4);

        verticalLayout->addLayout(horizontalLayout_2);

        line = new QFrame(CodeAnalyzeConfigDialog);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        label_4 = new QLabel(CodeAnalyzeConfigDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        verticalLayout->addWidget(label_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(CodeAnalyzeConfigDialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        setSelectBox = new QComboBox(CodeAnalyzeConfigDialog);
        setSelectBox->setObjectName(QStringLiteral("setSelectBox"));

        horizontalLayout_3->addWidget(setSelectBox);

        manageButton = new QToolButton(CodeAnalyzeConfigDialog);
        manageButton->setObjectName(QStringLiteral("manageButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(manageButton->sizePolicy().hasHeightForWidth());
        manageButton->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(manageButton);

        horizontalLayout_3->setStretch(0, 6);
        horizontalLayout_3->setStretch(1, 2);
        horizontalLayout_3->setStretch(2, 2);

        verticalLayout->addLayout(horizontalLayout_3);

        ruleTree = new QTreeWidget(CodeAnalyzeConfigDialog);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(ruleTree);
        __qtreewidgetitem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsEnabled);
        __qtreewidgetitem->setCheckState(0, Qt::PartiallyChecked);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(__qtreewidgetitem);
        __qtreewidgetitem1->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsEnabled);
        __qtreewidgetitem1->setCheckState(0, Qt::Checked);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem(__qtreewidgetitem);
        __qtreewidgetitem2->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsEnabled);
        __qtreewidgetitem2->setCheckState(0, Qt::Unchecked);
        QTreeWidgetItem *__qtreewidgetitem3 = new QTreeWidgetItem(__qtreewidgetitem);
        __qtreewidgetitem3->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsEnabled);
        __qtreewidgetitem3->setCheckState(0, Qt::Checked);
        QTreeWidgetItem *__qtreewidgetitem4 = new QTreeWidgetItem(ruleTree);
        __qtreewidgetitem4->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsEnabled);
        __qtreewidgetitem4->setCheckState(0, Qt::PartiallyChecked);
        QTreeWidgetItem *__qtreewidgetitem5 = new QTreeWidgetItem(__qtreewidgetitem4);
        __qtreewidgetitem5->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsEnabled);
        __qtreewidgetitem5->setCheckState(0, Qt::Checked);
        QTreeWidgetItem *__qtreewidgetitem6 = new QTreeWidgetItem(__qtreewidgetitem4);
        __qtreewidgetitem6->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsEnabled);
        __qtreewidgetitem6->setCheckState(0, Qt::Unchecked);
        QTreeWidgetItem *__qtreewidgetitem7 = new QTreeWidgetItem(ruleTree);
        __qtreewidgetitem7->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsEnabled);
        __qtreewidgetitem7->setCheckState(0, Qt::PartiallyChecked);
        QTreeWidgetItem *__qtreewidgetitem8 = new QTreeWidgetItem(__qtreewidgetitem7);
        __qtreewidgetitem8->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsEnabled);
        __qtreewidgetitem8->setCheckState(0, Qt::Checked);
        QTreeWidgetItem *__qtreewidgetitem9 = new QTreeWidgetItem(__qtreewidgetitem7);
        __qtreewidgetitem9->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsEnabled);
        __qtreewidgetitem9->setCheckState(0, Qt::Unchecked);
        ruleTree->setObjectName(QStringLiteral("ruleTree"));

        verticalLayout->addWidget(ruleTree);


        verticalLayout_2->addLayout(verticalLayout);

        line_2 = new QFrame(CodeAnalyzeConfigDialog);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_2);

        label_6 = new QLabel(CodeAnalyzeConfigDialog);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);

        verticalLayout_2->addWidget(label_6);

        checkBox = new QCheckBox(CodeAnalyzeConfigDialog);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setChecked(true);

        verticalLayout_2->addWidget(checkBox);

        checkBox_3 = new QCheckBox(CodeAnalyzeConfigDialog);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));
        checkBox_3->setChecked(true);

        verticalLayout_2->addWidget(checkBox_3);

        checkBox_2 = new QCheckBox(CodeAnalyzeConfigDialog);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setChecked(true);

        verticalLayout_2->addWidget(checkBox_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_2 = new QSpacerItem(12, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        label_7 = new QLabel(CodeAnalyzeConfigDialog);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_5->addWidget(label_7);

        comboBox = new QComboBox(CodeAnalyzeConfigDialog);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy2);

        horizontalLayout_5->addWidget(comboBox);

        horizontalLayout_5->setStretch(0, 1);
        horizontalLayout_5->setStretch(1, 14);
        horizontalLayout_5->setStretch(2, 14);

        horizontalLayout_6->addLayout(horizontalLayout_5);

        pushButton = new QPushButton(CodeAnalyzeConfigDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);

        horizontalLayout_6->addWidget(pushButton);

        horizontalLayout_6->setStretch(0, 4);
        horizontalLayout_6->setStretch(1, 1);

        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        checkBox_4 = new QCheckBox(CodeAnalyzeConfigDialog);
        checkBox_4->setObjectName(QStringLiteral("checkBox_4"));
        checkBox_4->setChecked(true);

        horizontalLayout_7->addWidget(checkBox_4);

        pushButton_2 = new QPushButton(CodeAnalyzeConfigDialog);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        sizePolicy1.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy1);

        horizontalLayout_7->addWidget(pushButton_2);


        verticalLayout_2->addLayout(horizontalLayout_7);

        line_3 = new QFrame(CodeAnalyzeConfigDialog);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_3);

        checkBox_5 = new QCheckBox(CodeAnalyzeConfigDialog);
        checkBox_5->setObjectName(QStringLiteral("checkBox_5"));
        checkBox_5->setChecked(true);

        verticalLayout_2->addWidget(checkBox_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        startAnalysisButton = new QPushButton(CodeAnalyzeConfigDialog);
        startAnalysisButton->setObjectName(QStringLiteral("startAnalysisButton"));

        horizontalLayout_4->addWidget(startAnalysisButton);

        cancelButton = new QPushButton(CodeAnalyzeConfigDialog);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout_4->addWidget(cancelButton);


        verticalLayout_2->addLayout(horizontalLayout_4);


        retranslateUi(CodeAnalyzeConfigDialog);

        QMetaObject::connectSlotsByName(CodeAnalyzeConfigDialog);
    } // setupUi

    void retranslateUi(QDialog *CodeAnalyzeConfigDialog)
    {
        CodeAnalyzeConfigDialog->setWindowTitle(QApplication::translate("CodeAnalyzeConfigDialog", "SCM Configuration", 0));
        label_5->setText(QApplication::translate("CodeAnalyzeConfigDialog", "Choose the Target", 0));
        label->setText(QApplication::translate("CodeAnalyzeConfigDialog", "Choose a target project:", 0));
        projectSelectBox->clear();
        projectSelectBox->insertItems(0, QStringList()
         << QApplication::translate("CodeAnalyzeConfigDialog", "Current project", 0)
         << QApplication::translate("CodeAnalyzeConfigDialog", "Project1", 0)
         << QApplication::translate("CodeAnalyzeConfigDialog", "Project2", 0)
         << QApplication::translate("CodeAnalyzeConfigDialog", "Project3", 0)
         << QApplication::translate("CodeAnalyzeConfigDialog", "Project4", 0)
        );
        label_2->setText(QApplication::translate("CodeAnalyzeConfigDialog", "Choose target files:", 0));
        fileSelectBox->clear();
        fileSelectBox->insertItems(0, QStringList()
         << QApplication::translate("CodeAnalyzeConfigDialog", "All files", 0)
         << QApplication::translate("CodeAnalyzeConfigDialog", "file 1", 0)
         << QApplication::translate("CodeAnalyzeConfigDialog", "file 2", 0)
         << QApplication::translate("CodeAnalyzeConfigDialog", "file 3", 0)
        );
        label_4->setText(QApplication::translate("CodeAnalyzeConfigDialog", "Program Analysis Property Set Config", 0));
        label_3->setText(QApplication::translate("CodeAnalyzeConfigDialog", "Choose a property set:", 0));
        setSelectBox->clear();
        setSelectBox->insertItems(0, QStringList()
         << QApplication::translate("CodeAnalyzeConfigDialog", "Default property set", 0)
         << QApplication::translate("CodeAnalyzeConfigDialog", "Property set 1", 0)
         << QApplication::translate("CodeAnalyzeConfigDialog", "Property set 2", 0)
         << QApplication::translate("CodeAnalyzeConfigDialog", "Property set 3", 0)
        );
        manageButton->setText(QApplication::translate("CodeAnalyzeConfigDialog", "Manage...", 0));
        QTreeWidgetItem *___qtreewidgetitem = ruleTree->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("CodeAnalyzeConfigDialog", "Property Check Rules", 0));

        const bool __sortingEnabled = ruleTree->isSortingEnabled();
        ruleTree->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = ruleTree->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QApplication::translate("CodeAnalyzeConfigDialog", "NullPointerException", 0));
        QTreeWidgetItem *___qtreewidgetitem2 = ___qtreewidgetitem1->child(0);
        ___qtreewidgetitem2->setText(0, QApplication::translate("CodeAnalyzeConfigDialog", "rule 1", 0));
        QTreeWidgetItem *___qtreewidgetitem3 = ___qtreewidgetitem1->child(1);
        ___qtreewidgetitem3->setText(0, QApplication::translate("CodeAnalyzeConfigDialog", "rule 2", 0));
        QTreeWidgetItem *___qtreewidgetitem4 = ___qtreewidgetitem1->child(2);
        ___qtreewidgetitem4->setText(0, QApplication::translate("CodeAnalyzeConfigDialog", "rule 3", 0));
        QTreeWidgetItem *___qtreewidgetitem5 = ruleTree->topLevelItem(1);
        ___qtreewidgetitem5->setText(0, QApplication::translate("CodeAnalyzeConfigDialog", "IndexOutOfBoundsException", 0));
        QTreeWidgetItem *___qtreewidgetitem6 = ___qtreewidgetitem5->child(0);
        ___qtreewidgetitem6->setText(0, QApplication::translate("CodeAnalyzeConfigDialog", "113: Thrown to indicate that an index of some sort  such as to an array, to a string, or to a vector is out of range", 0));
        QTreeWidgetItem *___qtreewidgetitem7 = ___qtreewidgetitem5->child(1);
        ___qtreewidgetitem7->setText(0, QApplication::translate("CodeAnalyzeConfigDialog", "rule 5", 0));
        QTreeWidgetItem *___qtreewidgetitem8 = ruleTree->topLevelItem(2);
        ___qtreewidgetitem8->setText(0, QApplication::translate("CodeAnalyzeConfigDialog", "NumberFormatException", 0));
        QTreeWidgetItem *___qtreewidgetitem9 = ___qtreewidgetitem8->child(0);
        ___qtreewidgetitem9->setText(0, QApplication::translate("CodeAnalyzeConfigDialog", "rule 6", 0));
        QTreeWidgetItem *___qtreewidgetitem10 = ___qtreewidgetitem8->child(1);
        ___qtreewidgetitem10->setText(0, QApplication::translate("CodeAnalyzeConfigDialog", "rule 7", 0));
        ruleTree->setSortingEnabled(__sortingEnabled);

        label_6->setText(QApplication::translate("CodeAnalyzeConfigDialog", "Choose the Other Techniques", 0));
        checkBox->setText(QApplication::translate("CodeAnalyzeConfigDialog", "Automatic Test Generation", 0));
        checkBox_3->setText(QApplication::translate("CodeAnalyzeConfigDialog", "Automatic Testing", 0));
        checkBox_2->setText(QApplication::translate("CodeAnalyzeConfigDialog", "Check Requirements in the Target Specification", 0));
        label_7->setText(QApplication::translate("CodeAnalyzeConfigDialog", "Choose the target specification:", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("CodeAnalyzeConfigDialog", "Current Specification", 0)
         << QApplication::translate("CodeAnalyzeConfigDialog", "Specification 1", 0)
         << QApplication::translate("CodeAnalyzeConfigDialog", "Specification 2", 0)
        );
        pushButton->setText(QApplication::translate("CodeAnalyzeConfigDialog", "Manage Specification", 0));
        checkBox_4->setText(QApplication::translate("CodeAnalyzeConfigDialog", "Check the Style of Coding", 0));
        pushButton_2->setText(QApplication::translate("CodeAnalyzeConfigDialog", "Style of Code Configuration", 0));
        checkBox_5->setText(QApplication::translate("CodeAnalyzeConfigDialog", "Dynamicly Analyze the Code when programming", 0));
        startAnalysisButton->setText(QApplication::translate("CodeAnalyzeConfigDialog", "Apply", 0));
        cancelButton->setText(QApplication::translate("CodeAnalyzeConfigDialog", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class CodeAnalyzeConfigDialog: public Ui_CodeAnalyzeConfigDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CODEANALYZECONFIGDIALOG_H
