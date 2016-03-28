#-------------------------------------------------
#
# Project created by QtCreator 2016-01-30T20:26:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 2dgraphicsengine
TEMPLATE = app

SOURCES += src/main.cpp\
    src/physicsengine/objects/Element.cpp \
    src/physicsengine/scenery/StaticScenery.cpp \
    src/physicsengine/Object2d.cpp

HEADERS  += \
    src/physicsengine/objects/Element.h \
    src/physicsengine/scenery/StaticScenery.h \
    src/physicsengine/Object2d.h

INCLUDEPATH += src/

CONFIG += c++11
