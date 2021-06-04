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

QString insertQueryBuilder(const QString &table, const QVector<QString> &fields, const QVector<QString> &values);

QString updateQueryBuilder(const QPair<QString, int> &tableCredentials, const QVector<QString> &fields, const QVector<QString> &values);

QString deleteQueryBuilder(const QPair<QString, int> &tableCredentials);


#endif // QUERYBUILDERS_H
