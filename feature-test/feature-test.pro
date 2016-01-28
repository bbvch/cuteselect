#
# (C) Copyright 2016
# Urs Fässler, bbv Software Services, http://bbv.ch
#
# SPDX-License-Identifier:	GPL-3.0+
#

TEMPLATE = app

CONFIG   += console
CONFIG   += c++11
CONFIG   += warn_on
CONFIG   -= app_bundle

QT       += core
QT       -= gui
QT += testlib


TARGET = feature-test

include(../core/core.pri)
feature-test.depends = core

LIBS += -lgtest -lboost_regex -lboost_system -lcucumber-cpp

SOURCES += \
    steps/configuration.cpp \
    steps/application.cpp \
    steps/gui.cpp

OTHER_FILES += \
    features/items.feature \
    features/configuration.feature

HEADERS += \
    helper/Context.h

