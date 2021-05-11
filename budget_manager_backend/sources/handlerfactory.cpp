#include "handlerfactory.h"
#include <Poco/Net/HTTPServerRequest.h>
#include "dbmanager.h"
#include "userhandler.h"
#include "categoryhandler.h"
#include "transactionhandler.h"

namespace handlers
{

HandlerFactory::HandlerFactory(){
    _dbManager.reset(new DBManager);

    addHandler("/user", new UserHandler(_dbManager));
    addHandler("/category", new CategoryHandler(_dbManager));
    addHandler("/transaction", new TransactionHandler(_dbManager));
}

Poco::Net::HTTPRequestHandler* HandlerFactory::createRequestHandler(
    const Poco::Net::HTTPServerRequest& request)
{
    std::cout<<request.getURI();
    if(handlers[request.getURI()])
        return handlers[request.getURI()]->getCopy();
    return nullptr;
}

void HandlerFactory::addHandler(std::string uri, IHandler* handler)
{
    handlers[uri] = handler;
}

}
