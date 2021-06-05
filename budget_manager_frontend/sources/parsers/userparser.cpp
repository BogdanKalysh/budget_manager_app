#include "userparser.h"
#include "constants.h"


User UserParser::parse(const QJsonObject &json)
{
    int id = json.value(models::ID).toInt();
    QString name = json.value(models::NAME).toString();
    QString email = json.value(models::MAIL).toString();
    QString password = json.value(models::PASSWORD).toString();

    return User(id, name, email, password);
}

QVector<User> UserParser::parseVector(const QJsonArray &jsonArray)
{
    QVector<User> users;
    for (const QJsonValue& json: jsonArray)
        users.append(this->parse(json.toObject()));

    return users;
}
