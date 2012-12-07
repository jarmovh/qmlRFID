#ifndef QMLINTERFACE_H
#define QMLINTERFACE_H

#include <QObject>
#include <QVariant>
#include <QQmlContext>
#include <QStringList>
#include <QString>


#include "qPhidgetRFID.h"
#include "qTagManager.h"

class qmlInterface : public QObject
{
    Q_OBJECT
public:
    explicit qmlInterface(QObject *parent = 0, QQmlContext *ctx = 0);

private:
    QQmlContext *context;
    qPhidgetRFID *rfid;
    qTagManager *tagManager;

    QStringList messageLog;

    void qmlSetTagText(QVariant text);
    void logMessage(QString message);
    
signals:
    void uiSetTagText(QVariant text);

public slots:
    void onRFIDTag(QVariant tag);
    
};

#endif // QMLINTERFACE_H
