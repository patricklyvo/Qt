#-------------------------------------------------
#
# Project created by QtCreator 2015-12-01T21:40:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NotePad
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    finddialog.cpp

HEADERS  += mainwindow.h \
    finddialog.h

FORMS    += mainwindow.ui \
    finddialog.ui

RESOURCES += \
    appresources.qrc

DISTFILES +=
