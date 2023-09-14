#ifndef MININETSCRIPTBUILDER_H
#define MININETSCRIPTBUILDER_H

#include <QStringList>
#include "PortMatrix.h"

class Switch;
class Host;
class SdnController;
class SSLink;

class MininetScriptBuilder
{
public:
    MininetScriptBuilder(PortMatrix portMatrix);
    void addSwitchData(Switch *sw);
    void addSdnControllerData(SdnController *controller);
    void addHostData(Host *host);
    void addSSLinkData(SSLink *link);

    QString buildMininetScript();

private:
    QStringList switchesData;
    QStringList sdnControllersData;
    QStringList hostsData;
    QStringList linksData;
    QStringList startingData;

    QString buildIncludeBlock();
    QString buildClassBeginBlock();
    QString buildFunctionBeginBlock();

    QString buildSdnControllersBlock();
    QString buildHostsBlock();
    QString buildSwitchesBlock();
    QString buildLinksBlock();
    QString buildStartingBlock();

    QString buildFunctionEndBlock();
    QString buildStartupBlock();

private:
    PortMatrix portMatrix;
};

#endif // MININETSCRIPTBUILDER_H
