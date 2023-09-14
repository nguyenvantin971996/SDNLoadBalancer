#ifndef NETWORKMAP_H
#define NETWORKMAP_H

#include <QList>
#include "SelectionFrame.h"
#include "MatrixRepository.h"

class QPixmap;
class Graph;
class Link;
class Node;
class Element;
class SSLink;
class CSLink;
class Switch;
class Host;
class SdnController;
class TextLabel;

class NetworkMap
{
public:
    ~NetworkMap();
    void clear();
    void removeElement(Element *e);


    Node *getNodeByPosition(QPoint position);
    Node *getNodeByName(QString name);
    Element *getElementByPosition(QPoint position);
    QList<Node *> getNodesBySelectedFrame();
    inline QList<Switch *> getSwitches() const;
    inline CommutationMatrix<SSLink> getGraphMatrix();
    inline SelectionFrame *getSelectionFrame();

    inline bool isConnected(Node *node1, Node *node2);

    void addSSLink(SSLink *ln);
    void addCSLink(CSLink *ln);
    void addSwitch(Switch *sw);
    void addHost(Host *hst);
    void addSdnController(SdnController *c);
    void addTextLabel(TextLabel *txt);

    void removeSSLink(SSLink *ln);
    void removeCSLink(CSLink *ln);
    void removeSwitch(Switch *sw);
    void removeHost(Host *hst);
    void removeSdnController(SdnController *c);
    void removeTextLabel(TextLabel *txt);

    void connectSdnController();   

    void visualizePath(QList<int> path);
    void visualizePaths(QList<QList<int> > paths);
    void visualizeTree(QList<QList<int> > tree);
    void visualizeTrees(QList<QList<QList<int> > > trees);
    void visualizeIslands(QList<QList<int>> islands);
    void unselectLinks();
    void unselectNodes();

    void changeMetric(QVector<float> metricData);

    QString createMininetScript();
    QString createXmlDocument();
    QPixmap draw();

private:
    QList<Node *> nodes;
    QList<Link *> links;
    QList<SSLink *> ssLinks;
    QList<CSLink *> csLinks;
    QList<Switch *> switches;
    QList<Host *> hosts;
    QList<SdnController *> sdnControllers;
    QList<TextLabel *> textLabels;

    SelectionFrame selectionFrame;
    MatrixRepository matrices;
    int globalId;

private:
    void disconnectNode(Node *node);
};

inline QList<Switch *> NetworkMap::getSwitches() const
{
    return switches;
}

inline CommutationMatrix<SSLink> NetworkMap::getGraphMatrix()
{
    return matrices.getGraphMatrix();
}

inline bool NetworkMap::isConnected(Node *node1, Node *node2)
{
    return matrices.getGlobalMatrix().getLink(node1, node2) != NULL;
}

inline SelectionFrame *NetworkMap::getSelectionFrame()
{
    return &selectionFrame;
}

#endif // NETWORKMAP_H
