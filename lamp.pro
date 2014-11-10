#-------------------------------------------------
#
# Project created by QtCreator 2014-11-08T12:15:36
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = testTaskLamp
TEMPLATE = app


SOURCES += main.cpp\
        lamp.cpp \
    clientlamp.cpp

HEADERS  += lamp.h \
    clientlamp.h

FORMS    += lamp.ui
