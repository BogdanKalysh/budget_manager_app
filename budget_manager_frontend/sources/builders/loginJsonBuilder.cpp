#include "loginJsonBuilder.h"
#include "constants.h"


QJsonObject LoginJsonBuilder::buildJson(User user){
    QJsonObject jObj;
    jObj.insert(jsonbuilder::EMAIL, QJsonValue::fromVariant(user.getEmail()));
    jObj.insert(jsonbuilder::PASSWORD, QJsonValue::fromVariant(user.getPassword()));

    return jObj;
}
