/****************************************************************************
** Meta object code from reading C++ file 'employee.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../employee.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'employee.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Employee_t {
    QByteArrayData data[27];
    char stringdata[254];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Employee_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Employee_t qt_meta_stringdata_Employee = {
    {
QT_MOC_LITERAL(0, 0, 8),
QT_MOC_LITERAL(1, 9, 5),
QT_MOC_LITERAL(2, 15, 0),
QT_MOC_LITERAL(3, 16, 11),
QT_MOC_LITERAL(4, 28, 12),
QT_MOC_LITERAL(5, 41, 11),
QT_MOC_LITERAL(6, 53, 9),
QT_MOC_LITERAL(7, 63, 11),
QT_MOC_LITERAL(8, 75, 9),
QT_MOC_LITERAL(9, 85, 11),
QT_MOC_LITERAL(10, 97, 11),
QT_MOC_LITERAL(11, 109, 8),
QT_MOC_LITERAL(12, 118, 12),
QT_MOC_LITERAL(13, 131, 9),
QT_MOC_LITERAL(14, 141, 11),
QT_MOC_LITERAL(15, 153, 8),
QT_MOC_LITERAL(16, 162, 9),
QT_MOC_LITERAL(17, 172, 6),
QT_MOC_LITERAL(18, 179, 11),
QT_MOC_LITERAL(19, 191, 8),
QT_MOC_LITERAL(20, 200, 9),
QT_MOC_LITERAL(21, 210, 6),
QT_MOC_LITERAL(22, 217, 11),
QT_MOC_LITERAL(23, 229, 8),
QT_MOC_LITERAL(24, 238, 5),
QT_MOC_LITERAL(25, 244, 2),
QT_MOC_LITERAL(26, 247, 5)
    },
    "Employee\0getID\0\0getBirthday\0getFirstname\0"
    "getLastname\0getGender\0getHiredate\0"
    "getSalary\0getChildren\0setBirthday\0"
    "birthday\0setFirstname\0firstname\0"
    "setLastname\0lastname\0setGender\0gender\0"
    "setHiredate\0hiredate\0setSalary\0salary\0"
    "setChildren\0children\0setID\0id\0other\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Employee[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       4,  162, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x02,
       3,    0,   95,    2, 0x02,
       4,    0,   96,    2, 0x02,
       5,    0,   97,    2, 0x02,
       6,    0,   98,    2, 0x02,
       7,    0,   99,    2, 0x02,
       8,    0,  100,    2, 0x02,
       9,    0,  101,    2, 0x02,
      10,    1,  102,    2, 0x02,
      12,    1,  105,    2, 0x02,
      14,    1,  108,    2, 0x02,
      16,    1,  111,    2, 0x02,
      18,    1,  114,    2, 0x02,
      20,    1,  117,    2, 0x02,
      22,    1,  120,    2, 0x02,
      24,    1,  123,    2, 0x00,

 // methods: parameters
    QMetaType::QString,
    QMetaType::QDate,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QDateTime,
    QMetaType::Double,
    QMetaType::Int,
    QMetaType::Void, QMetaType::QDate,   11,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void, QMetaType::QDateTime,   19,
    QMetaType::Void, QMetaType::Double,   21,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::QString,   25,

 // constructors: parameters
    0x80000000 | 2,
    0x80000000 | 2, 0x80000000 | 0,   26,
    0x80000000 | 2, QMetaType::QDate, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QDateTime, QMetaType::Double, QMetaType::Int,   11,   13,   15,   17,   19,   21,   23,
    0x80000000 | 2, QMetaType::QString, QMetaType::QDate, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QDateTime, QMetaType::Double, QMetaType::Int,   25,   11,   13,   15,   17,   19,   21,   23,

 // constructors: name, argc, parameters, tag, flags
       0,    0,  126,    2, 0x0e,
       0,    1,  127,    2, 0x0e,
       0,    7,  130,    2, 0x0e,
       0,    8,  145,    2, 0x0e,

       0        // eod
};

void Employee::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::CreateInstance) {
        switch (_id) {
        case 0: { Employee *_r = new Employee();
            if (_a[0]) *reinterpret_cast<QObject**>(_a[0]) = _r; } break;
        case 1: { Employee *_r = new Employee((*reinterpret_cast< const Employee(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast<QObject**>(_a[0]) = _r; } break;
        case 2: { Employee *_r = new Employee((*reinterpret_cast< QDate(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QDateTime(*)>(_a[5])),(*reinterpret_cast< double(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])));
            if (_a[0]) *reinterpret_cast<QObject**>(_a[0]) = _r; } break;
        case 3: { Employee *_r = new Employee((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QDate(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QDateTime(*)>(_a[6])),(*reinterpret_cast< double(*)>(_a[7])),(*reinterpret_cast< int(*)>(_a[8])));
            if (_a[0]) *reinterpret_cast<QObject**>(_a[0]) = _r; } break;
        }
    } else if (_c == QMetaObject::InvokeMetaMethod) {
        Employee *_t = static_cast<Employee *>(_o);
        switch (_id) {
        case 0: { QString _r = _t->getID();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 1: { QDate _r = _t->getBirthday();
            if (_a[0]) *reinterpret_cast< QDate*>(_a[0]) = _r; }  break;
        case 2: { QString _r = _t->getFirstname();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 3: { QString _r = _t->getLastname();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 4: { QString _r = _t->getGender();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 5: { QDateTime _r = _t->getHiredate();
            if (_a[0]) *reinterpret_cast< QDateTime*>(_a[0]) = _r; }  break;
        case 6: { double _r = _t->getSalary();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 7: { int _r = _t->getChildren();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 8: _t->setBirthday((*reinterpret_cast< QDate(*)>(_a[1]))); break;
        case 9: _t->setFirstname((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->setLastname((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->setGender((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->setHiredate((*reinterpret_cast< QDateTime(*)>(_a[1]))); break;
        case 13: _t->setSalary((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 14: _t->setChildren((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->setID((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject Employee::staticMetaObject = {
    { &QbPersistable::staticMetaObject, qt_meta_stringdata_Employee.data,
      qt_meta_data_Employee,  qt_static_metacall, 0, 0}
};


const QMetaObject *Employee::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Employee::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Employee.stringdata))
        return static_cast<void*>(const_cast< Employee*>(this));
    return QbPersistable::qt_metacast(_clname);
}

int Employee::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QbPersistable::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
