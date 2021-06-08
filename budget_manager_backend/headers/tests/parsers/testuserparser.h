#ifndef TESTUSERPARSER_H
#define TESTUSERPARSER_H

#include "userparser.h"
#include <QTest>
class TestUserParser: public QObject
{
    Q_OBJECT
private slots:
    void parseUser();
    void parseUserArray();

private:
    UserParser userParser;
};

#endif // TESTUSERPARSER_H
