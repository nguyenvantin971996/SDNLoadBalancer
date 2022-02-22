#-------------------------------------------------
#
# Project created by QtCreator 2016-02-20T20:42:35
#
#-------------------------------------------------

QT       += core gui \
            xml \
            network \
            charts \

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++11

TARGET = SNet
TEMPLATE = app


SOURCES += main.cpp \
    Core/Export/XmlSerializer.cpp \
    Core/Map/Search/SearchEngine.cpp \
    UI/LinkDialog.cpp \
    Core/Map/NetworkMap.cpp \
    Core/Tools/ElementEditor.cpp \
    Core/Tools/LinkCreator.cpp \
    Core/Tools/NodeCreator.cpp \
    Core/Tools/ConnectionClassifier.cpp \
    Core/Export/MininetScriptBuilder.cpp \
    Core/Import/XmlDeserializer.cpp \
    Core/Map/Nodes/TextLabel.cpp \
    UI/TextLabelDialog.cpp \
    Core/Map/Nodes/SdnController.cpp \
    Core/Map/Drawing/NetworkMapDrawer.cpp \
    Core/Map/SelectionFrame.cpp \
    Network/TcpServer.cpp \
    Core/Map/Links/CSLink.cpp \
    Network/PathDecoder.cpp \
    Core/Map/Element.cpp \
    Core/Map/Links/Link.cpp \
    Core/Map/Nodes/Node.cpp \
    Core/Map/Nodes/Switch/Switch.cpp \
    Core/Map/Nodes/Host.cpp \
    Core/Tools/Tool.cpp \
    UI/HostDialog.cpp \
    Core/Core.cpp \
    Utils/IO.cpp \
    UI/NetworkMapView.cpp \
    UI/MainWindow.cpp \
    UI/ControllerDialog.cpp \
    Core/Export/WeightsMatrix.cpp \
    Core/Map/Commutation/CommutationMatrix.cpp \
    Core/Map/Commutation/PortMatrix.cpp \
    Core/Map/Commutation/NodeConnector.cpp \
    Core/Map/Commutation/MatrixRepository.cpp \
    Core/Map/Drawing/DrawingMode.cpp \
    Network/CommandReceiver.cpp \
    Network/IslandsDecoder.cpp \
    Core/Map/Nodes/Switch/IslandPartSwitchState.cpp \
    Core/Map/Nodes/Switch/SelectedSwitchState.cpp \
    Core/Map/Nodes/Switch/SwitchState.cpp \
    Core/Map/Nodes/Switch/UnselectedSwitchState.cpp \
    Core/Map/Drawing/NetworkVisualizer.cpp \
    Core/Map/Links/SSLink/SSLink.cpp \
    Core/Map/Links/SSLink/SSLinkState.cpp \
    Core/Map/Links/SSLink/SelectedSSLinkState.cpp \
    Core/Map/Links/SSLink/UnselectedSSLinkState.cpp \
    Core/Map/Links/SSLink/IncludedInPathSSLinkState.cpp \
    Network/PathsDecoder.cpp \
    Core/Map/Links/SSLink/IncludedInPathsSSLinkState.cpp \
    Network/PairTransitionDecoder.cpp \
    Network/MetricDecoder.cpp \
    Network/TreeDecoder.cpp \
    Network/TreesDecoder.cpp \
    UI/tablemetric.cpp \

HEADERS  += \
    Core/Export/XmlSerializer.h \
    Core/Map/Search/SearchEngine.h \
    UI/LinkDialog.h \
    Core/Map/NetworkMap.h \
    Core/Tools/ElementEditor.h \
    Core/Tools/LinkCreator.h \
    Core/Tools/NodeCreator.h \
    Core/Tools/ConnectionClassifier.h \
    Core/Export/MininetScriptBuilder.h \
    Core/Import/XmlDeserializer.h \
    Core/Map/Nodes/TextLabel.h \
    UI/TextLabelDialog.h \
    Core/Map/Nodes/SdnController.h \
    Core/Map/Drawing/NetworkMapDrawer.h \
    Core/Map/SelectionFrame.h \
    Network/TcpServer.h \
    Core/Map/Links/CSLink.h \
    Network/PathDecoder.h \
    Core/Map/Element.h \
    Core/Map/Links/Link.h \
    Core/Map/Nodes/Node.h \
    Core/Map/Nodes/Switch/Switch.h \
    Core/Map/Nodes/Host.h \
    Core/Tools/Devicetype.h \
    Core/Tools/Tool.h \
    UI/HostDialog.h \
    Core/Core.h \
    Utils/IO.h \
    UI/NetworkMapView.h \
    UI/MainWindow.h \
    UI/ControllerDialog.h \
    Core/Export/WeightsMatrix.h \
    Core/Map/Commutation/CommutationMatrix.h \
    Core/Map/Commutation/PortMatrix.h \
    Core/Map/Commutation/NodeConnector.h \
    Core/Map/Commutation/MatrixRepository.h \
    Core/Map/Drawing/DrawingMode.h \
    Network/CommandReceiver.h \
    Network/IslandsDecoder.h \
    Core/Map/Nodes/Switch/SwitchState.h \
    Core/Map/Nodes/Switch/SelectedSwitchState.h \
    Core/Map/Nodes/Switch/UnselectedSwitchState.h \
    Core/Map/Nodes/Switch/IslandPartSwitchState.h \
    Core/Map/Drawing/NetworkVisualizer.h \
    Core/Map/Links/SSLink/SSLink.h \
    Core/Map/Links/SSLink/SSLinkState.h \
    Core/Map/Links/SSLink/SelectedSSLinkState.h \
    Core/Map/Links/SSLink/UnselectedSSLinkState.h \
    Core/Map/Links/SSLink/IncludedInPathSSLinkState.h \
    Network/PathsDecoder.h \
    Core/Map/Links/SSLink/IncludedInPathsSSLinkState.h \
    Network/PairTransitionDecoder.h \
    Network/MetricDecoder.h \
    Network/TreeDecoder.h \
    Network/TreesDecoder.h \
    UI/tablemetric.h \

FORMS    += $${_PRO_FILE_PWD_}/UI/mainwindow.ui \
            $${_PRO_FILE_PWD_}/UI/LinkDialog.ui \
            $${_PRO_FILE_PWD_}/UI/HostDialog.ui \
            $${_PRO_FILE_PWD_}/UI/TextLabelDialog.ui \
            $${_PRO_FILE_PWD_}/UI/ControllerDialog.ui \
            $${_PRO_FILE_PWD_}/UI/tablemetric.ui \

RESOURCES += images/img.qrc

INCLUDEPATH += $${_PRO_FILE_PWD_}/Utils \
               $${_PRO_FILE_PWD_}/Core \
               $${_PRO_FILE_PWD_}/Core/Export \
               $${_PRO_FILE_PWD_}/Core/Import \
               $${_PRO_FILE_PWD_}/Core/Tools \
               $${_PRO_FILE_PWD_}/Core/Map \
               $${_PRO_FILE_PWD_}/Core/Map/Commutation \
               $${_PRO_FILE_PWD_}/Core/Map/Nodes \
               $${_PRO_FILE_PWD_}/Core/Map/Nodes/Switch \
               $${_PRO_FILE_PWD_}/Core/Map/Links \
               $${_PRO_FILE_PWD_}/Core/Map/Links/SSLink \
               $${_PRO_FILE_PWD_}/Core/Map/Search \
               $${_PRO_FILE_PWD_}/Core/Map/Drawing \
               $${_PRO_FILE_PWD_}/UI \
               $${_PRO_FILE_PWD_}/Network
