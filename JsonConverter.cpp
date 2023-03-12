#include "JsonConverter.h"

JsonConverter::JsonConverter(QObject *parent)
    : QObject{parent}
{

}

void JsonConverter::writeJson(PairedDevices *obj, QString path)
{
    QVariantMap map;
    QVariantMap items;

    foreach(QString key, obj->getMap().keys()) {
        items.insert(key, QVariant(obj->getMap().value(key)));
    }

    map["items"] = QVariant(items);

    QJsonDocument document = QJsonDocument::fromVariant(map);

    QFile file(path);
    if(!file.open(QIODevice::WriteOnly)) {
        qCritical() << "Could not write file!";
        qCritical() << file.errorString();
        return;
    }

    file.write(document.toJson());
    file.close();

}

PairedDevices *JsonConverter::readJson(QString path)
{
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly)) {
        qCritical() << "Could not read file!";
        qCritical() << file.errorString();
        return nullptr;
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument document = QJsonDocument::fromJson(data);
    PairedDevices *t = new PairedDevices();
    QVariantMap vmap = qvariant_cast<QVariantMap>(document["items"]);

    QMap<QString,QString> map;
    foreach(QString key, vmap.keys()) {
        map.insert(key,vmap[key].toString());
    }
    t->setMap(map);

    return  t;
}
