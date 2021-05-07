#ifndef TRANSACTIONREPOSITORY_H
#define TRANSACTIONREPOSITORY_H

#include "irepository.h"
#include "transaction.h"

class TransactionRepository : public IRepository<Transaction>
{
public:
    QVector<Transaction> select(const QString &query) override;
    bool update(const Transaction &object) override;
    bool add(const Transaction &object) override;
    bool deleteObject(const int id) override;
};

#endif // TRANSACTIONREPOSITORY_H
