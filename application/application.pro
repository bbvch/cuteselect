#
# (C) Copyright 2016
# Urs Fässler, bbv Software Services, http://bbv.ch
#
# SPDX-License-Identifier:	GPL-3.0+
#

TEMPLATE = app

QT += qml quick
CONFIG += c++11

TARGET = cuteselect
unix {
    target.path = /usr/bin/
    INSTALLS += target
}

include(../core/core.pri)

SOURCES += main.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

OTHER_FILES += \
    data/cuteselect.config \
    data/Anonymous-Whale.svg \
    data/diamond-shape.svg \
    data/Girl-At-The-Beach.svg \
    data/Honey-in-the-can.svg \
    data/lightbulb.svg
