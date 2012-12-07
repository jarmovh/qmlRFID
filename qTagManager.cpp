#include "qTagManager.h"

#include <QDebug>

qTagManager::qTagManager(QObject *parent) :
    QObject(parent)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("RFID");
    db.setUserName("RFID");
    db.setPassword("RFID");
    db.setDatabaseName("RFIDTagData.sqlite.db");
    if(!db.open())
    {
        qDebug()<<"database failure";
        qDebug()<<db.lastError();
    }
    else
    {
        QSqlQuery e;
        e.exec("CREATE TABLE IF NOT EXISTS `RFIDTagData` (`idRFIDTagData` INT NOT NULL ,`tagID` TEXT NOT NULL ,`targetUrl` TEXT NOT NULL ,PRIMARY KEY (`idRFIDTagData`) )");
        qDebug()<<e.lastError();
    }

    db.close();
}

qTagManager::~qTagManager()
{
}
