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

//#include <createMD5.cpp>

#include "app.hpp"

void myDatabase(){

    QString response;

    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");

    db.setHostName("127.0.0.1");
    db.setPort(5432);

    db.setUserName("postgres");
    db.setPassword("password");

   bool ok = db.open();

   qDebug() << ok;

    if (db.open())
    {
        qDebug() << "opened dataBase!";

    }
    else
    {
        qDebug() << "Error!" << db.lastError().text();
    }

    QSqlQuery query;

    query.exec("create table mytable "
               "(nameFile varchar(120), "
               "path varchar(500), "
               "sumMD5 varchar(150))");

    query.prepare("insert into mytable (nameFile, path, sumMD5) values(:nameFile,:path,:sumMD5)");

    QString sum1 = createSumMD5("c://S2A_MSIL1C_20200322T065621_N0209_R063_T40TDP_20200322T090045.SAFE/MTD_MSIL1C.xml");
    QString path1 = "c://S2A_MSIL1C_20200322T065621_N0209_R063_T40TDP_20200322T090045.SAFE/MTD_MSIL1C.xml";
    QString name1 = "MTD_MSIL1C.xml";

    query.bindValue(":nameFile",name1);
    query.bindValue(":path",path1);
    query.bindValue(":sumMD5",sum1);

    query.exec();

    query.exec("create table mytable "
               "(nameFile varchar(120), "
               "path varchar(500), "
               "sumMD5 varchar(150))");

    query.prepare("insert into mytable (nameFile, path, sumMD5) values(:nameFile,:path,:sumMD5)");

    QString sum2 = createSumMD5("c://S2A_MSIL1C_20200322T065621_N0209_R063_T40TDP_20200322T090045.SAFE/GRANULE/L1C_T40TDP_A024799_20200322T065842/MTD_TL.xml");
    QString path2 = "c://S2A_MSIL1C_20200322T065621_N0209_R063_T40TDP_20200322T090045.SAFE/GRANULE/L1C_T40TDP_A024799_20200322T065842/MTD_TL.xml";
    QString name2 = "MTD_TL.xml";

    query.bindValue(":nameFile",name2);
    query.bindValue(":path",path2);
    query.bindValue(":sumMD5",sum2);

    query.exec();

    query.exec("create table mytable "
               "(nameFile varchar(120), "
               "path varchar(500), "
               "sumMD5 varchar(150))");

    query.prepare("insert into mytable (nameFile, path, sumMD5) values(:nameFile,:path,:sumMD5)");

    QString sum3 = createSumMD5("c://S2A_MSIL1C_20200322T065621_N0209_R063_T40TDP_20200322T090045.SAFE/DATASTRIP/DS_SGS__20200322T090045_S20200322T065842/MTD_DS.xml");
    QString path3 = "c://S2A_MSIL1C_20200322T065621_N0209_R063_T40TDP_20200322T090045.SAFE/DATASTRIP/DS_SGS__20200322T090045_S20200322T065842/MTD_DS.xml";
    QString name3 = "MTD_DS.xml";

    query.bindValue(":nameFile",name3);
    query.bindValue(":path",path2);
    query.bindValue(":sumMD5",sum3);

    query.exec();

    query.exec("create table mytable "
               "(nameFile varchar(120), "
               "path varchar(500), "
               "sumMD5 varchar(150))");

    query.prepare("insert into mytable (nameFile, path, sumMD5) values(:nameFile,:path,:sumMD5)");

    QString sum4 = createSumMD5("c://S2A_MSIL1C_20200322T065621_N0209_R063_T40TDP_20200322T090045.SAFE/DATASTRIP/DS_SGS__20200322T090045_S20200322T065842/QI_DATA/SENSOR_QUALITY.xml");
    QString path4 = "c://S2A_MSIL1C_20200322T065621_N0209_R063_T40TDP_20200322T090045.SAFE/DATASTRIP/DS_SGS__20200322T090045_S20200322T065842/QI_DATA/SENSOR_QUALITY.xml";
    QString name4 = "SENSOR_QUALITY.xml";

    query.bindValue(":nameFile",name4);
    query.bindValue(":path",path4);
    query.bindValue(":sumMD5",sum4);

    query.exec();

    QString sum5 = createSumMD5("c://S2A_MSIL1C_20200322T065621_N0209_R063_T40TDP_20200322T090045.SAFE/DATASTRIP/DS_SGS__20200322T090045_S20200322T065842/QI_DATA/RADIOMETRIC_QUALITY.xml");
    QString path5 = "c://S2A_MSIL1C_20200322T065621_N0209_R063_T40TDP_20200322T090045.SAFE/DATASTRIP/DS_SGS__20200322T090045_S20200322T065842/QI_DATA/RADIOMETRIC_QUALITY.xml";
    QString name5 = "RADIOMETRIC_QUALITY.xml";

    query.exec("create table mytable "
               "(nameFile varchar(120), "
               "path varchar(500), "
               "sumMD5 varchar(150))");

    query.prepare("insert into mytable (nameFile, path, sumMD5) values(:nameFile,:path,:sumMD5)");


    query.bindValue(":nameFile",name5);
    query.bindValue(":path",path5);
    query.bindValue(":sumMD5",sum5);

    query.exec();

    query.exec("create table mytable "
               "(nameFile varchar(120), "
               "path varchar(500), "
               "sumMD5 varchar(150))");

    query.prepare("insert into mytable (nameFile, path, sumMD5) values(:nameFile,:path,:sumMD5)");

    QString sum6 = createSumMD5("c://S2A_MSIL1C_20200322T065621_N0209_R063_T40TDP_20200322T090045.SAFE/DATASTRIP/DS_SGS__20200322T090045_S20200322T065842/QI_DATA/GEOMETRIC_QUALITY.xml");
    QString path6 = "c://S2A_MSIL1C_20200322T065621_N0209_R063_T40TDP_20200322T090045.SAFE/DATASTRIP/DS_SGS__20200322T090045_S20200322T065842/QI_DATA/GEOMETRIC_QUALITY.xml";
    QString name6 = "GEOMETRIC_QUALITY.xml";


    query.bindValue(":nameFile",name6);
    query.bindValue(":path",path6);
    query.bindValue(":sumMD5",sum6);

    query.exec();

    query.exec("create table mytable "
               "(nameFile varchar(120), "
               "path varchar(500), "
               "sumMD5 varchar(150))");

    query.prepare("insert into mytable (nameFile, path, sumMD5) values(:nameFile,:path,:sumMD5)");

    QString sum7 = createSumMD5("c://S2A_MSIL1C_20200322T065621_N0209_R063_T40TDP_20200322T090045.SAFE/DATASTRIP/DS_SGS__20200322T090045_S20200322T065842/QI_DATA/GENERAL_QUALITY.xml");
    QString path7 = "c://S2A_MSIL1C_20200322T065621_N0209_R063_T40TDP_20200322T090045.SAFE/DATASTRIP/DS_SGS__20200322T090045_S20200322T065842/QI_DATA/GENERAL_QUALITY.xml";
    QString name7 = "GENERAL_QUALITY.xml";

    query.bindValue(":nameFile",name7);
    query.bindValue(":path",path7);
    query.bindValue(":sumMD5",sum7);

    query.exec();

    query.exec("create table mytable "
               "(nameFile varchar(120), "
               "path varchar(500), "
               "sumMD5 varchar(150))");

    query.prepare("insert into mytable (nameFile, path, sumMD5) values(:nameFile,:path,:sumMD5)");

    QString sum8 = createSumMD5("c://S2A_MSIL1C_20200322T065621_N0209_R063_T40TDP_20200322T090045.SAFE/DATASTRIP/DS_SGS__20200322T090045_S20200322T065842/QI_DATA/FORMAT_CORRECTNESS.xml");
    QString path8 = "c://S2A_MSIL1C_20200322T065621_N0209_R063_T40TDP_20200322T090045.SAFE/DATASTRIP/DS_SGS__20200322T090045_S20200322T065842/QI_DATA/FORMAT_CORRECTNESS.xml";
    QString name8 = "FORMAT_CORRECTNESS.xml";

    query.bindValue(":nameFile",name8);
    query.bindValue(":path",path8);
    query.bindValue(":sumMD5",sum8);

    if (query.exec()) {
      // got no error, proceed
      qDebug() << "Yay! Great entity";
    } else {
      // got an error, deal with it
      qDebug() << query.executedQuery();
      qDebug() << query.lastError();
    }

    db.close();

    qDebug() << "end";
}



