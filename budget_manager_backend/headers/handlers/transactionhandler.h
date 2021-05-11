#ifndef TRANSACTIONHANDLER_H
#define TRANSACTIONHANDLER_H

#include "abstracthandler.h"
#include "transactionparser.h"

class TransactionHandler : public AbstractHandler
{
protected:
    std::shared_ptr<IJsonParser<Transaction>> parser;
    std::shared_ptr<IRepository<Transaction>> repository;

    void get(Poco::Net::HTTPServerRequest& request,
            Poco::Net::HTTPServerResponse& response) override;
    void post(Poco::Net::HTTPServerRequest& request,
            Poco::Net::HTTPServerResponse& response) override;
    void put(Poco::Net::HTTPServerRequest& request,
            Poco::Net::HTTPServerResponse& response) override;
    void del(Poco::Net::HTTPServerRequest& request,
            Poco::Net::HTTPServerResponse& response) override;

public:
    TransactionHandler(std::shared_ptr<IDBManager> dbManager, std::shared_ptr<IParserManager> parserManager);
    AbstractHandler* getCopy() override;

    void handleRequest(
            Poco::Net::HTTPServerRequest& request,
            Poco::Net::HTTPServerResponse& response) override;
};

#endif // TRANSACTIONHANDLER_H
