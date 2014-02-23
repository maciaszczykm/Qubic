#include "qbpersistable.h"

QbPersistable::QbPersistable() {

}

QString QbPersistable::getObjectName() {
    QString objectName = this->metaObject()->className();
    return objectName.toUpper();
}

QString QbPersistable::getObjectString() {
    QbProperties properties = QbProperties(QDir::currentPath()+"/qb.properties");
    QString prefix = properties.getProperty("qubic.configuration.getters.prefix");
    QString objectString;
    for(int i = 0; i < this->metaObject()->methodCount(); i++)
    {
        QMetaMethod method = this->metaObject()->method(i);
        if(method.name().startsWith(prefix.toStdString().c_str()))
        {
            QString memberName = method.name().right(method.name().length() - prefix.length());
            memberName = memberName.toUpper();
            QString memberValue;
            QMetaObject::invokeMethod(this, method.name(), Q_RETURN_ARG(QString, memberValue));
            objectString.append(memberName + " = " + memberValue + "; ");
        }
    }
    objectString = objectString.left(objectString.length() - 2);
    return objectString;
}
