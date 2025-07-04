#include "BluetoothScanner.h"

BluetoothScanner::BluetoothScanner(QObject *parent)
    : QObject(parent), m_agent(new QBluetoothDeviceDiscoveryAgent(this))
{
    connect(m_agent, &QBluetoothDeviceDiscoveryAgent::deviceDiscovered,
            this, &BluetoothScanner::deviceDiscovered);
    connect(m_agent, &QBluetoothDeviceDiscoveryAgent::finished,
            this, &BluetoothScanner::scanFinished);
}

void BluetoothScanner::startScan()
{
    m_devices.clear();
    emit devicesChanged();
    m_agent->start();
}

void BluetoothScanner::deviceDiscovered(const QBluetoothDeviceInfo &info)
{
    QVariantMap device;
    device["name"] = info.name();
    device["address"] = info.address().toString();
    m_devices.append(device);
    emit devicesChanged();
}

void BluetoothScanner::scanFinished()
{
    emit devicesChanged();
}

QVariantList BluetoothScanner::devices() const
{
    return m_devices;
}
