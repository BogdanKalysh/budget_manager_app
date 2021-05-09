#include "dbmanager.h"

UserRepository DBManager::getUserRepository()
{
    return UserRepository();
}

CategoryRepository DBManager::getCategoryRepository()
{
    return CategoryRepository();
}

TransactionRepository DBManager::getTransactionRepository()
{
    return TransactionRepository();
}


