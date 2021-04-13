TEMPLATE = app
TARGET = foodie

OBJECTS_DIR=obj
MOC_DIR=moc

QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

INCLUDEPATH += include

QMAKE_CXX = g++

CONFIG += c++11

SOURCES += \
    src/main.cpp 