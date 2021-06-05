#include "user.h"

User:: User(const int id, const QString &name, const QString &email, const QString &password)
{
    this->setId(id);
    this->setName(name);
    this->setEmail(email);
    this->setPassword(password);
//    this->setBalance(balance);
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

void User::setPassword(const QString &password)
{
    this->password = password;
}

void User::setEmail(const QString &email)
{
    this->email = email;
}
