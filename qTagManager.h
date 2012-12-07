#ifndef TAGMANAGER_H
#define TAGMANAGER_H

#include <QObject>
#include <QtSql/QtSql>
#include <QtSql/QSqlQuery>
#include <QDir>

class qTagManager : public QObject
{
    Q_OBJECT
public:
    qTagManager(QObject *parent = 0);
    ~qTagManager();

private:

};

#endif // TAGMANAGER_H
