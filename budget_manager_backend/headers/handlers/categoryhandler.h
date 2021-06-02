#ifndef CATEGORYHANDLER_H
#define CATEGORYHANDLER_H

#include "abstracthandler.h"
#include "categoryparser.h"
#include "categoryrepository.h"

class CategoryHandler : public AbstractHandler
{
protected:
    CategoryParser::ptr parser;
    CategoryRepository::ptr repository;

    void get(HTTPServerRequest& request,
            HTTPServerResponse& response) override;
    void post(HTTPServerRequest& request,
            HTTPServerResponse& response) override;
    void put(HTTPServerRequest& request,
            HTTPServerResponse& response) override;
    void del(HTTPServerRequest& request,
            HTTPServerResponse& response) override;

public:
    CategoryHandler(std::shared_ptr<IDBManager> dbManager, std::shared_ptr<IParserManager> parserManager);
    AbstractHandler* getCopy() override;

    void handleRequest(
            HTTPServerRequest& request,
            HTTPServerResponse& response) override;
};

#endif // CATEGORYHANDLER_H
