#-------------------------------------------------
#
# Project created by QtCreator 2016-01-20T13:57:35
#
#-------------------------------------------------

QT       += core

QT       -= gui
QT += testlib

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
    ConfigurationLoaderImplementation_Test.cpp \
    Configuration_Test.cpp

HEADERS += \
    ConfigurationLoader_Mock.h \
    ConfigurationListener_Mock.h
