#include "categoryjsonbuilder.h"
#include "constants.h"
#include <QJsonValue>

using namespace models;

QJsonObject CategoryJsonBuilder::buildJson(Category category){
    QJsonObject jObj;

    jObj.insert(ID, QJsonValue::fromVariant(category.getId()));
    jObj.insert(NAME, QJsonValue::fromVariant(category.getName()));
    jObj.insert(TYPE, QJsonValue::fromVariant(category.getType()));
    jObj.insert(COLOR, QJsonValue::fromVariant(category.getColor().name()));

    return jObj;
}
