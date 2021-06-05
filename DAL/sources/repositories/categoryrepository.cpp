#include "categoryrepository.h"

using namespace models;

QVector<Category> CategoryRepository::select(const QString &query)
{
    QVector<Category> categories;
    QSqlDatabase db = setUpDatabase();

    if (db.open()) {
        QSqlQuery result(query);

        while(result.next()){
            categories.push_back(Category(
                                result.value(ID).toInt(),
                                result.value(NAME).toString(),
                                result.value(TYPE).toString(),
                                QColor(result.value(COLOR).toString()),
                                result.value(USER_ID).toInt()));
        }

        db.close();
    } else {
        qDebug() << db.lastError();
    }

    return categories;
}

bool CategoryRepository::update(const Category &object)
{
    QSqlDatabase db = setUpDatabase();

    if (db.open()) {
        QSqlQuery query;

        QVector<QString> fields;
        fields << NAME << TYPE << COLOR;

        QVector<QString> values;
        values << object.getName()
               << object.getType()
               << object.getColor().name();

        if (query.exec(updateQueryBuilder(qMakePair(CATEGORY, object.getId()), fields, values))) {
            db.close();
            return true;
        }

        qDebug() << query.lastError();
        db.close();
    }

    qDebug() << db.lastError();
    return false;
}

bool CategoryRepository::add(const Category &object)
{
    QSqlDatabase db = setUpDatabase();

    if (db.open()) {
        QSqlQuery query;

        QVector<QString> fields;
        fields << NAME << TYPE << COLOR << USER_ID;

        QVector<QString> values;
        values << object.getName()
               << object.getType()
               << object.getColor().name()
               << QString::number(object.getUserId());

        if (query.exec(insertQueryBuilder(CATEGORY, fields, values))) {
            db.close();
            return true;
        }

        qDebug() << query.lastError();
        db.close();
    }

    qDebug() << db.lastError();
    return false;
}

bool CategoryRepository::deleteObject(const int id)
{
    QSqlDatabase db = setUpDatabase();

    if (db.open()) {
        QSqlQuery query;

        if(query.exec(deleteQueryBuilder(qMakePair(CATEGORY, id)))) {
            db.close();
            return true;
        }

        qDebug() << query.lastError();
        db.close();
    }

    qDebug() << db.lastError();
    return false;
}
