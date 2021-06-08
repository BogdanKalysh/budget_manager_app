#ifndef TESTTRANSACTIONJSONBUILDER_H
#define TESTTRANSACTIONJSONBUILDER_H

#include "transactionjsonbuilder.h"
#include <QTest>

class TestTransactionJsonBulder: public QObject
{
    Q_OBJECT
private slots:
    void testBuildJson();

private:
    TransactionJsonBuilder transactionJsonBuilder;
};

#endif // TESTTRANSACTIONJSONBUILDER_H
