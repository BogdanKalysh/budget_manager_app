#include "applicationservice.h"
#include <QLoggingCategory>
#include "logger.h"

#include "testquerybuilders.h"
#include "testuserrepository.h"
#include <QTest>

int main(int argc, char** argv)
{
    QLoggingCategory::setFilterRules("*.debug=true\n*.info=true\n*.warning=true\n*.critical=true");
    Logger::init();

    QTest::qExec(new TestQueryBuilders, argc, argv);
    QTest::qExec(new TestUserRepository, argc, argv);

    ApplicationService app;
    return app.run(argc, argv);
}
