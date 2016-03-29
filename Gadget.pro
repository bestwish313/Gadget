#-------------------------------------------------
#
# Project created by QtCreator 2016-03-05T18:46:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets serialport

TARGET = Gadget
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    cread_serial_port.cpp

HEADERS  += mainwindow.h \
    cread_serial_port.h

FORMS    += mainwindow.ui
