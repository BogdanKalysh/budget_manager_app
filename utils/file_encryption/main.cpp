#include <QCoreApplication>
#include <QFile>
#include <QDebug>
#include <QString>

#include <Poco/Crypto/CipherKey.h>
#include <Poco/Crypto/Cipher.h>
#include <Poco/Crypto/CipherFactory.h>

using namespace Poco::Crypto;

const QString KEY = "budget_manager";
const QString FILEPATH = "../../DAL/DB.txt";
const QString AES = "aes-256-ecb";

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    CipherFactory& factory = CipherFactory::defaultFactory();
    Cipher* pCipher = factory.createCipher(CipherKey(AES.toStdString(), KEY.toStdString()));

    QFile dbFile(FILEPATH);


    if(!dbFile.open(QIODevice::ReadOnly)) {
        qDebug() << "Error: Opening DB.txt during file encription!";
    } else {
        QTextStream fin(&dbFile);
        QString dbConfig = fin.readAll();;
        dbFile.close();

        if(dbFile.open(QIODevice::WriteOnly)){
            fin << pCipher->encryptString(dbConfig.toStdString(), Cipher::ENC_BASE64).c_str();
            dbFile.close();
        }
    }

    return a.exec();
}
