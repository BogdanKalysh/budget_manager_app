#include "setupdatabase.h"
#include <Poco/Crypto/CipherKey.h>
#include <Poco/Crypto/Cipher.h>
#include <Poco/Crypto/CipherFactory.h>


using namespace Poco::Crypto;

QSqlDatabase setUpDatabase()
{
    QFile dbFile(dal::DBCONFIGPATH);

    if (!dbFile.open(QIODevice::ReadOnly)) {
        qDebug() << "Error: Opening file DB.txt";
        return QSqlDatabase();
    }

    CipherFactory& factory = CipherFactory::defaultFactory();
    Cipher* pCipher = factory.createCipher(CipherKey(dal::AES.toStdString(), dal::KEY.toStdString()));

    QTextStream in(&dbFile);

    QString dbConfigContent = pCipher->decryptString(in.readAll().toStdString(), Cipher::ENC_BASE64).c_str();
    dbFile.close();

    QMap<QString, QString> dbConfig;

    QString field = "";
    QString value = "";
    bool firstPart = true;

    for(int i = 0; i <= dbConfigContent.length(); i++){

        if(i == dbConfigContent.length() || dbConfigContent[i] == '\n'){
            dbConfig[field] = value;
            field = "";
            value = "";
            firstPart = true;
            continue;
        }

        if(dbConfigContent[i] == '\r')
            continue;

        if(dbConfigContent[i] == ':'){
            firstPart = false;
            continue;
        }

        if(firstPart)
            field += dbConfigContent[i];
        else
            value += dbConfigContent[i];

    }

    dbFile.close();

    QSqlDatabase db = QSqlDatabase::addDatabase(dbConfig[dal::DB]);
    db.setHostName(dbConfig[dal::HOST]);
    db.setDatabaseName(dbConfig[dal::DBNAME]);
    db.setUserName(dbConfig[dal::USER]);
    db.setPassword(dbConfig[dal::USER_PASSWORD]);

    return db;
}

