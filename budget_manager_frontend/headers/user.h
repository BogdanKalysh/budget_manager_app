#ifndef USER_H
#define USER_H

#include <QString>

class User
{
    QString name;
    QString email;
    QString password;

public:
    User(QString email, QString password);
    User(QString name, QString email, QString password);
    QString getName();
    QString getPassword();
    QString getEmail();

    void setName(QString name);
    void setPassword(QString password);
    void setEmail(QString email);
};


#endif // USER_H
