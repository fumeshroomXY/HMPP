#include <QApplication>
#include <QCommandLineParser>
#include <QCommandLineOption>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(ui_images);  //Initializes the resources specified by the .qrc file with the specified base name

    QApplication app(argc, argv);    //����Ӧ�ó�����Դ
    QCoreApplication::setApplicationName("HMPP supportint tool");
    QCoreApplication::setOrganizationName("DependableSystemProject");
    QCoreApplication::setApplicationVersion(QT_VERSION_STR);
    QCommandLineParser parser;
    parser.setApplicationDescription("HMPP supporting tool demo");
    parser.addHelpOption();
    parser.addVersionOption();
    parser.addPositionalArgument("file", "The file to open.");
    parser.process(app);

    MainWindow mainWin;
    foreach (const QString &fileName, parser.positionalArguments())  //iterate over all the items in the parser in order
        mainWin.openFile(fileName);
    //mainWin.setSizePolicy(QSizePolicy::MinimumExpanding);
    mainWin.show();    //Ĭ��������½��������ɼ�
    qDebug() << "MainWindowisVisiable:" << mainWin.isVisible();
    return app.exec();   //��QApplication��������¼�ѭ��
}