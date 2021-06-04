#include "categoryparser.h"
#include "constants.h"

using namespace models;

Category CategoryParser::parse(const QJsonObject &json)
{
    int id = json.value(ID).toInt();
    QString name = json.value(NAME).toString();
    QString type = json.value(TYPE).toString();
    QColor color(json.value(COLOR).toString());
    int userId = json.value(USER_ID).toInt();

    return Category(id, name, type, color, userId);
}

QVector<Category> CategoryParser::parseVector(const QJsonArray &jsonArray)
{
    QVector<Category> categories;

    for (auto json : jsonArray)
        categories.append(this->parse(json.toObject()));

    return categories;
}
