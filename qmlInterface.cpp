#include "qmlInterface.h"
#include <QDebug>

qmlInterface::qmlInterface(QObject *parent, QQmlContext *ctx) :
    QObject(parent)
{
    context = ctx;
    rfid = new qPhidgetRFID(this);
    tagManager = new qTagManager(this);

    connect(rfid, SIGNAL(tagOn(QVariant)), this, SLOT(onRFIDTag(QVariant)));

}

void qmlInterface::logMessage(QString message)
{
    messageLog.append(message);
    context->setContextProperty("logMessageModel",QVariant::fromValue(messageLog));
}

void qmlInterface::onRFIDTag(QVariant tag)
{
    qDebug()<<"tag:"<<tag;
    logMessage("Read tag: "+tag.toString());
    //emit uiSetTagText(tag);
    //for testing
    //tagManager->addTagEntry(tag.toString(),QUrl("testi.url"));
    emit uiGoToUrl( QVariant::fromValue(tagManager->getTagEntry(tag.toString())) );
}
