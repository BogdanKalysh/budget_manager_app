#include "userparcer.h"

template<typename T>
User UserParcer<T>::parce(QJsonObject json)
{
    QString name = json.value("name").toString();
    QString email = json.value("email").toString();
    QString password = json.value("password").toString();

    return User(name, email, password);
}
