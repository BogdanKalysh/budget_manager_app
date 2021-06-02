#include "categoryJsonBuilder.h"
#include "constants.h"


QJsonObject CategoryJsonBuilder::buildJson(Category category){
    QJsonObject jObj;

    jObj.insert(models::ID, QJsonValue::fromVariant(category.getId()));
    jObj.insert(models::NAME, QJsonValue::fromVariant(category.getName()));
    jObj.insert(models::TYPE, QJsonValue::fromVariant(category.getType()));
    jObj.insert(models::COLOR, QJsonValue::fromVariant(category.getColor().name()));
    jObj.insert(models::USER_ID, QJsonValue::fromVariant(category.getUserId()));

    return jObj;
}
