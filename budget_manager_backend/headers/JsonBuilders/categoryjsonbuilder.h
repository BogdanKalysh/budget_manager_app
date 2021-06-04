#ifndef CATEGORYJSONBUILDER_H
#define CATEGORYJSONBUILDER_H

#include "category.h"
#include "IJsonBuilder.h"

class CategoryJsonBuilder : public IJsonBuilder<Category>
{
public:
    QJsonObject buildJson(const Category &category) override;
};

#endif // CATEGORYJSONBUILDER_H
