/****************************************************************************
** Meta object code from reading C++ file 'MainWindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../SNet-master/UI/MainWindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    const uint offsetsAndSize[130];
    char stringdata0[1539];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 26), // "signalConnectSdnController"
QT_MOC_LITERAL(38, 0), // ""
QT_MOC_LITERAL(39, 21), // "signalClearNetworkMap"
QT_MOC_LITERAL(61, 29), // "signalHandleMouseReleaseEvent"
QT_MOC_LITERAL(91, 27), // "signalHandleMousePressEvent"
QT_MOC_LITERAL(119, 26), // "signalHandleMouseMoveEvent"
QT_MOC_LITERAL(146, 28), // "signalHandleDoubleClickEvent"
QT_MOC_LITERAL(175, 31), // "signalHandleKeyDeletePressEvent"
QT_MOC_LITERAL(207, 23), // "signalChangeStateToEdit"
QT_MOC_LITERAL(231, 26), // "signalPrepareSdnController"
QT_MOC_LITERAL(258, 17), // "signalPrepareHost"
QT_MOC_LITERAL(276, 19), // "signalPrepareSwitch"
QT_MOC_LITERAL(296, 17), // "signalPrepareLink"
QT_MOC_LITERAL(314, 22), // "signalPrepareTextLabel"
QT_MOC_LITERAL(337, 15), // "signalShowPorts"
QT_MOC_LITERAL(353, 19), // "signalShowBandwidth"
QT_MOC_LITERAL(373, 15), // "signalShowDelay"
QT_MOC_LITERAL(389, 24), // "signalShowPacketLossRate"
QT_MOC_LITERAL(414, 25), // "signalCreateMininetScript"
QT_MOC_LITERAL(440, 24), // "signalCreateWeightMatrix"
QT_MOC_LITERAL(465, 10), // "loadRoutes"
QT_MOC_LITERAL(476, 9), // "showRoute"
QT_MOC_LITERAL(486, 9), // "hideRoute"
QT_MOC_LITERAL(496, 20), // "signalSaveNetworkMap"
QT_MOC_LITERAL(517, 20), // "signalLoadNetworkMap"
QT_MOC_LITERAL(538, 21), // "signalAlignVertically"
QT_MOC_LITERAL(560, 23), // "signalAlignHorizontally"
QT_MOC_LITERAL(584, 17), // "signalRemoveMarks"
QT_MOC_LITERAL(602, 19), // "signalVisualizePath"
QT_MOC_LITERAL(622, 10), // "QList<int>"
QT_MOC_LITERAL(633, 20), // "signalVisualizePaths"
QT_MOC_LITERAL(654, 17), // "QList<QList<int>>"
QT_MOC_LITERAL(672, 32), // "on_actionSdnController_triggered"
QT_MOC_LITERAL(705, 23), // "on_actionHost_triggered"
QT_MOC_LITERAL(729, 25), // "on_actionSwitch_triggered"
QT_MOC_LITERAL(755, 23), // "on_actionLink_triggered"
QT_MOC_LITERAL(779, 23), // "on_actionText_triggered"
QT_MOC_LITERAL(803, 23), // "on_actionEdit_triggered"
QT_MOC_LITERAL(827, 34), // "mouseLeftButtonReleaseEventOc..."
QT_MOC_LITERAL(862, 14), // "cursorPosition"
QT_MOC_LITERAL(877, 32), // "mouseLeftButtonPressEventOccured"
QT_MOC_LITERAL(910, 21), // "mouseMoveEventOccured"
QT_MOC_LITERAL(932, 21), // "mouseDoubleClickEvent"
QT_MOC_LITERAL(954, 28), // "on_actionShowPorts_triggered"
QT_MOC_LITERAL(983, 7), // "checked"
QT_MOC_LITERAL(991, 31), // "on_actionDisplayDelay_triggered"
QT_MOC_LITERAL(1023, 35), // "on_actionDisplayBandwidth_tri..."
QT_MOC_LITERAL(1059, 36), // "on_actionDisplayPacketLoss_tr..."
QT_MOC_LITERAL(1096, 22), // "on_actionNew_triggered"
QT_MOC_LITERAL(1119, 25), // "on_actionSaveAs_triggered"
QT_MOC_LITERAL(1145, 23), // "on_actionSave_triggered"
QT_MOC_LITERAL(1169, 23), // "on_actionOpen_triggered"
QT_MOC_LITERAL(1193, 35), // "on_actionCreateMnDataFile_tri..."
QT_MOC_LITERAL(1229, 39), // "on_actionMake_Full_Connection..."
QT_MOC_LITERAL(1269, 23), // "on_actionExit_triggered"
QT_MOC_LITERAL(1293, 33), // "on_actionWeights_Matrix_trigg..."
QT_MOC_LITERAL(1327, 37), // "on_actionAlign_Horizontally_t..."
QT_MOC_LITERAL(1365, 35), // "on_actionAlign_Vertically_tri..."
QT_MOC_LITERAL(1401, 31), // "on_actionRemove_Marks_triggered"
QT_MOC_LITERAL(1433, 38), // "on_actionCreate_optimal_path_..."
QT_MOC_LITERAL(1472, 24), // "on_actionNN_GA_triggered"
QT_MOC_LITERAL(1497, 21), // "refreshNetworkMapView"
QT_MOC_LITERAL(1519, 11), // "showMessage"
QT_MOC_LITERAL(1531, 7) // "message"

    },
    "MainWindow\0signalConnectSdnController\0"
    "\0signalClearNetworkMap\0"
    "signalHandleMouseReleaseEvent\0"
    "signalHandleMousePressEvent\0"
    "signalHandleMouseMoveEvent\0"
    "signalHandleDoubleClickEvent\0"
    "signalHandleKeyDeletePressEvent\0"
    "signalChangeStateToEdit\0"
    "signalPrepareSdnController\0signalPrepareHost\0"
    "signalPrepareSwitch\0signalPrepareLink\0"
    "signalPrepareTextLabel\0signalShowPorts\0"
    "signalShowBandwidth\0signalShowDelay\0"
    "signalShowPacketLossRate\0"
    "signalCreateMininetScript\0"
    "signalCreateWeightMatrix\0loadRoutes\0"
    "showRoute\0hideRoute\0signalSaveNetworkMap\0"
    "signalLoadNetworkMap\0signalAlignVertically\0"
    "signalAlignHorizontally\0signalRemoveMarks\0"
    "signalVisualizePath\0QList<int>\0"
    "signalVisualizePaths\0QList<QList<int>>\0"
    "on_actionSdnController_triggered\0"
    "on_actionHost_triggered\0"
    "on_actionSwitch_triggered\0"
    "on_actionLink_triggered\0on_actionText_triggered\0"
    "on_actionEdit_triggered\0"
    "mouseLeftButtonReleaseEventOccured\0"
    "cursorPosition\0mouseLeftButtonPressEventOccured\0"
    "mouseMoveEventOccured\0mouseDoubleClickEvent\0"
    "on_actionShowPorts_triggered\0checked\0"
    "on_actionDisplayDelay_triggered\0"
    "on_actionDisplayBandwidth_triggered\0"
    "on_actionDisplayPacketLoss_triggered\0"
    "on_actionNew_triggered\0on_actionSaveAs_triggered\0"
    "on_actionSave_triggered\0on_actionOpen_triggered\0"
    "on_actionCreateMnDataFile_triggered\0"
    "on_actionMake_Full_Connection_triggered\0"
    "on_actionExit_triggered\0"
    "on_actionWeights_Matrix_triggered\0"
    "on_actionAlign_Horizontally_triggered\0"
    "on_actionAlign_Vertically_triggered\0"
    "on_actionRemove_Marks_triggered\0"
    "on_actionCreate_optimal_path_triggered\0"
    "on_actionNN_GA_triggered\0refreshNetworkMapView\0"
    "showMessage\0message"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
      58,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      29,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  362,    2, 0x06,    0 /* Public */,
       3,    0,  363,    2, 0x06,    1 /* Public */,
       4,    1,  364,    2, 0x06,    2 /* Public */,
       5,    1,  367,    2, 0x06,    4 /* Public */,
       6,    1,  370,    2, 0x06,    6 /* Public */,
       7,    1,  373,    2, 0x06,    8 /* Public */,
       8,    0,  376,    2, 0x06,   10 /* Public */,
       9,    0,  377,    2, 0x06,   11 /* Public */,
      10,    0,  378,    2, 0x06,   12 /* Public */,
      11,    0,  379,    2, 0x06,   13 /* Public */,
      12,    0,  380,    2, 0x06,   14 /* Public */,
      13,    0,  381,    2, 0x06,   15 /* Public */,
      14,    0,  382,    2, 0x06,   16 /* Public */,
      15,    1,  383,    2, 0x06,   17 /* Public */,
      16,    0,  386,    2, 0x06,   19 /* Public */,
      17,    0,  387,    2, 0x06,   20 /* Public */,
      18,    0,  388,    2, 0x06,   21 /* Public */,
      19,    1,  389,    2, 0x06,   22 /* Public */,
      20,    1,  392,    2, 0x06,   24 /* Public */,
      21,    1,  395,    2, 0x06,   26 /* Public */,
      22,    1,  398,    2, 0x06,   28 /* Public */,
      23,    1,  401,    2, 0x06,   30 /* Public */,
      24,    1,  404,    2, 0x06,   32 /* Public */,
      25,    1,  407,    2, 0x06,   34 /* Public */,
      26,    0,  410,    2, 0x06,   36 /* Public */,
      27,    0,  411,    2, 0x06,   37 /* Public */,
      28,    0,  412,    2, 0x06,   38 /* Public */,
      29,    1,  413,    2, 0x06,   39 /* Public */,
      31,    1,  416,    2, 0x06,   41 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      33,    0,  419,    2, 0x08,   43 /* Private */,
      34,    0,  420,    2, 0x08,   44 /* Private */,
      35,    0,  421,    2, 0x08,   45 /* Private */,
      36,    0,  422,    2, 0x08,   46 /* Private */,
      37,    0,  423,    2, 0x08,   47 /* Private */,
      38,    0,  424,    2, 0x08,   48 /* Private */,
      39,    1,  425,    2, 0x08,   49 /* Private */,
      41,    1,  428,    2, 0x08,   51 /* Private */,
      42,    1,  431,    2, 0x08,   53 /* Private */,
      43,    1,  434,    2, 0x08,   55 /* Private */,
      44,    1,  437,    2, 0x08,   57 /* Private */,
      46,    0,  440,    2, 0x08,   59 /* Private */,
      47,    0,  441,    2, 0x08,   60 /* Private */,
      48,    0,  442,    2, 0x08,   61 /* Private */,
      49,    0,  443,    2, 0x08,   62 /* Private */,
      50,    0,  444,    2, 0x08,   63 /* Private */,
      51,    0,  445,    2, 0x08,   64 /* Private */,
      52,    0,  446,    2, 0x08,   65 /* Private */,
      53,    0,  447,    2, 0x08,   66 /* Private */,
      54,    0,  448,    2, 0x08,   67 /* Private */,
      55,    0,  449,    2, 0x08,   68 /* Private */,
      56,    0,  450,    2, 0x08,   69 /* Private */,
      57,    0,  451,    2, 0x08,   70 /* Private */,
      58,    0,  452,    2, 0x08,   71 /* Private */,
      59,    0,  453,    2, 0x08,   72 /* Private */,
      60,    0,  454,    2, 0x08,   73 /* Private */,
      61,    0,  455,    2, 0x08,   74 /* Private */,
      62,    1,  456,    2, 0x0a,   75 /* Public */,
      63,    1,  459,    2, 0x0a,   77 /* Public */,

 // signals: parameters
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
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 30,    2,
    QMetaType::Void, 0x80000000 | 32,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,   40,
    QMetaType::Void, QMetaType::QPoint,   40,
    QMetaType::Void, QMetaType::QPoint,   40,
    QMetaType::Void, QMetaType::QPoint,   40,
    QMetaType::Void, QMetaType::Bool,   45,
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
    QMetaType::Void, QMetaType::QPixmap,    2,
    QMetaType::Void, QMetaType::QString,   64,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signalConnectSdnController(); break;
        case 1: _t->signalClearNetworkMap(); break;
        case 2: _t->signalHandleMouseReleaseEvent((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 3: _t->signalHandleMousePressEvent((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 4: _t->signalHandleMouseMoveEvent((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 5: _t->signalHandleDoubleClickEvent((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 6: _t->signalHandleKeyDeletePressEvent(); break;
        case 7: _t->signalChangeStateToEdit(); break;
        case 8: _t->signalPrepareSdnController(); break;
        case 9: _t->signalPrepareHost(); break;
        case 10: _t->signalPrepareSwitch(); break;
        case 11: _t->signalPrepareLink(); break;
        case 12: _t->signalPrepareTextLabel(); break;
        case 13: _t->signalShowPorts((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->signalShowBandwidth(); break;
        case 15: _t->signalShowDelay(); break;
        case 16: _t->signalShowPacketLossRate(); break;
        case 17: _t->signalCreateMininetScript((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 18: _t->signalCreateWeightMatrix((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 19: _t->loadRoutes((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 20: _t->showRoute((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: _t->hideRoute((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->signalSaveNetworkMap((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 23: _t->signalLoadNetworkMap((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 24: _t->signalAlignVertically(); break;
        case 25: _t->signalAlignHorizontally(); break;
        case 26: _t->signalRemoveMarks(); break;
        case 27: _t->signalVisualizePath((*reinterpret_cast< QList<int>(*)>(_a[1]))); break;
        case 28: _t->signalVisualizePaths((*reinterpret_cast< QList<QList<int>>(*)>(_a[1]))); break;
        case 29: _t->on_actionSdnController_triggered(); break;
        case 30: _t->on_actionHost_triggered(); break;
        case 31: _t->on_actionSwitch_triggered(); break;
        case 32: _t->on_actionLink_triggered(); break;
        case 33: _t->on_actionText_triggered(); break;
        case 34: _t->on_actionEdit_triggered(); break;
        case 35: _t->mouseLeftButtonReleaseEventOccured((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 36: _t->mouseLeftButtonPressEventOccured((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 37: _t->mouseMoveEventOccured((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 38: _t->mouseDoubleClickEvent((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 39: _t->on_actionShowPorts_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 40: _t->on_actionDisplayDelay_triggered(); break;
        case 41: _t->on_actionDisplayBandwidth_triggered(); break;
        case 42: _t->on_actionDisplayPacketLoss_triggered(); break;
        case 43: _t->on_actionNew_triggered(); break;
        case 44: _t->on_actionSaveAs_triggered(); break;
        case 45: _t->on_actionSave_triggered(); break;
        case 46: _t->on_actionOpen_triggered(); break;
        case 47: _t->on_actionCreateMnDataFile_triggered(); break;
        case 48: _t->on_actionMake_Full_Connection_triggered(); break;
        case 49: _t->on_actionExit_triggered(); break;
        case 50: _t->on_actionWeights_Matrix_triggered(); break;
        case 51: _t->on_actionAlign_Horizontally_triggered(); break;
        case 52: _t->on_actionAlign_Vertically_triggered(); break;
        case 53: _t->on_actionRemove_Marks_triggered(); break;
        case 54: _t->on_actionCreate_optimal_path_triggered(); break;
        case 55: _t->on_actionNN_GA_triggered(); break;
        case 56: _t->refreshNetworkMapView((*reinterpret_cast< QPixmap(*)>(_a[1]))); break;
        case 57: _t->showMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 27:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<int> >(); break;
            }
            break;
        case 28:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<QList<int>> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalConnectSdnController)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalClearNetworkMap)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QPoint );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalHandleMouseReleaseEvent)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QPoint );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalHandleMousePressEvent)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QPoint );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalHandleMouseMoveEvent)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QPoint );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalHandleDoubleClickEvent)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalHandleKeyDeletePressEvent)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalChangeStateToEdit)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalPrepareSdnController)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalPrepareHost)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalPrepareSwitch)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalPrepareLink)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalPrepareTextLabel)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalShowPorts)) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalShowBandwidth)) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalShowDelay)) {
                *result = 15;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalShowPacketLossRate)) {
                *result = 16;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalCreateMininetScript)) {
                *result = 17;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalCreateWeightMatrix)) {
                *result = 18;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::loadRoutes)) {
                *result = 19;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::showRoute)) {
                *result = 20;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::hideRoute)) {
                *result = 21;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalSaveNetworkMap)) {
                *result = 22;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalLoadNetworkMap)) {
                *result = 23;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalAlignVertically)) {
                *result = 24;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalAlignHorizontally)) {
                *result = 25;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalRemoveMarks)) {
                *result = 26;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QList<int> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalVisualizePath)) {
                *result = 27;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QList<QList<int>> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalVisualizePaths)) {
                *result = 28;
                return;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QPoint, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QPoint, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QPoint, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QPoint, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QList<int>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QList<QList<int>>, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QPoint, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QPoint, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QPoint, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QPoint, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QPixmap, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>


>,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 58)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 58;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 58)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 58;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::signalConnectSdnController()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MainWindow::signalClearNetworkMap()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MainWindow::signalHandleMouseReleaseEvent(QPoint _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainWindow::signalHandleMousePressEvent(QPoint _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainWindow::signalHandleMouseMoveEvent(QPoint _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MainWindow::signalHandleDoubleClickEvent(QPoint _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MainWindow::signalHandleKeyDeletePressEvent()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void MainWindow::signalChangeStateToEdit()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void MainWindow::signalPrepareSdnController()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void MainWindow::signalPrepareHost()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void MainWindow::signalPrepareSwitch()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void MainWindow::signalPrepareLink()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}

// SIGNAL 12
void MainWindow::signalPrepareTextLabel()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}

// SIGNAL 13
void MainWindow::signalShowPorts(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void MainWindow::signalShowBandwidth()
{
    QMetaObject::activate(this, &staticMetaObject, 14, nullptr);
}

// SIGNAL 15
void MainWindow::signalShowDelay()
{
    QMetaObject::activate(this, &staticMetaObject, 15, nullptr);
}

// SIGNAL 16
void MainWindow::signalShowPacketLossRate()
{
    QMetaObject::activate(this, &staticMetaObject, 16, nullptr);
}

// SIGNAL 17
void MainWindow::signalCreateMininetScript(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 18
void MainWindow::signalCreateWeightMatrix(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}

// SIGNAL 19
void MainWindow::loadRoutes(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 19, _a);
}

// SIGNAL 20
void MainWindow::showRoute(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 20, _a);
}

// SIGNAL 21
void MainWindow::hideRoute(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 21, _a);
}

// SIGNAL 22
void MainWindow::signalSaveNetworkMap(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 22, _a);
}

// SIGNAL 23
void MainWindow::signalLoadNetworkMap(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 23, _a);
}

// SIGNAL 24
void MainWindow::signalAlignVertically()
{
    QMetaObject::activate(this, &staticMetaObject, 24, nullptr);
}

// SIGNAL 25
void MainWindow::signalAlignHorizontally()
{
    QMetaObject::activate(this, &staticMetaObject, 25, nullptr);
}

// SIGNAL 26
void MainWindow::signalRemoveMarks()
{
    QMetaObject::activate(this, &staticMetaObject, 26, nullptr);
}

// SIGNAL 27
void MainWindow::signalVisualizePath(QList<int> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 27, _a);
}

// SIGNAL 28
void MainWindow::signalVisualizePaths(QList<QList<int>> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 28, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
