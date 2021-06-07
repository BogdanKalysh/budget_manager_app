#include "userJsonBuilder.h"
#include "constants.h"


QJsonObject UserJsonBuilder::buildJson(const User &user){
    QJsonObject jObj;
    jObj.insert(models::ID, QJsonValue::fromVariant(user.getId()));
    jObj.insert(models::NAME, QJsonValue::fromVariant(user.getName()));
    jObj.insert(models::MAIL, QJsonValue::fromVariant(user.getEmail()));
    jObj.insert(models::PASSWORD, QJsonValue::fromVariant(user.getPassword()));

    return jObj;
}
