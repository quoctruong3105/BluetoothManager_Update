#ifndef PAIREDDEVICES_H
#define PAIREDDEVICES_H

#include <QObject>
#include <QDebug>
#include <QList>
#include <QDataStream>
#include <QVariantList>

class PairedDevices : public QObject
{
    Q_OBJECT
public:
    explicit PairedDevices(QObject *parent = nullptr);
    QMap<QString, QString> getMap();
    void setMap(QMap<QString, QString> map);
signals:
private:
    QMap<QString, QString> deviceInfo;
};

#endif // PAIREDDEVICES_H
