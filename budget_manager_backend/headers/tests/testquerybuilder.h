#ifndef TESTQUERYBUILDER_H
#define TESTQUERYBUILDER_H

#include <QtTest/QtTest>
#include "querybuilder.h"

class TestQueryBuilder: public QObject
{
    Q_OBJECT
private slots:
    void insertQuery();
    void updateQuery();
    void deleteQuery();
private:
    QueryBuilder queryBuilder;
};

#endif // TESTQUERYBUILDER_H
