/****************************************************************************
** Meta object code from reading C++ file 'MainWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SNet-master-NN/UI/MainWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[71];
    char stringdata0[1716];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 26), // "signalConnectSdnController"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 21), // "signalClearNetworkMap"
QT_MOC_LITERAL(4, 61, 29), // "signalHandleMouseReleaseEvent"
QT_MOC_LITERAL(5, 91, 27), // "signalHandleMousePressEvent"
QT_MOC_LITERAL(6, 119, 26), // "signalHandleMouseMoveEvent"
QT_MOC_LITERAL(7, 146, 28), // "signalHandleDoubleClickEvent"
QT_MOC_LITERAL(8, 175, 31), // "signalHandleKeyDeletePressEvent"
QT_MOC_LITERAL(9, 207, 23), // "signalChangeStateToEdit"
QT_MOC_LITERAL(10, 231, 26), // "signalPrepareSdnController"
QT_MOC_LITERAL(11, 258, 17), // "signalPrepareHost"
QT_MOC_LITERAL(12, 276, 19), // "signalPrepareSwitch"
QT_MOC_LITERAL(13, 296, 17), // "signalPrepareLink"
QT_MOC_LITERAL(14, 314, 22), // "signalPrepareTextLabel"
QT_MOC_LITERAL(15, 337, 15), // "signalShowPorts"
QT_MOC_LITERAL(16, 353, 19), // "signalShowBandwidth"
QT_MOC_LITERAL(17, 373, 15), // "signalShowDelay"
QT_MOC_LITERAL(18, 389, 24), // "signalShowPacketLossRate"
QT_MOC_LITERAL(19, 414, 25), // "signalCreateMininetScript"
QT_MOC_LITERAL(20, 440, 24), // "signalCreateWeightMatrix"
QT_MOC_LITERAL(21, 465, 18), // "signalRandomMetric"
QT_MOC_LITERAL(22, 484, 10), // "loadRoutes"
QT_MOC_LITERAL(23, 495, 9), // "showRoute"
QT_MOC_LITERAL(24, 505, 9), // "hideRoute"
QT_MOC_LITERAL(25, 515, 20), // "signalSaveNetworkMap"
QT_MOC_LITERAL(26, 536, 20), // "signalLoadNetworkMap"
QT_MOC_LITERAL(27, 557, 21), // "signalAlignVertically"
QT_MOC_LITERAL(28, 579, 23), // "signalAlignHorizontally"
QT_MOC_LITERAL(29, 603, 17), // "signalRemoveMarks"
QT_MOC_LITERAL(30, 621, 19), // "signalVisualizePath"
QT_MOC_LITERAL(31, 641, 10), // "QList<int>"
QT_MOC_LITERAL(32, 652, 20), // "signalVisualizePaths"
QT_MOC_LITERAL(33, 673, 18), // "QList<QList<int> >"
QT_MOC_LITERAL(34, 692, 32), // "on_actionSdnController_triggered"
QT_MOC_LITERAL(35, 725, 23), // "on_actionHost_triggered"
QT_MOC_LITERAL(36, 749, 25), // "on_actionSwitch_triggered"
QT_MOC_LITERAL(37, 775, 23), // "on_actionLink_triggered"
QT_MOC_LITERAL(38, 799, 23), // "on_actionText_triggered"
QT_MOC_LITERAL(39, 823, 23), // "on_actionEdit_triggered"
QT_MOC_LITERAL(40, 847, 34), // "mouseLeftButtonReleaseEventOc..."
QT_MOC_LITERAL(41, 882, 14), // "cursorPosition"
QT_MOC_LITERAL(42, 897, 32), // "mouseLeftButtonPressEventOccured"
QT_MOC_LITERAL(43, 930, 21), // "mouseMoveEventOccured"
QT_MOC_LITERAL(44, 952, 21), // "mouseDoubleClickEvent"
QT_MOC_LITERAL(45, 974, 28), // "on_actionShowPorts_triggered"
QT_MOC_LITERAL(46, 1003, 7), // "checked"
QT_MOC_LITERAL(47, 1011, 31), // "on_actionDisplayDelay_triggered"
QT_MOC_LITERAL(48, 1043, 35), // "on_actionDisplayBandwidth_tri..."
QT_MOC_LITERAL(49, 1079, 36), // "on_actionDisplayPacketLoss_tr..."
QT_MOC_LITERAL(50, 1116, 22), // "on_actionNew_triggered"
QT_MOC_LITERAL(51, 1139, 25), // "on_actionSaveAs_triggered"
QT_MOC_LITERAL(52, 1165, 23), // "on_actionSave_triggered"
QT_MOC_LITERAL(53, 1189, 23), // "on_actionOpen_triggered"
QT_MOC_LITERAL(54, 1213, 35), // "on_actionCreateMnDataFile_tri..."
QT_MOC_LITERAL(55, 1249, 39), // "on_actionMake_Full_Connection..."
QT_MOC_LITERAL(56, 1289, 23), // "on_actionExit_triggered"
QT_MOC_LITERAL(57, 1313, 33), // "on_actionWeights_Matrix_trigg..."
QT_MOC_LITERAL(58, 1347, 37), // "on_actionAlign_Horizontally_t..."
QT_MOC_LITERAL(59, 1385, 35), // "on_actionAlign_Vertically_tri..."
QT_MOC_LITERAL(60, 1421, 31), // "on_actionRemove_Marks_triggered"
QT_MOC_LITERAL(61, 1453, 38), // "on_actionCreate_optimal_path_..."
QT_MOC_LITERAL(62, 1492, 24), // "on_actionNN_GA_triggered"
QT_MOC_LITERAL(63, 1517, 31), // "on_actionRandomMetric_triggered"
QT_MOC_LITERAL(64, 1549, 30), // "on_actionNN_GA_8_8_8_triggered"
QT_MOC_LITERAL(65, 1580, 31), // "on_actionNN_ABC_8_8_8_triggered"
QT_MOC_LITERAL(66, 1612, 31), // "on_actionShow_results_triggered"
QT_MOC_LITERAL(67, 1644, 29), // "on_actionShow_chart_triggered"
QT_MOC_LITERAL(68, 1674, 21), // "refreshNetworkMapView"
QT_MOC_LITERAL(69, 1696, 11), // "showMessage"
QT_MOC_LITERAL(70, 1708, 7) // "message"

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
    "signalCreateWeightMatrix\0signalRandomMetric\0"
    "loadRoutes\0showRoute\0hideRoute\0"
    "signalSaveNetworkMap\0signalLoadNetworkMap\0"
    "signalAlignVertically\0signalAlignHorizontally\0"
    "signalRemoveMarks\0signalVisualizePath\0"
    "QList<int>\0signalVisualizePaths\0"
    "QList<QList<int> >\0on_actionSdnController_triggered\0"
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
    "on_actionNN_GA_triggered\0"
    "on_actionRandomMetric_triggered\0"
    "on_actionNN_GA_8_8_8_triggered\0"
    "on_actionNN_ABC_8_8_8_triggered\0"
    "on_actionShow_results_triggered\0"
    "on_actionShow_chart_triggered\0"
    "refreshNetworkMapView\0showMessage\0"
    "message"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      64,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      30,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  334,    2, 0x06 /* Public */,
       3,    0,  335,    2, 0x06 /* Public */,
       4,    1,  336,    2, 0x06 /* Public */,
       5,    1,  339,    2, 0x06 /* Public */,
       6,    1,  342,    2, 0x06 /* Public */,
       7,    1,  345,    2, 0x06 /* Public */,
       8,    0,  348,    2, 0x06 /* Public */,
       9,    0,  349,    2, 0x06 /* Public */,
      10,    0,  350,    2, 0x06 /* Public */,
      11,    0,  351,    2, 0x06 /* Public */,
      12,    0,  352,    2, 0x06 /* Public */,
      13,    0,  353,    2, 0x06 /* Public */,
      14,    0,  354,    2, 0x06 /* Public */,
      15,    1,  355,    2, 0x06 /* Public */,
      16,    0,  358,    2, 0x06 /* Public */,
      17,    0,  359,    2, 0x06 /* Public */,
      18,    0,  360,    2, 0x06 /* Public */,
      19,    1,  361,    2, 0x06 /* Public */,
      20,    1,  364,    2, 0x06 /* Public */,
      21,    0,  367,    2, 0x06 /* Public */,
      22,    1,  368,    2, 0x06 /* Public */,
      23,    1,  371,    2, 0x06 /* Public */,
      24,    1,  374,    2, 0x06 /* Public */,
      25,    1,  377,    2, 0x06 /* Public */,
      26,    1,  380,    2, 0x06 /* Public */,
      27,    0,  383,    2, 0x06 /* Public */,
      28,    0,  384,    2, 0x06 /* Public */,
      29,    0,  385,    2, 0x06 /* Public */,
      30,    1,  386,    2, 0x06 /* Public */,
      32,    1,  389,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      34,    0,  392,    2, 0x08 /* Private */,
      35,    0,  393,    2, 0x08 /* Private */,
      36,    0,  394,    2, 0x08 /* Private */,
      37,    0,  395,    2, 0x08 /* Private */,
      38,    0,  396,    2, 0x08 /* Private */,
      39,    0,  397,    2, 0x08 /* Private */,
      40,    1,  398,    2, 0x08 /* Private */,
      42,    1,  401,    2, 0x08 /* Private */,
      43,    1,  404,    2, 0x08 /* Private */,
      44,    1,  407,    2, 0x08 /* Private */,
      45,    1,  410,    2, 0x08 /* Private */,
      47,    0,  413,    2, 0x08 /* Private */,
      48,    0,  414,    2, 0x08 /* Private */,
      49,    0,  415,    2, 0x08 /* Private */,
      50,    0,  416,    2, 0x08 /* Private */,
      51,    0,  417,    2, 0x08 /* Private */,
      52,    0,  418,    2, 0x08 /* Private */,
      53,    0,  419,    2, 0x08 /* Private */,
      54,    0,  420,    2, 0x08 /* Private */,
      55,    0,  421,    2, 0x08 /* Private */,
      56,    0,  422,    2, 0x08 /* Private */,
      57,    0,  423,    2, 0x08 /* Private */,
      58,    0,  424,    2, 0x08 /* Private */,
      59,    0,  425,    2, 0x08 /* Private */,
      60,    0,  426,    2, 0x08 /* Private */,
      61,    0,  427,    2, 0x08 /* Private */,
      62,    0,  428,    2, 0x08 /* Private */,
      63,    0,  429,    2, 0x08 /* Private */,
      64,    0,  430,    2, 0x08 /* Private */,
      65,    0,  431,    2, 0x08 /* Private */,
      66,    0,  432,    2, 0x08 /* Private */,
      67,    0,  433,    2, 0x08 /* Private */,
      68,    1,  434,    2, 0x0a /* Public */,
      69,    1,  437,    2, 0x0a /* Public */,

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
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 31,    2,
    QMetaType::Void, 0x80000000 | 33,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,   41,
    QMetaType::Void, QMetaType::QPoint,   41,
    QMetaType::Void, QMetaType::QPoint,   41,
    QMetaType::Void, QMetaType::QPoint,   41,
    QMetaType::Void, QMetaType::Bool,   46,
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
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPixmap,    2,
    QMetaType::Void, QMetaType::QString,   70,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
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
        case 19: _t->signalRandomMetric(); break;
        case 20: _t->loadRoutes((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 21: _t->showRoute((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->hideRoute((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: _t->signalSaveNetworkMap((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 24: _t->signalLoadNetworkMap((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 25: _t->signalAlignVertically(); break;
        case 26: _t->signalAlignHorizontally(); break;
        case 27: _t->signalRemoveMarks(); break;
        case 28: _t->signalVisualizePath((*reinterpret_cast< QList<int>(*)>(_a[1]))); break;
        case 29: _t->signalVisualizePaths((*reinterpret_cast< QList<QList<int> >(*)>(_a[1]))); break;
        case 30: _t->on_actionSdnController_triggered(); break;
        case 31: _t->on_actionHost_triggered(); break;
        case 32: _t->on_actionSwitch_triggered(); break;
        case 33: _t->on_actionLink_triggered(); break;
        case 34: _t->on_actionText_triggered(); break;
        case 35: _t->on_actionEdit_triggered(); break;
        case 36: _t->mouseLeftButtonReleaseEventOccured((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 37: _t->mouseLeftButtonPressEventOccured((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 38: _t->mouseMoveEventOccured((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 39: _t->mouseDoubleClickEvent((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 40: _t->on_actionShowPorts_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 41: _t->on_actionDisplayDelay_triggered(); break;
        case 42: _t->on_actionDisplayBandwidth_triggered(); break;
        case 43: _t->on_actionDisplayPacketLoss_triggered(); break;
        case 44: _t->on_actionNew_triggered(); break;
        case 45: _t->on_actionSaveAs_triggered(); break;
        case 46: _t->on_actionSave_triggered(); break;
        case 47: _t->on_actionOpen_triggered(); break;
        case 48: _t->on_actionCreateMnDataFile_triggered(); break;
        case 49: _t->on_actionMake_Full_Connection_triggered(); break;
        case 50: _t->on_actionExit_triggered(); break;
        case 51: _t->on_actionWeights_Matrix_triggered(); break;
        case 52: _t->on_actionAlign_Horizontally_triggered(); break;
        case 53: _t->on_actionAlign_Vertically_triggered(); break;
        case 54: _t->on_actionRemove_Marks_triggered(); break;
        case 55: _t->on_actionCreate_optimal_path_triggered(); break;
        case 56: _t->on_actionNN_GA_triggered(); break;
        case 57: _t->on_actionRandomMetric_triggered(); break;
        case 58: _t->on_actionNN_GA_8_8_8_triggered(); break;
        case 59: _t->on_actionNN_ABC_8_8_8_triggered(); break;
        case 60: _t->on_actionShow_results_triggered(); break;
        case 61: _t->on_actionShow_chart_triggered(); break;
        case 62: _t->refreshNetworkMapView((*reinterpret_cast< QPixmap(*)>(_a[1]))); break;
        case 63: _t->showMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 28:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<int> >(); break;
            }
            break;
        case 29:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QList<int> > >(); break;
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
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalRandomMetric)) {
                *result = 19;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::loadRoutes)) {
                *result = 20;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::showRoute)) {
                *result = 21;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::hideRoute)) {
                *result = 22;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalSaveNetworkMap)) {
                *result = 23;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalLoadNetworkMap)) {
                *result = 24;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalAlignVertically)) {
                *result = 25;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalAlignHorizontally)) {
                *result = 26;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalRemoveMarks)) {
                *result = 27;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QList<int> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalVisualizePath)) {
                *result = 28;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QList<QList<int>> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::signalVisualizePaths)) {
                *result = 29;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
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
        if (_id < 64)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 64;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 64)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 64;
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
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainWindow::signalHandleMousePressEvent(QPoint _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainWindow::signalHandleMouseMoveEvent(QPoint _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MainWindow::signalHandleDoubleClickEvent(QPoint _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
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
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
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
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 18
void MainWindow::signalCreateWeightMatrix(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}

// SIGNAL 19
void MainWindow::signalRandomMetric()
{
    QMetaObject::activate(this, &staticMetaObject, 19, nullptr);
}

// SIGNAL 20
void MainWindow::loadRoutes(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 20, _a);
}

// SIGNAL 21
void MainWindow::showRoute(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 21, _a);
}

// SIGNAL 22
void MainWindow::hideRoute(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 22, _a);
}

// SIGNAL 23
void MainWindow::signalSaveNetworkMap(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 23, _a);
}

// SIGNAL 24
void MainWindow::signalLoadNetworkMap(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 24, _a);
}

// SIGNAL 25
void MainWindow::signalAlignVertically()
{
    QMetaObject::activate(this, &staticMetaObject, 25, nullptr);
}

// SIGNAL 26
void MainWindow::signalAlignHorizontally()
{
    QMetaObject::activate(this, &staticMetaObject, 26, nullptr);
}

// SIGNAL 27
void MainWindow::signalRemoveMarks()
{
    QMetaObject::activate(this, &staticMetaObject, 27, nullptr);
}

// SIGNAL 28
void MainWindow::signalVisualizePath(QList<int> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 28, _a);
}

// SIGNAL 29
void MainWindow::signalVisualizePaths(QList<QList<int>> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 29, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
