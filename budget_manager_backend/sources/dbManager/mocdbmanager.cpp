#include "mocdbmanager.h"


IRepository<User> *MocDBManager::getUserRepository()
{
    return new MocUserRepository();
}

IRepository<Category> *MocDBManager::getCategoryRepository()
{
    return new MocCategoryRepository();
}

IRepository<Transaction> *MocDBManager::getTransactionRepository()
{
    return new MocTransactionRepository();
}
