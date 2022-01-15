#include "NetworkMap.h"
#include "SearchEngine.h"
#include "MininetScriptBuilder.h"
#include "XmlSerializer.h"
#include "NetworkMapDrawer.h"
#include "Node.h"
#include "Link.h"
#include "Element.h"
#include "SdnController.h"
#include "Host.h"
#include "Switch.h"
#include "SSLink.h"
#include "CSLink.h"
#include "TextLabel.h"
#include "NodeConnector.h"
#include "CommutationMatrix.h"
#include "NetworkVisualizer.h"


NetworkMap::~NetworkMap()
{
    clear();
}

void NetworkMap::clear()
{
    foreach (Link *ln, links)
    {
        removeElement(ln);
    }
    foreach (Node *node, nodes)
    {
        removeElement(node);
    }
}

void NetworkMap::removeElement(Element *e)
{
    if (e == NULL)
    {
        return;
    }
    switch (e->getDeviceType())
    {
        case SSLINK:
            removeSSLink((SSLink*)e);
            break;
        case CSLINK:
            removeCSLink((CSLink*)e);
            break;
        case HOST:
            removeHost((Host*)e);
            break;
        case SWITCH:
            removeSwitch((Switch*)e);
            break;
        case SDNCONTROLLER:
            removeSdnController((SdnController*)e);
            break;
        case TEXTLABEL:
            removeTextLabel((TextLabel*)e);
            break;
        default:
            break;
    }
}

void NetworkMap::disconnectNode(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    CommutationMatrix<Link> matrix = matrices.getGlobalMatrix();
    foreach (Node *neighbor, matrix.getNeighbors(node))
    {
        removeElement(matrix.getLink(node, neighbor));
    }
}

Node *NetworkMap::getNodeByPosition(QPoint position)
{
    SearchEngine searcher;
    return searcher.findNode(nodes, position);
}

Node *NetworkMap::getNodeByName(QString name)
{
    SearchEngine searcher;
    return searcher.findNode(nodes, name);
}

Element *NetworkMap::getElementByPosition(QPoint position)
{
    SearchEngine searcher;
    Element *e = NULL;
    if ((e = searcher.findNode(nodes, position)) != NULL)
    {
        return e;
    }
    if ((e = searcher.findLink(links, position)) != NULL)
    {
        return e;
    }
    return e;
}

QList<Node *> NetworkMap::getNodesBySelectedFrame()
{
    SearchEngine searcher;
    return searcher.findNodes(nodes, selectionFrame.getTopLeft(),
                              selectionFrame.getBottomRight());
}

void NetworkMap::addSSLink(SSLink *ln)
{
    if (ln == NULL)
    {
        return;
    }
    int groupId = ssLinks.length() + 1;
    ln->setGroupId(groupId);
    ln->setGlobalId(globalId++);
    ssLinks.append(ln);
    links.append(ln);
    matrices.registerSSLink(ln);
}

void NetworkMap::addCSLink(CSLink *ln)
{
    if (ln == NULL)
    {
        return;
    }
    int groupId = csLinks.length() + 1;
    ln->setGroupId(groupId);
    ln->setGlobalId(globalId++);
    csLinks.append(ln);
    links.append(ln);
    matrices.registerLink(ln);
}

void NetworkMap::addSwitch(Switch *sw)
{
    if (sw == NULL)
    {
        return;
    }
    int groupId = switches.length() + 1;
    sw->setGroupId(groupId);
    sw->setup(groupId);
    sw->setGlobalId(globalId++);
    switches.append(sw);
    nodes.append(sw);
    matrices.registerSwitch(sw);
}

void NetworkMap::addHost(Host *hst)
{
    if (hst == NULL)
    {
        return;
    }
    int groupId = hosts.length() + 1;
    hst->setGroupId(groupId);
    hst->setup(groupId);
    hst->setGlobalId(globalId++);
    hosts.append(hst);
    nodes.append(hst);
    matrices.registerHost(hst);
}

void NetworkMap::addSdnController(SdnController *c)
{
    if (c == NULL)
    {
        return;
    }
    int groupId = sdnControllers.length();
    c->setGroupId(groupId);
    c->setup(groupId);
    c->setGlobalId(globalId++);
    sdnControllers.append(c);
    nodes.append(c);
    matrices.registerNode(c);
}

void NetworkMap::addTextLabel(TextLabel *txt)
{
    if (txt == NULL)
    {
        return;
    }
    int groupId = textLabels.length() + 1;
    txt->setGroupId(groupId);
    txt->setGlobalId(globalId++);
    textLabels.append(txt);
    nodes.append(txt);
}

void NetworkMap::removeSSLink(SSLink *ln)
{
    if (ln == NULL)
    {
        return;
    }
    links.removeOne(ln);
    ssLinks.removeOne(ln);
    matrices.unregisterSSLink(ln);
    for (int i = 0; i < ssLinks.length(); i++)
    {
        int groupId = i + 1;
        ssLinks[i]->setGroupId(groupId);
    }
    delete ln;
}

void NetworkMap::removeCSLink(CSLink *ln)
{
    if (ln == NULL)
    {
        return;
    }
    links.removeOne(ln);
    matrices.unregisterLink(ln);
    csLinks.removeOne(ln);
    for (int i = 0; i < csLinks.length(); i++)
    {
        int groupId = i + 1;
        csLinks[i]->setGroupId(groupId);
    }
    delete ln;
}

void NetworkMap::removeSwitch(Switch *sw)
{
    if (sw == NULL)
    {
        return;
    }
    disconnectNode(sw);
    matrices.unregisterSwitch(sw);
    switches.removeOne(sw);
    nodes.removeOne(sw);
    for (int i = 0; i < switches.length(); i++)
    {
        int groupId = i + 1;
        switches[i]->setGroupId(groupId);
        switches[i]->setup(groupId);
    }
    delete sw;
}

void NetworkMap::removeHost(Host *hst)
{
    if (hst == NULL)
    {
        return;
    }
    disconnectNode(hst);
    matrices.unregisterHost(hst);
    hosts.removeOne(hst);
    nodes.removeOne(hst);
    for (int i = 0; i < hosts.length(); i++)
    {
        int groupId = i + 1;
        hosts[i]->setGroupId(groupId);
        hosts[i]->setup(groupId);
    }
    delete hst;
}

void NetworkMap::removeSdnController(SdnController *c)
{
    if (c == NULL)
    {
        return;
    }
    disconnectNode(c);
    matrices.unregisterNode(c);
    nodes.removeOne(c);
    sdnControllers.removeOne(c);
    for (int i = 0; i < sdnControllers.length(); i++)
    {
        int groupId = i + 1;
        sdnControllers[i]->setGroupId(groupId);
        sdnControllers[i]->setup(groupId);
    }
    delete c;
}

void NetworkMap::removeTextLabel(TextLabel *txt)
{
    if (txt == NULL)
    {
        return;
    }
    textLabels.removeOne(txt);
    nodes.removeOne(txt);
    for (int i = 0; i < textLabels.length(); i++)
    {
        int groupId = i + 1;
        textLabels[i]->setGroupId(groupId);
    }
    delete txt;
}

void NetworkMap::connectSdnController()
{
    if (sdnControllers.length() == 0)
    {
        return;
    }
    foreach (CSLink *ln, csLinks)
    {
        removeCSLink(ln);
    }
    NodeConnector connector;
    foreach (CSLink *ln, connector.connectSdnControllerTo(switches, sdnControllers[0]))
    {
        addCSLink(ln);
    }
}

void NetworkMap::visualizePath(QList<int> path)
{
    NetworkVisualizer visualizer(matrices.getGraphMatrix(), switches);
    visualizer.visualizePath(path, QColor("red"));
}

void NetworkMap::visualizePaths(QList<QList<int> > paths)
{
    NetworkVisualizer visualizer(matrices.getGraphMatrix(), switches);
    visualizer.visualizePaths(paths);
}

void NetworkMap::visualizeTree(QList<QList<int> > tree)
{
    NetworkVisualizer visualizer(matrices.getGraphMatrix(), switches);
    visualizer.visualizeTree(tree, QColor(220, 20, 20));
}

void NetworkMap::visualizeTrees(QList<QList<QList<int> > > trees)
{
    NetworkVisualizer visualizer(matrices.getGraphMatrix(), switches);
    visualizer.visualizeTrees(trees);
}

void NetworkMap::visualizeIslands(QList<QList<int> > islands)
{
    NetworkVisualizer visualizer(matrices.getGraphMatrix(), switches);
    visualizer.visualizeIslands(islands);
}

void NetworkMap::unselectLinks()
{
    foreach (Link *ln, links)
    {
        ln->unselect();
    }
}

void NetworkMap::unselectNodes()
{
    foreach (Element *node, nodes)
    {
        node->unselect();
    }
}

void NetworkMap::changeMetric(QVector<float> metricData)
{
    SearchEngine searcher;
    CommutationMatrix<SSLink> graph = matrices.getGraphMatrix();
    Switch *sw1 = searcher.findSwitch(switches, metricData[0]);
    Switch *sw2 = searcher.findSwitch(switches, metricData[2]);
    SSLink *ln = graph.getLink(sw1, sw2);
    ln->setDelay(metricData[1]);
}

QPixmap NetworkMap::draw()
{
    NetworkMapDrawer drawer(QSize(1645, 1024));
    drawer.beginDrawing();
    foreach (CSLink *ln, csLinks)
    {
        ln->draw(&drawer);
    }
    foreach (SSLink *ln, ssLinks)
    {
        ln->draw(&drawer, matrices.getPortMatrix());
    }
    foreach (Switch *sw, switches)
    {
        sw->draw(&drawer);
    }
    foreach (Host *hst, hosts)
    {
        hst->draw(&drawer);
    }
    foreach (SdnController *c, sdnControllers)
    {
        c->draw(&drawer);
    }
    foreach (TextLabel *txt, textLabels)
    {
        txt->draw(&drawer);
    }
    selectionFrame.draw(&drawer);
    return drawer.getImage();
}

QString NetworkMap::createMininetScript()
{
    auto portMatrix = matrices.getPortMatrix();
    MininetScriptBuilder builder(portMatrix);
    foreach (SSLink *ln, ssLinks)
    {
        builder.addSSLinkData(ln);
    }
    foreach (Switch *sw, switches)
    {
        builder.addSwitchData(sw);
    }
    foreach (Host *hst, hosts)
    {
        builder.addHostData(hst);
    }
    foreach (SdnController *c, sdnControllers)
    {
        builder.addSdnControllerData(c);
    }
    return builder.buildMininetScript();
}

QString NetworkMap::createXmlDocument()
{
    XmlSerializer builder;
    foreach (CSLink *ln, csLinks)
    {
        builder.addCSLinkData(ln);
    }
    foreach (SSLink *ln, ssLinks)
    {
        builder.addSSLinkData(ln);
    }
    foreach (Switch *sw, switches)
    {
        builder.addSwitchData(sw);
    }
    foreach (Host *hst, hosts)
    {
        builder.addHostData(hst);
    }
    foreach (SdnController *c, sdnControllers)
    {
        builder.addSdnControllerData(c);
    }
    foreach (TextLabel *c, textLabels)
    {
        builder.addTextLabelData(c);
    }
    return builder.buildXmlDocument();
}
