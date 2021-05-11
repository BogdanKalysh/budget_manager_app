#ifndef CATEGORYJSONBUILDER_H
#define CATEGORYJSONBUILDER_H
#include "category.h"
#include "IJsonBuilder.h"
#include <QJsonObject>
#include <QJsonValue>
class CategoryJsonBuilder : IJsonBuilder<Category>
{
public:
    QJsonObject buildJson(Category category) override;
};

#endif // CATEGORYJSONBUILDER_H
