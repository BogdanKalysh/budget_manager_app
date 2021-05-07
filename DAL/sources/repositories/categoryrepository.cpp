#include "categoryrepository.h"

using namespace dal;
QVector<Category> CategoryRepository::select(const QString &query)
{
    QVector<Category> categories;
    QSqlDatabase db = setUpDatabase();

    if(db.open()){
        QSqlQuery result(query);

        while(result.next()){

            categories.push_back(Category(
                                result.value(ID).toInt(),
                                result.value(NAME).toString(),
                                (Type)result.value(TYPE).toInt(),
                                QColor(result.value(COLOR).toString()),
                                result.value(CATEGORY_ID).toInt()
                                ));
        }
    } else {
        qDebug() << db.lastError();
    }

    return categories;
}

bool CategoryRepository::update(const Category &object)
{
    QSqlDatabase db = setUpDatabase();

    if(db.open()) {
        QSqlQuery query;

        QVector<QString> fields;
        fields << NAME << TYPE << COLOR;

        QVector<QString> values;
        values << object.getName()
               << (object.getType() == 0?INCOME:EXPENSE)
               << object.getColor().name();

        query.exec(updateQueryBuilder(qMakePair(CATEGORY, object.getId()), fields, values));
        db.close();

        return true;
    } else {
        qDebug() << db.lastError();
    }

    return false;
}

bool CategoryRepository::add(const Category &object)
{
    QSqlDatabase db = setUpDatabase();

    if(db.open()) {
        QSqlQuery query;

        QVector<QString> fields;
        fields << NAME << TYPE << COLOR << USER_ID;

        QVector<QString> values;
        values << object.getName()
               << (object.getType() == 0?INCOME:EXPENSE)
               << object.getColor().name()
               << QString::number(object.getUserId());

        query.exec(insertQueryBuilder(CATEGORY, fields, values));
        db.close();

        return true;
    } else {
        qDebug() << db.lastError();
    }

    return false;
}

bool CategoryRepository::deleteObject(const int id)
{
    QSqlDatabase db = setUpDatabase();

    if(db.open()){
        QSqlQuery query;

        query.exec(deleteQueryBuilder(qMakePair(CATEGORY, id)));
        db.close();

        return true;
    } else {
        qDebug() << db.lastError();
    }

    return false;
}
