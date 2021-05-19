#include "categoryJsonBuilder.h"
#include "constants.h"

QJsonObject CategoryJsonBuilder::buildJson(Category category){
    QJsonObject jObj;

    jObj.insert(jsonbuilder::ID, QJsonValue::fromVariant(category.getId()));
    jObj.insert(jsonbuilder::NAME, QJsonValue::fromVariant(category.getName()));
    jObj.insert(jsonbuilder::TYPE, QJsonValue::fromVariant(category.getType()));
    jObj.insert(jsonbuilder::COLOR, QJsonValue::fromVariant(category.getColor().name()));
    jObj.insert(jsonbuilder::USER_ID, QJsonValue::fromVariant(category.getUserId()));

    return jObj;
}
