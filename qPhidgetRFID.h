#ifndef QPHIDGETRFID_H
#define QPHIDGETRFID_H

#include <QObject>
#include <QVariant>
#include <QByteArray>
#include "phidget21.h"

class qPhidgetRFID : public QObject
{
    Q_OBJECT
public:
    explicit qPhidgetRFID(QObject *parent = 0);
    ~qPhidgetRFID();

    void emitTagOnEvent(unsigned char *tag);
    void emitTagLostEvent();

private:
    CPhidgetRFIDHandle rfidHandle;
    bool checkIfDeviceConnected();

signals:
    void handlerAttached();
    void handlerRemoved();
    void tagOn(QVariant);
    
public slots:
    void onHandlerAttached();
    void onHandlerRemoved();
    
};

int attachHandler(CPhidgetHandle phid, void *userptr);
int detachHandler(CPhidgetHandle phid, void *userptr);
int errorHandler(CPhidgetHandle phid, void *userptr);
int tagOnHandler(CPhidgetRFIDHandle phid, void *userPtr, unsigned char *tag);
int tagLostHandler(CPhidgetRFIDHandle phid, void *userPtr, unsigned char *tag);
#endif // QPHIDGETRFID_H
