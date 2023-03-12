#ifndef JSONCONVERTER_H
#define JSONCONVERTER_H

#include <QObject>
#include <QBluetoothDeviceInfo>
#include <QObject>
#include <QDebug>
#include <QFile>
#include <QDir>
#include <QVariant>
#include <QVariantMap>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QList>
#include <QVariantList>
#include <PairedDevices.h>

class JsonConverter : public QObject
{
    Q_OBJECT
public:
    explicit JsonConverter(QObject *parent = nullptr);
    static void writeJson(PairedDevices *obj, QString path);
    static PairedDevices* readJson(QString path);
signals:
};

#endif // JSONCONVERTER_H
