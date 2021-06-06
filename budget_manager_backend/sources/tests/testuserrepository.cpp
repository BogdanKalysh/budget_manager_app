#include "testuserrepository.h"

#include <Poco/Crypto/CipherKey.h>
#include <Poco/Crypto/Cipher.h>
#include <Poco/Crypto/CipherFactory.h>

void TestUserRepository::initTestCase()
{
    this->repository.add(User(1, "TESTAndriy", "testandriy@gmail.com", "test"));

}

void TestUserRepository::cleanupTestCase()
{
    User user = this->repository.select("SELECT * from users WHERE mail='testandriy@gmail.com'")[0];
    this->repository.deleteObject(user.getId());
}

void TestUserRepository::testSelect()
{
    QString query = "SELECT * FROM users WHERE name='TESTAndriy'";
    QVector<User> users = {User(1, "TESTAndriy", "testandriy@gmail.com", "test")};
    QCOMPARE(this->repository.select(query), users);

    QCOMPARE(this->repository.select(""), QVector<User>());
    QCOMPARE(this->repository.select("SOME NOT valid QUERY !!"), QVector<User>());
}

void TestUserRepository::testUpdate()
{
    User user = this->repository.select("SELECT * from users WHERE mail='testandriy@gmail.com'")[0];
    user.setName(user.getName() + "(changed)");

    QCOMPARE(this->repository.update(user), true);

    User changedUser = this->repository.select("SELECT * from users WHERE mail='testandriy@gmail.com'")[0];
    QCOMPARE(user, changedUser);

    user.setId(user.getId() + 10000); // No user with such ID
    user.setName(user.getName() + "(changed)");
    this->repository.update(user);
    changedUser = this->repository.select("SELECT * from users WHERE mail='testandriy@gmail.com'")[0];
    QVERIFY(user != changedUser);

}

void TestUserRepository::testAdd()
{
    QCOMPARE(this->repository.add(User(1, "AddTESTAndriy", "Addtestandriy@gmail.com", "test")), true);
}

void TestUserRepository::testDelete()
{
    User user = this->repository.select("SELECT * from users WHERE mail='Addtestandriy@gmail.com'")[0];
    QCOMPARE(this->repository.deleteObject(user.getId()), true);
    QVERIFY(this->repository.select("SELECT * from users WHERE mail='Addtestandriy@gmail.com'").isEmpty());
}

