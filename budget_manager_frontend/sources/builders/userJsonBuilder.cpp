#include "userJsonBuilder.h"
#include "constants.h"


QJsonObject UserJsonBuilder::buildJson(User user){
    QJsonObject jObj;
    jObj.insert(jsonbuilder::ID, QJsonValue::fromVariant(user.getId()));
    jObj.insert(jsonbuilder::NAME, QJsonValue::fromVariant(user.getName()));
    jObj.insert(jsonbuilder::EMAIL, QJsonValue::fromVariant(user.getEmail()));
    jObj.insert(jsonbuilder::PASSWORD, QJsonValue::fromVariant(user.getPassword()));

    return jObj;
}
