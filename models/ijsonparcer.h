#ifndef IJSONPARCER_H
#define IJSONPARCER_H

#include <QJsonObject>
#include <QJsonArray>
#include <QVector>


template <typename  T>
class IJsonParcer
{
public:
    virtual T parce(QJsonObject json) = 0;
    virtual QVector<T> parceVector(QJsonArray jsonArray) = 0;
};

#endif // IJSONPARCER_H
