#ifndef USER_H
#define USER_H

#include <QString>

class User
{
    QString name;
    QString password;
    QString email;
public:
    User(QString name, QString email, QString password);
    QString getName();
    QString getPassword();
    QString getEmail();

    QString setName(QString name);
    QString setPassword(QString password);
    QString setEmail(QString email);
};

#endif // USER_H
