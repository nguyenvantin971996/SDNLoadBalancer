#include "MininetScriptBuilder.h"
#include "Switch.h"
#include "Host.h"
#include "SdnController.h"
#include "SSLink.h"

MininetScriptBuilder::MininetScriptBuilder(PortMatrix portMatrix) :
    portMatrix(portMatrix)
{
}

void MininetScriptBuilder::addSwitchData(Switch *sw)
{
    switchesData.append(QString("%0 = net.addSwitch('%0')")
                                .arg(sw->getName()));
    startingData.append(QString("%0.start([c0])").arg(sw->getName()));
}

void MininetScriptBuilder::addSdnControllerData(SdnController *controller)
{
    sdnControllersData.append
            (QString("%0 = net.addController('%0', controller=RemoteController, ip='%1', port=%2)")
                .arg(controller->getName()).arg(controller->getIp()).arg(controller->getPort()));
    startingData.insert(0, QString("%0.start()").arg(controller->getName()));
}

void MininetScriptBuilder::addHostData(Host *host)
{
    hostsData.append(QString("%0 = net.addHost('%0', mac='%1', ip='%2')").arg(
                             host->getName(),
                             host->getMac(),
                             host->getIp()));
}

void MininetScriptBuilder::addSSLinkData(SSLink *link)
{
    Node *node1 = link->getNode1();
    Node *node2 = link->getNode2();
    linksData.append(QString("net.addLink(%0, %1, %2, %3, bw=%4, delay='%5ms', loss=%6)").arg(
                             node1->getName(),
                             node2->getName(),
                             QString::number(portMatrix.getPortNumber(node1, node2)),
                             QString::number(portMatrix.getPortNumber(node2, node1)),
                             QString::number(link->getBandwidth()),
                             QString::number(link->getDelay()),
                             QString::number(link->getPacketLoss())));
}

QString MininetScriptBuilder::buildIncludeBlock()
{
    QStringList includeBlock;
    includeBlock.append("from mininet.net import Mininet");
    includeBlock.append("from mininet.node import Controller, RemoteController, OVSKernelSwitch");
    includeBlock.append("from mininet.cli import CLI");
    includeBlock.append("from mininet.log import setLogLevel");
    includeBlock.append("from mininet.link import TCLink");
    return includeBlock.join("\n").append("\n\n");
}

QString MininetScriptBuilder::buildFunctionBeginBlock()
{
    QStringList functionBeginBlock;
    functionBeginBlock.append("def topology():");
    functionBeginBlock.append("net = Mininet(controller=RemoteController, link=TCLink, switch=OVSKernelSwitch)");
    return functionBeginBlock.join("\n\t").append("\n\n");
}

QString MininetScriptBuilder::buildSdnControllersBlock()
{
    return QString("\t").append(sdnControllersData.join("\n\t").append("\n\n"));
}

QString MininetScriptBuilder::buildHostsBlock()
{
    return QString("\t").append(hostsData.join("\n\t").append("\n\n"));
}

QString MininetScriptBuilder::buildSwitchesBlock()
{
    return QString("\t").append(switchesData.join("\n\t").append("\n\n"));
}

QString MininetScriptBuilder::buildLinksBlock()
{
    return QString("\t").append(linksData.join("\n\t").append("\n\n"));
}

QString MininetScriptBuilder::buildStartingBlock()
{
    return QString("\t").append(startingData.join("\n\t").append("\n\n"));
}

QString MininetScriptBuilder::buildFunctionEndBlock()
{
    QStringList functionEndBlock;
    functionEndBlock.append("\t");
    functionEndBlock.append("CLI(net)");
    functionEndBlock.append("net.stop()");
    return functionEndBlock.join("\n\t").append("\n\n");
}

QString MininetScriptBuilder::buildStartupBlock()
{
    QStringList startupBlock;
    startupBlock.append("if __name__ == '__main__':");
    startupBlock.append("setLogLevel( 'info' )");
    startupBlock.append("topology()");
    return startupBlock.join("\n\t").append("\n\n");
}
QString MininetScriptBuilder::buildMininetScript()
{
    startingData.append("net.build()");

    QString script;

    script.append(buildIncludeBlock());
    script.append(buildFunctionBeginBlock());

    script.append(buildSdnControllersBlock());
    script.append(buildHostsBlock());
    script.append(buildSwitchesBlock());
    script.append(buildLinksBlock());
    script.append(buildStartingBlock());

    script.append(buildFunctionEndBlock());
    script.append(buildStartupBlock());
    return script;
}
