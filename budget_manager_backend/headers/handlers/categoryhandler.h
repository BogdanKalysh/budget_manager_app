#ifndef CATEGORYHANDLER_H
#define CATEGORYHANDLER_H
#include "ihandler.h"
#include "category.h"
#include "ijsonparser.h"

class CategoryHandler : public IHandler
{
private:
    std::shared_ptr<IRepository<Category>> repository;
public:

    CategoryHandler(std::shared_ptr <IDBManager> manager);
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

#endif // CATEGORYHANDLER_H
