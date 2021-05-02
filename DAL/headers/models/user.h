#ifndef USER_H
#define USER_H

#include <QString>

class User
{
    int id;
    QString name;
    QString password;
    QString email;
    int balance;

public:
    User(const int &id, const QString &name, const QString &email, const QString &password, const int &balance);
    int getId() const;
    QString getName() const;
    QString getPassword() const;
    QString getEmail() const;
    int getBalance() const;

    QString setId(const int &id);
    QString setName(const QString &name);
    QString setPassword(const QString &password);
    QString setEmail(const QString &email);
    QString setBalance(const int &balance);
};

#endif // USER_H
