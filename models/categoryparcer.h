#ifndef CATEGORYPARCER_H
#define CATEGORYPARCER_H

#include "ijsonparcer.h"
#include "category.h"

template <typename T>
class CategoryParcer: IJsonParcer<T>
{
public:
    virtual Category parce(QJsonObject json);
    virtual QVector<Category> parceVector(QJsonArray jsonArray);
};

#endif // CATEGORYPARCER_H
