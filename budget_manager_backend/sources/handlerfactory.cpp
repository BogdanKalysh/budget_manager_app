#include "handlerfactory.h"
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/URI.h>
#include "dbmanager.h"
#include "parsermanager.h"
#include "userhandler.h"
#include "categoryhandler.h"
#include "transactionhandler.h"
#include "constants.h"

namespace handlers
{
HandlerFactory::HandlerFactory(){
    _dbManager.reset(new DBManager);
    _parserManager.reset(new ParserManager);

    addHandler(USERPATH.toStdString(), new UserHandler(_dbManager, _parserManager));
    addHandler(CATEGORYPATH.toStdString(), new CategoryHandler(_dbManager, _parserManager));
    addHandler(TRANSACTIONPATH.toStdString(), new TransactionHandler(_dbManager, _parserManager));
}

Poco::Net::HTTPRequestHandler* HandlerFactory::createRequestHandler(
    const Poco::Net::HTTPServerRequest& request)
{
    if (handlers[Poco::URI(request.getURI()).getPath()])
            return handlers[Poco::URI(request.getURI()).getPath()]->getCopy();
    return nullptr;
}

void HandlerFactory::addHandler(std::string uri, AbstractHandler* handler)
{
    handlers[uri] = handler;
}
}
