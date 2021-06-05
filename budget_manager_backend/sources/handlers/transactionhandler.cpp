#include "transactionhandler.h"
#include "transactionjsonbuilder.h"


TransactionHandler::TransactionHandler(std::shared_ptr<IDBManager> dbManager, std::shared_ptr<IParserManager> parserManager)
{
    this->_dbManager = dbManager;
    this->_parserManager = parserManager;
    parser.reset(_parserManager->getTransactionParser());
    repository.reset(_dbManager->getTransactionRepository());
}

AbstractHandler *TransactionHandler::getCopy()
{
    return new TransactionHandler(_dbManager, _parserManager);
}

void TransactionHandler::get(HTTPServerRequest& request, HTTPServerResponse& response)
{    
    try {
        QMap<QString,QString> uri_map = getParametrsFromUrl(Poco::URI(request.getURI()));

        QString user_id = uri_map.constFind(USER_ID).value();
        QString start_date = uri_map.constFind(START_DATE).value();
        QString end_date = uri_map.constFind(END_DATE).value();

        QString query = QString("SELECT %1.*, %2.%3, %2.%4, %2.%5 FROM %2 INNER JOIN "
                            "%1 ON %2.%6 = %1.%7 WHERE %2.%8 = " + user_id +" AND %1.%9 >= '"
                            + start_date + "'::%9 AND %1.%9 <= '" + end_date + "'::%9 ORDER BY %1.%6 DESC")
                            .arg(TRANSACTION, CATEGORY, NAME, COLOR, TYPE, ID, CATEGORY_ID, USER_ID, models::DATE);

        QVector<Transaction> transactions = repository->select(query);
        TransactionJsonBuilder transactionJsonBuilder;
        QJsonArray jsonArr;

        for (const auto &transaction : transactions) {
            jsonArr.append(transactionJsonBuilder.buildJson(transaction));
        }

        QJsonDocument doc;
        doc.setArray(jsonArr);
        QString jsonString = doc.toJson();

        response.setContentType(APPLICATIONJSON.toStdString());

        response.setStatus(HTTPServerResponse::HTTP_OK);
        std::ostream& ostr = response.send();
        ostr<< jsonString.toStdString();
    } catch(...) {
        response.setStatus(HTTPServerResponse::HTTP_BAD_GATEWAY);
    }
}

void TransactionHandler::post(HTTPServerRequest& request, HTTPServerResponse& response)
{
    try{
        QJsonObject bodyObj = convertIstreamToJson(request.stream());
        Transaction transaction = parser->parse(bodyObj);
        repository->add(transaction);

        response.setStatus(HTTPServerResponse::HTTP_OK);
    } catch (...) {
        response.setStatus(HTTPServerResponse::HTTP_BAD_GATEWAY);
    }

    response.send();
}

void TransactionHandler::put(HTTPServerRequest& request, HTTPServerResponse& response)
{
    try{
        QJsonObject bodyObj = convertIstreamToJson(request.stream());
        Transaction transaction = parser->parse(bodyObj);
        repository->update(transaction);

        response.setStatus(HTTPServerResponse::HTTP_OK);
    } catch (...) {
        response.setStatus(HTTPServerResponse::HTTP_BAD_GATEWAY);
    }

    response.send();
}

void TransactionHandler::del(HTTPServerRequest& request, HTTPServerResponse& response)
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

void TransactionHandler::handleRequest(HTTPServerRequest& request, HTTPServerResponse& response)
{
    if (request.getMethod() == HTTPRequest::HTTP_GET){
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
