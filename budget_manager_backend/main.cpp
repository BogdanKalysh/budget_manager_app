#include <QCoreApplication>
#include "querybuilders.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QSqlDatabase tst = setUpDatabase();
    qDebug() << tst.databaseName();
    return a.exec();
}
