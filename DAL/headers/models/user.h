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
    User(int id, QString name, QString email, QString password, int balance);
    int getId();
    QString getName();
    QString getPassword();
    QString getEmail();
    int getBalance();

    QString setId(int id);
    QString setName(QString name);
    QString setPassword(QString password);
    QString setEmail(QString email);
    QString setBalance(int balance);
};

#endif // USER_H
