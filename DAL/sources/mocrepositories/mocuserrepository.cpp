#include "mocuserrepository.h"

using namespace models;

QVector<User> MocUserRepository::select(const QString &query)
{
    QVector<User> users;
    users.push_back(User(1,"bob","bob@gmail.com","passpass"));
    qDebug()<<users[0].getEmail();
    return users;
}

bool MocUserRepository::update(const User &object)
{
    return true;
}

bool MocUserRepository::add(const User &object)
{
   return true;
}

bool MocUserRepository::deleteObject(const int id)
{
    return true;
}
