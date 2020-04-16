#ifndef APP_H // jeżeli nie zdefiniowano makra APP_H to
#define APP_H // definiuj makro APP_H


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



QByteArray createSumMD5(QString path);
void writeFileCSV();
void writeFileTxt();
void myDatabase();
void readDatabase();

#endif
