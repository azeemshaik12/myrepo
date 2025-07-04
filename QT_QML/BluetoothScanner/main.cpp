#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QCoreApplication>
#include "bluetoothscanner.h"
#include <QDebug>
#include <QBluetoothLocalDevice>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    // ✅ Register the BluetoothScanner type in the QML module
    qmlRegisterType<BluetoothScanner>("bluetoothscan", 1, 0, "BluetoothScanner");
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
    engine.loadFromModule("bluetoothscan", "Main");

    return app.exec();
}
