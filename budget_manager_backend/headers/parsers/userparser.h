#ifndef USERPARSER_H
#define USERPARSER_H

#include "ijsonparser.h"
#include "user.h"

class UserParser: public IJsonParser<User>
{
public:
    User parse(QJsonObject json) override;
    QVector<User> parseVector(QJsonArray jsonArray) override;
};

#endif // USERPARSER_H
