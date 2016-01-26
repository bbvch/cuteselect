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

SOURCES += \
    ConfigurationLoaderImplementation.cpp \
    Configuration.cpp \
    FilePathResolverImplementation.cpp \
    IostreamPrinter.cpp

HEADERS += \
    ConfigurationLoaderImplementation.h \
    ConfigurationLoader.h \
    ConfigurationListener.h \
    Configuration.h \
    FilePathResolverImplementation.h \
    FilePathResolver.h \
    IostreamPrinter.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
