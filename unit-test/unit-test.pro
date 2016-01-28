#
# (C) Copyright 2016
# Urs Fässler, bbv Software Services, http://bbv.ch
#
# SPDX-License-Identifier:	GPL-3.0+
#

QT       += core

QT       -= gui
QT += testlib

CONFIG   += console
CONFIG   -= app_bundle
CONFIG   += c++11

TEMPLATE = app

TARGET = unit-test

include(../core/core.pri)

LIBS += -lgmock_main
LIBS += -lgmock -lpthread

SOURCES += \
    ConfigurationLoaderImplementation_Test.cpp \
    Configuration_Test.cpp \
    FilePathResolver_Test.cpp \
    IostreamPrinter_test.cpp \
    ItemListImplementation_Test.cpp \
    ImageItemImplementation_Test.cpp \
    ImageItem_Test.cpp

HEADERS += \
    ConfigurationLoader_Mock.h \
    ConfigurationListener_Mock.h \
    FilePathResolver_Mock.h \
    ItemList_Mock.h \
    ImageItem_Mock.h
