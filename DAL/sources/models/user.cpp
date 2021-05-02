#include "user.h"

User:: User(const int &id, const QString &name, const QString &email, const QString &password, const int &balance)
{
    this->setId(id);
    this->setName(name);
    this->setEmail(email);
    this->setPassword(password);
    this->setBalance(balance);
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

int User::getBalance() const
{
    return this->balance;
}

QString User::setId(const int &id)
{
    // TODO: Int validation logic
    this->id = id;
    return "Success";
}

QString User::setName(const QString &name)
{
    // TODO: Name validation logic
    this->name = name;
    return "Success";
}

QString User::setPassword(const QString &password)
{
    // TODO: Password validation logic
    this->password = password;
    return "Success";
}

QString User::setEmail(const QString &email)
{
    // TODO: Email validation logic
    this->email = email;
    return "Success";
}

QString User::setBalance(const int &balance)
{
    // TODO: validation logic
    this->balance = balance;
    return "Success";
}
