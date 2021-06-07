#include "user.h"

User:: User(){
}

User:: User(const QString &email, const QString &password)
{
    this->email = email;
    this->password = password;
}

User:: User(const int id, const QString &name, const QString &email, const QString &password):User(email, password)
{
    this->id = id;
    this->name = name;
}


int User::getId() const
{
    return this->id;
}

QString User::getName() const
{
    return this->name;
}

QString User::getPassword() const
{
    return this->password;
}

QString User::getEmail() const
{
    return this->email;
}


void User::setId(const int id)
{
    this->id = id;
}

void User::setName(const QString &name)
{
    this->name = name;
}

void User::setEmail(const QString &email)
{
    this->email = email;
}

void User::setPassword(const QString &password)
{
    this->password = password;
}

