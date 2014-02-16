#ifndef QBLOGGER_H
#define QBLOGGER_H

#include "QsLog\QsLog.h"
#include "QsLog\QsLogDest.h"
#include <QDir>
#include <QDate>
#include <QTime>

class QbLogger
{
public:
    void debug(QString message);
    void info(QString message);
    void trace(QString message);
    void warn(QString message);
    void error(QString message);
    void fatal(QString message);
    static QbLogger* getInstance();
private:
    static QbLogger* instance;
    QbLogger();
};

#endif // QBLOGGER_H
