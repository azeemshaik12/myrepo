import QtQuick 2.15
import QtQuick.Controls 2.15
import BluetoothScan 1.0

ApplicationWindow {
    visible: true
    width: 400
    height: 600
    title: "QML Bluetooth Scanner"

    BluetoothScanner {
        id: scanner
    }

    Column {
        anchors.fill: parent
        spacing: 12
        padding: 20

        Button {
            text: "Scan for Devices"
            onClicked: scanner.startScan()
        }

        ListView {
            width: parent.width
            height: parent.height - 100
            model: scanner.devices
            delegate: Rectangle {
                width: parent.width
                height: 60
                color: "lightblue"
                border.color: "gray"
                border.width: 1

                Column {
                    anchors.centerIn: parent
                    spacing: 5
                    Text { text: modelData.name; font.bold: true }
                    Text { text: modelData.address; font.pixelSize: 12 }
                }
            }
        }
    }
}
