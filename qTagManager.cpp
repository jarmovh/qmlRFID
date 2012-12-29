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
        QSqlQuery q;
        q.exec("CREATE TABLE IF NOT EXISTS `RFIDTagData` (`tagID` TEXT NOT NULL ,`targetUrl` TEXT NOT NULL ,UNIQUE(`tagID`) PRIMARY KEY (`tagID`) )");
        qDebug()<<q.lastError();
    }
}

qTagManager::~qTagManager()
{
    QSqlDatabase db = QSqlDatabase::database();
    db.close();
}

void qTagManager::addTagEntry(QString tagID, QUrl refUrl)
{
    QSqlQuery q;
    q.exec("INSERT INTO `RFIDTagData` VALUES('"+tagID+"','"+refUrl.toString()+"')");
    qDebug()<<q.lastError();
}

QUrl qTagManager::getTagEntry(QString tagID)
{
    QSqlQuery q;
    q.exec("SELECT targetUrl from RFIDTagData WHERE tagID='"+tagID+"'");
    qDebug()<<q.lastError();
    QUrl retVal = QUrl("blank.url"); //default url in case of no match
    while(q.next())
    {
        //next() works since all tag id's should be unique so only one result is found from query result
        retVal = q.value("targetUrl").toUrl();
    }
    qDebug()<<retVal;
    return retVal;
}
