#ifndef TRANSACTIONJSONBUILDER_H
#define TRANSACTIONJSONBUILDER_H

#include "IJsonBuilder.h"
#include <QJsonObject>
#include <QJsonValue>
#include "transaction.h"


class TransactionJsonBuilder: public IJsonBuilder<Transaction>
{
public:
    QJsonObject buildJson(Transaction transaction) override;
};

#endif // TRANSACTIONJSONBUILDER_H
