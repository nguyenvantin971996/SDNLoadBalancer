/****************************************************************************
** Meta object code from reading C++ file 'CommandReceiver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SNet-master-NN/Network/CommandReceiver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CommandReceiver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CommandReceiver_t {
    QByteArrayData data[25];
    char stringdata0[320];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CommandReceiver_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CommandReceiver_t qt_meta_stringdata_CommandReceiver = {
    {
QT_MOC_LITERAL(0, 0, 15), // "CommandReceiver"
QT_MOC_LITERAL(1, 16, 18), // "signalPathReceived"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 10), // "QList<int>"
QT_MOC_LITERAL(4, 47, 4), // "path"
QT_MOC_LITERAL(5, 52, 21), // "signalIslandsReceived"
QT_MOC_LITERAL(6, 74, 18), // "QList<QList<int> >"
QT_MOC_LITERAL(7, 93, 7), // "islands"
QT_MOC_LITERAL(8, 101, 19), // "signalPathsReceived"
QT_MOC_LITERAL(9, 121, 5), // "paths"
QT_MOC_LITERAL(10, 127, 16), // "signalPTReceived"
QT_MOC_LITERAL(11, 144, 2), // "pt"
QT_MOC_LITERAL(12, 147, 20), // "signalMetricReceived"
QT_MOC_LITERAL(13, 168, 14), // "QVector<float>"
QT_MOC_LITERAL(14, 183, 10), // "metricData"
QT_MOC_LITERAL(15, 194, 21), // "signalMessageReceived"
QT_MOC_LITERAL(16, 216, 7), // "message"
QT_MOC_LITERAL(17, 224, 18), // "signalTreeReceived"
QT_MOC_LITERAL(18, 243, 4), // "tree"
QT_MOC_LITERAL(19, 248, 19), // "signalTreesReceived"
QT_MOC_LITERAL(20, 268, 26), // "QList<QList<QList<int> > >"
QT_MOC_LITERAL(21, 295, 5), // "trees"
QT_MOC_LITERAL(22, 301, 2), // "on"
QT_MOC_LITERAL(23, 304, 10), // "handleData"
QT_MOC_LITERAL(24, 315, 4) // "data"

    },
    "CommandReceiver\0signalPathReceived\0\0"
    "QList<int>\0path\0signalIslandsReceived\0"
    "QList<QList<int> >\0islands\0"
    "signalPathsReceived\0paths\0signalPTReceived\0"
    "pt\0signalMetricReceived\0QVector<float>\0"
    "metricData\0signalMessageReceived\0"
    "message\0signalTreeReceived\0tree\0"
    "signalTreesReceived\0QList<QList<QList<int> > >\0"
    "trees\0on\0handleData\0data"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CommandReceiver[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       5,    1,   67,    2, 0x06 /* Public */,
       8,    1,   70,    2, 0x06 /* Public */,
      10,    1,   73,    2, 0x06 /* Public */,
      12,    1,   76,    2, 0x06 /* Public */,
      15,    1,   79,    2, 0x06 /* Public */,
      17,    1,   82,    2, 0x06 /* Public */,
      19,    1,   85,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      22,    0,   88,    2, 0x0a /* Public */,
      23,    1,   89,    2, 0x0a /* Public */,

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
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalPathReceived((*reinterpret_cast< QList<int>(*)>(_a[1]))); break;
        case 1: _t->signalIslandsReceived((*reinterpret_cast< QList<QList<int> >(*)>(_a[1]))); break;
        case 2: _t->signalPathsReceived((*reinterpret_cast< QList<QList<int> >(*)>(_a[1]))); break;
        case 3: _t->signalPTReceived((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->signalMetricReceived((*reinterpret_cast< QVector<float>(*)>(_a[1]))); break;
        case 5: _t->signalMessageReceived((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->signalTreeReceived((*reinterpret_cast< QList<QList<int> >(*)>(_a[1]))); break;
        case 7: _t->signalTreesReceived((*reinterpret_cast< QList<QList<QList<int> > >(*)>(_a[1]))); break;
        case 8: _t->on(); break;
        case 9: _t->handleData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<int> >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QList<int> > >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QList<int> > >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<float> >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QList<int> > >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QList<QList<int> > > >(); break;
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

QT_INIT_METAOBJECT const QMetaObject CommandReceiver::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_CommandReceiver.data,
    qt_meta_data_CommandReceiver,
    qt_static_metacall,
    nullptr,
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
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CommandReceiver::signalIslandsReceived(QList<QList<int> > _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CommandReceiver::signalPathsReceived(QList<QList<int> > _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CommandReceiver::signalPTReceived(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CommandReceiver::signalMetricReceived(QVector<float> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void CommandReceiver::signalMessageReceived(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void CommandReceiver::signalTreeReceived(QList<QList<int>> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void CommandReceiver::signalTreesReceived(QList<QList<QList<int> > > _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
