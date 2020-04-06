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


QList<QString> listName;
QList<QString> listpath;
QList<QString> listsumMD5;


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    myDatabase();

    createSumMD5("c://S2A_MSIL1C_20200322T065621_N0209_R063_T40TDP_20200322T090045.SAFE/MTD_MSIL1C.xml");
    createSumMD5("c://S2A_MSIL1C_20200322T065621_N0209_R063_T40TDP_20200322T090045.SAFE/GRANULE/L1C_T40TDP_A024799_20200322T065842/MTD_TL.xml");
    createSumMD5("c://S2A_MSIL1C_20200322T065621_N0209_R063_T40TDP_20200322T090045.SAFE/DATASTRIP/DS_SGS__20200322T090045_S20200322T065842/MTD_DS.xml");
    createSumMD5("c://S2A_MSIL1C_20200322T065621_N0209_R063_T40TDP_20200322T090045.SAFE/DATASTRIP/DS_SGS__20200322T090045_S20200322T065842/QI_DATA/SENSOR_QUALITY.xml");
    createSumMD5("c://S2A_MSIL1C_20200322T065621_N0209_R063_T40TDP_20200322T090045.SAFE/DATASTRIP/DS_SGS__20200322T090045_S20200322T065842/QI_DATA/RADIOMETRIC_QUALITY.xml");
    createSumMD5("c://S2A_MSIL1C_20200322T065621_N0209_R063_T40TDP_20200322T090045.SAFE/DATASTRIP/DS_SGS__20200322T090045_S20200322T065842/QI_DATA/GEOMETRIC_QUALITY.xml");
    createSumMD5("c://S2A_MSIL1C_20200322T065621_N0209_R063_T40TDP_20200322T090045.SAFE/DATASTRIP/DS_SGS__20200322T090045_S20200322T065842/QI_DATA/GENERAL_QUALITY.xml");
    createSumMD5("c://S2A_MSIL1C_20200322T065621_N0209_R063_T40TDP_20200322T090045.SAFE/DATASTRIP/DS_SGS__20200322T090045_S20200322T065842/QI_DATA/FORMAT_CORRECTNESS.xml");

    readDatabase();

    writeFileCSV();

    writeFileTxt();

    return a.exec();

}


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


void writeFileCSV(){
    QFile csvFile("C:/Dokumenty/Qt Creator/ResultCloudFerro/CSVFile.csv");
    // Open or create the file if it does not exist
        if(csvFile.open( QIODevice::WriteOnly | QFile::Truncate | QIODevice::Append))
        {
            // Create a text stream, which will write the data
            QTextStream textStream( &csvFile );
            QStringList stringList; // The helper object QSqtringList, which will form a line
                   
            int i = 0;
            while(i < listName.count() - 1){
                stringList.append(listName[i]);
                stringList.append(" ");
                stringList.append(listpath[i]);
                stringList.append(" ");
                stringList.append(listsumMD5[i]);
                stringList.append("\n");
                i++;
                /* Then send the entire file stringList by adding text flow dividers
                 * in the form of "" and putting at the end of a line terminator
                 * */

            }
            for(int i = 0; i < listName.count() - 1;i++)
                textStream << stringList[i];

        }
            // Close the file - ready
            csvFile.close();
}


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

    QString val1, val2, val3;
    int  z = 0;
    while (query.next()) {

        listName.append(query.value(0).toString());

        listpath.append(query.value(1).toString());

        listsumMD5.append(query.value(2).toString());

        qDebug() << listName[z];
        z++;
    }

    db1.close();
}

