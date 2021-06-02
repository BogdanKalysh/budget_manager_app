#include "userjsonbuilder.h"
#include "constants.h"
#include <QJsonValue>

using namespace models;

QJsonObject UserJsonBuilder::buildJson(User user){
    QJsonObject jObj;

    jObj.insert(ID, QJsonValue::fromVariant(user.getId()));
    jObj.insert(NAME, QJsonValue::fromVariant(user.getName()));
    jObj.insert(MAIL, QJsonValue::fromVariant(user.getEmail()));
    jObj.insert(PASSWORD, QJsonValue::fromVariant(user.getPassword()));

    return jObj;
}
