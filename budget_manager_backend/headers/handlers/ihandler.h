#ifndef IHANDLER_H
#define IHANDLER_H

#include "idbmanager.h"
#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/JSON/Object.h>
#include <memory>

class IHandler : public Poco::Net::HTTPRequestHandler
{
protected:
    std::shared_ptr <IDBManager> _dbManager;

public:
    virtual IHandler* getCopy() = 0;

    QJsonObject convertIstreamToJson(std::istream &body);

    virtual void get(Poco::Net::HTTPServerRequest& request,
                     Poco::Net::HTTPServerResponse& response) = 0;
    virtual void post(Poco::Net::HTTPServerRequest& request,
                      Poco::Net::HTTPServerResponse& response) = 0;
    virtual void put(Poco::Net::HTTPServerRequest& request,
                     Poco::Net::HTTPServerResponse& response) = 0;
    virtual void del(Poco::Net::HTTPServerRequest& request,
                     Poco::Net::HTTPServerResponse& response) = 0;
};

#endif // IHANDLER_H
