#ifndef USERPARCER_H
#define USERPARCER_H

#include "ijsonparcer.h"
#include "user.h"

template <typename T>
class UserParcer: IJsonParcer<T>
{
public:
    virtual User parce(QJsonObject json);
};

#endif // USERPARCER_H
