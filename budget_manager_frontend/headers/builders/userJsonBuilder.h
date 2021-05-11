#ifndef USERJSONBUILDER_H
#define USERJSONBUILDER_H

#include "IJsonBuilder.h"
#include <QJsonObject>
#include <QJsonValue>
#include "user.h"


class UserJsonBuilder: public IJsonBuilder<User>
{
public:
    QJsonObject buildJson(User user) override;
};

#endif // USERJSONBUILDER_H
