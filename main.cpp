#include <QApplication>
#include <QCommandLineParser>
#include <QCommandLineOption>

#include "mainwindow.h"
#include "guidewizard.h"

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(ui_images);  //Initializes the resources specified by the .qrc file with the specified base name

    QApplication app(argc, argv);    //管理应用程序资源
    GuideWizard wizard;

    MainWindow mainWin;

    // Connect the custom signal to the slot in MainWindow
    //QObject::connect(&wizard, &GuideWizard::wizardFinished, &mainWin, &MainWindow::receiveGuideWizardFileInfo);

    // Show the MainWindow when the wizard is finished
    QObject::connect(&wizard, &QWizard::finished, [&mainWin, &wizard]() {
        mainWin.showMaximized();
        mainWin.receiveGuideWizardFileInfo(wizard.createNewFlag,
                                           wizard.field("project name").toString(),
                                           wizard.field("project path").toString(),
                                           wizard.field("specification path").toString(),
                                           wizard.field("target language").toString());
    });

    wizard.show();

    //mainWin.setSizePolicy(QSizePolicy::MinimumExpanding);
    //mainWin.show();    //默认情况下新建部件不可见
    return app.exec();   //让QApplication对象进入事件循环
}
