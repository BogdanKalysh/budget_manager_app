#ifndef USERPARSER_H
#define USERPARSER_H

#include "ijsonparser.h"
#include "user.h"


class UserParser: public IJsonParser<User>
{
public:
    User parse(const QJsonObject &json) override;
    QVector<User> parseVector(const QJsonArray &jsonArray) override;
};

#endif // USERPARSER_H
