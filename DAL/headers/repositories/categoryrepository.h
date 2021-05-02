#ifndef CATEGORYREPOSITORY_H
#define CATEGORYREPOSITORY_H

#include "irepository.h"
#include "category.h"

class CategoryRepository : public IRepository<Category>
{
public:
    QVector<Category> select(const QString &query) override;
    bool update(const Category &object) override;
    bool add(const Category &object) override;
    bool deleteObject(const int &id) override;
};

#endif // CATEGORYREPOSITORY_H
