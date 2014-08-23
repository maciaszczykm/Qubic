QT += core
QT += sql
QT -= gui

TARGET = Qubic

CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11

TEMPLATE = app

OTHER_FILES += qb.properties

include(Qubic\Qubic.pri)
include(Test\Test.pri)
