#include "qPhidgetRFID.h"

#include <QDebug>

qPhidgetRFID::qPhidgetRFID(QObject *parent) :
    QObject(parent)
{
    CPhidgetRFID_create(&rfidHandle);

    CPhidget_set_OnAttach_Handler((CPhidgetHandle)rfidHandle, attachHandler, NULL);
    CPhidget_set_OnDetach_Handler((CPhidgetHandle)rfidHandle, detachHandler, NULL);
//    CPhidget_set_OnError_Handler((CPhidgetHandle)gpsHandle, errorHandler, NULL);
    CPhidgetRFID_set_OnTag_Handler(rfidHandle, tagOnHandler, this);
    CPhidgetRFID_set_OnTagLost_Handler(rfidHandle, tagLostHandler, this);

    CPhidget_open((CPhidgetHandle)rfidHandle,-1);

}

qPhidgetRFID::~qPhidgetRFID()
{
    CPhidget_close((CPhidgetHandle)rfidHandle);
    CPhidget_delete((CPhidgetHandle)rfidHandle);
}

void qPhidgetRFID::emitTagOnEvent(unsigned char *tag)
{
    qDebug()<<"tag:"<<tag;
}

void qPhidgetRFID::emitTagLostEvent()
{
    qDebug()<<"tag lost";
}

void qPhidgetRFID::onHandlerAttached()
{
    qDebug()<<"signal emit, handler attached";
}

void qPhidgetRFID::onHandlerRemoved()
{
    qDebug()<<"signal emit, handler removed";
}

//Callback functions
int attachHandler(CPhidgetHandle phid, void *userptr)
{
    //CPhidgetRFIDHandle rfid = (CPhidgetRFIDHandle)phid;
    qDebug()<<"attach handler ran";

    return 0;
}

int detachHandler(CPhidgetHandle phid, void *userptr)
{
    qDebug()<<"Detach handler ran!";
    return 0;
}

int errorHandler(CPhidgetHandle phid, void *userptr, int ErrorCode, const char *unknown)
{
    qDebug()<<"Error handler ran!";
    return 0;
}

int tagOnHandler(CPhidgetRFIDHandle phid, void *userPtr, unsigned char *tag)
{
    qPhidgetRFID* p;
    p = (qPhidgetRFID*) userPtr;

    CPhidgetRFIDHandle rfid = (CPhidgetRFIDHandle)phid;

    CPhidgetRFID_setLEDOn(rfid,1);
    CPhidgetRFID_getLastTag(rfid,tag);

    qDebug()<<tag;

    p->emitTagOnEvent(tag);

    return 0;
}

int tagLostHandler(CPhidgetRFIDHandle phid, void *userPtr, unsigned char *tag)
{
    qPhidgetRFID* p;
    p = (qPhidgetRFID*) userPtr;

    CPhidgetRFIDHandle rfid = (CPhidgetRFIDHandle)phid;

    CPhidgetRFID_setLEDOn(rfid,0);

    p->emitTagLostEvent();

    return 0;
}
