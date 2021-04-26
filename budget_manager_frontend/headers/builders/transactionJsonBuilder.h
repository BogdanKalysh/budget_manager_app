#ifndef TRANSACTIONJSONBUILDER_H
#define TRANSACTIONJSONBUILDER_H

#include "IJsonBuilder.h"
#include <QJsonObject>
#include <QJsonValue>
#include "transaction.h"

class TransactionJsonBuilder: IJsonBuilder<Transaction>
{
public:
    virtual QJsonObject buildJson(Transaction transaction);
};

#endif // TRANSACTIONJSONBUILDER_H
