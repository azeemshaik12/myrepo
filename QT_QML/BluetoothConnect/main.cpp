#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QCoreApplication>
#include "bluetoothmanager.h"
#include <QDebug>
#include <QBluetoothLocalDevice>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    // ✅ Register the BluetoothScanner type in the QML module
    qmlRegisterType<BluetoothManager>("BluetoothApp", 1, 0, "BluetoothManager");
    QBluetoothLocalDevice localDevice;

    if (localDevice.isValid()) {
        qDebug() << "Bluetooth available. Device name:" << localDevice.name();
    } else {
        qDebug() << "No Bluetooth hardware found or accessible.";
    }

    QQmlApplicationEngine engine;
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
                     &app, []() { QCoreApplication::exit(-1); },
                     Qt::QueuedConnection);

    // ✅ Load Main.qml via module (matches qt_add_qml_module URI and filename)
    engine.loadFromModule("bluetooth_app", "Main");

    return app.exec();
}
