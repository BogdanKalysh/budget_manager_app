#ifndef USER_H
#define USER_H
#include <QString>
#include <constants.h>

class User
{
    int id;
    QString name;
    QString password;
    QString email;

public:
    User(const int id, const QString &name, const QString &email, const QString &password);

    int getId() const;
    QString getName() const;
    QString getPassword() const;
    QString getEmail() const;

    void setId(const int id);
    void setName(const QString &name);
    void setPassword(const QString &password);
    void setEmail(const QString &email);
};

#endif // USER_H
