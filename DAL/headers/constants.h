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
    const QString CATEGORY_ID = "category_id";
    const QString DATE = "date";
    const QString EMAIL = "email";
    const QString PASSWORD = "password";
    const QString BALANCE = "balance";
    const QString USER_ID = "user_id";
    const QString START_DATE = "start_date";
    const QString END_DATE = "end_date";
}

namespace dal {
    const QString DB = "DB";
    const QString HOST = "HOST";
    const QString USER = "USER";
    const QString USER_PASSWORD = "PASSWORD";
    const QString DBNAME = "DBNAME";
    const QString DBCONFIGPATH = "../DAL/DB.txt";
    const QString USERS = "users";
    const QString CATEGORY = "category";
    const QString TRANSACTION = "transaction";
    const QString KEY = "budget_manager";
    const QString AES = "aes-256-ecb";

    const QString ID = "id";
    const QString MAIL = "mail";
    const QString PASSWORD = "password";
    const QString CREATED_ON = "created_on";
    const QString ROLE = "role";
    const QString CATEGORY_NAME = "category_name";
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
