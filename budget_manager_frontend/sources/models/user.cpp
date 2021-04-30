#include "user.h"

User:: User(){
}

User:: User(QString email, QString password)
{
    this->email = email;
    this->password = password;
}

User:: User(QString name, QString email, QString password):User(email, password)
{
    this->name = name;
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

void User::setName(QString name)
{
    this->name = name;
}

void User::setEmail(QString email)
{
    this->email = email;
}

void User::setPassword(QString password)
{
    this->password = password;
}

