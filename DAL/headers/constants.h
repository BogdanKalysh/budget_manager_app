#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <QString>

namespace dal {
    const QString DB = "DB";
    const QString HOST = "HOST";
    const QString USER = "USER";
    const QString USER_PASSWORD = "PASSWORD";
    const QString DBNAME = "DBNAME";
    const QString DBCONFIGPATH = "../DAL/DB.txt";
    const QString KEY = "budget_manager";
    const QString AES = "aes-256-ecb";
//    const QString DBCONFIGPATH = "../../../../DAL/DB.txt";
}

namespace models{
    const QString USERS = "users";
    const QString CATEGORY = "category";
    const QString TRANSACTION = "transaction";

    const QString ID = "id";
    const QString NAME = "name";
    const QString MAIL = "mail";
    const QString PASSWORD = "password";
    const QString CREATED_ON = "created_on";
    const QString CATEGORY_NAME = "category_name";
    const QString USER_ID = "user_id";
    const QString TYPE = "type";
    const QString CATEGORY_ID = "category_id";
    const QString AMOUNT = "amount";
    const QString DESCRIPTION = "description";
    const QString DATE = "date";
    const QString COLOR = "color";
    const QString INCOME = "income";
    const QString EXPENSE = "expense";
    const QString START_DATE = "start_date";
    const QString END_DATE = "end_date";
}

namespace logger{
    const QString LOGFILEPATH = "../budget_manager_backend/logfile.log";
//    const QString LOGFILEPATH = "../../../../budget_manager_backend/logfile.log";
}

namespace handlers{
    const QString USERPATH = "/user";
    const QString CATEGORYPATH = "/category";
    const QString TRANSACTIONPATH = "/transaction";
    const QString APPLICATIONJSON = "application/json";
}

#endif // CONSTANTS_H
