/****************************************************************************
** Meta object code from reading C++ file 'company.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../company.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'company.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Company_t {
    QByteArrayData data[9];
    char stringdata[73];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Company_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Company_t qt_meta_stringdata_Company = {
    {
QT_MOC_LITERAL(0, 0, 7),
QT_MOC_LITERAL(1, 8, 5),
QT_MOC_LITERAL(2, 14, 0),
QT_MOC_LITERAL(3, 15, 14),
QT_MOC_LITERAL(4, 30, 14),
QT_MOC_LITERAL(5, 45, 11),
QT_MOC_LITERAL(6, 57, 5),
QT_MOC_LITERAL(7, 63, 2),
QT_MOC_LITERAL(8, 66, 5)
    },
    "Company\0getID\0\0getCompanyname\0"
    "setCompanyname\0companyname\0setID\0id\0"
    "other\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Company[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       4,   54, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x02,
       3,    0,   35,    2, 0x02,
       4,    1,   36,    2, 0x02,
       6,    1,   39,    2, 0x00,

 // methods: parameters
    QMetaType::Int,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::Int,    7,

 // constructors: parameters
    0x80000000 | 2,
    0x80000000 | 2, 0x80000000 | 0,    8,
    0x80000000 | 2, QMetaType::QString,    5,
    0x80000000 | 2, QMetaType::Int, QMetaType::QString,    7,    5,

 // constructors: name, argc, parameters, tag, flags
       0,    0,   42,    2, 0x0e,
       0,    1,   43,    2, 0x0e,
       0,    1,   46,    2, 0x0e,
       0,    2,   49,    2, 0x0e,

       0        // eod
};

void Company::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::CreateInstance) {
        switch (_id) {
        case 0: { Company *_r = new Company();
            if (_a[0]) *reinterpret_cast<QObject**>(_a[0]) = _r; } break;
        case 1: { Company *_r = new Company((*reinterpret_cast< const Company(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast<QObject**>(_a[0]) = _r; } break;
        case 2: { Company *_r = new Company((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast<QObject**>(_a[0]) = _r; } break;
        case 3: { Company *_r = new Company((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast<QObject**>(_a[0]) = _r; } break;
        }
    } else if (_c == QMetaObject::InvokeMetaMethod) {
        Company *_t = static_cast<Company *>(_o);
        switch (_id) {
        case 0: { int _r = _t->getID();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 1: { QString _r = _t->getCompanyname();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 2: _t->setCompanyname((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->setID((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject Company::staticMetaObject = {
    { &QbPersistable::staticMetaObject, qt_meta_stringdata_Company.data,
      qt_meta_data_Company,  qt_static_metacall, 0, 0}
};


const QMetaObject *Company::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Company::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Company.stringdata))
        return static_cast<void*>(const_cast< Company*>(this));
    return QbPersistable::qt_metacast(_clname);
}

int Company::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QbPersistable::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
