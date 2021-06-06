#include "querybuilder.h"


QString QueryBuilder::insertQuery(const QString &table, const QVector<QString> &fields, const QVector<QString> &values)
{
    //          EXAMPLE QUERY
    //  INSERT INTO table (column1, column2, ...)
    //  VALUES (value1, value2, ...)

    if (fields.size() == values.size()) {
        QString queryInsert = "INSERT INTO " + table + " (";
        QString queryValues = " VALUES (";

        for (int i = 0; i < fields.size(); i++) {
            queryInsert += fields[i];
            queryValues += "'" + values[i] + "'";

            if (i != fields.size() - 1) {
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

QString QueryBuilder::updateQuery(const QPair<QString, int> &tableCredentials, const QVector<QString> &fields, const QVector<QString> &values)
{
    //      EXAMPLE QUERY
    //  UPDATE table_name
    //  SET column1 = value1, column2 = value2, ...
    //  WHERE condition

    if (fields.size() == values.size()) {
        QString queryUpdate = "UPDATE " + tableCredentials.first + " SET ";

        for (int i = 0; i < fields.size(); i++) {
            queryUpdate += fields[i] + " = '" + values[i] + "'";

            if (i != fields.size() - 1)
                queryUpdate += ", ";
            else
                queryUpdate += " WHERE id = " + QString::number(tableCredentials.second);
        }

        return queryUpdate;
    }

    return "";
}

QString QueryBuilder::deleteQuery(const QPair<QString, int> &tableCredentials)
{
    //      EXEMPLE QUERY
    // DELETE FROM table_name WHERE condition

    return "DELETE FROM " + tableCredentials.first + " WHERE id = " + QString::number(tableCredentials.second);
}
