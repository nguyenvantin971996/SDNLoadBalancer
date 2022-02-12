#include "MainWindow.h"
#include <QApplication>
#include "Core.h"
#include "CommandReceiver.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow view;
    Core c;
    CommandReceiver receiver;

    // States connection
    QObject::connect(&view, SIGNAL(signalChangeStateToEdit()), &c, SLOT(changeStateToEdit()));
    QObject::connect(&view, SIGNAL(signalPrepareHost()), &c, SLOT(prepareHost()));
    QObject::connect(&view, SIGNAL(signalPrepareLink()), &c, SLOT(prepareLink()));
    QObject::connect(&view, SIGNAL(signalPrepareSdnController()), &c, SLOT(prepareSdnController()));
    QObject::connect(&view, SIGNAL(signalPrepareSwitch()), &c, SLOT(prepareSwitch()));
    QObject::connect(&view, SIGNAL(signalPrepareTextLabel()), &c, SLOT(prepareTextLabel()));

    // Key events connection
    QObject::connect(&view, SIGNAL(signalHandleDoubleClickEvent(QPoint)), &c, SLOT(handleDoubleClickEvent(QPoint)));
    QObject::connect(&view, SIGNAL(signalHandleKeyDeletePressEvent()), &c, SLOT(handleKeyDeletePressEvent()));
    QObject::connect(&view, SIGNAL(signalHandleMouseMoveEvent(QPoint)), &c, SLOT(handleMouseMoveEvent(QPoint)));
    QObject::connect(&view, SIGNAL(signalHandleMousePressEvent(QPoint)), &c, SLOT(handleMousePressEvent(QPoint)));
    QObject::connect(&view, SIGNAL(signalHandleMouseReleaseEvent(QPoint)), &c, SLOT(handleMouseReleaseEvent(QPoint)));

    // Network map actions connection
    QObject::connect(&view, SIGNAL(signalSaveNetworkMap(QString)), &c, SLOT(saveNetworkMap(QString)));
    QObject::connect(&view, SIGNAL(signalLoadNetworkMap(QString)), &c, SLOT(loadNetworkMap(QString)));
    QObject::connect(&view, SIGNAL(signalCreateMininetScript(QString)), &c, SLOT(createMininetScript(QString)));
    QObject::connect(&view, SIGNAL(signalConnectSdnController()), &c, SLOT(connectSdnController()));
    QObject::connect(&view, SIGNAL(signalClearNetworkMap()), &c, SLOT(clearNetworkMap()));
    QObject::connect(&view, SIGNAL(signalCreateWeightMatrix(QString)), &c, SLOT(createWeightsMatrix(QString)));
    QObject::connect(&view, SIGNAL(signalAlignHorizontally()), &c, SLOT(AlignHorizontally()));
    QObject::connect(&view, SIGNAL(signalAlignVertically()), &c, SLOT(AlignVertically()));
    QObject::connect(&view, SIGNAL(signalRandomMetric()), &c, SLOT(RandomMetric()));

    // Display properties connection
    QObject::connect(&view, SIGNAL(signalShowBandwidth()), &c, SLOT(showBandwidth()));
    QObject::connect(&view, SIGNAL(signalShowDelay()), &c, SLOT(showDelay()));
    QObject::connect(&view, SIGNAL(signalShowPacketLossRate()), &c, SLOT(showPacketLossRate()));
    QObject::connect(&view, SIGNAL(signalShowPorts(bool)), &c, SLOT(showPorts(bool)));
    QObject::connect(&view, SIGNAL(signalVisualizePath(QList<int>)), &c, SLOT(visualizePath(QList<int>)));
    QObject::connect(&view, SIGNAL(signalVisualizePaths(QList<QList<int>>)), &c, SLOT(visualizePaths(QList<QList<int>>)));

    // Drawing connection
    QObject::connect(&c, SIGNAL(signalRefreshNetworkMapView(QPixmap)), &view, SLOT(refreshNetworkMapView(QPixmap)));

    // Network command handler connection
    QObject::connect(&view, SIGNAL(signalRemoveMarks()), &c, SLOT(eraseMarks()));
    QObject::connect(&receiver, SIGNAL(signalPathReceived(QList<int>)), &c, SLOT(visualizePath(QList<int>)));
    QObject::connect(&receiver, SIGNAL(signalTreeReceived(QList<QList<int> >)), &c, SLOT(visualizeTree(QList<QList<int> >)));
    QObject::connect(&receiver, SIGNAL(signalTreesReceived(QList<QList<QList<int> > >)), &c, SLOT(visualizeTrees(QList<QList<QList<int> > >)));
    QObject::connect(&receiver, SIGNAL(signalIslandsReceived(QList<QList<int> >)), &c, SLOT(visualizeIslands(QList<QList<int> >)));
    QObject::connect(&receiver, SIGNAL(signalPathsReceived(QList<QList<int> >)), &c, SLOT(visualizePaths(QList<QList<int> >)));
    QObject::connect(&receiver, SIGNAL(signalPTReceived(double)), &c, SLOT(appendPairTransitionsData(double)));
    QObject::connect(&receiver, SIGNAL(signalMessageReceived(QString)), &view, SLOT(showMessage(QString)));

    view.show();
    receiver.on();
    return a.exec();
}

