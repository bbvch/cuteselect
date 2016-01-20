#-------------------------------------------------
#
# Project created by QtCreator 2016-01-20T13:28:19
#
#-------------------------------------------------

QT       -= gui
QT += xml

TARGET = core
TEMPLATE = lib
CONFIG += staticlib
CONFIG   += c++11

SOURCES += Application.cpp \
    ApplicationFactory.cpp \
    ApplicationImplementation.cpp \
    ConfigurationLoaderImplementation.cpp

HEADERS += Application.h \
    Configuration.h \
    ApplicationFactory.h \
    ApplicationImplementation.h \
    ConfigurationLoaderImplementation.h \
    ConfigurationLoader.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
