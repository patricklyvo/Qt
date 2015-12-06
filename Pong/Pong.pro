#-------------------------------------------------
#
# Project created by QtCreator 2015-12-05T16:56:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Pong
TEMPLATE = app


SOURCES += main.cpp\
    pong.cpp \
    ball.cpp \
    settings.cpp

HEADERS  += \
    pong.h \
    ball.h \
    settings.h

FORMS    += \
    pong.ui \
    settings.ui
