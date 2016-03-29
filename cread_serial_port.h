#ifndef CREAD_SERIAL_PORT_H
#define CREAD_SERIAL_PORT_H


#include <QtSerialPort/QSerialPort>
#include <QMainWindow>
#include <QObject>
#include <QWidget>


class CREAD_SERIAL_PORT
{
public:
    CREAD_SERIAL_PORT(const QString &, const QString &, const QString &, const QString &, const QString &, const QString &);

    struct Settings {
        QString name;
        qint32 baudRate;
        QString stringBaudRate;
        QSerialPort::DataBits dataBits;
        QString stringDataBits;
        QSerialPort::Parity parity;
        QString stringParity;
        QSerialPort::StopBits stopBits;
        QString stringStopBits;
        QSerialPort::FlowControl flowControl;
        QString stringFlowControl;
        bool localEchoEnabled;
    };
    QSerialPort *serial;
    Settings currentSettings;

    void connectPort();
    void readData();
};

#endif // CREAD_SERIAL_PORT_H
