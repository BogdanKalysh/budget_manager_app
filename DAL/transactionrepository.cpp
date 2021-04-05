#include "transactionrepository.h"

QVector<Transaction> TransactionRepository::select(QString query)
{
    //No realization yet
    //it's pseudo result
    QVector<Transaction> transactions;
    transactions.push_back(Transaction(1, 300, QDate(2020, 04, 27), "going to a restaurant", 2));
    return transactions;
}

bool TransactionRepository::update(Transaction &object)
{
    //No realization yet
    //it's pseudo result
    return true;
}

bool TransactionRepository::add(Transaction &object)
{
    //No realization yet
    //it's pseudo result
    return true;
}

bool TransactionRepository::deleteObject(int id)
{
    //No realization yet
    //it's pseudo result
    return true;
}
