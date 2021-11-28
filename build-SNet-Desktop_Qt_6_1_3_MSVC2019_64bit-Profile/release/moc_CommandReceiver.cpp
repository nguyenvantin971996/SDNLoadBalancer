/****************************************************************************
** Meta object code from reading C++ file 'CommandReceiver.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../SNet-master/Network/CommandReceiver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CommandReceiver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CommandReceiver_t {
    const uint offsetsAndSize[50];
    char stringdata0[315];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_CommandReceiver_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_CommandReceiver_t qt_meta_stringdata_CommandReceiver = {
    {
QT_MOC_LITERAL(0, 15), // "CommandReceiver"
QT_MOC_LITERAL(16, 18), // "signalPathReceived"
QT_MOC_LITERAL(35, 0), // ""
QT_MOC_LITERAL(36, 10), // "QList<int>"
QT_MOC_LITERAL(47, 4), // "path"
QT_MOC_LITERAL(52, 21), // "signalIslandsReceived"
QT_MOC_LITERAL(74, 17), // "QList<QList<int>>"
QT_MOC_LITERAL(92, 7), // "islands"
QT_MOC_LITERAL(100, 19), // "signalPathsReceived"
QT_MOC_LITERAL(120, 5), // "paths"
QT_MOC_LITERAL(126, 16), // "signalPTReceived"
QT_MOC_LITERAL(143, 2), // "pt"
QT_MOC_LITERAL(146, 20), // "signalMetricReceived"
QT_MOC_LITERAL(167, 12), // "QList<float>"
QT_MOC_LITERAL(180, 10), // "metricData"
QT_MOC_LITERAL(191, 21), // "signalMessageReceived"
QT_MOC_LITERAL(213, 7), // "message"
QT_MOC_LITERAL(221, 18), // "signalTreeReceived"
QT_MOC_LITERAL(240, 4), // "tree"
QT_MOC_LITERAL(245, 19), // "signalTreesReceived"
QT_MOC_LITERAL(265, 24), // "QList<QList<QList<int>>>"
QT_MOC_LITERAL(290, 5), // "trees"
QT_MOC_LITERAL(296, 2), // "on"
QT_MOC_LITERAL(299, 10), // "handleData"
QT_MOC_LITERAL(310, 4) // "data"

    },
    "CommandReceiver\0signalPathReceived\0\0"
    "QList<int>\0path\0signalIslandsReceived\0"
    "QList<QList<int>>\0islands\0signalPathsReceived\0"
    "paths\0signalPTReceived\0pt\0"
    "signalMetricReceived\0QList<float>\0"
    "metricData\0signalMessageReceived\0"
    "message\0signalTreeReceived\0tree\0"
    "signalTreesReceived\0QList<QList<QList<int>>>\0"
    "trees\0on\0handleData\0data"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CommandReceiver[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   74,    2, 0x06,    0 /* Public */,
       5,    1,   77,    2, 0x06,    2 /* Public */,
       8,    1,   80,    2, 0x06,    4 /* Public */,
      10,    1,   83,    2, 0x06,    6 /* Public */,
      12,    1,   86,    2, 0x06,    8 /* Public */,
      15,    1,   89,    2, 0x06,   10 /* Public */,
      17,    1,   92,    2, 0x06,   12 /* Public */,
      19,    1,   95,    2, 0x06,   14 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      22,    0,   98,    2, 0x0a,   16 /* Public */,
      23,    1,   99,    2, 0x0a,   17 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    9,
    QMetaType::Void, QMetaType::Double,   11,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void, 0x80000000 | 6,   18,
    QMetaType::Void, 0x80000000 | 20,   21,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,   24,

       0        // eod
};

void CommandReceiver::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CommandReceiver *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signalPathReceived((*reinterpret_cast< QList<int>(*)>(_a[1]))); break;
        case 1: _t->signalIslandsReceived((*reinterpret_cast< QList<QList<int>>(*)>(_a[1]))); break;
        case 2: _t->signalPathsReceived((*reinterpret_cast< QList<QList<int>>(*)>(_a[1]))); break;
        case 3: _t->signalPTReceived((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->signalMetricReceived((*reinterpret_cast< QList<float>(*)>(_a[1]))); break;
        case 5: _t->signalMessageReceived((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->signalTreeReceived((*reinterpret_cast< QList<QList<int>>(*)>(_a[1]))); break;
        case 7: _t->signalTreesReceived((*reinterpret_cast< QList<QList<QList<int>>>(*)>(_a[1]))); break;
        case 8: _t->on(); break;
        case 9: _t->handleData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<int> >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<QList<int>> >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<QList<int>> >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<float> >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<QList<int>> >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<QList<QList<int>>> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CommandReceiver::*)(QList<int> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CommandReceiver::signalPathReceived)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CommandReceiver::*)(QList<QList<int> > );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CommandReceiver::signalIslandsReceived)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CommandReceiver::*)(QList<QList<int> > );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CommandReceiver::signalPathsReceived)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (CommandReceiver::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CommandReceiver::signalPTReceived)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (CommandReceiver::*)(QVector<float> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CommandReceiver::signalMetricReceived)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (CommandReceiver::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CommandReceiver::signalMessageReceived)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (CommandReceiver::*)(QList<QList<int>> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CommandReceiver::signalTreeReceived)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (CommandReceiver::*)(QList<QList<QList<int> > > );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CommandReceiver::signalTreesReceived)) {
                *result = 7;
                return;
            }
        }
    }
}

const QMetaObject CommandReceiver::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CommandReceiver.offsetsAndSize,
    qt_meta_data_CommandReceiver,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_CommandReceiver_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QList<int>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QList<QList<int> >, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QList<QList<int> >, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QVector<float>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QList<QList<int>>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QList<QList<QList<int> > >, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>


>,
    nullptr
} };


const QMetaObject *CommandReceiver::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CommandReceiver::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CommandReceiver.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CommandReceiver::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void CommandReceiver::signalPathReceived(QList<int> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CommandReceiver::signalIslandsReceived(QList<QList<int> > _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CommandReceiver::signalPathsReceived(QList<QList<int> > _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CommandReceiver::signalPTReceived(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CommandReceiver::signalMetricReceived(QVector<float> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void CommandReceiver::signalMessageReceived(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void CommandReceiver::signalTreeReceived(QList<QList<int>> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void CommandReceiver::signalTreesReceived(QList<QList<QList<int> > > _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
