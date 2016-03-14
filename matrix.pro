#-------------------------------------------------
#
# Project created by QtCreator 2016-01-30T20:26:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = matrix
TEMPLATE = app


SOURCES += main.cpp\
    GUI/Element.cpp \
    GUI/Decor.cpp \
    GUI/Thing.cpp

HEADERS  += \
    GUI/Element.h \
    GUI/Decor.h \
    GUI/Thing.h

FORMS    += GUI/mainwindow.ui

CONFIG += c++11
