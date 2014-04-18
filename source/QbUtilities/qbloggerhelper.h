#ifndef QBLOGGERHELPER_H
#define QBLOGGERHELPER_H

#include "QsLog\QsLog.h"
#include "QsLog\QsLogDest.h"
#include <QbCore/qbproperties.h>
#include <QDir>
#include <QDate>
#include <QTime>

class QbLoggerHelper
{
public:
    static void initialize();

private:
    static bool isInitialized;
};

#endif // QBLOGGERHELPER_H
