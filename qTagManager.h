#ifndef TAGMANAGER_H
#define TAGMANAGER_H

#include <QObject>
#include <QtSql/QtSql>
#include <QtSql/QSqlQuery>
#include <QDir>
#include <QUrl>

class qTagManager : public QObject
{
    Q_OBJECT
public:
    qTagManager(QObject *parent = 0);
    ~qTagManager();

    void addTagEntry(QString tagID, QUrl refUrl);
    QUrl getTagEntry(QString tagID);

private:

};

#endif // TAGMANAGER_H
