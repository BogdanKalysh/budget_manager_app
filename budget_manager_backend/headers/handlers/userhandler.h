#ifndef USERHANDLER_H
#define USERHANDLER_H

#include "ihandler.h"
#include "userparser.h"
#include <QJsonDocument>

class UserHandler: public IHandler
{
private:
    UserParser parser;
    
public:
    UserHandler(std::shared_ptr<IDBManager> manager);
    IHandler* getCopy() override;

    QJsonObject convertIstreamToJson(std::istream &body) override;

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
