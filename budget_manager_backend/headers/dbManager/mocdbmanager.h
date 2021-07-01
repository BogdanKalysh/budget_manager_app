#ifndef MOCDBMANAGER_H
#define MOCDBMANAGER_H

#include "idbmanager.h"

class MocDBManager :public IDBManager
{
public:
    IRepository<User> *getUserRepository() override;
    IRepository<Category> *getCategoryRepository() override;
    IRepository<Transaction> *getTransactionRepository() override;
};

#endif // MOCDBMANAGER_H
