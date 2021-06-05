#include "constants.h"
#include "logger.h"
#include <QDateTime>
#include <QDebug>
#include <QMutex>

bool Logger::isInit = false;

QScopedPointer<QFile> Logger::logFile(nullptr);

void Logger::messageHandler(QtMsgType type,
    const QMessageLogContext &context,
    const QString &msg)
{
    static QMutex mutex;
    QMutexLocker lock(&mutex);

    QTextStream out(logFile.data());

    QString stringType;
    switch (type)
    {
    case QtInfoMsg:
        stringType = "INF ";
        break;
    case QtDebugMsg:
        stringType = "DBG ";
        break;
    case QtWarningMsg:
        stringType = "WRN ";
        break;
    case QtCriticalMsg:
        stringType = "CRT ";
        break;
    case QtFatalMsg:
        stringType = "FTL ";
        break;
    }

    QString log = QString("%1 | %2 | line %3 | %4 | %5 | %6\n").
            arg(QDateTime::currentDateTime().toString("dd-MM-yyyy hh:mm:ss")).
            arg(stringType).
            arg(context.line).              //line number
            arg(QString(context.file).
                section('\\', -1)).			// File name
            arg(QString(context.function).
                section('(', -2, -2).		// Function name
                section(' ', -1)).
            arg(msg);


    out << log << Qt::endl;
    out.flush();
}

void Logger::init()
{
    if (isInit) {
        return;
    }

    logFile.reset(new QFile(logger::LOGFILEPATH));

    if (!logFile.data()->open(QFile::Append | QFile::Text)) {
        qDebug()<<"file is not open";
        return;
    }

    qInstallMessageHandler(Logger::messageHandler);
    isInit = true;
}

