#include "userparser.h"
#include "constants.h"

using namespace models;

User UserParser::parse(const QJsonObject &json)
{
    int id = json.value(ID).toInt();
    QString name = json.value(NAME).toString();
    QString email = json.value(MAIL).toString();
    QString password = json.value(PASSWORD).toString();

    return User(id, name, email, password);
}


QVector<User> UserParser::parseVector(const QJsonArray &jsonArray)
{
    QVector<User> users;

    for (auto json : jsonArray)
        users.append(this->parse(json.toObject()));

    return users;
}
