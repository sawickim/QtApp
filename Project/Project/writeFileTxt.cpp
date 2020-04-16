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

void writeFileTxt(){
    QFile file("C:/Dokumenty/Qt Creator/ResultCloudFerro/result_storage.txt");
          if(file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
          {
              // We're going to streaming text to the file
              QTextStream stream(&file);

              stream << " Data range is : beginposition:[2015-01-01T00:00:00.000Z TO 2015-01-05T00:00:00.000Z]";

              file.close();
              qDebug() << "Writing finished";
          }
}
