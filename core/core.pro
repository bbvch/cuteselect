#
# (C) Copyright 2016
# Urs Fässler, bbv Software Services, http://bbv.ch
#
# SPDX-License-Identifier:	GPL-3.0+
#

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
    IostreamPrinter.cpp \
    ItemListImplementation.cpp \
    ImageItemImplementation.cpp \
    ImageItem.cpp

HEADERS += \
    ConfigurationLoaderImplementation.h \
    ConfigurationLoader.h \
    ConfigurationListener.h \
    Configuration.h \
    FilePathResolverImplementation.h \
    FilePathResolver.h \
    IostreamPrinter.h \
    ItemListImplementation.h \
    ItemList.h \
    ImageItemImplementation.h \
    ImageItem.h
