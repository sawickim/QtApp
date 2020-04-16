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

//#include <readDatabase.cpp>

#include "app.hpp"
#include "struct.hpp"



void writeFileCSV(){
    QFile csvFile("C:/Dokumenty/Qt Creator/ResultCloudFerro/CSVFile.csv");
    // Open or create the file if it does not exist
        if(csvFile.open( QIODevice::WriteOnly | QFile::Truncate | QIODevice::Append))
        {
            // Create a text stream, which will write the data
            QTextStream textStream( &csvFile );
            QStringList stringList; // The helper object QSqtringList, which will form a line

            StructLists structlist;
            int i = 0;
            while(i < structlist.listName.count() - 1){
                stringList.append(structlist.listName[i]);
                stringList.append(" ");
                stringList.append(structlist.listpath[i]);
                stringList.append(" ");
                stringList.append(structlist.listsumMD5[i]);
                stringList.append("\n");
                i++;
                /* Then send the entire file stringList by adding text flow dividers
                 * in the form of "" and putting at the end of a line terminator
                 * */

            }
            for(int i = 0; i < structlist.listName.count() - 1;i++)
                textStream << stringList[i];

        }
            // Close the file - ready
            csvFile.close();
}
