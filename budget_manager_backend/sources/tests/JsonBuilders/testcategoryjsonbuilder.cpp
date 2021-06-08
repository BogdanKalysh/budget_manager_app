#include "testcategoryjsonbuilder.h"
#include "constants.h"

using namespace models;

void TestCategoryJsonBulder::testBuildJson() {
    Category category(1, "Market", "income", "#000000", 3);

    QJsonObject result
    {
        {ID, 1},
        {NAME, "Market"},
        {TYPE, "income"},
        {COLOR,"#000000"}
    };

    QJsonObject built = categoryJsonBuilder.buildJson(category);

    QVERIFY(result == built);
}
