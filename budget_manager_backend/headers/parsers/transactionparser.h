#ifndef TRANSACTIONPARSER_H
#define TRANSACTIONPARSER_H

#include "ijsonparser.h"
#include "transaction.h"

class TransactionParser: public IJsonParser<Transaction>
{
public:
    using ptr = std::shared_ptr<IJsonParser<Transaction>>;

    Transaction parse(const QJsonObject &json) override;
    QVector<Transaction> parseVector(const QJsonArray &jsonArray) override;
};


#endif // TRANSACTIONPARSER_H
