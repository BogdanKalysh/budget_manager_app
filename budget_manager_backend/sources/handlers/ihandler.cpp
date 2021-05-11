#include "ihandler.h"
#include <QJsonObject>
#include <QJsonDocument>

QJsonObject IHandler::convertIstreamToJson(std::istream &body)
{
    std::string sBody;
    sBody = std::string((std::istreambuf_iterator<char>(body)), std::istreambuf_iterator<char>());

    QString qBody = QString::fromStdString(sBody);
    QByteArray br = qBody.toUtf8();
    QJsonDocument doc = QJsonDocument::fromJson(br);
    QJsonObject obj = doc.object();

    return obj;
}
