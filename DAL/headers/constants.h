#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <QString>

enum Type {income, expense};

namespace parser {
    const QString ID = "id";
    const QString NAME = "name";
    const QString TYPE = "type";
    const QString COLOR = "color";
    const QString AMOUNT = "amount";
    const QString DESCRIPTION = "description";
    const QString CATEGORY_ID = "categoryId";
    const QString DATE = "date";
    const QString EMAIL = "email";
    const QString PASSWORD = "password";
    const QString BALANCE = "balance";
    const QString USER_ID = "user_id";
}

namespace dal {
    const QString DBTYPE = "QPSQL";
    const QString HOST = "34.118.91.164";
    const QString USER = "andriy";
    const QString USER_PASSWORD = "root";
    const QString DBNAME = "budget-manager";

    const QString USERS = "users";
    const QString CATEGORY = "category";
    const QString TRANSACTION = "transaction";

    const QString ID = "id";
    const QString MAIL = "mail";
    const QString PASSWORD = "password";
    const QString CREATED_ON = "created_on";
    const QString ROLE = "role";
    const QString NAME = "name";
    const QString BALANCE = "balance";
    const QString USER_ID = "user_id";
    const QString TYPE = "type";
    const QString CATEGORY_ID = "category_id";
    const QString AMOUNT = "amount";
    const QString DESCRIPTION = "description";
    const QString DATE = "date";
    const QString COLOR = "color";
    const QString INCOME = "income";
    const QString EXPENSE = "expense";
}


#endif // CONSTANTS_H
