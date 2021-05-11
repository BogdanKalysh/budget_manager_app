#include "userparser.h"
#include "constants.h"


User UserParser::parse(QJsonObject json)
{
    int id = json.value(jsonbuilder::ID).toInt();
    QString name = json.value(jsonbuilder::NAME).toString();
    QString email = json.value(jsonbuilder::EMAIL).toString();
    QString password = json.value(jsonbuilder::PASSWORD).toString();

    return User(id, name, email, password);
}


QVector<User> UserParser::parseVector(QJsonArray jsonArray)
{
    QVector<User> users;
    for (const QJsonValue& json: jsonArray)
        users.append(this->parse(json.toObject()));

    return users;
}
