/********************************************************************************
** Form generated from reading UI file 'cscrtooldialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CSCRTOOLDIALOG_H
#define UI_CSCRTOOLDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_cscrtooldialog
{
public:
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QRadioButton *reviewButton;
    QRadioButton *loadButton;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QComboBox *methodComboBox;
    QSpacerItem *verticalSpacer_2;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit;
    QPushButton *loadFileButton;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *cscrtooldialog)
    {
        if (cscrtooldialog->objectName().isEmpty())
            cscrtooldialog->setObjectName(QStringLiteral("cscrtooldialog"));
        cscrtooldialog->resize(400, 300);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cscrtooldialog->sizePolicy().hasHeightForWidth());
        cscrtooldialog->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(cscrtooldialog);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        reviewButton = new QRadioButton(cscrtooldialog);
        reviewButton->setObjectName(QStringLiteral("reviewButton"));

        verticalLayout->addWidget(reviewButton);

        loadButton = new QRadioButton(cscrtooldialog);
        loadButton->setObjectName(QStringLiteral("loadButton"));

        verticalLayout->addWidget(loadButton);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 1);

        verticalLayout_3->addLayout(verticalLayout);

        stackedWidget = new QStackedWidget(cscrtooldialog);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        sizePolicy.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        verticalLayout_4 = new QVBoxLayout(page);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(page);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(page);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        methodComboBox = new QComboBox(page);
        methodComboBox->setObjectName(QStringLiteral("methodComboBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(methodComboBox->sizePolicy().hasHeightForWidth());
        methodComboBox->setSizePolicy(sizePolicy1);
        methodComboBox->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        horizontalLayout->addWidget(methodComboBox);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalLayout_2->setStretch(0, 2);
        verticalLayout_2->setStretch(1, 2);

        verticalLayout_4->addLayout(verticalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        verticalLayout_6 = new QVBoxLayout(page_2);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_3 = new QLabel(page_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_5->addWidget(label_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lineEdit = new QLineEdit(page_2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout_2->addWidget(lineEdit);

        loadFileButton = new QPushButton(page_2);
        loadFileButton->setObjectName(QStringLiteral("loadFileButton"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/toolbar_images/folder.png"), QSize(), QIcon::Normal, QIcon::Off);
        loadFileButton->setIcon(icon);

        horizontalLayout_2->addWidget(loadFileButton);


        verticalLayout_5->addLayout(horizontalLayout_2);

        verticalLayout_5->setStretch(0, 2);
        verticalLayout_5->setStretch(1, 2);

        verticalLayout_6->addLayout(verticalLayout_5);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer);

        stackedWidget->addWidget(page_2);

        verticalLayout_3->addWidget(stackedWidget);

        verticalLayout_3->setStretch(0, 1);
        verticalLayout_3->setStretch(1, 2);

        gridLayout_2->addLayout(verticalLayout_3, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(cscrtooldialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_2->addWidget(buttonBox, 1, 0, 1, 1);


        retranslateUi(cscrtooldialog);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(cscrtooldialog);
    } // setupUi

    void retranslateUi(QDialog *cscrtooldialog)
    {
        cscrtooldialog->setWindowTitle(QApplication::translate("cscrtooldialog", "Dialog", 0));
        reviewButton->setText(QApplication::translate("cscrtooldialog", "Review the method in the current file", 0));
        loadButton->setText(QApplication::translate("cscrtooldialog", "Load a bug report from a directory", 0));
        label->setText(QApplication::translate("cscrtooldialog", "Choose the method you would like to review in CSCR-Tool:", 0));
        label_2->setText(QApplication::translate("cscrtooldialog", "Target Method:", 0));
        label_3->setText(QApplication::translate("cscrtooldialog", "Load the bug report:", 0));
        loadFileButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class cscrtooldialog: public Ui_cscrtooldialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CSCRTOOLDIALOG_H
