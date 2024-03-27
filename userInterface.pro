#-------------------------------------------------
#
# Project created by QtCreator 2023-11-06T19:51:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = userInterface
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mdichild.cpp \
    codeanalyzeconfigdialog.cpp \
    ruledescriptdialog.cpp \
    allruledescriptdialog.cpp \
    managepropertysetdialog.cpp \
    faultinstance.cpp \
    highlighter.cpp \
    screenfactor.cpp \
    faultpromptdialog.cpp \
    faultlinehighlighter.cpp \
    requirementtreeview.cpp

HEADERS  += mainwindow.h \
    mdichild.h \
    codeanalyzeconfigdialog.h \
    ruledescriptdialog.h \
    allruledescriptdialog.h \
    managepropertysetdialog.h \
    faultinstance.h \
    highlighter.h \
    screenfactor.h \
    faultpromptdialog.h \
    faultlinehighlighter.h \
    requirementtreeview.h

RESOURCES += \
    ui_images.qrc

FORMS += \
    mainwindow.ui \
    codeanalyzeconfigdialog.ui \
    ruledescriptdialog.ui \
    allruledescriptdialog.ui \
    managepropertysetdialog.ui \
    faultpromptdialog.ui
