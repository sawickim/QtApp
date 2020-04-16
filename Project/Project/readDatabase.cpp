#include <QDebug>
#include <QtCore/QCoreApplication>
#include <QtSql>
//#include <QPSQLDriver>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QCryptographicHash>
#include <QSqlError>
#include <cstdio>
#include <QList>
#include <QStringList>
#include <QFile>
#include <QString>
#include <winsock2.h>
#include <windows.h>
#include <iphlpapi.h>
#include <QDir>
#include <QCoreApplication>
#include <QTextStream>



#include "app.hpp"
#include "struct.hpp"


void readDatabase(){

    QString response;

    QSqlDatabase db1 = QSqlDatabase::database();

    db1.setHostName("127.0.0.1");
    db1.setPort(5432);

    db1.setUserName("postgres");
    db1.setPassword("password");

   bool ok = db1.open();

   qDebug() << ok;

    if (db1.open())
    {
        qDebug() << "opened!";

    }
    else
    {
        qDebug() << "Error!" << db1.lastError().text();
    }

    QSqlQuery query;

    QString value1, value2, value3;
    //QSqlQuery query1(db);
    query.setForwardOnly(true);
    query.exec("select * FROM mytable");

    StructLists structlist;
    QString val1, val2, val3;
    int  z = 0;
    while (query.next()) {

        structlist.listName.append(query.value(0).toString());

        structlist.listpath.append(query.value(1).toString());

        structlist.listsumMD5.append(query.value(2).toString());

        qDebug() << structlist.listName[z];
        z++;
    }

    db1.close();
}

