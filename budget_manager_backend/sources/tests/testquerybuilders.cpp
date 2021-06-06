#include "testquerybuilders.h"
#include "querybuilders.h"
#include <Poco/Crypto/CipherKey.h>
#include <Poco/Crypto/Cipher.h>
#include <Poco/Crypto/CipherFactory.h>

using namespace models;

void TestQueryBuilders::testInsertQueryBuilder()
{
    QString table = USERS;
    QVector<QString> fields = {ID, NAME, PASSWORD};
    QVector<QString> values = {"1", "Andriy", "Pasemko"};

    QString result = "INSERT INTO users (id, name, password) VALUES ('1', 'Andriy', 'Pasemko')";

    QCOMPARE(insertQueryBuilder(table, fields, values), result);

    values.push_back("andriy@gmail.com");
    QCOMPARE(insertQueryBuilder(table, fields, values), "");

    fields.push_back(MAIL);
    fields.push_back(models::DATE);
    QCOMPARE(insertQueryBuilder(table, fields, values), "");
}

void TestQueryBuilders::testUpdateQueryBuilder()
{
    QPair<QString, int> tableCredentials(USERS, 1);
    QVector<QString> fields = {ID, NAME, PASSWORD};
    QVector<QString> values = {"1", "Andriy", "Pasemko"};

    QString result = "UPDATE users SET id = '1', name = 'Andriy', password = 'Pasemko' WHERE id = 1";

    QCOMPARE(updateQueryBuilder(tableCredentials, fields, values), result);

    values.push_back("andriy@gmail.com");
    QCOMPARE(updateQueryBuilder(tableCredentials, fields, values), "");

    fields.push_back(MAIL);
    fields.push_back(models::DATE);
    QCOMPARE(updateQueryBuilder(tableCredentials, fields, values), "");
}

void TestQueryBuilders::testDeleteQueryBuilder()
{
    QPair<QString, int> tableCredentials(USERS, 1);
    QString result = "DELETE FROM users WHERE id = 1";

    QCOMPARE(deleteQueryBuilder(tableCredentials), result);
}


void TestQueryBuilders::testSetUpDatabase()
{
    // Problem has appeared: QSqlDatabase objects cannot be compared.
}
