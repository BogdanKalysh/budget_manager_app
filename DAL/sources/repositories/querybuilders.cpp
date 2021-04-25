#include "querybuilders.h"

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

QSqlDatabase setUpDatabase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase(dal::DBTYPE);
    db.setHostName(dal::HOST);
    db.setDatabaseName(dal::DBNAME);
    db.setUserName(dal::USER);
    db.setPassword(dal::USER_PASSWORD);

    return db;
}
