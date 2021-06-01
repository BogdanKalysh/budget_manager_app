#include "querybuilders.h"

#include <Poco/Crypto/CipherKey.h>
#include <Poco/Crypto/Cipher.h>
#include <Poco/Crypto/CipherFactory.h>

QString insertQueryBuilder(QString table, QVector<QString> fields, QVector<QString> values)
{
    //          EXAMPLE QUERY
    //  INSERT INTO table (column1, column2, ...)
    //  VALUES (value1, value2, ...)

    if(fields.size() == values.size()) {
        QString queryInsert = "INSERT INTO " + table + " (";
        QString queryValues = " VALUES (";

        for(int i = 0; i < fields.size(); i++) {
            queryInsert += fields[i];
            queryValues += "'" + values[i] + "'";

            if(i != fields.size() - 1) {
                queryInsert += ", ";
                queryValues += ", ";
            } else {
                queryInsert += ")";
                queryValues += ")";
            }
        }
        return queryInsert + queryValues;
    }
    return "";
}


QString updateQueryBuilder(QPair<QString, int> tableCredentials, QVector<QString> fields, QVector<QString> values)
{
    //      EXAMPLE QUERY
    //  UPDATE table_name
    //  SET column1 = value1, column2 = value2, ...
    //  WHERE condition

    if(fields.size() == values.size()) {
        QString queryUpdate = "UPDATE " + tableCredentials.first + " SET ";

        for(int i = 0; i < fields.size(); i++){
            queryUpdate += fields[i] + " = '" + values[i] + "'";

            if(i != fields.size() - 1)
                queryUpdate += ", ";
            else
                queryUpdate += " WHERE id = " + QString::number(tableCredentials.second);
        }
        return queryUpdate;
    }
    return "";
}

QString deleteQueryBuilder(QPair<QString, int> tableCredentials)
{
    //      EXEMPLE QUERY
    // DELETE FROM table_name WHERE condition

    return "DELETE FROM " + tableCredentials.first + " WHERE id = " + QString::number(tableCredentials.second);
}

using namespace Poco::Crypto;

QSqlDatabase setUpDatabase()
{

//    QFile dbFile(dal::DBCONFIGPATH);
    QFile dbFile("../DAL/DB.txt");


    if(!dbFile.open(QIODevice::ReadOnly)) {
        qDebug() << "Error: Opening file DB.txt";
        return QSqlDatabase();
    }
    qDebug() << "Fuck!!!";
    CipherFactory& factory = CipherFactory::defaultFactory();
    Cipher* pCipher = factory.createCipher(CipherKey(dal::AES.toStdString(), dal::KEY.toStdString()));

    QTextStream in(&dbFile);

    QString dbConfigContent = pCipher->decryptString(in.readAll().toStdString(), Cipher::ENC_BASE64).c_str();
    dbFile.close();

    QMap<QString, QString> dbConfig;
    QString field = "";
    QString value = "";
    bool firstPart = true;


    for(int i = 0; i <= dbConfigContent.length(); i++){

        if(i == dbConfigContent.length() || dbConfigContent[i] == '\n'){
            dbConfig[field] = value;
            qDebug() << field << value;
            field = "";
            value = "";
            firstPart = true;
            continue;
        }

        if(dbConfigContent[i] == '\r')
            continue;

        if(dbConfigContent[i] == ':'){
            firstPart = false;
            continue;
        }

        if(firstPart)
            field += dbConfigContent[i];
        else
            value += dbConfigContent[i];

    }


    QSqlDatabase db = QSqlDatabase::addDatabase(dbConfig[dal::DB]);
    qDebug() << dbConfig[dal::HOST];
    qDebug() << dbConfig[dal::DBNAME];
    qDebug() << dbConfig[dal::USER];
    qDebug() << dbConfig[dal::USER_PASSWORD];
    db.setHostName(dbConfig[dal::HOST]);
    db.setDatabaseName(dbConfig[dal::DBNAME]);
    db.setUserName(dbConfig[dal::USER]);
    db.setPassword(dbConfig[dal::USER_PASSWORD]);

    return db;
}
