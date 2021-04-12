#include "userrepository.h"

QVector<User> UserRepository::select(QString query)
{
    //No realization yet
    //it's pseudo result
    QVector<User> users;
    users.push_back(User(1, "Petro", "petromostavchuk228@gmail.com", "motyvaciya"));
    return users;
}


bool UserRepository::update(User &object)
{
    //No realization yet
    //it's pseudo result
    return true;
}

bool UserRepository::add(User &object)
{
    //No realization yet
    //it's pseudo result
    return true;
}

bool UserRepository::deleteObject(int id)
{
    //No realization yet
    //it's pseudo result
    return true;
}
