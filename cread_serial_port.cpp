#include "cread_serial_port.h"

#include <QMessageBox>
#include <QTextStream>
#include <QCoreApplication>
#include <QFile>
#include <QObject>
#include <QStringList>


CREAD_SERIAL_PORT::CREAD_SERIAL_PORT(const QString &port, const QString &baud, const QString &data,
                                     const QString &parity, const QString &stop, const QString &flow)
{
    serial = new QSerialPort();

    connect(serial, SIGNAL(readyRead()), this, SLOT(readData()));

    currentSettings.name = port;
    currentSettings.baudRate = static_cast<QSerialPort::BaudRate>(baud.toInt());
    currentSettings.dataBits = static_cast<QSerialPort::DataBits>(data.toInt());
    currentSettings.parity = static_cast<QSerialPort::Parity>(parity.toInt());
    currentSettings.stopBits = static_cast<QSerialPort::StopBits>(stop.toInt());
    currentSettings.flowControl = static_cast<QSerialPort::FlowControl>(flow.toInt());

    connectPort();
}

void
CREAD_SERIAL_PORT::
connectPort() {

    serial->setPortName(currentSettings.name);
    serial->setBaudRate(currentSettings.baudRate);
    serial->setDataBits(currentSettings.dataBits);
    serial->setParity(currentSettings.parity);
    serial->setStopBits(currentSettings.stopBits);
    serial->setFlowControl(currentSettings.flowControl);

    if (serial->open(QIODevice::ReadWrite)) {

    }
    else
        QMessageBox::critical(NULL, QObject::tr("Error"), serial->errorString(), QMessageBox::Ok);
}

void
CREAD_SERIAL_PORT::
readData() {

}

