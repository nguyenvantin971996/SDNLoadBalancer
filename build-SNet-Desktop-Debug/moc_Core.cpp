/****************************************************************************
** Meta object code from reading C++ file 'Core.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SNet-master-NN/Core/Core.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Core.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Core_t {
    QByteArrayData data[44];
    char stringdata0[663];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Core_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Core_t qt_meta_stringdata_Core = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Core"
QT_MOC_LITERAL(1, 5, 27), // "signalRefreshNetworkMapView"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 20), // "connectSdnController"
QT_MOC_LITERAL(4, 55, 15), // "clearNetworkMap"
QT_MOC_LITERAL(5, 71, 23), // "handleMouseReleaseEvent"
QT_MOC_LITERAL(6, 95, 21), // "handleMousePressEvent"
QT_MOC_LITERAL(7, 117, 20), // "handleMouseMoveEvent"
QT_MOC_LITERAL(8, 138, 22), // "handleDoubleClickEvent"
QT_MOC_LITERAL(9, 161, 25), // "handleKeyDeletePressEvent"
QT_MOC_LITERAL(10, 187, 17), // "changeStateToEdit"
QT_MOC_LITERAL(11, 205, 20), // "prepareSdnController"
QT_MOC_LITERAL(12, 226, 11), // "prepareHost"
QT_MOC_LITERAL(13, 238, 13), // "prepareSwitch"
QT_MOC_LITERAL(14, 252, 11), // "prepareLink"
QT_MOC_LITERAL(15, 264, 16), // "prepareTextLabel"
QT_MOC_LITERAL(16, 281, 9), // "showPorts"
QT_MOC_LITERAL(17, 291, 13), // "showBandwidth"
QT_MOC_LITERAL(18, 305, 9), // "showDelay"
QT_MOC_LITERAL(19, 315, 18), // "showPacketLossRate"
QT_MOC_LITERAL(20, 334, 19), // "createMininetScript"
QT_MOC_LITERAL(21, 354, 19), // "createWeightsMatrix"
QT_MOC_LITERAL(22, 374, 4), // "path"
QT_MOC_LITERAL(23, 379, 12), // "RandomMetric"
QT_MOC_LITERAL(24, 392, 14), // "saveNetworkMap"
QT_MOC_LITERAL(25, 407, 14), // "loadNetworkMap"
QT_MOC_LITERAL(26, 422, 13), // "visualizePath"
QT_MOC_LITERAL(27, 436, 10), // "QList<int>"
QT_MOC_LITERAL(28, 447, 14), // "visualizePaths"
QT_MOC_LITERAL(29, 462, 18), // "QList<QList<int> >"
QT_MOC_LITERAL(30, 481, 5), // "paths"
QT_MOC_LITERAL(31, 487, 16), // "visualizeIslands"
QT_MOC_LITERAL(32, 504, 7), // "islands"
QT_MOC_LITERAL(33, 512, 13), // "visualizeTree"
QT_MOC_LITERAL(34, 526, 4), // "tree"
QT_MOC_LITERAL(35, 531, 14), // "visualizeTrees"
QT_MOC_LITERAL(36, 546, 26), // "QList<QList<QList<int> > >"
QT_MOC_LITERAL(37, 573, 5), // "trees"
QT_MOC_LITERAL(38, 579, 10), // "eraseMarks"
QT_MOC_LITERAL(39, 590, 12), // "changeMetric"
QT_MOC_LITERAL(40, 603, 14), // "QVector<float>"
QT_MOC_LITERAL(41, 618, 10), // "metricData"
QT_MOC_LITERAL(42, 629, 15), // "AlignVertically"
QT_MOC_LITERAL(43, 645, 17) // "AlignHorizontally"

    },
    "Core\0signalRefreshNetworkMapView\0\0"
    "connectSdnController\0clearNetworkMap\0"
    "handleMouseReleaseEvent\0handleMousePressEvent\0"
    "handleMouseMoveEvent\0handleDoubleClickEvent\0"
    "handleKeyDeletePressEvent\0changeStateToEdit\0"
    "prepareSdnController\0prepareHost\0"
    "prepareSwitch\0prepareLink\0prepareTextLabel\0"
    "showPorts\0showBandwidth\0showDelay\0"
    "showPacketLossRate\0createMininetScript\0"
    "createWeightsMatrix\0path\0RandomMetric\0"
    "saveNetworkMap\0loadNetworkMap\0"
    "visualizePath\0QList<int>\0visualizePaths\0"
    "QList<QList<int> >\0paths\0visualizeIslands\0"
    "islands\0visualizeTree\0tree\0visualizeTrees\0"
    "QList<QList<QList<int> > >\0trees\0"
    "eraseMarks\0changeMetric\0QVector<float>\0"
    "metricData\0AlignVertically\0AlignHorizontally"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Core[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      32,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  174,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,  177,    2, 0x0a /* Public */,
       4,    0,  178,    2, 0x0a /* Public */,
       5,    1,  179,    2, 0x0a /* Public */,
       6,    1,  182,    2, 0x0a /* Public */,
       7,    1,  185,    2, 0x0a /* Public */,
       8,    1,  188,    2, 0x0a /* Public */,
       9,    0,  191,    2, 0x0a /* Public */,
      10,    0,  192,    2, 0x0a /* Public */,
      11,    0,  193,    2, 0x0a /* Public */,
      12,    0,  194,    2, 0x0a /* Public */,
      13,    0,  195,    2, 0x0a /* Public */,
      14,    0,  196,    2, 0x0a /* Public */,
      15,    0,  197,    2, 0x0a /* Public */,
      16,    1,  198,    2, 0x0a /* Public */,
      17,    0,  201,    2, 0x0a /* Public */,
      18,    0,  202,    2, 0x0a /* Public */,
      19,    0,  203,    2, 0x0a /* Public */,
      20,    1,  204,    2, 0x0a /* Public */,
      21,    1,  207,    2, 0x0a /* Public */,
      23,    0,  210,    2, 0x0a /* Public */,
      24,    1,  211,    2, 0x0a /* Public */,
      25,    1,  214,    2, 0x0a /* Public */,
      26,    1,  217,    2, 0x0a /* Public */,
      28,    1,  220,    2, 0x0a /* Public */,
      31,    1,  223,    2, 0x0a /* Public */,
      33,    1,  226,    2, 0x0a /* Public */,
      35,    1,  229,    2, 0x0a /* Public */,
      38,    0,  232,    2, 0x0a /* Public */,
      39,    1,  233,    2, 0x0a /* Public */,
      42,    0,  236,    2, 0x0a /* Public */,
      43,    0,  237,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QPixmap,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,   22,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 27,   22,
    QMetaType::Void, 0x80000000 | 29,   30,
    QMetaType::Void, 0x80000000 | 29,   32,
    QMetaType::Void, 0x80000000 | 29,   34,
    QMetaType::Void, 0x80000000 | 36,   37,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 40,   41,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Core::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Core *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalRefreshNetworkMapView((*reinterpret_cast< QPixmap(*)>(_a[1]))); break;
        case 1: _t->connectSdnController(); break;
        case 2: _t->clearNetworkMap(); break;
        case 3: _t->handleMouseReleaseEvent((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 4: _t->handleMousePressEvent((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 5: _t->handleMouseMoveEvent((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 6: _t->handleDoubleClickEvent((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 7: _t->handleKeyDeletePressEvent(); break;
        case 8: _t->changeStateToEdit(); break;
        case 9: _t->prepareSdnController(); break;
        case 10: _t->prepareHost(); break;
        case 11: _t->prepareSwitch(); break;
        case 12: _t->prepareLink(); break;
        case 13: _t->prepareTextLabel(); break;
        case 14: _t->showPorts((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: _t->showBandwidth(); break;
        case 16: _t->showDelay(); break;
        case 17: _t->showPacketLossRate(); break;
        case 18: _t->createMininetScript((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 19: _t->createWeightsMatrix((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 20: _t->RandomMetric(); break;
        case 21: _t->saveNetworkMap((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 22: _t->loadNetworkMap((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 23: _t->visualizePath((*reinterpret_cast< QList<int>(*)>(_a[1]))); break;
        case 24: _t->visualizePaths((*reinterpret_cast< QList<QList<int> >(*)>(_a[1]))); break;
        case 25: _t->visualizeIslands((*reinterpret_cast< QList<QList<int> >(*)>(_a[1]))); break;
        case 26: _t->visualizeTree((*reinterpret_cast< QList<QList<int> >(*)>(_a[1]))); break;
        case 27: _t->visualizeTrees((*reinterpret_cast< QList<QList<QList<int> > >(*)>(_a[1]))); break;
        case 28: _t->eraseMarks(); break;
        case 29: _t->changeMetric((*reinterpret_cast< QVector<float>(*)>(_a[1]))); break;
        case 30: _t->AlignVertically(); break;
        case 31: _t->AlignHorizontally(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 23:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<int> >(); break;
            }
            break;
        case 24:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QList<int> > >(); break;
            }
            break;
        case 25:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QList<int> > >(); break;
            }
            break;
        case 26:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QList<int> > >(); break;
            }
            break;
        case 27:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QList<QList<int> > > >(); break;
            }
            break;
        case 29:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<float> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Core::*)(QPixmap );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Core::signalRefreshNetworkMapView)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Core::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_Core.data,
    qt_meta_data_Core,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Core::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Core::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Core.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Core::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 32)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 32;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 32)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 32;
    }
    return _id;
}

// SIGNAL 0
void Core::signalRefreshNetworkMapView(QPixmap _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
