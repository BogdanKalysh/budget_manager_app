#ifndef QUERYBUILDERS_H
#define QUERYBUILDERS_H

#include <QString>
#include <QVector>
#include <QPair>

QString insertQueryBuilder(QString table, QVector<QString> fields, QVector<QString> values);

QString updateQueryBuilder(QPair<QString, int> tableCredentials, QVector<QString> fields, QVector<QString> values);

QString deleteQueryBuilder(QPair<QString, int> tableCredentials);


#endif // QUERYBUILDERS_H
