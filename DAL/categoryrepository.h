#ifndef CATEGORYREPOSITORY_H
#define CATEGORYREPOSITORY_H

#include "irepository.h"
#include "category.h"

class CategoryRepository : public IRepository<Category>
{
public:
    QVector<Category> select(QString query) override;
    bool update(Category &object) override;
    bool add(Category &object) override;
    bool deleteObject(int id) override;
};

#endif // CATEGORYREPOSITORY_H
