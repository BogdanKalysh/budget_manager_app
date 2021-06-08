
#include "constants.h"

#include <testuserjsonbuilder.h>

using namespace models;

void TestUserJsonBulder::testBuildJson() {
    User user(1, "Rostyslav", "rost@gmail.com", "qwerty123");

    QJsonObject result
    {
        {ID, 1},
        {NAME, "Rostyslav"},
        {MAIL, "rost@gmail.com"},
        {PASSWORD,"qwerty123"}
    };

    QJsonObject built = userJsonBuilder.buildJson(user);

    QVERIFY(result == built);
}
