#ifndef TRANSACTIONPARSER_H
#define TRANSACTIONPARSER_H

#include "ijsonparser.h"
#include "transaction.h"

template <typename T>
class TransactionParser: IJsonParser<T>
{
public:
    virtual Transaction parse(QJsonObject json);
    virtual QVector<Transaction> parseVector(QJsonArray jsonArray);
};

#endif // TRANSACTIONPARSER_H
