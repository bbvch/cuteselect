#-------------------------------------------------
#
# Project created by QtCreator 2016-01-20T11:48:13
#
#-------------------------------------------------

TEMPLATE = app

CONFIG   += console
CONFIG   += c++11
CONFIG   += warn_on
CONFIG   -= app_bundle

QT       += core
QT       -= gui


TARGET = feature-test

include(../core/core.pri)
feature-test.depends = core

LIBS += -lgtest -lboost_regex -lboost_system -lcucumber-cpp

SOURCES += \
    steps/configuration.cpp \
    steps/application.cpp \
    steps/gui.cpp

OTHER_FILES += \
    features/background.feature \
    features/items.feature

HEADERS += \
    helper/Context.h

