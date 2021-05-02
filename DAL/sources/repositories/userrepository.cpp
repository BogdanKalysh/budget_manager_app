#include "userrepository.h"

using namespace dal;

QVector<User> UserRepository::select(const QString &query)
{

    QVector<User> users;
    QSqlDatabase db = setUpDatabase();

    if(db.open())
    {
        QSqlQuery result(query);

        while(result.next()){
            users.push_back(User(
                                result.value(ID).toInt(),
                                result.value(NAME).toString(),
                                result.value(MAIL).toString(),
                                result.value(PASSWORD).toString(),
                                result.value(BALANCE).toInt()
                                ));
        }
    } else {
        qDebug() << db.lastError();
    }

    return users;
}


bool UserRepository::update(const User &object)
{
    QSqlDatabase db = setUpDatabase();

    if(db.open())
    {
        QSqlQuery query;

        QVector<QString> fields;
        fields << MAIL << PASSWORD << NAME << BALANCE;

        QVector<QString> values;
        values << object.getEmail()
               << object.getPassword()
               << object.getName()
               << QString::number(object.getBalance());

        query.exec(updateQueryBuilder(qMakePair(USERS, object.getId()), fields, values));
        db.close();

        return true;
    } else {
        qDebug() << db.lastError();
    }

    return false;
}

bool UserRepository::add(const User &object)
{
    QSqlDatabase db = setUpDatabase();

    if(db.open())
    {
        QSqlQuery query;

        QVector<QString> fields;
        fields << MAIL << PASSWORD << NAME << BALANCE;

        QVector<QString> values;
        values << object.getEmail()
               << object.getPassword()
               << object.getName()
               << QString::number(object.getBalance());

        query.exec(insertQueryBuilder(USERS, fields, values));
        db.close();

        return true;
    } else {
        qDebug() << db.lastError();
    }

    return false;
}

bool UserRepository::deleteObject(const int &id)
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
}
