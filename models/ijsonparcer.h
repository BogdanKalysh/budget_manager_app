#ifndef IJSONPARCER_H
#define IJSONPARCER_H

#include <QJsonObject>

template <typename  T>
class IJsonParcer
{
public:
    virtual T parce(QJsonObject json) = 0;
};

#endif // IJSONPARCER_H
