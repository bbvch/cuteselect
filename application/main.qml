/*
 * (C) Copyright 2016
 * Urs Fässler, bbv Software Services, http://bbv.ch
 *
 * SPDX-License-Identifier:	GPL-3.0+
 */

import QtQuick 2.3
import QtQuick.Controls 1.2

Rectangle {
    id: root
    visible: true
    width: 640
    height: 480

    color: configuration.backgroundColor

    GridView {
        anchors.fill: parent

        id: grid
        cellWidth: root.width * configuration.relativeWidth
        cellHeight: root.height * configuration.relativeHeight

        model: configuration.items

        delegate: gridDelegate
    }

    Component {
        id: gridDelegate
        Item {
            width: grid.cellWidth
            height: grid.cellHeight
            Image {
                anchors.fill: parent
                sourceSize.width: width
                sourceSize.height: height
                fillMode: Image.PreserveAspectFit

                source: "file://" + model.path
            }
            MouseArea {
                anchors.fill: parent
                onClicked: configuration.activate(index)
            }
        }
    }
}

