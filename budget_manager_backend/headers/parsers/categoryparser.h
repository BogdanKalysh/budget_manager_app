#ifndef CATEGORYPARSER_H
#define CATEGORYPARSER_H

#include "ijsonparser.h"
#include "category.h"


class CategoryParser: public IJsonParser<Category>
{
public:
    Category parse(QJsonObject json) override;
    QVector<Category> parseVector(QJsonArray jsonArray) override;
};

#endif // CATEGORYPARSER_H
