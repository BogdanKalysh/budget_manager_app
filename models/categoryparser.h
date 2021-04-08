#ifndef CATEGORYPARSER_H
#define CATEGORYPARSER_H

#include "ijsonparser.h"
#include "category.h"

template <typename T>
class CategoryParser: IJsonParser<T>
{
public:
    virtual Category parse(QJsonObject json);
    virtual QVector<Category> parseVector(QJsonArray jsonArray);
};

#endif // CATEGORYPARSER_H
