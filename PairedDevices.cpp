#include "PairedDevices.h"

PairedDevices::PairedDevices(QObject *parent)
    : QObject{parent}
{

}

QMap<QString, QString> PairedDevices::getMap() {
    return this->deviceInfo;
}

void PairedDevices::setMap(QMap<QString, QString> map) {
    this->deviceInfo = map;
}
