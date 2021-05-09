#ifndef DBMANAGER_H
#define DBMANAGER_H


#include "idbmanager.h"

class DBManager : public IDBManager
{

public:
    UserRepository getUserRepository() override;
    CategoryRepository getCategoryRepository() override;
    TransactionRepository getTransactionRepository() override;
};

#endif // DBMANAGER_H
