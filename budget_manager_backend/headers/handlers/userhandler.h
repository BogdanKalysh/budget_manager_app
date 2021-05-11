#ifndef USERHANDLER_H
#define USERHANDLER_H

#include "abstracthandler.h"
#include "userparser.h"

class UserHandler: public AbstractHandler
{
protected:
    using parsPtr = std::shared_ptr<IJsonParser<User>>;
    using reposPtr = std::shared_ptr<IRepository<User>>;

    parsPtr parser;
    reposPtr repository;

    void get(Poco::Net::HTTPServerRequest& request,
            Poco::Net::HTTPServerResponse& response) override;
    void post(Poco::Net::HTTPServerRequest& request,
            Poco::Net::HTTPServerResponse& response) override;
    void put(Poco::Net::HTTPServerRequest& request,
            Poco::Net::HTTPServerResponse& response) override;
    void del(Poco::Net::HTTPServerRequest& request,
            Poco::Net::HTTPServerResponse& response) override;

public:
    UserHandler(std::shared_ptr<IDBManager> dbManager, std::shared_ptr<IParserManager> parserManager);
    AbstractHandler* getCopy() override;

    void handleRequest(
            Poco::Net::HTTPServerRequest& request,
            Poco::Net::HTTPServerResponse& response) override;
};

#endif // USERHANDLER_H
