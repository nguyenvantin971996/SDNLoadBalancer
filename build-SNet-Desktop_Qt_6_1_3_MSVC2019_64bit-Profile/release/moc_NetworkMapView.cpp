/****************************************************************************
** Meta object code from reading C++ file 'NetworkMapView.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../SNet-master/UI/NetworkMapView.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'NetworkMapView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_NetworkMapView_t {
    const uint offsetsAndSize[14];
    char stringdata0[132];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_NetworkMapView_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_NetworkMapView_t qt_meta_stringdata_NetworkMapView = {
    {
QT_MOC_LITERAL(0, 14), // "NetworkMapView"
QT_MOC_LITERAL(15, 29), // "signalMouseLeftButtonReleased"
QT_MOC_LITERAL(45, 0), // ""
QT_MOC_LITERAL(46, 14), // "cursorPosition"
QT_MOC_LITERAL(61, 28), // "signalMouseLeftButtonPressed"
QT_MOC_LITERAL(90, 16), // "signalMouseMoved"
QT_MOC_LITERAL(107, 24) // "signalMouseDoubleClicked"

    },
    "NetworkMapView\0signalMouseLeftButtonReleased\0"
    "\0cursorPosition\0signalMouseLeftButtonPressed\0"
    "signalMouseMoved\0signalMouseDoubleClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NetworkMapView[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   38,    2, 0x06,    0 /* Public */,
       4,    1,   41,    2, 0x06,    2 /* Public */,
       5,    1,   44,    2, 0x06,    4 /* Public */,
       6,    1,   47,    2, 0x06,    6 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QPoint,    3,
    QMetaType::Void, QMetaType::QPoint,    3,
    QMetaType::Void, QMetaType::QPoint,    3,
    QMetaType::Void, QMetaType::QPoint,    3,

       0        // eod
};

void NetworkMapView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<NetworkMapView *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signalMouseLeftButtonReleased((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 1: _t->signalMouseLeftButtonPressed((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 2: _t->signalMouseMoved((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 3: _t->signalMouseDoubleClicked((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (NetworkMapView::*)(QPoint );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetworkMapView::signalMouseLeftButtonReleased)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (NetworkMapView::*)(QPoint );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetworkMapView::signalMouseLeftButtonPressed)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (NetworkMapView::*)(QPoint );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetworkMapView::signalMouseMoved)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (NetworkMapView::*)(QPoint );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetworkMapView::signalMouseDoubleClicked)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject NetworkMapView::staticMetaObject = { {
    QMetaObject::SuperData::link<QLabel::staticMetaObject>(),
    qt_meta_stringdata_NetworkMapView.offsetsAndSize,
    qt_meta_data_NetworkMapView,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_NetworkMapView_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QPoint, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QPoint, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QPoint, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QPoint, std::false_type>



>,
    nullptr
} };


const QMetaObject *NetworkMapView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NetworkMapView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_NetworkMapView.stringdata0))
        return static_cast<void*>(this);
    return QLabel::qt_metacast(_clname);
}

int NetworkMapView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void NetworkMapView::signalMouseLeftButtonReleased(QPoint _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void NetworkMapView::signalMouseLeftButtonPressed(QPoint _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void NetworkMapView::signalMouseMoved(QPoint _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void NetworkMapView::signalMouseDoubleClicked(QPoint _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
