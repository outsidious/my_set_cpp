/****************************************************************************
** Meta object code from reading C++ file 'testSet.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../testSet.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'testSet.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Test_Set_Constructors_t {
    QByteArrayData data[7];
    char stringdata0[145];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Test_Set_Constructors_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Test_Set_Constructors_t qt_meta_stringdata_Test_Set_Constructors = {
    {
QT_MOC_LITERAL(0, 0, 21), // "Test_Set_Constructors"
QT_MOC_LITERAL(1, 22, 18), // "createEmptySetTest"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 31), // "createSetFromIitializerListTest"
QT_MOC_LITERAL(4, 74, 22), // "createSetFromArrayTest"
QT_MOC_LITERAL(5, 97, 20), // "createSetFromSetTest"
QT_MOC_LITERAL(6, 118, 26) // "createSetFromIteratorsTest"

    },
    "Test_Set_Constructors\0createEmptySetTest\0"
    "\0createSetFromIitializerListTest\0"
    "createSetFromArrayTest\0createSetFromSetTest\0"
    "createSetFromIteratorsTest"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Test_Set_Constructors[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    0,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Test_Set_Constructors::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Test_Set_Constructors *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->createEmptySetTest(); break;
        case 1: _t->createSetFromIitializerListTest(); break;
        case 2: _t->createSetFromArrayTest(); break;
        case 3: _t->createSetFromSetTest(); break;
        case 4: _t->createSetFromIteratorsTest(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Test_Set_Constructors::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Test_Set_Constructors.data,
    qt_meta_data_Test_Set_Constructors,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Test_Set_Constructors::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Test_Set_Constructors::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Test_Set_Constructors.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Test_Set_Constructors::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
struct qt_meta_stringdata_Test_Set_Methods_t {
    QByteArrayData data[22];
    char stringdata0[455];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Test_Set_Methods_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Test_Set_Methods_t qt_meta_stringdata_Test_Set_Methods = {
    {
QT_MOC_LITERAL(0, 0, 16), // "Test_Set_Methods"
QT_MOC_LITERAL(1, 17, 15), // "getSetBeginTest"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 13), // "getSetEndTest"
QT_MOC_LITERAL(4, 48, 18), // "hasSetElemTrueTest"
QT_MOC_LITERAL(5, 67, 19), // "hasSetElemFalseTest"
QT_MOC_LITERAL(6, 87, 19), // "addNewElemToSetTest"
QT_MOC_LITERAL(7, 107, 19), // "addOldElemToSetTest"
QT_MOC_LITERAL(8, 127, 19), // "unionSetWithSetTest"
QT_MOC_LITERAL(9, 147, 23), // "unionSetWithNewElemTest"
QT_MOC_LITERAL(10, 171, 23), // "unionSetWithOldElemTest"
QT_MOC_LITERAL(11, 195, 24), // "deleteOldElemFromSetTest"
QT_MOC_LITERAL(12, 220, 24), // "deleteNewElemFromSetTest"
QT_MOC_LITERAL(13, 245, 24), // "differenceSetWithSetTest"
QT_MOC_LITERAL(14, 270, 28), // "differenceSetWithNewElemTest"
QT_MOC_LITERAL(15, 299, 28), // "differenceSetWithOldElemTest"
QT_MOC_LITERAL(16, 328, 26), // "intersectionSetWithSetTest"
QT_MOC_LITERAL(17, 355, 27), // "symDifferenceSetWithSetTest"
QT_MOC_LITERAL(18, 383, 18), // "isSubsetOfTrueTest"
QT_MOC_LITERAL(19, 402, 19), // "isSubsetOfFalseTest"
QT_MOC_LITERAL(20, 422, 15), // "containTrueTest"
QT_MOC_LITERAL(21, 438, 16) // "containFalseTest"

    },
    "Test_Set_Methods\0getSetBeginTest\0\0"
    "getSetEndTest\0hasSetElemTrueTest\0"
    "hasSetElemFalseTest\0addNewElemToSetTest\0"
    "addOldElemToSetTest\0unionSetWithSetTest\0"
    "unionSetWithNewElemTest\0unionSetWithOldElemTest\0"
    "deleteOldElemFromSetTest\0"
    "deleteNewElemFromSetTest\0"
    "differenceSetWithSetTest\0"
    "differenceSetWithNewElemTest\0"
    "differenceSetWithOldElemTest\0"
    "intersectionSetWithSetTest\0"
    "symDifferenceSetWithSetTest\0"
    "isSubsetOfTrueTest\0isSubsetOfFalseTest\0"
    "containTrueTest\0containFalseTest"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Test_Set_Methods[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  114,    2, 0x08 /* Private */,
       3,    0,  115,    2, 0x08 /* Private */,
       4,    0,  116,    2, 0x08 /* Private */,
       5,    0,  117,    2, 0x08 /* Private */,
       6,    0,  118,    2, 0x08 /* Private */,
       7,    0,  119,    2, 0x08 /* Private */,
       8,    0,  120,    2, 0x08 /* Private */,
       9,    0,  121,    2, 0x08 /* Private */,
      10,    0,  122,    2, 0x08 /* Private */,
      11,    0,  123,    2, 0x08 /* Private */,
      12,    0,  124,    2, 0x08 /* Private */,
      13,    0,  125,    2, 0x08 /* Private */,
      14,    0,  126,    2, 0x08 /* Private */,
      15,    0,  127,    2, 0x08 /* Private */,
      16,    0,  128,    2, 0x08 /* Private */,
      17,    0,  129,    2, 0x08 /* Private */,
      18,    0,  130,    2, 0x08 /* Private */,
      19,    0,  131,    2, 0x08 /* Private */,
      20,    0,  132,    2, 0x08 /* Private */,
      21,    0,  133,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Test_Set_Methods::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Test_Set_Methods *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->getSetBeginTest(); break;
        case 1: _t->getSetEndTest(); break;
        case 2: _t->hasSetElemTrueTest(); break;
        case 3: _t->hasSetElemFalseTest(); break;
        case 4: _t->addNewElemToSetTest(); break;
        case 5: _t->addOldElemToSetTest(); break;
        case 6: _t->unionSetWithSetTest(); break;
        case 7: _t->unionSetWithNewElemTest(); break;
        case 8: _t->unionSetWithOldElemTest(); break;
        case 9: _t->deleteOldElemFromSetTest(); break;
        case 10: _t->deleteNewElemFromSetTest(); break;
        case 11: _t->differenceSetWithSetTest(); break;
        case 12: _t->differenceSetWithNewElemTest(); break;
        case 13: _t->differenceSetWithOldElemTest(); break;
        case 14: _t->intersectionSetWithSetTest(); break;
        case 15: _t->symDifferenceSetWithSetTest(); break;
        case 16: _t->isSubsetOfTrueTest(); break;
        case 17: _t->isSubsetOfFalseTest(); break;
        case 18: _t->containTrueTest(); break;
        case 19: _t->containFalseTest(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Test_Set_Methods::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Test_Set_Methods.data,
    qt_meta_data_Test_Set_Methods,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Test_Set_Methods::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Test_Set_Methods::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Test_Set_Methods.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Test_Set_Methods::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 20;
    }
    return _id;
}
struct qt_meta_stringdata_Test_Iterator_Constructors_t {
    QByteArrayData data[4];
    char stringdata0[78];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Test_Iterator_Constructors_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Test_Iterator_Constructors_t qt_meta_stringdata_Test_Iterator_Constructors = {
    {
QT_MOC_LITERAL(0, 0, 26), // "Test_Iterator_Constructors"
QT_MOC_LITERAL(1, 27, 23), // "createEmptyIteratorTest"
QT_MOC_LITERAL(2, 51, 0), // ""
QT_MOC_LITERAL(3, 52, 25) // "createIteratorFromSetTest"

    },
    "Test_Iterator_Constructors\0"
    "createEmptyIteratorTest\0\0"
    "createIteratorFromSetTest"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Test_Iterator_Constructors[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x08 /* Private */,
       3,    0,   25,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Test_Iterator_Constructors::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Test_Iterator_Constructors *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->createEmptyIteratorTest(); break;
        case 1: _t->createIteratorFromSetTest(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Test_Iterator_Constructors::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Test_Iterator_Constructors.data,
    qt_meta_data_Test_Iterator_Constructors,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Test_Iterator_Constructors::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Test_Iterator_Constructors::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Test_Iterator_Constructors.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Test_Iterator_Constructors::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
struct qt_meta_stringdata_Test_Iterator_Operators_t {
    QByteArrayData data[7];
    char stringdata0[132];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Test_Iterator_Operators_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Test_Iterator_Operators_t qt_meta_stringdata_Test_Iterator_Operators = {
    {
QT_MOC_LITERAL(0, 0, 23), // "Test_Iterator_Operators"
QT_MOC_LITERAL(1, 24, 12), // "getValueTest"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 23), // "setIteratorEqualSetTest"
QT_MOC_LITERAL(4, 62, 28), // "setIteratorEqualIteratorTest"
QT_MOC_LITERAL(5, 91, 19), // "IteratorPlusNumTest"
QT_MOC_LITERAL(6, 111, 20) // "IteratorMinusNumTest"

    },
    "Test_Iterator_Operators\0getValueTest\0"
    "\0setIteratorEqualSetTest\0"
    "setIteratorEqualIteratorTest\0"
    "IteratorPlusNumTest\0IteratorMinusNumTest"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Test_Iterator_Operators[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    0,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Test_Iterator_Operators::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Test_Iterator_Operators *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->getValueTest(); break;
        case 1: _t->setIteratorEqualSetTest(); break;
        case 2: _t->setIteratorEqualIteratorTest(); break;
        case 3: _t->IteratorPlusNumTest(); break;
        case 4: _t->IteratorMinusNumTest(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Test_Iterator_Operators::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Test_Iterator_Operators.data,
    qt_meta_data_Test_Iterator_Operators,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Test_Iterator_Operators::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Test_Iterator_Operators::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Test_Iterator_Operators.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Test_Iterator_Operators::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
