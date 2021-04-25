#include "categoryparser.h"
#include "constants.h"


Category CategoryParser::parse(QJsonObject json)
{
    int id = json.value(jsonbuilder::ID).toInt();
    QString name = json.value(jsonbuilder::NAME).toString();
    int type = json.value(jsonbuilder::TYPE).toInt();
    QColor color(json.value(jsonbuilder::COLOR).toString());

    return Category(id, name, (Type)type, color);
}


QVector<Category> CategoryParser::parseVector(QJsonArray jsonArray)
{
    QVector<Category> categories;
    foreach(QJsonValue json, jsonArray)
        categories.append(this->parse(json.toObject()));

    return categories;
}
