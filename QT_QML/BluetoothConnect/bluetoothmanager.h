// bluetoothmanager.h
#pragma once

#include <QObject>
#include <QAbstractListModel>
#include <QBluetoothDeviceDiscoveryAgent>
#include <QBluetoothLocalDevice>
#include <QBluetoothSocket>

struct BluetoothDeviceEntry {
    QString name;
    QString address;
    QString status; // Discovered, Connecting, Connected, Failed, Offline
};

class BluetoothManager : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(bool scanning READ isScanning NOTIFY scanningChanged)

public:
    enum Roles {
        NameRole = Qt::UserRole + 1,
        AddressRole,
        StatusRole
    };

    explicit BluetoothManager(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE void startScan();
    Q_INVOKABLE void connectTo(const QString &address);

    bool isScanning() const;

signals:
    void scanningChanged();

private slots:
    void deviceDiscovered(const QBluetoothDeviceInfo &device);
    void scanFinished();
    void onPairingFinished(const QBluetoothAddress &address, QBluetoothLocalDevice::Pairing pairing);

private:
    QList<BluetoothDeviceEntry> m_devices;
    QBluetoothDeviceDiscoveryAgent *discoveryAgent;
    QBluetoothLocalDevice localDevice;
    QBluetoothSocket *socket = nullptr;
    bool m_scanning = false;

    void updateDeviceStatus(const QString &address, const QString &status);
    void removeDevice(const QString &address);
};

