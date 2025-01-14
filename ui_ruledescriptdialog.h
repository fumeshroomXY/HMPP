/********************************************************************************
** Form generated from reading UI file 'ruledescriptdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RULEDESCRIPTDIALOG_H
#define UI_RULEDESCRIPTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RuleDescriptDialog
{
public:
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QLabel *labelHeader;
    QLabel *labelRating;
    QTabWidget *tabWidget;
    QWidget *tabDescription;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_2;
    QTextBrowser *textBrowser_2;
    QTextEdit *textEdit_2;
    QWidget *tabFix;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QTextBrowser *textBrowser_3;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton;

    void setupUi(QDialog *RuleDescriptDialog)
    {
        if (RuleDescriptDialog->objectName().isEmpty())
            RuleDescriptDialog->setObjectName(QStringLiteral("RuleDescriptDialog"));
        RuleDescriptDialog->resize(600, 700);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(RuleDescriptDialog->sizePolicy().hasHeightForWidth());
        RuleDescriptDialog->setSizePolicy(sizePolicy);
        RuleDescriptDialog->setMinimumSize(QSize(600, 700));
        verticalLayout_4 = new QVBoxLayout(RuleDescriptDialog);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        labelHeader = new QLabel(RuleDescriptDialog);
        labelHeader->setObjectName(QStringLiteral("labelHeader"));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(17);
        font.setBold(true);
        font.setWeight(75);
        labelHeader->setFont(font);
        labelHeader->setWordWrap(true);

        verticalLayout_3->addWidget(labelHeader);

        labelRating = new QLabel(RuleDescriptDialog);
        labelRating->setObjectName(QStringLiteral("labelRating"));
        QFont font1;
        font1.setPointSize(13);
        font1.setBold(true);
        font1.setWeight(75);
        labelRating->setFont(font1);
        labelRating->setTextFormat(Qt::AutoText);
        labelRating->setScaledContents(false);

        verticalLayout_3->addWidget(labelRating);

        tabWidget = new QTabWidget(RuleDescriptDialog);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabDescription = new QWidget();
        tabDescription->setObjectName(QStringLiteral("tabDescription"));
        gridLayout_2 = new QGridLayout(tabDescription);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        textBrowser_2 = new QTextBrowser(tabDescription);
        textBrowser_2->setObjectName(QStringLiteral("textBrowser_2"));
        textBrowser_2->setContextMenuPolicy(Qt::DefaultContextMenu);
        textBrowser_2->setAutoFillBackground(false);
        textBrowser_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textBrowser_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        textBrowser_2->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);

        verticalLayout_2->addWidget(textBrowser_2);

        textEdit_2 = new QTextEdit(tabDescription);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));

        verticalLayout_2->addWidget(textEdit_2);


        gridLayout_2->addLayout(verticalLayout_2, 0, 0, 1, 1);

        tabWidget->addTab(tabDescription, QString());
        tabFix = new QWidget();
        tabFix->setObjectName(QStringLiteral("tabFix"));
        gridLayout = new QGridLayout(tabFix);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        textBrowser_3 = new QTextBrowser(tabFix);
        textBrowser_3->setObjectName(QStringLiteral("textBrowser_3"));
        textBrowser_3->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textBrowser_3->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textBrowser_3->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);

        verticalLayout->addWidget(textBrowser_3);

        textEdit = new QTextEdit(tabFix);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setReadOnly(true);

        verticalLayout->addWidget(textEdit);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        tabWidget->addTab(tabFix, QString());

        verticalLayout_3->addWidget(tabWidget);

        verticalLayout_3->setStretch(1, 1);
        verticalLayout_3->setStretch(2, 15);

        verticalLayout_4->addLayout(verticalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_2 = new QPushButton(RuleDescriptDialog);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(RuleDescriptDialog);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);

        pushButton = new QPushButton(RuleDescriptDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout_4->addLayout(horizontalLayout);


        retranslateUi(RuleDescriptDialog);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(RuleDescriptDialog);
    } // setupUi

    void retranslateUi(QDialog *RuleDescriptDialog)
    {
        RuleDescriptDialog->setWindowTitle(QApplication::translate("RuleDescriptDialog", "Property Rule Description", 0));
        labelHeader->setText(QApplication::translate("RuleDescriptDialog", "Trying to divide an integer or Decimal number by zero throws a DivideByZeroException exception. (113)", 0));
        labelRating->setText(QApplication::translate("RuleDescriptDialog", "Severity|Fault Type", 0));
        textBrowser_2->setHtml(QApplication::translate("RuleDescriptDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Segoe UI,SegoeUI,Helvetica Neue,Helvetica,Arial,sans-serif'; font-size:12pt; color:#161616; background-color:#ffffff;\">Trying to divide an integer or</span><span style=\" font-family:'Segoe UI,SegoeUI,Helvetica Neue,Helvetica,Arial,sans-serif'; font-size:12pt; color:#161616;\">\302\240</span><a href=\"https://learn.microsoft.com/en-us/dotnet/api/system.decimal?view=net-8.0\"><span style=\" font-family:'Segoe UI,SegoeUI,Helvetica Neue,Helvetica,Arial,sans-serif'; font-size:12pt; text-decoration: underline; color:#000000; background-color"
                        ":transparent;\">Decimal</span></a><span style=\" font-family:'Segoe UI,SegoeUI,Helvetica Neue,Helvetica,Arial,sans-serif'; font-size:12pt; color:#161616;\">\302\240number by zero throws a\302\240</span><a href=\"https://learn.microsoft.com/en-us/dotnet/api/system.dividebyzeroexception?view=net-8.0\"><span style=\" font-family:'Segoe UI,SegoeUI,Helvetica Neue,Helvetica,Arial,sans-serif'; font-size:12pt; text-decoration: underline; color:#000000; background-color:transparent;\">DivideByZeroException</span></a><span style=\" font-family:'Segoe UI,SegoeUI,Helvetica Neue,Helvetica,Arial,sans-serif'; font-size:12pt; color:#161616;\">\302\240exception. To prevent the exception, ensure that the denominator in a division operation with integer or\302\240</span><a href=\"https://learn.microsoft.com/en-us/dotnet/api/system.decimal?view=net-8.0\"><span style=\" font-family:'Segoe UI,SegoeUI,Helvetica Neue,Helvetica,Arial,sans-serif'; font-size:12pt; text-decoration: underline; color:#000000; background-color:transparent;\""
                        ">Decimal</span></a><span style=\" font-family:'Segoe UI,SegoeUI,Helvetica Neue,Helvetica,Arial,sans-serif'; font-size:12pt; color:#161616;\">\302\240values is non-zero.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; background-color:#ffffff;\"><span style=\" font-family:'Segoe UI,SegoeUI,Helvetica Neue,Helvetica,Arial,sans-serif'; font-size:12pt; color:#161616; background-color:#ffffff;\">Dividing a floating-point value by zero doesn't throw an exception; it results in positive infinity, negative infinity, or not a number (NaN), according to the rules of IEEE 754 arithmetic. Because the following example uses floating-point division rather than integer division, the operation does not throw a</span><span style=\" font-family:'Segoe UI,SegoeUI,Helvetica Neue,Helvetica,Arial,sans-serif'; font-size:12pt; color:#161616;\">\302\240</span><a href=\"https://learn.microsoft.com/en-us/dotnet/api/system.dividebyzeroexception?view=net-"
                        "8.0\"><span style=\" font-family:'Segoe UI,SegoeUI,Helvetica Neue,Helvetica,Arial,sans-serif'; font-size:12pt; text-decoration: underline; color:#000000; background-color:transparent;\">DivideByZeroException</span></a><span style=\" font-family:'Segoe UI,SegoeUI,Helvetica Neue,Helvetica,Arial,sans-serif'; font-size:12pt; color:#161616;\">\302\240exception.</span></p></body></html>", 0));
        textEdit_2->setHtml(QApplication::translate("RuleDescriptDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SFMono-Regular,Consolas,Liberation Mono,Menlo,Courier,monospace'; font-size:12pt; color:#0101fd; background-color:#f2f2f2;\">using</span><span style=\" font-family:'SFMono-Regular,Consolas,Liberation Mono,Menlo,Courier,monospace'; font-size:12pt; color:#161616; background-color:#f2f2f2;\"> System;</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'SFMono-Regular,Consolas,Liberation Mono,Menlo,Courier,monospace'; font-s"
                        "ize:12pt; color:#161616;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SFMono-Regular,Consolas,Liberation Mono,Menlo,Courier,monospace'; font-size:12pt; color:#0101fd; background-color:#f2f2f2;\">public</span><span style=\" font-family:'SFMono-Regular,Consolas,Liberation Mono,Menlo,Courier,monospace'; font-size:12pt; color:#161616; background-color:#f2f2f2;\"> </span><span style=\" font-family:'SFMono-Regular,Consolas,Liberation Mono,Menlo,Courier,monospace'; font-size:12pt; color:#0101fd; background-color:#f2f2f2;\">class</span><span style=\" font-family:'SFMono-Regular,Consolas,Liberation Mono,Menlo,Courier,monospace'; font-size:12pt; color:#161616; background-color:#f2f2f2;\"> </span><span style=\" font-family:'SFMono-Regular,Consolas,Liberation Mono,Menlo,Courier,monospace'; font-size:12pt; color:#006881; background-color:#f2f2f2;\">Example</span></p>\n"
"<p style=\" margin-top:0px; margi"
                        "n-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SFMono-Regular,Consolas,Liberation Mono,Menlo,Courier,monospace'; font-size:12pt; color:#161616; background-color:#f2f2f2;\">{</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SFMono-Regular,Consolas,Liberation Mono,Menlo,Courier,monospace'; font-size:12pt; color:#161616; background-color:#f2f2f2;\">   </span><span style=\" font-family:'SFMono-Regular,Consolas,Liberation Mono,Menlo,Courier,monospace'; font-size:12pt; color:#0101fd; background-color:#f2f2f2;\">public</span><span style=\" font-family:'SFMono-Regular,Consolas,Liberation Mono,Menlo,Courier,monospace'; font-size:12pt; color:#161616; background-color:#f2f2f2;\"> </span><span style=\" font-family:'SFMono-Regular,Consolas,Liberation Mono,Menlo,Courier,monospace'; font-size:12pt; color:#0101fd; background-color:#f2f2f2;\">sta"
                        "tic</span><span style=\" font-family:'SFMono-Regular,Consolas,Liberation Mono,Menlo,Courier,monospace'; font-size:12pt; color:#161616; background-color:#f2f2f2;\"> </span><span style=\" font-family:'SFMono-Regular,Consolas,Liberation Mono,Menlo,Courier,monospace'; font-size:12pt; color:#0101fd; background-color:#f2f2f2;\">void</span><span style=\" font-family:'SFMono-Regular,Consolas,Liberation Mono,Menlo,Courier,monospace'; font-size:12pt; color:#161616; background-color:#f2f2f2;\"> </span><span style=\" font-family:'SFMono-Regular,Consolas,Liberation Mono,Menlo,Courier,monospace'; font-size:12pt; color:#006881; background-color:#f2f2f2;\">Main</span><span style=\" font-family:'SFMono-Regular,Consolas,Liberation Mono,Menlo,Courier,monospace'; font-size:12pt; color:#161616; background-color:#f2f2f2;\">()</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SFMono-Regular,Consolas,Liberation Mono,Menlo"
                        ",Courier,monospace'; font-size:12pt; color:#161616; background-color:#f2f2f2;\">   {</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SFMono-Regular,Consolas,Liberation Mono,Menlo,Courier,monospace'; font-size:12pt; color:#161616; background-color:#f2f2f2;\">      </span><span style=\" font-family:'SFMono-Regular,Consolas,Liberation Mono,Menlo,Courier,monospace'; font-size:12pt; color:#0101fd; background-color:#f2f2f2;\">int</span><span style=\" font-family:'SFMono-Regular,Consolas,Liberation Mono,Menlo,Courier,monospace'; font-size:12pt; color:#161616; background-color:#f2f2f2;\"> number1 = 3000;</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SFMono-Regular,Consolas,Liberation Mono,Menlo,Courier,monospace'; font-size:12pt; color:#161616; background-color:#f2f2f2;\">      </span><sp"
                        "an style=\" font-family:'SFMono-Regular,Consolas,Liberation Mono,Menlo,Courier,monospace'; font-size:12pt; color:#0101fd; background-color:#f2f2f2;\">int</span><span style=\" font-family:'SFMono-Regular,Consolas,Liberation Mono,Menlo,Courier,monospace'; font-size:12pt; color:#161616; background-color:#f2f2f2;\"> number2 = 0;</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SFMono-Regular,Consolas,Liberation Mono,Menlo,Courier,monospace'; font-size:12pt; color:#161616; background-color:#f2f2f2;\">      Console.WriteLine(number1 / number2);</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SFMono-Regular,Consolas,Liberation Mono,Menlo,Courier,monospace'; font-size:12pt; color:#161616; background-color:#f2f2f2;\">   }</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-le"
                        "ft:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SFMono-Regular,Consolas,Liberation Mono,Menlo,Courier,monospace'; font-size:12pt; color:#161616; background-color:#f2f2f2;\">}</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SFMono-Regular,Consolas,Liberation Mono,Menlo,Courier,monospace'; font-size:12pt; color:#008000; background-color:#f2f2f2;\">// The example displays the following output:</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SFMono-Regular,Consolas,Liberation Mono,Menlo,Courier,monospace'; font-size:12pt; color:#008000; background-color:#f2f2f2;\">//     </span></p></body></html>", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabDescription), QApplication::translate("RuleDescriptDialog", "Detailed description", 0));
        textBrowser_3->setHtml(QApplication::translate("RuleDescriptDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; background-color:#ffffff;\"><span style=\" font-family:'Segoe UI,SegoeUI,Helvetica Neue,Helvetica,Arial,sans-serif'; font-size:12pt; color:#161616; background-color:#ffffff;\">Trying to divide an integer or</span><span style=\" font-family:'Segoe UI,SegoeUI,Helvetica Neue,Helvetica,Arial,sans-serif'; font-size:12pt; color:#161616;\">\302\240</span><a href=\"https://learn.microsoft.com/en-us/dotnet/api/system.decimal?view=net-8.0\"><span style=\" font-family:'Segoe UI,SegoeUI,Helvetica Neue,Helvetica,Arial,sans-serif'; font-size:12pt; text-decoration: underline; color"
                        ":#000000; background-color:transparent;\">Decimal</span></a><span style=\" font-family:'Segoe UI,SegoeUI,Helvetica Neue,Helvetica,Arial,sans-serif'; font-size:12pt; color:#161616;\">\302\240number by zero throws a\302\240</span><a href=\"https://learn.microsoft.com/en-us/dotnet/api/system.dividebyzeroexception?view=net-8.0\"><span style=\" font-family:'Segoe UI,SegoeUI,Helvetica Neue,Helvetica,Arial,sans-serif'; font-size:12pt; text-decoration: underline; color:#000000; background-color:transparent;\">DivideByZeroException</span></a><span style=\" font-family:'Segoe UI,SegoeUI,Helvetica Neue,Helvetica,Arial,sans-serif'; font-size:12pt; color:#161616;\">\302\240exception. To prevent the exception, ensure that the denominator in a division operation with integer or\302\240</span><a href=\"https://learn.microsoft.com/en-us/dotnet/api/system.decimal?view=net-8.0\"><span style=\" font-family:'Segoe UI,SegoeUI,Helvetica Neue,Helvetica,Arial,sans-serif'; font-size:12pt; text-decoration: underline; color:#000000; back"
                        "ground-color:transparent;\">Decimal</span></a><span style=\" font-family:'Segoe UI,SegoeUI,Helvetica Neue,Helvetica,Arial,sans-serif'; font-size:12pt; color:#161616;\">\302\240values is non-zero.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; background-color:#ffffff;\"><span style=\" font-family:'Segoe UI,SegoeUI,Helvetica Neue,Helvetica,Arial,sans-serif'; font-size:12pt; color:#161616; background-color:#ffffff;\">Dividing a floating-point value by zero doesn't throw an exception; it results in positive infinity, negative infinity, or not a number (NaN), according to the rules of IEEE 754 arithmetic. Because the following example uses floating-point division rather than integer division, the operation does not throw a</span><span style=\" font-family:'Segoe UI,SegoeUI,Helvetica Neue,Helvetica,Arial,sans-serif'; font-size:12pt; color:#161616;\">\302\240</span><a href=\"https://learn.microsoft.com/en-us/dotnet/api/system.divi"
                        "debyzeroexception?view=net-8.0\"><span style=\" font-family:'Segoe UI,SegoeUI,Helvetica Neue,Helvetica,Arial,sans-serif'; font-size:12pt; text-decoration: underline; color:#000000; background-color:transparent;\">DivideByZeroException</span></a><span style=\" font-family:'Segoe UI,SegoeUI,Helvetica Neue,Helvetica,Arial,sans-serif'; font-size:12pt; color:#161616;\">\302\240exception.</span></p></body></html>", 0));
        textEdit->setHtml(QApplication::translate("RuleDescriptDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SFMono-Regular,Consolas,Liberation Mono,Menlo,Courier,monospace'; font-size:12pt; color:#0101fd; background-color:#f2f2f2;\">using</span><span style=\" font-family:'SFMono-Regular,Consolas,Liberation Mono,Menlo,Courier,monospace'; font-size:12pt; color:#161616; background-color:#f2f2f2;\"> System;</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'SFMono-Regular,Consolas,Liberation Mono,Menlo,Courier,monospace'; font-s"
                        "ize:12pt; color:#161616;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SFMono-Regular,Consolas,Liberation Mono,Menlo,Courier,monospace'; font-size:12pt; color:#0101fd; background-color:#f2f2f2;\">public</span><span style=\" font-family:'SFMono-Regular,Consolas,Liberation Mono,Menlo,Courier,monospace'; font-size:12pt; color:#161616; background-color:#f2f2f2;\"> </span><span style=\" font-family:'SFMono-Regular,Consolas,Liberation Mono,Menlo,Courier,monospace'; font-size:12pt; color:#0101fd; background-color:#f2f2f2;\">class</span><span style=\" font-family:'SFMono-Regular,Consolas,Liberation Mono,Menlo,Courier,monospace'; font-size:12pt; color:#161616; background-color:#f2f2f2;\"> </span><span style=\" font-family:'SFMono-Regular,Consolas,Liberation Mono,Menlo,Courier,monospace'; font-size:12pt; color:#006881; background-color:#f2f2f2;\">Example</span></p>\n"
"<p style=\" margin-top:0px; margi"
                        "n-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SFMono-Regular,Consolas,Liberation Mono,Menlo,Courier,monospace'; font-size:12pt; color:#161616; background-color:#f2f2f2;\">{</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SFMono-Regular,Consolas,Liberation Mono,Menlo,Courier,monospace'; font-size:12pt; color:#161616; background-color:#f2f2f2;\">   </span><span style=\" font-family:'SFMono-Regular,Consolas,Liberation Mono,Menlo,Courier,monospace'; font-size:12pt; color:#0101fd; background-color:#f2f2f2;\">public</span><span style=\" font-family:'SFMono-Regular,Consolas,Liberation Mono,Menlo,Courier,monospace'; font-size:12pt; color:#161616; background-color:#f2f2f2;\"> </span><span style=\" font-family:'SFMono-Regular,Consolas,Liberation Mono,Menlo,Courier,monospace'; font-size:12pt; color:#0101fd; background-color:#f2f2f2;\">sta"
                        "tic</span><span style=\" font-family:'SFMono-Regular,Consolas,Liberation Mono,Menlo,Courier,monospace'; font-size:12pt; color:#161616; background-color:#f2f2f2;\"> </span><span style=\" font-family:'SFMono-Regular,Consolas,Liberation Mono,Menlo,Courier,monospace'; font-size:12pt; color:#0101fd; background-color:#f2f2f2;\">void</span><span style=\" font-family:'SFMono-Regular,Consolas,Liberation Mono,Menlo,Courier,monospace'; font-size:12pt; color:#161616; background-color:#f2f2f2;\"> </span><span style=\" font-family:'SFMono-Regular,Consolas,Liberation Mono,Menlo,Courier,monospace'; font-size:12pt; color:#006881; background-color:#f2f2f2;\">Main</span><span style=\" font-family:'SFMono-Regular,Consolas,Liberation Mono,Menlo,Courier,monospace'; font-size:12pt; color:#161616; background-color:#f2f2f2;\">()</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SFMono-Regular,Consolas,Liberation Mono,Menlo"
                        ",Courier,monospace'; font-size:12pt; color:#161616; background-color:#f2f2f2;\">   {</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SFMono-Regular,Consolas,Liberation Mono,Menlo,Courier,monospace'; font-size:12pt; color:#161616; background-color:#f2f2f2;\">      </span><span style=\" font-family:'SFMono-Regular,Consolas,Liberation Mono,Menlo,Courier,monospace'; font-size:12pt; color:#0101fd; background-color:#f2f2f2;\">int</span><span style=\" font-family:'SFMono-Regular,Consolas,Liberation Mono,Menlo,Courier,monospace'; font-size:12pt; color:#161616; background-color:#f2f2f2;\"> number1 = 3000;</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SFMono-Regular,Consolas,Liberation Mono,Menlo,Courier,monospace'; font-size:12pt; color:#161616; background-color:#f2f2f2;\">      </span><sp"
                        "an style=\" font-family:'SFMono-Regular,Consolas,Liberation Mono,Menlo,Courier,monospace'; font-size:12pt; color:#0101fd; background-color:#f2f2f2;\">int</span><span style=\" font-family:'SFMono-Regular,Consolas,Liberation Mono,Menlo,Courier,monospace'; font-size:12pt; color:#161616; background-color:#f2f2f2;\"> number2 = 0;</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SFMono-Regular,Consolas,Liberation Mono,Menlo,Courier,monospace'; font-size:12pt; color:#161616; background-color:#f2f2f2;\">      </span><span style=\" font-family:'SFMono-Regular,Consolas,Liberation Mono,Menlo,Courier,monospace'; font-size:12pt; color:#0101fd; background-color:#f2f2f2;\">try</span><span style=\" font-family:'SFMono-Regular,Consolas,Liberation Mono,Menlo,Courier,monospace'; font-size:12pt; color:#161616; background-color:#f2f2f2;\"> {</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px"
                        "; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SFMono-Regular,Consolas,Liberation Mono,Menlo,Courier,monospace'; font-size:12pt; color:#161616; background-color:#f2f2f2;\">         Console.WriteLine(number1 / number2);</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SFMono-Regular,Consolas,Liberation Mono,Menlo,Courier,monospace'; font-size:12pt; color:#161616; background-color:#f2f2f2;\">      }</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SFMono-Regular,Consolas,Liberation Mono,Menlo,Courier,monospace'; font-size:12pt; color:#161616; background-color:#f2f2f2;\">      catch (DivideByZeroException) {</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span "
                        "style=\" font-family:'SFMono-Regular,Consolas,Liberation Mono,Menlo,Courier,monospace'; font-size:12pt; color:#161616; background-color:#f2f2f2;\">         Console.WriteLine(</span><span style=\" font-family:'SFMono-Regular,Consolas,Liberation Mono,Menlo,Courier,monospace'; font-size:12pt; color:#a31515; background-color:#f2f2f2;\">&quot;Division of {0} by zero.&quot;</span><span style=\" font-family:'SFMono-Regular,Consolas,Liberation Mono,Menlo,Courier,monospace'; font-size:12pt; color:#161616; background-color:#f2f2f2;\">, number1);</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SFMono-Regular,Consolas,Liberation Mono,Menlo,Courier,monospace'; font-size:12pt; color:#161616; background-color:#f2f2f2;\">      }</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SFMono-Regular,Consola"
                        "s,Liberation Mono,Menlo,Courier,monospace'; font-size:12pt; color:#161616; background-color:#f2f2f2;\">   }</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SFMono-Regular,Consolas,Liberation Mono,Menlo,Courier,monospace'; font-size:12pt; color:#161616; background-color:#f2f2f2;\">}</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SFMono-Regular,Consolas,Liberation Mono,Menlo,Courier,monospace'; font-size:12pt; color:#008000; background-color:#f2f2f2;\">// The example displays the following output:</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SFMono-Regular,Consolas,Liberation Mono,Menlo,Courier,monospace'; font-size:12pt; color:#008000; background-color:#f2f2f2;\">//"
                        "     </span></p></body></html>", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabFix), QApplication::translate("RuleDescriptDialog", "How to fix", 0));
        pushButton_2->setText(QApplication::translate("RuleDescriptDialog", "Add to rule set 1", 0));
        pushButton_3->setText(QApplication::translate("RuleDescriptDialog", "Deactivate in rule set 1", 0));
        pushButton->setText(QApplication::translate("RuleDescriptDialog", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class RuleDescriptDialog: public Ui_RuleDescriptDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RULEDESCRIPTDIALOG_H
