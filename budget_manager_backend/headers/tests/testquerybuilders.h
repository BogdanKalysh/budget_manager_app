#ifndef TESTQUERYBUILDERS_H
#define TESTQUERYBUILDERS_H

#include <QtTest/QtTest>

class TestQueryBuilders: public QObject
{
    Q_OBJECT
private slots:
    void testInsertQueryBuilder();
    void testUpdateQueryBuilder();
    void testDeleteQueryBuilder();
    void testSetUpDatabase();
};

#endif // TESTQUERYBUILDERS_H
