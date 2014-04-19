#include "qbadvancedqueryhelper.h"
#include "QbCore/qbdatabase.h"

QList<QbPersistable*> QbAdvancedQueryHelper::queryOneToMany(QString className, QString conditionClass, int id)
{
    if(QbDatabase::getInstance()->checkDriver("QMYSQL"))
    {
        QbQuery* query = new QbMySQLQuery(className);
        query->appendWhere(conditionClass, QString::number(id), QbQuery::EQUALS);
        return QbDatabase::getInstance()->load(query);
    }
    else
    {
        QLOG_FATAL() << "Advanced queries are not implemented for " + QbDatabase::getInstance()->getDatabase()->driverName() + " driver";
        return QList<QbPersistable*>();
    }
}
