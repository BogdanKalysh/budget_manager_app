#ifndef USER_H
#define USER_H

#include <QString>

class User
{
    int id;
    QString name;
    QString password;
    QString email;
public:
    User(int id, QString name, QString email, QString password);
    int getId();
    QString getName();
    QString getPassword();
    QString getEmail();

    QString setId(int id);
    QString setName(QString name);
    QString setPassword(QString password);
    QString setEmail(QString email);
};

#endif // USER_H
