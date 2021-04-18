TEMPLATE = app
TARGET = fudie

ICON = res/fudie_logo.icns

OBJECTS_DIR=obj
MOC_DIR=moc

QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

INCLUDEPATH += include

QMAKE_CXX = g++

CONFIG += c++11

SOURCES += \
    src/*.cpp \
    src/gui/*.cpp

HEADERS += \
    include/*.h \
    include/gui/*.h

RESOURCES += res/resources.qrc \
    res/resources.qrc
