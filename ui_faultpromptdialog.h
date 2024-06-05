/********************************************************************************
** Form generated from reading UI file 'faultpromptdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FAULTPROMPTDIALOG_H
#define UI_FAULTPROMPTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_FaultPromptDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTextBrowser *textBrowser;
    QHBoxLayout *horizontalLayout;
    QPushButton *detailButton;
    QPushButton *fixButton;
    QPushButton *unfixButton;
    QPushButton *deactivateButton;
    QPushButton *okButton;

    void setupUi(QDialog *FaultPromptDialog)
    {
        if (FaultPromptDialog->objectName().isEmpty())
            FaultPromptDialog->setObjectName(QStringLiteral("FaultPromptDialog"));
        FaultPromptDialog->resize(400, 134);
        FaultPromptDialog->setContextMenuPolicy(Qt::DefaultContextMenu);
        FaultPromptDialog->setWindowOpacity(1);
        verticalLayout = new QVBoxLayout(FaultPromptDialog);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(FaultPromptDialog);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setFrameShape(QFrame::StyledPanel);

        verticalLayout->addWidget(label);

        textBrowser = new QTextBrowser(FaultPromptDialog);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setFrameShape(QFrame::StyledPanel);
        textBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textBrowser->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textBrowser->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);

        verticalLayout->addWidget(textBrowser);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        detailButton = new QPushButton(FaultPromptDialog);
        detailButton->setObjectName(QStringLiteral("detailButton"));

        horizontalLayout->addWidget(detailButton);

        fixButton = new QPushButton(FaultPromptDialog);
        fixButton->setObjectName(QStringLiteral("fixButton"));

        horizontalLayout->addWidget(fixButton);

        unfixButton = new QPushButton(FaultPromptDialog);
        unfixButton->setObjectName(QStringLiteral("unfixButton"));

        horizontalLayout->addWidget(unfixButton);

        deactivateButton = new QPushButton(FaultPromptDialog);
        deactivateButton->setObjectName(QStringLiteral("deactivateButton"));

        horizontalLayout->addWidget(deactivateButton);

        okButton = new QPushButton(FaultPromptDialog);
        okButton->setObjectName(QStringLiteral("okButton"));

        horizontalLayout->addWidget(okButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(FaultPromptDialog);

        QMetaObject::connectSlotsByName(FaultPromptDialog);
    } // setupUi

    void retranslateUi(QDialog *FaultPromptDialog)
    {
        FaultPromptDialog->setWindowTitle(QString());
        label->setText(QApplication::translate("FaultPromptDialog", "Divide By Zero Exception", 0));
        textBrowser->setHtml(QApplication::translate("FaultPromptDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Trying to divide an integer or Decimal number by zero throws a DivideByZeroException exception. (113)</p></body></html>", 0));
        detailButton->setText(QApplication::translate("FaultPromptDialog", "View detail", 0));
        fixButton->setText(QApplication::translate("FaultPromptDialog", "Quick fix", 0));
        unfixButton->setText(QApplication::translate("FaultPromptDialog", "Undo fix", 0));
        deactivateButton->setText(QApplication::translate("FaultPromptDialog", "Deactivate", 0));
        okButton->setText(QApplication::translate("FaultPromptDialog", "OK", 0));
    } // retranslateUi

};

namespace Ui {
    class FaultPromptDialog: public Ui_FaultPromptDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FAULTPROMPTDIALOG_H
