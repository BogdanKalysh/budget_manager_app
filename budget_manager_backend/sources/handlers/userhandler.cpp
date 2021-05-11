#include "userhandler.h"
#include "userparser.h"
#include "user.h"
#include <QJsonDocument>
//UserHandler::UserHandler(){
////    parser.reset(new UserParser);
//}

UserHandler::UserHandler(std::shared_ptr<IDBManager> manager)
{
    this->_dbManager = manager;
}

IHandler *UserHandler::getCopy()
{
    return new UserHandler(_dbManager);
}

QJsonObject UserHandler::convertIstreamToJson(std::istream &body)
{
    std::string sBody;
    sBody = std::string((std::istreambuf_iterator<char>(body)), std::istreambuf_iterator<char>());

    QString qBody = QString::fromStdString(sBody);
    QByteArray br = qBody.toUtf8();
    QJsonDocument doc = QJsonDocument::fromJson(br);
    QJsonObject obj = doc.object();

    return obj;
}

void UserHandler::handleRequest(
    Poco::Net::HTTPServerRequest& request,
    Poco::Net::HTTPServerResponse& response){

    if(request.getMethod() == Poco::Net::HTTPRequest::HTTP_GET){

    }else if(request.getMethod() == Poco::Net::HTTPRequest::HTTP_POST){
        post(request, response);
    }else if(request.getMethod() == Poco::Net::HTTPRequest::HTTP_PUT){

    }else if(request.getMethod() == Poco::Net::HTTPRequest::HTTP_DELETE){

    }
}

void UserHandler::get(Poco::Net::HTTPServerRequest& request,
                       Poco::Net::HTTPServerResponse& response)
{

}

void UserHandler::post(Poco::Net::HTTPServerRequest& request,
                       Poco::Net::HTTPServerResponse& response)
{
    QJsonObject bodyObj = convertIstreamToJson(request.stream());

    UserParser parser;
    User user = parser.parse(bodyObj);

    qDebug() << user.getName();


    IRepository<User> * repository = _dbManager->getUserRepository();
    repository->add(user);

    response.setStatus(Poco::Net::HTTPServerResponse::HTTP_OK);
    response.send();
}

void UserHandler::put(Poco::Net::HTTPServerRequest& request,
                      Poco::Net::HTTPServerResponse& response)
{

}

void UserHandler::del(Poco::Net::HTTPServerRequest& request,
                      Poco::Net::HTTPServerResponse& response)
{

}

//UserHandler::~UserHandler(){

//}
