#include "moctransactionrepository.h"

using namespace models;

QVector<Transaction> MocTransactionRepository::select(const QString &query)
{
    QVector<Transaction> transactions;
    transactions.push_back(Transaction(1,100,QDate(),"description1",1));
    transactions.push_back(Transaction(2,200,QDate(),"description2",1));
    transactions.push_back(Transaction(3,300,QDate(),"description3",1));
    transactions.push_back(Transaction(4,400,QDate(),"description4",1));

    return transactions;
}

bool MocTransactionRepository::update(const Transaction &object)
{
   return true;
}

bool MocTransactionRepository::add(const Transaction &object)
{
    return true;
}

bool MocTransactionRepository::deleteObject(const int id)
{
    return true;
}
