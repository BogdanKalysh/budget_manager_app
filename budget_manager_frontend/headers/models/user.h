#ifndef USER_H
#define USER_H

#include <QString>

class User
{
    int id;
    QString name;
    QString email;
    QString password;

public:
    User();
    User(QString email, QString password);
    User(int id, QString name, QString email, QString password);

    int getId();
    QString getName();
    QString getPassword();
    QString getEmail();

    void setId(int id);
    void setName(QString name);
    void setPassword(QString password);
    void setEmail(QString email);
};


#endif // USER_H
