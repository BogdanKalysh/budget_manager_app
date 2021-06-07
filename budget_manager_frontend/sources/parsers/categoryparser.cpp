#include "categoryparser.h"
#include "constants.h"


Category CategoryParser::parse(const QJsonObject &json)
{
    int id = json.value(models::ID).toInt();
    QString name = json.value(models::NAME).toString();
    QString type = json.value(models::TYPE).toString();
    QColor color(json.value(models::COLOR).toString());
    int userId = json.value(models::USER_ID).toInt();

    return Category(id, name, type, color, userId);
}

QVector<Category> CategoryParser::parseVector(const QJsonArray &jsonArray)
{
    QVector<Category> categories;
    for (const QJsonValue& json: jsonArray)
        categories.append(this->parse(json.toObject()));

    return categories;
}
