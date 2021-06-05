#ifndef USERHANDLER_H
#define USERHANDLER_H

#include "abstracthandler.h"
#include "userparser.h"
#include "userrepository.h"

class UserHandler: public AbstractHandler
{
protected:
    UserParser::ptr parser;
    UserRepository::ptr repository;

    void get(HTTPServerRequest& request,
            HTTPServerResponse& response) override;
    void post(HTTPServerRequest& request,
            HTTPServerResponse& response) override;
    void put(HTTPServerRequest& request,
            HTTPServerResponse& response) override;
    void del(HTTPServerRequest& request,
            HTTPServerResponse& response) override;

public:
    UserHandler(std::shared_ptr<IDBManager> dbManager, std::shared_ptr<IParserManager> parserManager);
    AbstractHandler* getCopy() override;

    void handleRequest(
            HTTPServerRequest& request,
            HTTPServerResponse& response) override;
};

#endif // USERHANDLER_H
