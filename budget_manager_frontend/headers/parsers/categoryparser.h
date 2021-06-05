#ifndef CATEGORYPARSER_H
#define CATEGORYPARSER_H

#include "ijsonparser.h"
#include "category.h"


class CategoryParser: public IJsonParser<Category>
{
public:
    Category parse(const QJsonObject &json) override;
    QVector<Category> parseVector(const QJsonArray &jsonArray) override;
};

#endif // CATEGORYPARSER_H
