#include "transactionhandler.h"
#include "transactionparser.h"
#include "transactionjsonbuilder.h"
#include "transaction.h"
#include <QJsonDocument>


TransactionHandler::TransactionHandler(std::shared_ptr<IDBManager> manager)
{
    this->_dbManager = manager;
}

IHandler *TransactionHandler::getCopy()
{
    return new TransactionHandler(_dbManager);
}

QJsonObject TransactionHandler::convertIstreamToJson(std::istream &body)
{
    std::string sBody;
    sBody = std::string((std::istreambuf_iterator<char>(body)), std::istreambuf_iterator<char>());

    QString qBody = QString::fromStdString(sBody);
    QByteArray br = qBody.toUtf8();
    QJsonDocument doc = QJsonDocument::fromJson(br);
    QJsonObject obj = doc.object();

    return obj;
}

void TransactionHandler::handleRequest(
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
}


void TransactionHandler::get(Poco::Net::HTTPServerRequest& request,
                       Poco::Net::HTTPServerResponse& response)
{
    QJsonObject bodyObj = convertIstreamToJson(request.stream());
    std::string user_id = std::to_string(bodyObj.value("id").toInt());
    QString start_date = bodyObj.value("start_date").toVariant().toString();
    QString end_date = bodyObj.value("end_date").toVariant().toString();

    QString select = "SELECT transaction.*, category.name, category.color, category.type FROM category INNER JOIN "
                     "transaction ON category.id = transaction.category_id WHERE category.user_id = "+ QString(user_id.c_str()) +
                     " AND transaction.date > '"+start_date+"'::date AND transaction.date < '"+end_date+"'::date";

    qDebug()<<select;
    IRepository<Transaction> * repository = _dbManager->getTransactionRepository();

    QVector<Transaction> transactions = repository->select(select);
    TransactionJsonBuilder transactionJsonBuilder;

    QJsonArray jsonArr;
    for(const auto &transaction : transactions){
        jsonArr.append(transactionJsonBuilder.buildJson(transaction));
    }

    QJsonDocument doc;
    doc.setArray(jsonArr);
    QString jsonString = doc.toJson();

    response.setContentType("application/json");
    std::ostream& ostr = response.send();
    response.setStatus(Poco::Net::HTTPServerResponse::HTTP_OK);
    ostr<< jsonString.toStdString();
}

void TransactionHandler::post(Poco::Net::HTTPServerRequest& request,
                       Poco::Net::HTTPServerResponse& response)
{
    QJsonObject bodyObj = convertIstreamToJson(request.stream());
    TransactionParser parser;
    Transaction transaction = parser.parse(bodyObj);
    IRepository<Transaction> * repository = _dbManager->getTransactionRepository();
    repository->add(transaction);

    response.setStatus(Poco::Net::HTTPServerResponse::HTTP_OK);
    response.send();
}

void TransactionHandler::put(Poco::Net::HTTPServerRequest& request,
                      Poco::Net::HTTPServerResponse& response)
{
    QJsonObject bodyObj = convertIstreamToJson(request.stream());
    TransactionParser parser;
    Transaction transaction = parser.parse(bodyObj);
    IRepository<Transaction> * repository = _dbManager->getTransactionRepository();
    repository->update(transaction);

    response.setStatus(Poco::Net::HTTPServerResponse::HTTP_OK);
    response.send();
}

void TransactionHandler::del(Poco::Net::HTTPServerRequest& request,
                      Poco::Net::HTTPServerResponse& response)
{
    QJsonObject bodyObj = convertIstreamToJson(request.stream());
    int user_id = bodyObj.value("id").toInt();
    IRepository<Transaction> * repository = _dbManager->getTransactionRepository();
    repository->deleteObject(user_id);

    response.setStatus(Poco::Net::HTTPServerResponse::HTTP_OK);
    response.send();
}
