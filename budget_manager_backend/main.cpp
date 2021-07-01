#include "applicationservice.h"
#include <QLoggingCategory>
#include "logger.h"

int main(int argc, char** argv)
{
    QLoggingCategory::setFilterRules("*.debug=true\n*.info=true\n*.warning=true\n*.critical=true");
    //Logger::init();

    ApplicationService app;
    return app.run(argc, argv);
}
