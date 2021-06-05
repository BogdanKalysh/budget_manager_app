#ifndef CATEGORYJSONBUILDER_H
#define CATEGORYJSONBUILDER_H

#include "IJsonBuilder.h"
#include <QJsonObject>
#include <QJsonValue>
#include "category.h"


class CategoryJsonBuilder: public IJsonBuilder<Category>
{
public:
    QJsonObject buildJson(const Category &category) override;
};

#endif // CATEGORYJSONBUILDER_H
