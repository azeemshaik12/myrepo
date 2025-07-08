import QtQuick 2.15
import QtQuick.Controls 2.15
import BluetoothApp 1.0

ApplicationWindow {
    visible: true
    width: 420
    height: 600
    title: "Bluetooth Scanner"

    BluetoothManager {
        id: scanner
    }

    Column {
        anchors.fill: parent
        spacing: 10
        anchors.margins: 12

        Button {
            id: scanButton
            width: parent.width
            text: scanner.scanning ? "🔄 Scanning..." : "🔍 Start Scan"
            onClicked: scanner.startScan()
            enabled: !scanner.scanning
        }

        ListView {
            id: listView
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: scanButton.bottom
            anchors.bottom: parent.bottom
            //anchors.rightMargin:10
            spacing: 8
            clip: true
            model: scanner

            delegate: Rectangle {
                width: listView.width-20
                height: 80
                color: "#f9f9f9"
                radius: 6
                border.color: "#ccc"

                Row {
                    anchors.fill: parent
                    anchors.margins: 10
                    spacing: 10

                    Column {
                        width: parent.width - 120
                        spacing: 4

                        Text {
                            text: name
                            font.bold: true
                            font.pointSize: 12
                            elide: Text.ElideRight
                        }

                        Text {
                            text: address
                            font.pointSize: 10
                            color: "#666"
                            elide: Text.ElideRight
                        }

                        Text {
                            text: status
                            font.pointSize: 10
                            color: status === "Connected" ? "green"
                                  : status === "Connecting" ? "orange"
                                  : status === "Failed" ? "red"
                                  : "#888"
                        }
                    }

                    Button {
                        text: "Connect"
                        width: 80
                        height: 30
                        anchors.verticalCenter: parent.verticalCenter
                        enabled: status !== "Connected" && status !== "Connecting"
                        onClicked: scanner.connectTo(address)
                    }
                }
            }

            ScrollBar.vertical: ScrollBar {}
        }
    }
}
