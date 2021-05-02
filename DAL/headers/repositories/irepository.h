#ifndef IREPOSITORY_H
#define IREPOSITORY_H

#include "querybuilders.h"

template <typename T>
class IRepository
{
public:
    virtual QVector<T> select(const QString &query) = 0;
    virtual bool update(const T &object) = 0;
    virtual bool add(const T &object) = 0;
    virtual bool deleteObject(const int &id) = 0;
};

#endif // IREPOSITORY_H
