#include "categoryparser.h"
#include "constants.h"

template<typename T>
Category CategoryParser<T>::parse(QJsonObject json)
{
    int id = json.value(parser::ID).toInt();
    QString name = json.value(parser::NAME).toString();
    int type = json.value(parser::TYPE).toInt();

    QJsonArray jRGB = json.value(parser::COLOR).toArray();
    QColor color(jRGB[0].toInt(), jRGB[1].toInt(), jRGB[2].toInt());

    return Category(id, name, (Type)type, color);
}

template<typename T>
QVector<Category> CategoryParser<T>::parseVector(QJsonArray jsonArray)
{
    QVector<Category> categories;
    foreach(QJsonValue json, jsonArray)
        categories.append(this->parse(json));

    return categories;
}
