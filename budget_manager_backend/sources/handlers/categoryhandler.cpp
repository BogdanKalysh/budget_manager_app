#include "categoryhandler.h"
#include "categoryparser.h"
#include "category.h"
#include <QJsonDocument>


CategoryHandler::CategoryHandler(std::shared_ptr<IDBManager> manager)
{
    this->_dbManager = manager;
}

IHandler *CategoryHandler::getCopy()
{
    return new CategoryHandler(_dbManager);
}

QJsonObject CategoryHandler::convertIstreamToJson(std::istream &body)
{
    std::string sBody;
    sBody = std::string((std::istreambuf_iterator<char>(body)), std::istreambuf_iterator<char>());

    QString qBody = QString::fromStdString(sBody);
    QByteArray br = qBody.toUtf8();
    QJsonDocument doc = QJsonDocument::fromJson(br);
    QJsonObject obj = doc.object();

    return obj;
}

void CategoryHandler::handleRequest(
    Poco::Net::HTTPServerRequest& request,
    Poco::Net::HTTPServerResponse& response){

    if(request.getMethod() == Poco::Net::HTTPRequest::HTTP_GET){

    }else if(request.getMethod() == Poco::Net::HTTPRequest::HTTP_POST){
        post(request, response);
    }else if(request.getMethod() == Poco::Net::HTTPRequest::HTTP_PUT){

    }else if(request.getMethod() == Poco::Net::HTTPRequest::HTTP_DELETE){

    }
}


void CategoryHandler::get(Poco::Net::HTTPServerRequest& request,
                       Poco::Net::HTTPServerResponse& response)
{

}

void CategoryHandler::post(Poco::Net::HTTPServerRequest& request,
                       Poco::Net::HTTPServerResponse& response)
{
    QJsonObject bodyObj = convertIstreamToJson(request.stream());
    CategoryParser parser;
    Category category = parser.parse(bodyObj);

    IRepository<Category> * repository = _dbManager->getCategoryRepository();
    repository->add(category);

    response.setStatus(Poco::Net::HTTPServerResponse::HTTP_OK);
    response.send();
}

void CategoryHandler::put(Poco::Net::HTTPServerRequest& request,
                      Poco::Net::HTTPServerResponse& response)
{

}

void CategoryHandler::del(Poco::Net::HTTPServerRequest& request,
                      Poco::Net::HTTPServerResponse& response)
{

}
