#include "moccategoryrepository.h"

using namespace models;

QVector<Category> MocCategoryRepository::select(const QString &query)
{
    QVector<Category> categories;
    categories.push_back(Category(1,"Category1","income",QColor("red"),1));
    categories.push_back(Category(2,"Category2","income",QColor("green"),1));
    categories.push_back(Category(3,"Category3","expense",QColor("blue"),1));
    categories.push_back(Category(4,"Category4","expense",QColor("white"),1));


    return categories;

}

bool MocCategoryRepository::update(const Category &object)
{
    return true;
}

bool MocCategoryRepository::add(const Category &object)
{
   return true;
}

bool MocCategoryRepository::deleteObject(const int id)
{
    return true;
}
