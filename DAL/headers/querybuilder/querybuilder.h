#ifndef QUERYBUILDER_H
#define QUERYBUILDER_H

#include <QMap>
#include <QVector>
#include <QPair>
#include <QString>

class QueryBuilder
{
public:
    QString insertQuery(const QString &table, const QVector<QString> &fields, const QVector<QString> &values);
    QString updateQuery(const QPair<QString, int> &tableCredentials, const QVector<QString> &fields, const QVector<QString> &values);
    QString deleteQuery(const QPair<QString, int> &tableCredentials);
};

#endif // QUERYBUILDER_H
