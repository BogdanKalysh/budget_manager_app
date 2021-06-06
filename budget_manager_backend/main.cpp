#include "applicationservice.h"
#include <QLoggingCategory>
#include "logger.h"

#include "testquerybuilder.h"
#include <QTest>

int main(int argc, char** argv)
{
    QLoggingCategory::setFilterRules("*.debug=true\n*.info=true\n*.warning=true\n*.critical=true");
    Logger::init();

    QTest::qExec(new TestQueryBuilder, argc, argv);

    ApplicationService app;
    return app.run(argc, argv);
}
