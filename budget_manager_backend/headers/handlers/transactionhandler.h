#ifndef TRANSACTIONHANDLER_H
#define TRANSACTIONHANDLER_H

#include "abstracthandler.h"
#include "transactionparser.h"
#include "transactionrepository.h"

class TransactionHandler : public AbstractHandler
{
protected:
    TransactionParser::ptr parser;
    TransactionRepository::ptr repository;

    void get(HTTPServerRequest& request,
            HTTPServerResponse& response) override;
    void post(HTTPServerRequest& request,
            HTTPServerResponse& response) override;
    void put(HTTPServerRequest& request,
            HTTPServerResponse& response) override;
    void del(HTTPServerRequest& request,
            HTTPServerResponse& response) override;

public:
    TransactionHandler(std::shared_ptr<IDBManager> dbManager, std::shared_ptr<IParserManager> parserManager);
    AbstractHandler* getCopy() override;

    void handleRequest(
            HTTPServerRequest& request,
            HTTPServerResponse& response) override;
};

#endif // TRANSACTIONHANDLER_H
