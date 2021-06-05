#ifndef LOGGER_H
#define LOGGER_H

#include <QFile>

class Logger
{
private:
    static bool isInit;
    static QScopedPointer<QFile> logFile;

    /**
     * it's our messageHandler
     *
     * after we install this messageHandler
     * using qDebug, qInfo, etc. will write info in file instead of console
     */
    static void messageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg);
public:

    /**
     * all we need to do to use the logger is to call once this method and just use qDebug, qInfo, etc.
     */
    static void init();
};

#endif // LOGGER_H
