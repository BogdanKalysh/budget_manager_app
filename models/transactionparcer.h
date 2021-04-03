#ifndef TRANSACTIONPARCER_H
#define TRANSACTIONPARCER_H

#include "ijsonparcer.h"
#include "transaction.h"

template <typename T>
class TransactionParcer: IJsonParcer<T>
{
public:
    virtual Transaction parce(QJsonObject json);
};

#endif // TRANSACTIONPARCER_H
