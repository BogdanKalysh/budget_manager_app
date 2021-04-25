#include "userrepository.h"
using namespace dal;
QVector<User> UserRepository::select(QString query)
{
    //No realization yet
    //it's pseudo result
    QVector<User> users;
    users.push_back(User(1, "Petro", "petromostavchuk228@gmail.com", "motyvaciya", 1));
    return users;
}


bool UserRepository::update(User &object)
{
    QSqlDatabase db = setUpDatabase();

    if(db.open())
    {
        QSqlQuery query;
        QVector<QString> fields;
        fields << MAIL << PASSWORD << NAME << BALANCE;
        QVector<QString> values;
        values << object.getEmail() << object.getPassword() << object.getName() << QString::number(object.getBalance());

        query.exec(updateQueryBuilder(qMakePair(USERS, object.getId()), fields, values));
        db.close();
        return true;
    } else {
        qDebug() << db.lastError();
    }

    return false;
}

bool UserRepository::add(User &object)
{
    QSqlDatabase db = setUpDatabase();

    if(db.open())
    {
        QSqlQuery query;
        QVector<QString> fields;
        fields << MAIL << PASSWORD << NAME << BALANCE;
        QVector<QString> values;
        values << object.getEmail() << object.getPassword() << object.getName() << QString::number(object.getBalance());

        query.exec(insertQueryBuilder(USERS, fields, values));
        db.close();
        return true;
    } else {
        qDebug() << db.lastError();
    }

    return false;
}

bool UserRepository::deleteObject(int id)
{
    QSqlDatabase db = setUpDatabase();

    if(db.open())
    {
        QSqlQuery query;
        query.exec(deleteQueryBuilder(qMakePair(USERS, id)));
        db.close();
        return true;
    } else {
        qDebug() << db.lastError();
    }

    return false;
    return true;
}
