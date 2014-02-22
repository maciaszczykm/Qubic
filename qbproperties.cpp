#include "qbproperties.h"

QbProperties::QbProperties()
{

}

QbProperties::QbProperties(QString path)
{
    this->path = path;
    QFile file(path);
    if(!file.exists() || !file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QbLogger::getInstance()->fatal("Cannot open properties file");
        return;
    }
    QTextStream in(&file);
    while(!in.atEnd())
    {
        QString line = in.readLine();
        QStringList fields = line.split("=");
        if(line.at(0)!='#' && fields.size()==2) {
            properties.insert(properties.end(), fields.at(0), fields.at(1));
        }
    }
    file.close();
    QbLogger::getInstance()->info("Properties successfully read from " + QDir::currentPath() + "/qb.properties");
}

QString QbProperties::getProperty(QString property)
{
    return properties.take(property);
}

void QbProperties::setProperty(QString property, QString value)
{
    properties.insert(property,value);
}

void QbProperties::store()
{
    QFile file(path);
    if(!file.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        QbLogger::getInstance()->fatal("Cannot open properties file");
        return;
    }
    QTextStream out(&file);
    out << "#############################################" << endl
        << "#                                           #" << endl
        << "#   Qubic properties file                   #" << endl
        << "#                                           #" << endl
        << "#   To comment line use # character         #" << endl
        << "#   Do not leave any spaces                 #" << endl
        << "#                                           #" << endl
        << "#############################################" << endl << endl;
    for(auto prop : properties.keys())
    {
        out << prop << "=" << properties.value(prop) << endl;
    }
    file.close();
}


