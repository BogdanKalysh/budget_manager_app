#include "userhandler.h"
#include "Poco/JSON/Object.h"
#include "userjsonbuilder.h"
UserHandler::UserHandler(std::shared_ptr<IDBManager> manager)
{
    this->manager = manager;
    parser = UserParser();
}

IHandler *UserHandler::getCopy()
{
    return new UserHandler(this->manager);
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

void UserHandler::get(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response)
{
    IRepository<User> *userRepository;

    try {
    QJsonObject json = convertIstreamToJson(request.stream());

    QString mail = json.value(parser::EMAIL).toString();
    QString password = json.value(parser::PASSWORD).toString();

    userRepository = (manager.get()->getUserRepository());

    QString query = "SELECT * FROM users WHERE " + dal::MAIL + "='" + mail+ "'AND " + dal::PASSWORD + "='" +password + "';" ;
    QVector<User> users = userRepository->select(query);
    UserJsonBuilder builder;

    QJsonObject jsonObject =builder.buildJson(users.first());
    QString jsonString = QJsonDocument(jsonObject).toJson(QJsonDocument::Compact);

    response.setStatus(Poco::Net::HTTPServerResponse::HTTP_OK);
    response.setContentType("application/json");

    std::ostream& ostr =response.send();
    ostr<< jsonString.toStdString();

    } catch (...) {
        response.setStatus(Poco::Net::HTTPServerResponse::HTTP_BAD_GATEWAY);
    }
    delete userRepository;
}

void UserHandler::post(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response)
{
    IRepository<User> *userRepository;

    try {

    QJsonObject json = convertIstreamToJson(request.stream());
    User user = parser.parse(json);

    userRepository = (manager.get()->getUserRepository());

    QVector<User> users = userRepository->select("SELECT * FROM users WHERE "+ dal::MAIL + "='"+user.getEmail()+"';" );
    if(users.empty()){

        userRepository->add(user);
        response.setStatus(Poco::Net::HTTPServerResponse::HTTP_CREATED);
    }
    else{
        response.setStatus(Poco::Net::HTTPServerResponse::HTTP_FORBIDDEN);
    }

    } catch (...) {
        response.setStatus(Poco::Net::HTTPServerResponse::HTTP_BAD_GATEWAY);
    }

    response.send();
    delete userRepository;
}

void UserHandler::put(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response)
{
    IRepository<User> *userRepository;

    try {
    QJsonObject json = convertIstreamToJson(request.stream());
    User user = parser.parse(json);

    userRepository = (manager.get()->getUserRepository());

    QVector<User> users = userRepository->select("SELECT * FROM users WHERE "+ dal::MAIL + "='"+user.getEmail()+"';" );

    if(!users.empty()){
        userRepository->update(user);
        response.setStatus(Poco::Net::HTTPServerResponse::HTTP_ACCEPTED);
    }
    else{
        response.setStatus(Poco::Net::HTTPServerResponse::HTTP_NOT_FOUND);
    }

    } catch (...) {
        response.setStatus(Poco::Net::HTTPServerResponse::HTTP_BAD_GATEWAY);
    }

    response.send();
    delete userRepository;
}

void UserHandler::del(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response)
{
    IRepository<User> *userRepository;
    try {

    QJsonObject json = convertIstreamToJson(request.stream());
    int id = json.value(parser::ID).toInt();

    userRepository = (manager.get()->getUserRepository());

    userRepository->deleteObject(id);

    response.setStatus(Poco::Net::HTTPServerResponse::HTTP_OK);

     } catch (...) {
        response.setStatus(Poco::Net::HTTPServerResponse::HTTP_BAD_GATEWAY);
    }

    response.send();
    delete userRepository;
}

void UserHandler::handleRequest(
    Poco::Net::HTTPServerRequest& request,
    Poco::Net::HTTPServerResponse& response){

    if(request.getMethod() == Poco::Net::HTTPRequest::HTTP_GET){
        get(request, response);

    }else if(request.getMethod() == Poco::Net::HTTPRequest::HTTP_POST){
        post(request, response);

    }else if(request.getMethod() == Poco::Net::HTTPRequest::HTTP_PUT){
        put(request, response);

    }else if(request.getMethod() == Poco::Net::HTTPRequest::HTTP_DELETE){
        del(request, response);
    }
    else{
        response.setStatus(Poco::Net::HTTPServerResponse::HTTP_BAD_REQUEST);
        response.send();
    }
}
