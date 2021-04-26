#ifndef REGISTRATIONJSONBUILDER_H
#define REGISTRATIONJSONBUILDER_H
#include "IJsonBuilder.h"
#include <QJsonObject>
#include <QJsonValue>
#include "user.h"


class RegistrationJsonBuilder: IJsonBuilder<User>
{
public:
    virtual QJsonObject buildJson(User user);
};


#endif // REGISTRATIONJSONBUILDER_H
