#ifndef USERPARCER_H
#define USERPARCER_H

#include "ijsonparcer.h"
#include "user.h"

template <typename T>
class UserParcer: IJsonParcer<T>
{
public:
    virtual User parce(QJsonObject json);
    virtual QVector<User> parceVector(QJsonArray jsonArray);
};

#endif // USERPARCER_H
