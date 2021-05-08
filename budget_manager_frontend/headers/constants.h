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
    const QString CATEGORYID = "categoryId";
    const QString DATE = "date";
    const QString EMAIL = "email";
    const QString PASSWORD = "password";
    const QString CATEGORYNAME = "category_name";
    const QString INCOME = "income";
    const QString EXPENCE = "expence";

}

#endif // CONSTANTS_H
