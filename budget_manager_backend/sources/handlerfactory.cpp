#include "handlerfactory.h"
#include <Poco/Net/HTTPServerRequest.h>
#include "dbmanager.h"
#include "userhandler.h"
#include "categoryhandler.h"
#include "transactionhandler.h"

namespace handlers
{

HandlerFactory::HandlerFactory(){
      manager.reset(new DBManager);

//    addHandler("/user", new UserHandler(manager));
//    addHandler("/category", new CategoryHandler);
//    addHandler("/transaction", new TransactionHandler);
}

Poco::Net::HTTPRequestHandler* HandlerFactory::createRequestHandler(
    const Poco::Net::HTTPServerRequest& request)
{
    if(handlers[request.getURI()])
        return handlers[request.getURI()]->getCopy();
    return nullptr;
}

void HandlerFactory::addHandler(std::string uri, IHandler* handler){
    handlers[uri] = handler;
}

}
