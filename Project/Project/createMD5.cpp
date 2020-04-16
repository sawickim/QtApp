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

QByteArray createSumMD5(QString path){

    QFile file(path);

        if (file.open(QIODevice::ReadOnly)) {
            QByteArray fileData = file.readAll();
            QByteArray hashData = QCryptographicHash::hash(fileData, QCryptographicHash::Md5);

            qDebug() << hashData.toHex();

            return hashData.toHex();
        }
    file.close();
}
