#include "user.h"

User:: User(QString name, QString email, QString password)
{
    this->setName(name);
    this->setEmail(email);
    this->setPassword(password);
}

QString User::getName()
{
    return this->name;
}

QString User::getPassword()
{
    return this->password;
}

QString User::getEmail()
{
    return this->email;
}

QString User::setName(QString name)
{
    // TODO: Name validation logic
    this->name = name;
    return "Success";
}

QString User::setPassword(QString password)
{
    // TODO: Password validation logic
    this->password = password;
    return "Success";
}

QString User::setEmail(QString email)
{
    // TODO: Email validation logic
    this->email = email;
    return "Success";
}
