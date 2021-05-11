#ifndef USERHANDLER_H
#define USERHANDLER_H

#include "ihandler.h"
#include "userparser.h"

class UserHandler: public IHandler
{
private:
    UserParser parser;
    std::shared_ptr<IRepository<User>> repository;

public:
    UserHandler(std::shared_ptr<IDBManager> manager);
    IHandler* getCopy() override;

//    QJsonObject convertIstreamToJson(std::istream &body) override;

    void handleRequest(
            Poco::Net::HTTPServerRequest& request,
            Poco::Net::HTTPServerResponse& response) override;

    void get(Poco::Net::HTTPServerRequest& request,
            Poco::Net::HTTPServerResponse& response) override;
    void post(Poco::Net::HTTPServerRequest& request,
            Poco::Net::HTTPServerResponse& response) override;
    void put(Poco::Net::HTTPServerRequest& request,
            Poco::Net::HTTPServerResponse& response) override;
    void del(Poco::Net::HTTPServerRequest& request,
            Poco::Net::HTTPServerResponse& response) override;
};

#endif // USERHANDLER_H
