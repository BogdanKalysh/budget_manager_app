#include "testquerybuilder.h"
#include "constants.h"


using namespace models;

void TestQueryBuilder::insertQuery()
{
    QString table = USERS;
    QVector<QString> fields = {ID, NAME, PASSWORD};
    QVector<QString> values = {"1", "Andriy", "Pasemko"};

    QString result = "INSERT INTO users (id, name, password) VALUES ('1', 'Andriy', 'Pasemko')";

    QCOMPARE(this->queryBuilder.insertQuery(table, fields, values), result);

    values.push_back("andriy@gmail.com");
    QCOMPARE(this->queryBuilder.insertQuery(table, fields, values), "");

    fields.push_back(MAIL);
    fields.push_back(models::DATE);
    QCOMPARE(this->queryBuilder.insertQuery(table, fields, values), "");
}

void TestQueryBuilder::updateQuery()
{
    QPair<QString, int> tableCredentials(USERS, 1);
    QVector<QString> fields = {ID, NAME, PASSWORD};
    QVector<QString> values = {"1", "Andriy", "Pasemko"};

    QString result = "UPDATE users SET id = '1', name = 'Andriy', password = 'Pasemko' WHERE id = 1";

    QCOMPARE(this->queryBuilder.updateQuery(tableCredentials, fields, values), result);

    values.push_back("andriy@gmail.com");
    QCOMPARE(this->queryBuilder.updateQuery(tableCredentials, fields, values), "");

    fields.push_back(MAIL);
    fields.push_back(models::DATE);
    QCOMPARE(this->queryBuilder.updateQuery(tableCredentials, fields, values), "");
}

void TestQueryBuilder::deleteQuery()
{
    QPair<QString, int> tableCredentials(USERS, 1);
    QString result = "DELETE FROM users WHERE id = 1";

    QCOMPARE(this->queryBuilder.deleteQuery(tableCredentials), result);
}

