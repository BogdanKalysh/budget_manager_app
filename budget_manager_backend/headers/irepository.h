#ifndef IREPOSITORY_H
#define IREPOSITORY_H

#include <QString>
#include <QVector>

template <typename T>
class IRepository
{
public:
    virtual QVector<T> select(QString query) = 0;
    virtual bool update(T &object) = 0;
    virtual bool add(T &object) = 0;
    virtual bool deleteObject(int id) = 0;
};

#endif // IREPOSITORY_H
