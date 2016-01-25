TEMPLATE = app

QT += qml quick widgets
CONFIG += c++11

include(../core/core.pri)
feature-test.depends = core

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
