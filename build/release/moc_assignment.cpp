/****************************************************************************
** Meta object code from reading C++ file 'assignment.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../source/QbTest/assignment.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'assignment.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Assignment_t {
    QByteArrayData data[13];
    char stringdata[149];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Assignment_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Assignment_t qt_meta_stringdata_Assignment = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 16),
QT_MOC_LITERAL(2, 28, 11),
QT_MOC_LITERAL(3, 40, 0),
QT_MOC_LITERAL(4, 41, 16),
QT_MOC_LITERAL(5, 58, 13),
QT_MOC_LITERAL(6, 72, 14),
QT_MOC_LITERAL(7, 87, 9),
QT_MOC_LITERAL(8, 97, 14),
QT_MOC_LITERAL(9, 112, 11),
QT_MOC_LITERAL(10, 124, 14),
QT_MOC_LITERAL(11, 139, 5),
QT_MOC_LITERAL(12, 145, 2)
    },
    "Assignment\0getDepartmentPtr\0Department*\0"
    "\0setDepartmentPtr\0departmentPtr\0"
    "getEmployeePtr\0Employee*\0setEmployeePtr\0"
    "employeePtr\0QbPersistable*\0other\0id\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Assignment[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       4,   74, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    0,   44,    3, 0x02,
       4,    1,   45,    3, 0x02,
       6,    0,   48,    3, 0x02,
       8,    1,   49,    3, 0x02,
       4,    1,   52,    3, 0x00,
       8,    1,   55,    3, 0x00,

 // methods: parameters
    0x80000000 | 2,
    0x80000000 | 2, 0x80000000 | 2,    5,
    0x80000000 | 7,
    0x80000000 | 7, 0x80000000 | 7,    9,
    QMetaType::Void, 0x80000000 | 10,    5,
    QMetaType::Void, 0x80000000 | 10,    9,

 // constructors: parameters
    0x80000000 | 3,
    0x80000000 | 3, 0x80000000 | 0,   11,
    0x80000000 | 3, 0x80000000 | 2, 0x80000000 | 7,    5,    9,
    0x80000000 | 3, QMetaType::Int, 0x80000000 | 2, 0x80000000 | 7,   12,    5,    9,

 // constructors: name, argc, parameters, tag, flags
       0,    0,   58,    3, 0x0e,
       0,    1,   59,    3, 0x0e,
       0,    2,   62,    3, 0x0e,
       0,    3,   67,    3, 0x0e,

       0        // eod
};

void Assignment::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::CreateInstance) {
        switch (_id) {
        case 0: { Assignment *_r = new Assignment();
            if (_a[0]) *reinterpret_cast<QObject**>(_a[0]) = _r; } break;
        case 1: { Assignment *_r = new Assignment((*reinterpret_cast< const Assignment(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast<QObject**>(_a[0]) = _r; } break;
        case 2: { Assignment *_r = new Assignment((*reinterpret_cast< Department*(*)>(_a[1])),(*reinterpret_cast< Employee*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast<QObject**>(_a[0]) = _r; } break;
        case 3: { Assignment *_r = new Assignment((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Department*(*)>(_a[2])),(*reinterpret_cast< Employee*(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast<QObject**>(_a[0]) = _r; } break;
        }
    } else if (_c == QMetaObject::InvokeMetaMethod) {
        Assignment *_t = static_cast<Assignment *>(_o);
        switch (_id) {
        case 0: { Department* _r = _t->getDepartmentPtr();
            if (_a[0]) *reinterpret_cast< Department**>(_a[0]) = _r; }  break;
        case 1: { Department* _r = _t->setDepartmentPtr((*reinterpret_cast< Department*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< Department**>(_a[0]) = _r; }  break;
        case 2: { Employee* _r = _t->getEmployeePtr();
            if (_a[0]) *reinterpret_cast< Employee**>(_a[0]) = _r; }  break;
        case 3: { Employee* _r = _t->setEmployeePtr((*reinterpret_cast< Employee*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< Employee**>(_a[0]) = _r; }  break;
        case 4: _t->setDepartmentPtr((*reinterpret_cast< QbPersistable*(*)>(_a[1]))); break;
        case 5: _t->setEmployeePtr((*reinterpret_cast< QbPersistable*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Department* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Employee* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QbPersistable* >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QbPersistable* >(); break;
            }
            break;
        }
    }
}

const QMetaObject Assignment::staticMetaObject = {
    { &QbPersistable::staticMetaObject, qt_meta_stringdata_Assignment.data,
      qt_meta_data_Assignment,  qt_static_metacall, 0, 0}
};


const QMetaObject *Assignment::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Assignment::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Assignment.stringdata))
        return static_cast<void*>(const_cast< Assignment*>(this));
    return QbPersistable::qt_metacast(_clname);
}

int Assignment::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QbPersistable::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
