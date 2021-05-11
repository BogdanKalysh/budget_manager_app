#ifndef USERHANDLER_H
#define USERHANDLER_H

#include "ihandler.h"
#include "ijsonparser.h"
#include "user.h"

class UserHandler : public IHandler //<User>
{
public:
//    UserHandler();
    UserHandler(std::shared_ptr <IDBManager> manager);
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

//    ~UserHandler();
};

#endif // USERHANDLER_H
