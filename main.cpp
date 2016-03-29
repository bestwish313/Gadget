#include "mainwindow.h"
#include "cread_serial_port.h"

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

    QCommandLineOption baudOption(QStringList() << "b" << "baud",
                                QCoreApplication::translate("main", "Set baud rate <BITS>."),
                                QCoreApplication::translate("main", "BAUD"));
    parser.addOption(baudOption);
    QCommandLineOption stopBitOption(QStringList() << "s" << "stop",
                                QCoreApplication::translate("main", "Set stop bits <BITS>."),
                                QCoreApplication::translate("main", "STOP"));
    parser.addOption(stopBitOption);
    QCommandLineOption dataBitOption(QStringList() << "d" << "data",
                                QCoreApplication::translate("main", "Set data bits <BITS>."),
                                QCoreApplication::translate("main", "DATA"));
    parser.addOption(dataBitOption);
    QCommandLineOption parityOption(QStringList() << "y" << "parity",
                                QCoreApplication::translate("main", "Set parity <PARITY>."),
                                QCoreApplication::translate("main", "PARITY"));
    parser.addOption(parityOption);
    QCommandLineOption flowControlOption(QStringList() << "f" << "flow",
                                QCoreApplication::translate("main", "Set flow control <FLOW>."),
                                QCoreApplication::translate("main", "FLOW"));
    parser.addOption(flowControlOption);

    QCommandLineOption logOption(QStringList() << "l" << "log",
                                QCoreApplication::translate("main", "Save log to <FILE>."),
                                QCoreApplication::translate("main", "FILE"));
    parser.addOption(logOption);

    // Process the actual command line arguments given by the user
    parser.process(app);
    MainWindow w;

    if (parser.isSet(portOption) ||
       (parser.isSet(messageAllOption)) ||
       (parser.isSet(logOption))) {

        QString port;
        QString baud = "57600";
        QString stop = "1";
        QString data = "8";
        QString flow = "None";
        QString parity = "None";
        QString log = "";

        if (!parser.isSet(portOption) ||
             parser.value(portOption).contains("-") || parser.value(portOption).contains("--") ||
             parser.value(baudOption).contains("-") || parser.value(baudOption).contains("--") ||
             parser.value(stopBitOption).contains("-") || parser.value(stopBitOption).contains("--") ||
             parser.value(flowControlOption).contains("-") || parser.value(flowControlOption).contains("--") ||
             parser.value(dataBitOption).contains("-") || parser.value(dataBitOption).contains("--") ||
             parser.value(parityOption).contains("-") || parser.value(parityOption).contains("--") ||
             parser.value(logOption).contains("-") || parser.value(logOption).contains("--")) {
            fputs(qPrintable("Option argument missing."), stderr);
            fputs("\n\n", stderr);
            fputs(qPrintable(parser.helpText()), stderr);
            return 1;
        }
        else {
            if (parser.isSet(portOption)) {
                port = parser.value(portOption);
            }
            if (parser.isSet(baudOption)) {
                baud = parser.value(baudOption);
            }
            if (parser.isSet(stopBitOption)) {
                stop = parser.value(stopBitOption);
            }
            if (parser.isSet(dataBitOption)) {
                data = parser.value(dataBitOption);
            }
            if (parser.isSet(flowControlOption)) {
                flow = parser.value(flowControlOption);
            }
            if (parser.isSet(parityOption)) {
                parity = parser.value(parityOption);
            }
            if (parser.isSet(logOption)) {
                log = parser.value(logOption);
            }
            if (parser.isSet(messageAllOption)) {

            }

            CREAD_SERIAL_PORT *cReadSerialPort = new CREAD_SERIAL_PORT(port, baud, data, parity, stop, flow);
        }
    }
    else
        w.show();

    return app.exec();
}
