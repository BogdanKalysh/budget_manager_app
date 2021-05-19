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
                                (Type)(result.value(TYPE) == INCOME),
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
               << QColor(object.getColor()).name(QColor::NameFormat::HexRgb);

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

        if(query.exec(insertQueryBuilder(CATEGORY, fields, values))){
            db.close();
            return true;
        }
        else
        {
            qDebug() << query.lastError();
            db.close();
            return false;
        }

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
