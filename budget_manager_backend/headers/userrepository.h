#ifndef USERREPOSITORY_H
#define USERREPOSITORY_H

#include "irepository.h"
#include "user.h"

class UserRepository : public IRepository<User>
{
public:
    QVector<User> select(QString query) override;
    bool update(User &object) override;
    bool add(User &object) override;
    bool deleteObject(int id) override;
};

#endif // USERREPOSITORY_H
