import QtQuick 2.3
import QtQuick.Controls 1.2

ApplicationWindow {
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

        model: configuration

        delegate: Component {
            Image {
                width: grid.cellWidth
                height: grid.cellHeight
                sourceSize.width: width
                sourceSize.height: height
                fillMode: Image.PreserveAspectFit

                source: "file://" + model.display
            }
        }
    }
}
