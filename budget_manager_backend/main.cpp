#include "applicationservice.h"
#include <QLoggingCategory>
#include "logger.h"

//#include "testcategoryparser.h"
#include "testtransactionparser.h"
#include "testuserparser.h"

//#include "testcategoryjsonbuilder.h"
//#include "testtransactionjsonbuilder.h"
#include "testuserjsonbuilder.h"

#include <QTest>

int main(int argc, char** argv)
{
    QLoggingCategory::setFilterRules("*.debug=true\n*.info=true\n*.warning=true\n*.critical=true");
    Logger::init();

//    QTest::qExec(new TestCategoryParser, argc, argv);
//    QTest::qExec(new TestUserParser, argc, argv);
    QTest::qExec(new TestTransactionParser, argc, argv);

//    QTest::qExec(new TestCategoryJsonBulder, argc, argv);
//    QTest::qExec(new TestTransactionJsonBulder, argc, argv);
//    QTest::qExec(new TestUserJsonBulder, argc, argv);

    ApplicationService app;
    return app.run(argc, argv);
}
