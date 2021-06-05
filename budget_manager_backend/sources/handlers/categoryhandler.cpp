#include "categoryhandler.h"
#include "categoryjsonbuilder.h"


CategoryHandler::CategoryHandler(std::shared_ptr<IDBManager> dbManager, std::shared_ptr<IParserManager> parserManager)
{
    this->_dbManager = dbManager;
    this->_parserManager = parserManager;
    parser.reset(_parserManager->getCategoryParser());
    repository.reset(_dbManager->getCategoryRepository());
}

AbstractHandler *CategoryHandler::getCopy()
{
    return new CategoryHandler(_dbManager, _parserManager);
}


void CategoryHandler::get(HTTPServerRequest& request, HTTPServerResponse& response)
{
    try {
        QMap<QString,QString> uri_map = getParametrsFromUrl(Poco::URI(request.getURI()));

        QString query(QString("SELECT * FROM %1 WHERE %2 = %3 ORDER BY %4 ASC").
                      arg(CATEGORY, USER_ID, uri_map[USER_ID], ID));

        QVector<Category> categories = repository->select(query);
        CategoryJsonBuilder categoryJsonBuilder;
        QJsonArray jsonArr;

        for (const auto &category : categories) {
            jsonArr.append(categoryJsonBuilder.buildJson(category));
        }

        QJsonDocument doc;
        doc.setArray(jsonArr);
        QString jsonString = doc.toJson();

        response.setContentType(APPLICATIONJSON.toStdString());

        response.setStatus(HTTPServerResponse::HTTP_OK);
        std::ostream& ostr = response.send();
        ostr<< jsonString.toStdString();
    } catch (...) {
        response.setStatus(HTTPServerResponse::HTTP_BAD_GATEWAY);
    }
}

void CategoryHandler::post(HTTPServerRequest& request, HTTPServerResponse& response)
{
    try{
        QJsonObject bodyObj = convertIstreamToJson(request.stream());
        Category category = parser->parse(bodyObj);
        repository->add(category);

        response.setStatus(HTTPServerResponse::HTTP_OK);
    } catch (...) {
        response.setStatus(HTTPServerResponse::HTTP_BAD_GATEWAY);
    }

    response.send();
}

void CategoryHandler::put(HTTPServerRequest& request, HTTPServerResponse& response)
{
    try{
        QJsonObject bodyObj = convertIstreamToJson(request.stream());
        Category category = parser->parse(bodyObj);
        repository->update(category);

        response.setStatus(HTTPServerResponse::HTTP_OK);
    } catch (...) {
        response.setStatus(HTTPServerResponse::HTTP_BAD_GATEWAY);
    }

    response.send();
}

void CategoryHandler::del(HTTPServerRequest& request, HTTPServerResponse& response)
{
    try{
        QMap<QString,QString> uri_map = getParametrsFromUrl(Poco::URI(request.getURI()));
        int id = uri_map[ID].toInt();
        repository->deleteObject(id);

        response.setStatus(HTTPServerResponse::HTTP_OK);
    } catch (...) {
        response.setStatus(HTTPServerResponse::HTTP_BAD_GATEWAY);
    }

    response.send();
}

void CategoryHandler::handleRequest(HTTPServerRequest &request, HTTPServerResponse &response)
{
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
