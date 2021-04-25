#ifndef USERJSONBUILDER_H
#define USERJSONBUILDER_H
#include "IJsonBuilder.h"
#include <QJsonObject>
#include <QJsonValue>
#include "user.h"


class UserJsonBuilder: IJsonBuilder<User>
{
public:
    virtual QJsonObject buildJson(User user);
};


#endif // USERJSONBUILDER_H
