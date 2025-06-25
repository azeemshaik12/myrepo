import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.15

ApplicationWindow {
    visible: true
    width: 500
    height: 500
    title: "Clean Inline Drag-and-Drop Grid"

    property int gridSize: 100
    property int columns: 4

    ListModel {
        id: iconModel
        ListElement { name: "1" }
        ListElement { name: "2" }
        ListElement { name: "3" }
        ListElement { name: "4" }
        ListElement { name: "5" }
        ListElement { name: "6" }
        ListElement { name: "7" }
        ListElement { name: "8" }
    }

    GridView {
        id: gridView
        anchors.centerIn: parent
        width: columns * gridSize
        height: Math.ceil(iconModel.count / columns) * gridSize
        cellWidth: gridSize
        cellHeight: gridSize
        model: iconModel
        interactive: false

        delegate: Item {
            id: root
            width: gridSize
            height: gridSize

            property int originalIndex: index
            property bool dragging: false

            z: dragging ? 999 : index

            Behavior on x { NumberAnimation { duration: 150 } }
            Behavior on y { NumberAnimation { duration: 150 } }

            Rectangle {
                id: iconRect
                anchors.centerIn: parent
                width: parent.width * 0.8
                height: parent.height * 0.8
                radius: 12
                color: dragArea.drag.active ? "#ffaa00" : "#444"
                border.color: "white"
                border.width: 1

                Text {
                    anchors.centerIn: parent
                    text: model.name
                    color: "white"
                    font.pixelSize: 14
                }

                MouseArea {
                    id: dragArea
                    anchors.fill: parent
                    drag.target: root
                    drag.axis: Drag.XAndYAxis

                    property bool didDrag: false

                    onPressed: {
                        dragging = true
                        didDrag = false
                        originalIndex = index
                    }

                    onPositionChanged: {
                        if (!drag.active)
                            return

                        didDrag = true

                        let dropX = root.x + root.width /2
                        let dropY = root.y + root.height /2
                        let col = Math.floor(dropX / gridSize)
                        let row = Math.floor(dropY / gridSize)
                        let newIndex = row * columns + col

                        if (newIndex >= 0 && newIndex < iconModel.count && newIndex !== index) {
                            iconModel.move(index, newIndex, 1) //for moving effect
                        }
                    }


                    onReleased: {
                        dragging = false

                        if (!didDrag || index === originalIndex) {
                            // Cancel and restore original position
                            iconModel.move(index, originalIndex, 1)

                            // Reset to original grid position
                            let col = originalIndex % columns
                            let row = Math.floor(originalIndex / columns)
                            root.x = col * gridSize
                            root.y = row * gridSize
                        } else {
                            // Drag is accepted, snap to new position
                            let col = index % columns
                            let row = Math.floor(index / columns)
                            root.x = col * gridSize
                            root.y = row * gridSize
                        }
                    }


                }
            }
        }
    }
}
