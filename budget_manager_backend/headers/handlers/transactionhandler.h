#ifndef TRANSACTIONHANDLER_H
#define TRANSACTIONHANDLER_H

#include "ihandler.h"
#include "ijsonparser.h"
#include "transaction.h"

class TransactionHandler : public IHandler
{
public:

    TransactionHandler(std::shared_ptr <IDBManager> manager);
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

#endif // TRANSACTIONHANDLER_H
