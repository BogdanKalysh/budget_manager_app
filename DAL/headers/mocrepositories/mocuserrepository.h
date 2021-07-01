#ifndef MOCUSERREPOSITORY_H
#define MOCUSERREPOSITORY_H
#include "irepository.h"
#include "user.h"

class MocUserRepository : public IRepository<User>
{
public:
    using ptr = std::shared_ptr<IRepository<User>>;

    QVector<User> select(const QString &query) override;
    bool update(const User &object) override;
    bool add(const User &object) override;
    bool deleteObject(const int id) override;
};

#endif // USERREPOSITORY_H
