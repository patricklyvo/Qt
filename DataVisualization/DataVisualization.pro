#-------------------------------------------------
#
# Project created by QtCreator 2015-12-12T15:21:12
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = DataVisualization
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    qcustomplot.cpp

HEADERS  += dialog.h \
    qcustomplot.h

FORMS    += dialog.ui
