#ifndef IJSONBUILDER_H
#define IJSONBUILDER_H

#include <QJsonObject>
#include <QVector>

template <typename  T>
class IJsonBuilder
{
public:
    virtual QJsonObject buildJson(const T &obj) = 0;
};

#endif // IJSONBUILDER_H
