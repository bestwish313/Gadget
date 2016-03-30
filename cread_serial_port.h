#ifndef CREAD_SERIAL_PORT_H
#define CREAD_SERIAL_PORT_H


#include <QtSerialPort/QSerialPort>
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QTextStream>
#include <QTimer>

QT_USE_NAMESPACE

class CREAD_SERIAL_PORT : public QObject
{
    Q_OBJECT;

public:
    CREAD_SERIAL_PORT(const QString &, const QString &, const QString &, const QString &, const QString &, const QString &, QObject *parent = 0);

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

    void connectPort();
    void readData();

private:
    Settings currentSettings;

    QByteArray  m_readData;
    QTextStream m_standardOutput;
    QTimer      m_timer;
};

#endif // CREAD_SERIAL_PORT_H
