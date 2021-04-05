#include "userparcer.h"

template<typename T>
User UserParcer<T>::parce(QJsonObject json)
{
    int id = json.value("id").toInt();
    QString name = json.value("name").toString();
    QString email = json.value("email").toString();
    QString password = json.value("password").toString();

    return User(id, name, email, password);
}

template<typename T>
QVector<User> UserParcer<T>::parceVector(QJsonArray jsonArray)
{
    QVector<User> users;
    foreach(QJsonValue json, jsonArray)
        users.append(this->parce(json));

    return users;
}
