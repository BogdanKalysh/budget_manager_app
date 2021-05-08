#ifndef QUERYBUILDERS_H
#define QUERYBUILDERS_H

#include "constants.h"
#include <QVector>
#include <QPair>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QFile>
#include <QMap>
#include <QDebug>

QSqlDatabase setUpDatabase();

QString insertQueryBuilder(QString table, QVector<QString> fields, QVector<QString> values);

QString updateQueryBuilder(QPair<QString, int> tableCredentials, QVector<QString> fields, QVector<QString> values);

QString deleteQueryBuilder(QPair<QString, int> tableCredentials);


#endif // QUERYBUILDERS_H
