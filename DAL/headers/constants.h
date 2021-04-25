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
}

namespace validationMessage {

}

#endif // CONSTANTS_H
