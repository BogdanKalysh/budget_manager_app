#ifndef TESTTRANSACTIONPARSER_H
#define TESTTRANSACTIONPARSER_H

#include "transactionparser.h"
#include <QTest>
class TestTransactionParser: public QObject
{
    Q_OBJECT
private slots:
    void parseTransaction();
    void parseTransactionArray();

private:
    TransactionParser transactionParser;
};

#endif // TESTTRANSACTIONPARSER_H
