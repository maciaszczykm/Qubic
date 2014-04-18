QT += core
QT += sql
QT -= gui

TARGET = Qubic

CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11

TEMPLATE = app

OTHER_FILES += qb.properties

include(QsLog\QsLog.pri)
include(QbCore\QbCore.pri)
include(QbTest\QbTest.pri)
include(QbUtilities\QbUtilities.pri)
