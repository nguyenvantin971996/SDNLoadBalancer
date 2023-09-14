/* Core:
 * - monitores user operations
 */

#ifndef CORE_H
#define CORE_H

#include <QObject>
#include "NetworkMap.h"
#include "ElementEditor.h"
#include "NodeCreator.h"
#include "LinkCreator.h"

class Tool;

class Core : public QObject
{
    Q_OBJECT

public:
    explicit Core(QObject *parent = 0);

    void refreshNetworkMap();

private:
    NetworkMap map;

    Tool *tool;
    NodeCreator nodeCreator;
    LinkCreator linkCreator;
    ElementEditor elementEditor;

signals:
    void signalRefreshNetworkMapView(QPixmap);

public slots:
    void connectSdnController();
    void clearNetworkMap();

    void handleMouseReleaseEvent(QPoint);
    void handleMousePressEvent(QPoint);
    void handleMouseMoveEvent(QPoint);
    void handleDoubleClickEvent(QPoint);
    void handleKeyDeletePressEvent();

    void changeStateToEdit();
    void prepareSdnController();
    void prepareHost();
    void prepareSwitch();
    void prepareLink();
    void prepareTextLabel();

    void showPorts(bool);
    void showBandwidth();
    void showDelay();
    void showPacketLossRate();
    void showDelayBandwidth();

    void createMininetScript(QString);
    void createWeightsMatrix(QString path);
    void RandomMetric();

    void saveNetworkMap(QString);
    void loadNetworkMap(QString);

    void visualizePath(QList<int> path);
    void visualizePaths(QList<QList<int> > paths);
    void visualizeIslands(QList<QList<int> > islands);
    void visualizeTree(QList<QList<int> > tree);
    void visualizeTrees(QList<QList<QList<int> > > trees);
    void eraseMarks();

    void changeMetric(QVector<float> metricData);

    void AlignVertically();
    void AlignHorizontally();
};

#endif // CORE_H
