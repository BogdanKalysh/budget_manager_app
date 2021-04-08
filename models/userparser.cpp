#include "userparser.h"
#include "constants.h"

template<typename T>
User UserParser<T>::parse(QJsonObject json)
{
    int id = json.value(parser::ID).toInt();
    QString name = json.value(parser::NAME).toString();
    QString email = json.value(parser::EMAIL).toString();
    QString password = json.value(parser::PASSWORD).toString();

    return User(id, name, email, password);
}

template<typename T>
QVector<User> UserParser<T>::parseVector(QJsonArray jsonArray)
{
    QVector<User> users;
    foreach(QJsonValue json, jsonArray)
        users.append(this->parse(json));

    return users;
}
