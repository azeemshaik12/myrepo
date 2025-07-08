// bluetoothmanager.cpp
#include "bluetoothmanager.h"
#include <QTimer>
#include <QDebug>

BluetoothManager::BluetoothManager(QObject *parent)
    : QAbstractListModel(parent), localDevice()
{
    discoveryAgent = new QBluetoothDeviceDiscoveryAgent(this);
    connect(discoveryAgent, &QBluetoothDeviceDiscoveryAgent::deviceDiscovered,
            this, &BluetoothManager::deviceDiscovered);
    connect(discoveryAgent, &QBluetoothDeviceDiscoveryAgent::finished,
            this, &BluetoothManager::scanFinished);
    connect(&localDevice, &QBluetoothLocalDevice::pairingFinished,
            this, &BluetoothManager::onPairingFinished);
}

int BluetoothManager::rowCount(const QModelIndex &) const {
    return m_devices.count();
}

QVariant BluetoothManager::data(const QModelIndex &index, int role) const {
    if (!index.isValid() || index.row() >= m_devices.count())
        return QVariant();

    const BluetoothDeviceEntry &entry = m_devices[index.row()];
    switch (role) {
    case NameRole: return entry.name;
    case AddressRole: return entry.address;
    case StatusRole: return entry.status;
    default: return QVariant();
    }
}

QHash<int, QByteArray> BluetoothManager::roleNames() const {
    return {
        { NameRole, "name" },
        { AddressRole, "address" },
        { StatusRole, "status" }
    };
}

bool BluetoothManager::isScanning() const {
    return m_scanning;
}

void BluetoothManager::startScan() {
    beginResetModel();
    m_devices.clear();
    endResetModel();

    m_scanning = true;
    emit scanningChanged();
    discoveryAgent->start();
}

void BluetoothManager::deviceDiscovered(const QBluetoothDeviceInfo &device) {
    QString address = device.address().toString();
    for (const auto &d : m_devices) {
        if (d.address == address)
            return;
    }

    beginInsertRows(QModelIndex(), m_devices.count(), m_devices.count());
    m_devices.append({ device.name(), address, "Discovered" });
    endInsertRows();

    qDebug() << "Found:" << device.name() << address;
}

void BluetoothManager::scanFinished() {
    m_scanning = false;
    emit scanningChanged();
}

void BluetoothManager::connectTo(const QString &address) {
    int index = -1;
    for (int i = 0; i < m_devices.size(); ++i) {
        if (m_devices[i].address == address) {
            index = i;
            break;
        }
    }
    if (index == -1) return;

    updateDeviceStatus(address, "Connecting");

    QBluetoothAddress btAddr(address);

    if (localDevice.pairingStatus(btAddr) != QBluetoothLocalDevice::Paired &&
        localDevice.pairingStatus(btAddr) != QBluetoothLocalDevice::AuthorizedPaired) {
        localDevice.requestPairing(btAddr, QBluetoothLocalDevice::Paired);
        return;
    }

    if (socket) {
        socket->deleteLater();
        socket = nullptr;
    }

    socket = new QBluetoothSocket(QBluetoothServiceInfo::RfcommProtocol, this);

    connect(socket, &QBluetoothSocket::connected, this, [this, address]() {
        updateDeviceStatus(address, "Connected");
    });

    connect(socket, &QBluetoothSocket::errorOccurred, this, [this, address](QBluetoothSocket::SocketError) {
        updateDeviceStatus(address, "Failed");
        QTimer::singleShot(0, this, [this, address]() {
            removeDevice(address);
        });
    });

    QBluetoothUuid uuid(QStringLiteral("00001101-0000-1000-8000-00805F9B34FB"));
    socket->connectToService(btAddr, uuid);
}

void BluetoothManager::onPairingFinished(const QBluetoothAddress &address,
                                         QBluetoothLocalDevice::Pairing pairing) {
    if (pairing == QBluetoothLocalDevice::Paired || pairing == QBluetoothLocalDevice::AuthorizedPaired) {
        updateDeviceStatus(address.toString(), "Paired");
    } else {
        updateDeviceStatus(address.toString(), "Pairing Failed");
    }
}

void BluetoothManager::updateDeviceStatus(const QString &address, const QString &status) {
    for (int i = 0; i < m_devices.size(); ++i) {
        if (m_devices[i].address == address) {
            m_devices[i].status = status;
            emit dataChanged(index(i), index(i));
            break;
        }
    }
}

void BluetoothManager::removeDevice(const QString &address) {
    for (int i = 0; i < m_devices.size(); ++i) {
        if (m_devices[i].address == address) {
            beginRemoveRows(QModelIndex(), i, i);
            m_devices.removeAt(i);
            endRemoveRows();
            break;
        }
    }
}
