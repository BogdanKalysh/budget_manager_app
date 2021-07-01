#include "userhandler.h"
#include "userjsonbuilder.h"


UserHandler::UserHandler(std::shared_ptr<IDBManager> dbManager, std::shared_ptr<IParserManager> parserManager)
{
    this->_dbManager = dbManager;
    this->_parserManager = parserManager;
    parser.reset(_parserManager->getUserParser());
    repository.reset(_dbManager->getUserRepository());
}

AbstractHandler *UserHandler::getCopy()
{
    return new UserHandler(_dbManager, _parserManager);
}

void UserHandler::get(HTTPServerRequest &request, HTTPServerResponse &response)
{
    try {
        QMap<QString,QString> uri_map =getParametrsFromUrl(Poco::URI(request.getURI()));

        QString mail = uri_map.constFind(MAIL).value();
        QString password = uri_map.constFind(PASSWORD).value();

        QString query = "SELECT * FROM users WHERE " + MAIL + "='" + mail+ "'AND " + PASSWORD + "='" +password + "';";
        qDebug()<<mail;
        QVector<User> users = repository->select(query);
        UserJsonBuilder builder;
        if (!users.isEmpty()) {
            QJsonObject jsonObject = builder.buildJson(users.first());
            QString jsonString = QJsonDocument(jsonObject).toJson(QJsonDocument::Compact);
            response.setStatus(HTTPServerResponse::HTTP_OK);
            response.setContentType("application/json");

            std::ostream& ostr = response.send();
            ostr<< jsonString.toStdString();
        } else {
            response.setStatus(HTTPServerResponse::HTTP_NOT_FOUND);
            response.send();
        }
    } catch (...) {
        response.setStatus(HTTPServerResponse::HTTP_BAD_GATEWAY);
        response.send();
    }
}

void UserHandler::post(HTTPServerRequest &request, HTTPServerResponse &response)
{
    try {
        QJsonObject json = convertIstreamToJson(request.stream());
        User user = parser->parse(json);
        qDebug()<<user.getEmail();
        QVector<User> users = repository->select("SELECT * FROM users WHERE "+ MAIL + "='" + user.getEmail() + "';" );
        if (users.empty()) {
            repository->add(user);
            response.setStatus(HTTPServerResponse::HTTP_CREATED);
        } else {
            response.setStatus(HTTPServerResponse::HTTP_FORBIDDEN);
        }
    } catch (...) {
        response.setStatus(HTTPServerResponse::HTTP_BAD_GATEWAY);

    }

    response.send();
}

void UserHandler::put(HTTPServerRequest &request, HTTPServerResponse &response)
{
    try {
        QJsonObject json = convertIstreamToJson(request.stream());
        User user = parser->parse(json);

        QVector<User> users = repository->select("SELECT * FROM users WHERE "+ ID + "=" + std::to_string(user.getId()).c_str() + ";" );

        if (!users.empty()) {
            users = repository->select("SELECT * FROM users WHERE "+ MAIL + "='" + user.getEmail() + "';" );
            if (users.isEmpty() || users[0].getId() == user.getId()) {
                repository->update(user);
                response.setStatus(HTTPServerResponse::HTTP_ACCEPTED);
            } else {
                response.setStatus(HTTPServerResponse::HTTP_FORBIDDEN);
            }
        } else {
            response.setStatus(HTTPServerResponse::HTTP_NOT_FOUND);
        }

    } catch (...) {
        response.setStatus(HTTPServerResponse::HTTP_BAD_GATEWAY);
    }

    response.send();
}

void UserHandler::del(HTTPServerRequest &request, HTTPServerResponse &response)
{
    try {
        QMap<QString,QString> uri_map = getParametrsFromUrl(Poco::URI(request.getURI()));
        int id = uri_map[ID].toInt();

        QVector<User> users = repository->select("SELECT * FROM users WHERE "+ ID + "=" + std::to_string(id).c_str() + ";" );

        if (!users.isEmpty()) {
            repository->deleteObject(id);
            response.setStatus(HTTPServerResponse::HTTP_OK);
        } else {
            response.setStatus(HTTPServerResponse::HTTP_NOT_FOUND);
        }
    } catch (...) {
        response.setStatus(HTTPServerResponse::HTTP_BAD_GATEWAY);
    }

    response.send();
}

void UserHandler::handleRequest(HTTPServerRequest& request, HTTPServerResponse& response){

    if (request.getMethod() == HTTPRequest::HTTP_GET) {
        get(request, response);
    } else if(request.getMethod() == HTTPRequest::HTTP_POST) {
        post(request, response);
    } else if(request.getMethod() == HTTPRequest::HTTP_PUT) {
        put(request, response);
    } else if(request.getMethod() == HTTPRequest::HTTP_DELETE) {
        del(request, response);
    } else {
        response.setStatus(HTTPServerResponse::HTTP_BAD_REQUEST);
        response.send();
    }
}
