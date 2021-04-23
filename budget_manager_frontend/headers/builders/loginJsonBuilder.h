#ifndef LOGINJSONBUILDER_H
#define LOGINJSONBUILDER_H
#include "IJsonBuilder.h"
#include <QJsonObject>
#include <QJsonValue>
#include "user.h"


class LoginJsonBuilder: IJsonBuilder<User>
{
public:
    virtual QJsonObject buildJson(User user);
};

#endif // LOGINJSONBUILDER_H
