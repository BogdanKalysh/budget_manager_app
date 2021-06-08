#include "testcategoryparser.h"
#include "constants.h"

using namespace models;


void TestCategoryParser::parseCategory()
{
    QJsonObject correctJson
    {
        {ID, 1},
        {NAME, "Market"},
        {TYPE, "income"},
        {COLOR,"#000000"},
        {USER_ID, 3}
    };
    Category result(1, "Market", "income", "#000000", 3);
    Category parsed = categoryParser.parse(correctJson);

    QCOMPARE(parsed.getId(), result.getId());
    QCOMPARE(parsed.getName(), result.getName());
    QCOMPARE(parsed.getType(), result.getType());
    QCOMPARE(parsed.getColor(), result.getColor());
    QCOMPARE(parsed.getUserId(), result.getUserId());
}

void TestCategoryParser::parseCategoryArray()
{
    QVector<Category> correctCategories = {{1, "Market", "income", "#000000", 2},
                                           {2, "Supermarket", "expense", "#000011", 2},
                                           {1, "Market", "income", "#000000", 2}};

    QJsonObject correctJson1 {{ID, 1}, {NAME, "Market"}, {TYPE, "income"}, {COLOR,"#000000"}, {USER_ID, 2}};
    QJsonObject correctJson2 {{ID, 2}, {NAME, "Supermarket"}, {TYPE, "expense"}, {COLOR,"#000011"}, {USER_ID, 2}};

    QJsonArray correctJsonArray = {
        correctJson1, correctJson2, correctJson1,
    };

    QVector<Category> parsedArray = categoryParser.parseVector(correctJsonArray);

    for(int i=0; i < correctCategories.size(); i++) {
        QCOMPARE(parsedArray[i].getId(), correctCategories[i].getId());
        QCOMPARE(parsedArray[i].getName(), correctCategories[i].getName());
        QCOMPARE(parsedArray[i].getType(), correctCategories[i].getType());
        QCOMPARE(parsedArray[i].getColor(), correctCategories[i].getColor());
    }
}
