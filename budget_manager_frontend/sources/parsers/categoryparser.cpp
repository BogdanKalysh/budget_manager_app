#include "categoryparser.h"
#include "constants.h"


Category CategoryParser::parse(QJsonObject json)
{
    int id = json.value(jsonbuilder::ID).toInt();
    QString name = json.value(jsonbuilder::NAME).toString();
    int type = json.value(jsonbuilder::TYPE).toInt();

    QJsonArray jRGB = json.value(jsonbuilder::COLOR).toArray();
    QColor color(jRGB[0].toInt(), jRGB[1].toInt(), jRGB[2].toInt());

    return Category(id, name, (Type)type, color);
}


QVector<Category> CategoryParser::parseVector(QJsonArray jsonArray)
{
    QVector<Category> categories;
    foreach(QJsonValue json, jsonArray)
        categories.append(this->parse(json.toObject()));

    return categories;
}
