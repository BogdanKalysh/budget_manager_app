#include "categoryrepository.h"
#include "querybuilders.h"
#include "constants.h"

using namespace dal;
QVector<Category> CategoryRepository::select(QString query)
{
    //No realization yet
    //it's pseudo result
    QVector<Category> categories;
    QSqlDatabase db = setUpDatabase();

    if(db.open())
    {
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
    }
    else
        qDebug() << db.lastError();
    categories.push_back(Category(1, "Credits", Type::expense, QColor("#d41111"), 1));
    return categories;
}

bool CategoryRepository::update(Category &object)
{
    QSqlDatabase db = setUpDatabase();

    if(db.open())
    {
        QSqlQuery query;
        QVector<QString> fields;
        fields << NAME << TYPE << COLOR;
        QVector<QString> values;
        QString type;
        if(object.getType() == 0)
            type = "income";
        else
            type = "expense";

        values << object.getName() << type << object.getColor().name();


        query.exec(updateQueryBuilder(qMakePair(CATEGORY, object.getId()), fields, values));
        db.close();
        return true;
    } else {
        qDebug() << db.lastError();
    }

    return false;
}

bool CategoryRepository::add(Category &object)
{
    QSqlDatabase db = setUpDatabase();

    if(db.open())
    {
        QSqlQuery query;
        QVector<QString> fields;
        fields << NAME << TYPE << COLOR << USER_ID;
        QVector<QString> values;
        QString type;
        if(object.getType() == 0)
            type = "income";
        else
            type = "expense";

        values << object.getName() << type << object.getColor().name() << QString::number(object.getUserId());
        query.exec(insertQueryBuilder(CATEGORY, fields, values));
        db.close();
        return true;
    } else {
        qDebug() << db.lastError();
    }

    return false;
}

bool CategoryRepository::deleteObject(int id)
{
    QSqlDatabase db = setUpDatabase();

    if(db.open())
    {
        QSqlQuery query;
        query.exec(deleteQueryBuilder(qMakePair(CATEGORY, id)));
        db.close();
        return true;
    } else {
        qDebug() << db.lastError();
    }

    return false;
}
