#ifndef ABSTRACTHANDLER_H
#define ABSTRACTHANDLER_H
#include "idbmanager.h"
#include "iparsermanager.h"
#include "ijsonparser.h"
#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/JSON/Object.h>
#include <Poco/URI.h>
#include <QMap>
#include <memory>

using namespace Poco::Net;
using namespace models;
using namespace handlers;

class AbstractHandler : public Poco::Net::HTTPRequestHandler
{
protected:
    std::shared_ptr <IDBManager> _dbManager;
    std::shared_ptr <IParserManager> _parserManager;

    virtual void get(HTTPServerRequest& request,
                     HTTPServerResponse& response) = 0;
    virtual void post(HTTPServerRequest& request,
                     HTTPServerResponse& response) = 0;
    virtual void put(HTTPServerRequest& request,
                     HTTPServerResponse& response) = 0;
    virtual void del(HTTPServerRequest& request,
                     HTTPServerResponse& response) = 0;

public:
    virtual AbstractHandler* getCopy() = 0;

    QJsonObject convertIstreamToJson(std::istream &body);
    QMap<QString,QString> getParametrsFromUrl(const Poco::URI &uri);
};

#endif // ABSTRACTHANDLER_H
