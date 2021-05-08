#ifndef TRANSACTIONPARSER_H
#define TRANSACTIONPARSER_H

#include "ijsonparser.h"
#include "transaction.h"

class TransactionParser: public IJsonParser<Transaction>
{
public:
    Transaction parse(QJsonObject json) override;
    QVector<Transaction> parseVector(QJsonArray jsonArray) override;
};


#endif // TRANSACTIONPARSER_H
