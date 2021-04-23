#include "categoryrepository.h"

QVector<Category> CategoryRepository::select(QString query)
{
    //No realization yet
    //it's pseudo result
    QVector<Category> categories;
    categories.push_back(Category(1, "Credits", Type::expense, QColor("#d4d4d4")));
    return categories;
}

bool CategoryRepository::update(Category &object)
{
    //No realization yet
    //it's pseudo result
    return true;
}

bool CategoryRepository::add(Category &object)
{
    //No realization yet
    //it's pseudo result
    return true;
}

bool CategoryRepository::deleteObject(int id)
{
    //No realization yet
    //it's pseudo result
    return true;
}
