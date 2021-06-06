#ifndef TESTUSERREPOSITORY_H
#define TESTUSERREPOSITORY_H

#include <QtTest/QtTest>
#include "userrepository.h"

class TestUserRepository : public QObject
{
    Q_OBJECT
private slots:
    void initTestCase();
    void cleanupTestCase();
    void testSelect();
    void testUpdate();
    void testAdd();
    void testDelete();

private:
    UserRepository repository;
};

#endif // TESTUSERREPOSITORY_H
