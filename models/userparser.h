#ifndef USERPARSER_H
#define USERPARSER_H

#include "ijsonparser.h"
#include "user.h"

template <typename T>
class UserParser: IJsonParser<T>
{
public:
    virtual User parse(QJsonObject json);
    virtual QVector<User> parseVector(QJsonArray jsonArray);
};

#endif // USERPARSER_H
