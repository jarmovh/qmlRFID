#include "qmlInterface.h"
#include <QDebug>

qmlInterface::qmlInterface(QObject *parent, QQmlContext *ctx) :
    QObject(parent)
{
    context = ctx;
    rfid = new qPhidgetRFID(this);

    connect(rfid, SIGNAL(tagOn(QVariant)), this, SLOT(onRFIDTag(QVariant)));
}

void qmlInterface::onRFIDTag(QVariant tag)
{
    qDebug()<<"tag:"<<tag;
    emit uiSetTagText(tag);
}
