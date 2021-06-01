#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <QString>

enum Type {income, expense};

namespace jsonbuilder {
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
    const QString CATEGORYNAME = "category_name";
    const QString INCOME = "income";
    const QString EXPENSE = "expense";
    const QString USER_ID = "user_id";
    const QString START_DATE = "start_date";
    const QString END_DATE = "end_date";

    const QString USERURL = "http://localhost:5000/user";
    const QString CATEGORYURL = "http://localhost:5000/category";
    const QString TRANSACTIONURL = "http://localhost:5000/transaction";

    const QString SETTINGSICONPATH = ":/new/img/settings_icon.png";
    const QString USERICONPATH = ":/new/img/user_icon.png";

    const QString PIECHARTCOLOR = "#528bba";

}

#endif // CONSTANTS_H
