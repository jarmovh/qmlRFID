#ifndef QMLINTERFACE_H
#define QMLINTERFACE_H

#include <QObject>
#include <QVariant>
#include <QQmlContext>

#include "qPhidgetRFID.h"

class qmlInterface : public QObject
{
    Q_OBJECT
public:
    explicit qmlInterface(QObject *parent = 0, QQmlContext *ctx = 0);

private:
    QQmlContext *context;
    qPhidgetRFID *rfid;
    void qmlSetTagText(QVariant text);
    
signals:
    void uiSetTagText(QVariant text);

public slots:
    void onRFIDTag(QVariant tag);
    
};

#endif // QMLINTERFACE_H
