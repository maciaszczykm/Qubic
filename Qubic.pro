QT += core
QT += sql
QT -= gui

TARGET = Qubic

CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11

TEMPLATE = app

SOURCES += main.cpp \
    qbproperties.cpp \
    qbdatabase.cpp \
    qbpersistable.cpp \
    employee.cpp \
    qblogger.cpp \
    qbmappinghelper.cpp

HEADERS += \
    qbproperties.h \
    qbdatabase.h \
    qbpersistable.h \
    employee.h \
    qblogger.h \
    qbmappinghelper.h

OTHER_FILES += \
    qb.properties

include(QsLog\QsLog.pri)
