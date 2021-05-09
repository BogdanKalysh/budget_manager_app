#ifndef IDBMANAGER_H
#define IDBMANAGER_H

#include "userrepository.h"
#include "categoryrepository.h"
#include "transactionrepository.h"

class IDBManager{
public:
    virtual UserRepository getUserRepository() = 0;
    virtual CategoryRepository getCategoryRepository() = 0;
    virtual TransactionRepository getTransactionRepository() = 0;
};

#endif // IDBMANAGER_H
