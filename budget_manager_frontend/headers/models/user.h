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
    User(const QString &email, const QString &password);
    User(const int id, const QString &name, const QString &email, const QString &password);

    int getId() const;
    QString getName() const;
    QString getPassword() const;
    QString getEmail() const;

    void setId(const int id);
    void setName(const QString &name);
    void setPassword(const QString &password);
    void setEmail(const QString &email);
    void setUserId(const int userId);
};


#endif // USER_H
