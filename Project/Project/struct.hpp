#ifndef STRUCT_H // jeżeli nie zdefiniowano makra APP_H to
#define STRUCT_H // definiuj makro APP_H


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

class StructLists{

public:
QList<QString> listName;
QList<QString> listpath;
QList<QString> listsumMD5;

};
#endif

