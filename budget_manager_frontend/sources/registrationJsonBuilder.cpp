#include "registrationJsonBuilder.h"
#include "constants.h"


QJsonObject RegistrationJsonBuilder::buildJson(User user){
    QJsonObject jObj;
    jObj.insert(jsonbuilder::NAME, QJsonValue::fromVariant(user.getName()));
    jObj.insert(jsonbuilder::EMAIL, QJsonValue::fromVariant(user.getEmail()));
    jObj.insert(jsonbuilder::PASSWORD, QJsonValue::fromVariant(user.getPassword()));

    return jObj;
}
