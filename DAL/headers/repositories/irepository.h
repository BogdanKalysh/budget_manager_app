#ifndef IREPOSITORY_H
#define IREPOSITORY_H

#include "querybuilders.h"

template <typename T>
class IRepository
{
public:
    virtual QVector<T> select(const QString &query) = 0;
    virtual bool update(T &object) = 0;
    virtual bool add(T &object) = 0;
    virtual bool deleteObject(int id) = 0;
};

#endif // IREPOSITORY_H
