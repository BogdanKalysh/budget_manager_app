#include "testuserparser.h"
#include "constants.h"

using namespace models;


void TestUserParser::parseUser()
{
    QJsonObject correctJson
    {
        {ID, 1},
        {NAME, "Rostyslav"},
        {MAIL, "rost@gmail.com"},
        {PASSWORD,"qwerty123"},
    };
    User result(1, "Rostyslav", "rost@gmail.com", "qwerty123");
    User parsed = userParser.parse(correctJson);

    QCOMPARE(parsed.getId(), result.getId());
    QCOMPARE(parsed.getName(), result.getName());
    QCOMPARE(parsed.getEmail(), result.getEmail());
    QCOMPARE(parsed.getPassword(), result.getPassword());
}

void TestUserParser::parseUserArray()
{
    QVector<User> correctUsers = {{1, "Rostyslav", "rost@gmail.com", "qwerty123"},
                                           {2, "Ruslan", "rus@gmail.com", "qwerty321"},
                                           {1, "Rostyslav", "rost@gmail.com", "qwerty123"}};

    QJsonObject correctJson1 {{ID, 1}, {NAME, "Rostyslav"}, {MAIL, "rost@gmail.com"}, {PASSWORD,"qwerty123"}};
    QJsonObject correctJson2 {{ID, 2}, {NAME, "Ruslan"}, {MAIL, "rus@gmail.com"}, {PASSWORD, "qwerty321"}};

    QJsonArray correctJsonArray = {
        correctJson1, correctJson2, correctJson1,
    };

    QVector<User> parsedArray = userParser.parseVector(correctJsonArray);

    for(int i=0; i < correctUsers.size(); i++) {
        QCOMPARE(correctUsers[i].getId(),parsedArray[i].getId());
        QCOMPARE(correctUsers[i].getName(), parsedArray[i].getName());
        QCOMPARE(correctUsers[i].getEmail(), parsedArray[i].getEmail());
        QCOMPARE(correctUsers[i].getPassword(), parsedArray[i].getPassword());
    }
}
