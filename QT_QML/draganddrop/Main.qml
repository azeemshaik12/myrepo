import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.15

// Main application window
ApplicationWindow {
    visible: true
    width: 400
    height: 250
    title: "Drag & Drop Grid Paging"

    // Grid configuration
    property int gridSize: 100
    property int columns: 4
    property int rows: 2
    property int itemsPerPage: columns * rows
    property int currentPage: Math.round(flick.contentX / width)

    // Data model holding draggable items
    ListModel {
        id: iconModel
        Component.onCompleted: {
            for (let i = 1; i <= 12; ++i)
                append({ name: i.toString() })  // Add 12 initial items
        }
    }

    // Total number of pages (calculated based on model size)
    property int totalPages: Math.ceil(iconModel.count / itemsPerPage)

    // Drag flags for triggering auto page scroll
    property bool draggingToLeft: false
    property bool draggingToRight: false

    // Timer for auto page scroll during dragging near edges
    Timer {
        id: autoScrollTimer
        interval: 400
        repeat: false
        onTriggered: {
            if (draggingToLeft && currentPage < totalPages - 1) {
                currentPage++
                flick.contentX = currentPage * width
            } else if (draggingToRight && currentPage > 0) {
                currentPage--
                flick.contentX = currentPage * width
            }
        }
    }

    // Scrollable container for paging layout
    Flickable {
        id: flick
        anchors.fill: parent
        contentWidth: totalPages * width
        boundsBehavior: Flickable.StopAtBounds
        flickableDirection: Flickable.HorizontalFlick
        clip: true

        onContentXChanged: currentPage = Math.round(contentX / width)

        // Container holding all grid items
        Item {
            id: content
            width: flick.contentWidth
            height: flick.height

            // Repeats grid items for each model entry
            Repeater {
                id: iconRepeater
                model: iconModel

                // Single grid item
                Item {
                    id: iconItem
                    width: gridSize
                    height: gridSize

                    // Internal properties
                    property int indexInModel: index
                    property int originalIndex: index
                    property bool dragging: false
                    property bool didDrag: false

                    // Position based on index in model
                    x: (Math.floor(index / itemsPerPage)) * flick.width +
                       ((index % itemsPerPage) % columns) * gridSize
                    y: Math.floor((index % itemsPerPage) / columns) * gridSize
                    z: dragging ? 999 : index

                    // Smooth animation when position changes
                    Behavior on x { NumberAnimation { duration: 150 } }
                    Behavior on y { NumberAnimation { duration: 150 } }

                    // Visual rectangle with label
                    Rectangle {
                        id: icon
                        width: parent.width * 0.8
                        height: parent.height * 0.8
                        anchors.centerIn: parent
                        radius: 10
                        color: dragArea.drag.active ? "#ffaa00" : "#444"
                        border.color: "white"
                        border.width: 1

                        // Label inside icon
                        Text {
                            anchors.centerIn: parent
                            text: model.name
                            color: "white"
                            font.pixelSize: 16
                        }

                        // Drag logic using MouseArea
                        MouseArea {
                            id: dragArea
                            anchors.fill: parent
                            drag.target: iconItem
                            drag.axis: Drag.XAndYAxis

                            // On drag start
                            onPressed: {
                                dragging = true
                                didDrag = false
                                originalIndex = index
                            }

                            // During drag movement
                            onPositionChanged: {
                                if (!drag.active) return
                                didDrag = true

                                // Calculate drop target based on center point
                                let centerX = iconItem.x + iconItem.width / 2
                                let centerY = iconItem.y + iconItem.height / 2
                                let targetPage = Math.max(0, Math.min(Math.floor(centerX / flick.width), totalPages - 1))
                                let localX = centerX - targetPage * flick.width
                                let col = Math.floor(localX / gridSize)
                                let row = Math.floor(centerY / gridSize)
                                let dropIndex = targetPage * itemsPerPage + row * columns + col

                                // Trigger auto-scroll if near page edge
                                draggingToLeft = centerX > (flick.contentX + flick.width - 30)
                                draggingToRight = centerX < (flick.contentX + 30)
                                if ((draggingToLeft || draggingToRight) && !autoScrollTimer.running)
                                    autoScrollTimer.start()

                                // Valid move
                                if (dropIndex >= 0 && dropIndex < iconModel.count && dropIndex !== index &&
                                    col >= 0 && col < columns && row >= 0 && row < rows)
                                {
                                    iconModel.move(index, dropIndex, 1)
                                }
                            }

                            // On drop (drag end)
                            onReleased: {
                                dragging = false

                                // Final drop location calculation
                                let centerX = iconItem.x + iconItem.width / 2
                                let centerY = iconItem.y + iconItem.height / 2
                                let pageDrop = Math.floor(centerX / flick.width)
                                let localX = centerX - pageDrop * flick.width
                                let dropCol = Math.floor(localX / gridSize)
                                let dropRow = Math.floor(centerY / gridSize)
                                let dropIndex = pageDrop * itemsPerPage + dropRow * columns + dropCol

                                let valid = dropCol >= 0 && dropCol < columns &&
                                            dropRow >= 0 && dropRow < rows &&
                                            dropIndex >= 0 && dropIndex < iconModel.count

                                // Drop fallback logic (if invalid)
                                if (!didDrag || !valid) {
                                    if (pageDrop === 1 && iconModel.count > 8) {
                                        // Move first item of page 2 to last of page 1
                                        iconModel.move(8, 7, 1)
                                        // Move dragged item to last slot (index 11)
                                        iconModel.move(index, 11, 1)
                                    } else {
                                        iconModel.move(index, originalIndex, 1)
                                    }
                                }

                                // Re-layout all icons to correct positions
                                for (let i = 0; i < iconRepeater.count; ++i) {
                                    let item = iconRepeater.itemAt(i)
                                    if (item) {
                                        let page = Math.floor(i / itemsPerPage)
                                        let col = (i % itemsPerPage) % columns
                                        let row = Math.floor((i % itemsPerPage) / columns)
                                        item.x = page * flick.width + col * gridSize
                                        item.y = row * gridSize
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    // Page indicator at bottom
    Row {
        spacing: 10
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10

        Repeater {
            model: totalPages
            Rectangle {
                width: 15
                height: 5
                radius: 5
                color: index === currentPage ? "#ffaa00" : "#aaa"
            }
        }
    }
}
