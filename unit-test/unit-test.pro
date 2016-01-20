#-------------------------------------------------
#
# Project created by QtCreator 2016-01-20T13:57:35
#
#-------------------------------------------------

QT       += core

QT       -= gui

CONFIG   += console
CONFIG   -= app_bundle
CONFIG   += c++11

TEMPLATE = app

TARGET = unit-test

include(../core/core.pri)
unit-test.depends = core

LIBS += -lgmock_main
LIBS += -lgmock -lpthread

SOURCES += \
    ApplicationFactory_Test.cpp \
    ApplicationImplementation_Test.cpp \
    ConfigurationLoaderImplementation_Test.cpp

HEADERS += \
    Configuration_Mock.h \
    ConfigurationLoader_Mock.h
