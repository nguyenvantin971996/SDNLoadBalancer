#include "Core.h"
#include "IO.h"
#include "XmlDeserializer.h"
#include "WeightsMatrix.h"
#include "DrawingMode.h"

Core::Core(QObject *parent) :
    QObject(parent),
    linkCreator(&map),
    nodeCreator(&map),
    elementEditor(&map)
{
    changeStateToEdit();
    DrawingMode::showDelay();
}

void Core::refreshNetworkMap()
{
    emit signalRefreshNetworkMapView(map.draw());
}

void Core::handleMouseReleaseEvent(QPoint position)
{
    tool->handleMouseUp(position);
    refreshNetworkMap();
}

void Core::handleMousePressEvent(QPoint position)
{
    tool->handleMouseDown(position);
    refreshNetworkMap();
}

void Core::handleMouseMoveEvent(QPoint position)
{
    if (tool->handleMouseMove(position))
    {
        refreshNetworkMap();
    }
}

void Core::handleDoubleClickEvent(QPoint position)
{
    tool->handleMouseDoubleClicked(position);
    refreshNetworkMap();
}

void Core::handleKeyDeletePressEvent()
{
    tool->handleKeyDeletePressEvent();
    refreshNetworkMap();
}

void Core::changeStateToEdit()
{
    tool = &elementEditor;
}

void Core::prepareSdnController()
{
    tool = &nodeCreator;
    nodeCreator.setSdnControllerCreation();
}

void Core::prepareHost()
{
    tool = &nodeCreator;
    nodeCreator.setHostCreation();
}

void Core::prepareSwitch()
{
    tool = &nodeCreator;
    nodeCreator.setSwitchCreation();
}

void Core::prepareLink()
{
    tool = &linkCreator;
}

void Core::prepareTextLabel()
{
    tool = &nodeCreator;
    nodeCreator.setTextLabelCreation();
}

void Core::showPorts(bool status)
{
    DrawingMode::needShowPorts = status;
    refreshNetworkMap();
}

void Core::showBandwidth()
{
    DrawingMode::showBandwidth();
    refreshNetworkMap();
}

void Core::showDelay()
{
    DrawingMode::showDelay();
    refreshNetworkMap();
}

void Core::showPacketLossRate()
{
    DrawingMode::showPacketLossRate();
    refreshNetworkMap();
}
void Core::showDelayBandwidth()
{
    DrawingMode::showDelayBandwidth();
    refreshNetworkMap();
}
void Core::createMininetScript(QString filePath)
{
    IO io;
    io.writeFile(map.createMininetScript(), filePath);
}

void Core::saveNetworkMap(QString filePath)
{
    IO io;
    io.writeFile(map.createXmlDocument(), filePath);
}

void Core::loadNetworkMap(QString filePath)
{
    IO io;
    XmlDeserializer deserializer;
    QString xmlDocument = io.readFile(filePath);
    deserializer.deserialize(xmlDocument, &map);
    elementEditor.handleMouseDown(QPoint(-999, -999));
    refreshNetworkMap();
}

void Core::visualizePath(QList<int> path)
{
    map.unselectLinks();
    map.visualizePath(path);
    refreshNetworkMap();
}

void Core::visualizePaths(QList<QList<int> > paths)
{
    map.unselectLinks();
    map.visualizePaths(paths);
    refreshNetworkMap();
}

void Core::visualizeIslands(QList<QList<int> > islands)
{
    map.unselectNodes();
    map.visualizeIslands(islands);
    refreshNetworkMap();
}

void Core::visualizeTree(QList<QList<int> > tree)
{
    map.unselectLinks();
    map.visualizeTree(tree);
    refreshNetworkMap();
}

void Core::visualizeTrees(QList<QList<QList<int> > > trees)
{
    map.unselectLinks();
    map.visualizeTrees(trees);
    refreshNetworkMap();
}

void Core::eraseMarks()
{
    map.unselectLinks();
    map.unselectNodes();
    refreshNetworkMap();
}

void Core::changeMetric(QVector<float> metricData)
{
    map.changeMetric(metricData);
    refreshNetworkMap();
}

void Core::AlignVertically()
{
    elementEditor.AlignVertically();
    refreshNetworkMap();
}

void Core::AlignHorizontally()
{
    elementEditor.AlignHorizontally();
    refreshNetworkMap();
}

void Core::createWeightsMatrix(QString path)
{
    WeightsMatrix matrix;
    IO io;
    QString content = matrix.build(map.getGraphMatrix(), map.getSwitches());
    io.writeFile(content, path);
}
void Core::RandomMetric()
{
    CommutationMatrix<SSLink> graphMatrix=map.getGraphMatrix();
    QList<Switch *> switches=map.getSwitches();
    foreach (Switch *sw, switches)
    {
        foreach (Node *node, graphMatrix.getNeighbors(sw))
        {
            SSLink *ln = graphMatrix.getLink(sw, node);
            if (ln != NULL)
            {
                int n1 = sw->getGroupId();
                int n2 = node->getGroupId();
                ln->setDelay(5*(rand()%19+1));
                ln->setBandwidth(100);
            }
        }
    }
    refreshNetworkMap();
}

void Core::connectSdnController()
{
    map.connectSdnController();
    refreshNetworkMap();
}

void Core::clearNetworkMap()
{
    elementEditor.handleMouseDown(QPoint(-999, -999));
    map.clear();
    refreshNetworkMap();
}
