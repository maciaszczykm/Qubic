#include "qblogger.h"

QbLogger* QbLogger::instance = NULL;

QbLogger::QbLogger()
{
    QsLogging::Logger& logger = QsLogging::Logger::instance();
    logger.setLoggingLevel(QsLogging::TraceLevel);
    QString date = QDate::currentDate().toString("ddMMyyyy");
    QString time = QTime::currentTime().toString("hhmmss");
    const QString filepath (QDir::currentPath() + "/logs/" + date + time + ".txt");
    QFileInfo logs("logs");
    if(!logs.exists() || !logs.isDir())
    {
        QDir logsDir;
        logsDir.mkdir("logs");
    }
    QsLogging::DestinationPtr fileDestination(QsLogging::DestinationFactory::MakeFileDestination(filepath, true, 512, 2));
    QsLogging::DestinationPtr debugDestination(QsLogging::DestinationFactory::MakeDebugOutputDestination());
    logger.addDestination(debugDestination);
    logger.addDestination(fileDestination);
}

QbLogger *QbLogger::getInstance()
{
    if (instance == NULL) instance = new QbLogger();
    return instance;
}

void QbLogger::debug(QString message)
{
    QLOG_DEBUG() << message;
}

void QbLogger::info(QString message)
{
    QLOG_INFO() << message;
}

void QbLogger::trace(QString message)
{
    QLOG_TRACE() << message;
}

void QbLogger::warn(QString message)
{
    QLOG_WARN() << message;
}

void QbLogger::error(QString message)
{
    QLOG_ERROR() << message;
}

void QbLogger::fatal(QString message)
{
    QLOG_FATAL() << message;
}
