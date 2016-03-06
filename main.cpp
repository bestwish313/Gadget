#include "mainwindow.h"
#include <QApplication>
#include <QCommandLineParser>
#include <QCommandLineOption>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QCoreApplication::setApplicationName("Gadget");
    QCoreApplication::setApplicationVersion("1.0");

    QCommandLineParser parser;
    parser.addHelpOption();
    parser.addVersionOption();

    ///////////////////////////////////////////////////////////
    ///// BOOLEAN OPTIONS WITH A SINGLE NAME
    ////////////////////////////////////////////////////////////

    QCommandLineOption messageAllOption(QStringList() << "a" << "all",QCoreApplication::translate("main", "Listen to all messages."));
    parser.addOption(messageAllOption);


    ///////////////////////////////////////////////////////////
    ///// BOOLEAN OPTIONS WITH MULTIPLE NAMES
    ////////////////////////////////////////////////////////////

    QCommandLineOption guiOption(QStringList() << "g" << "gui",
                           QCoreApplication::translate("main", "Invoke Gadget in gui mode."));
    parser.addOption(guiOption);

    ///////////////////////////////////////////////////////////
    ///// OPTIONS WITH A VALUE
    ////////////////////////////////////////////////////////////

    QCommandLineOption portOption(QStringList() << "p" << "port",
                                QCoreApplication::translate("main", "Listen to port <PORT>."),
                                QCoreApplication::translate("main", "PORT"));
    parser.addOption(portOption);

    // Process the actual command line arguments given by the user
    parser.process(app);
    MainWindow w;

    if (parser.isSet(portOption) || (parser.isSet(messageAllOption))) {

        if (!parser.isSet(portOption) || parser.value(portOption).contains("-") || parser.value(portOption).contains("--")) {
            fputs(qPrintable("Port number missing."), stderr);
            fputs("\n\n", stderr);
            fputs(qPrintable(parser.helpText()), stderr);
            return 1;
        }
        else {
            if (parser.isSet(portOption)) {

            }
            if (parser.isSet(messageAllOption)) {

            }
        }
    }
    else
        w.show();


    return app.exec();
}
