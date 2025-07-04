#ifndef BLUETOOTHSCANNER_H
#define BLUETOOTHSCANNER_H

#include <QObject>
#include <QBluetoothDeviceDiscoveryAgent>
#include <QBluetoothDeviceInfo>
#include <QVariantList>

class BluetoothScanner : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariantList devices READ devices NOTIFY devicesChanged)

public:
    explicit BluetoothScanner(QObject *parent = nullptr);
    Q_INVOKABLE void startScan();
    QVariantList devices() const;

signals:
    void devicesChanged();

private slots:
    void deviceDiscovered(const QBluetoothDeviceInfo &info);
    void scanFinished();

private:
    QBluetoothDeviceDiscoveryAgent *m_agent;
    QVariantList m_devices;
};

#endif // BLUETOOTHSCANNER_H
