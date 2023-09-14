/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>
#include "NetworkMapView.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionExit;
    QAction *actionCreateMnDataFile;
    QAction *actionShowPorts;
    QAction *actionCreateNetworkMap;
    QAction *actionSave;
    QAction *actionSaveAs;
    QAction *actionDisplayDelay;
    QAction *actionDisplayBandwidth;
    QAction *actionDisplayPacketLoss;
    QAction *actionHost;
    QAction *actionSwitch;
    QAction *actionLink;
    QAction *actionCreate;
    QAction *actionDelete;
    QAction *actionMove;
    QAction *actionEdit;
    QAction *actionSdnController;
    QAction *actionMake_Full_Connection;
    QAction *actionNew;
    QAction *actionText;
    QAction *actionWeights_Matrix;
    QAction *actionAlign_Vertically;
    QAction *actionAlign_Horizontally;
    QAction *actionRemove_Marks;
    QAction *actionCreate_optimal_path;
    QAction *actionNN_ABC_8_8_8;
    QAction *actionRandomMetric;
    QAction *actionNN_GA_8_8_8;
    QAction *actionShow_results;
    QAction *actionShow_chart;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollContents;
    QGridLayout *gridLayout_2;
    NetworkMapView *networkMapView;
    QTextBrowser *terminal;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuConverter;
    QMenu *menuOptions;
    QMenu *menuShow_metric;
    QMenu *menuInstruments;
    QMenu *menuActions;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->resize(1000, 649);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMaximumSize(QSize(16777215, 16777215));
        MainWindow->setContextMenuPolicy(Qt::ActionsContextMenu);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/controller.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionCreateMnDataFile = new QAction(MainWindow);
        actionCreateMnDataFile->setObjectName(QString::fromUtf8("actionCreateMnDataFile"));
        actionShowPorts = new QAction(MainWindow);
        actionShowPorts->setObjectName(QString::fromUtf8("actionShowPorts"));
        actionShowPorts->setCheckable(true);
        actionCreateNetworkMap = new QAction(MainWindow);
        actionCreateNetworkMap->setObjectName(QString::fromUtf8("actionCreateNetworkMap"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionSaveAs = new QAction(MainWindow);
        actionSaveAs->setObjectName(QString::fromUtf8("actionSaveAs"));
        actionDisplayDelay = new QAction(MainWindow);
        actionDisplayDelay->setObjectName(QString::fromUtf8("actionDisplayDelay"));
        actionDisplayDelay->setCheckable(true);
        actionDisplayDelay->setChecked(true);
        actionDisplayBandwidth = new QAction(MainWindow);
        actionDisplayBandwidth->setObjectName(QString::fromUtf8("actionDisplayBandwidth"));
        actionDisplayBandwidth->setCheckable(true);
        actionDisplayBandwidth->setChecked(false);
        actionDisplayPacketLoss = new QAction(MainWindow);
        actionDisplayPacketLoss->setObjectName(QString::fromUtf8("actionDisplayPacketLoss"));
        actionDisplayPacketLoss->setCheckable(true);
        actionHost = new QAction(MainWindow);
        actionHost->setObjectName(QString::fromUtf8("actionHost"));
        actionHost->setCheckable(true);
        actionHost->setChecked(false);
        actionSwitch = new QAction(MainWindow);
        actionSwitch->setObjectName(QString::fromUtf8("actionSwitch"));
        actionSwitch->setCheckable(true);
        actionLink = new QAction(MainWindow);
        actionLink->setObjectName(QString::fromUtf8("actionLink"));
        actionLink->setCheckable(true);
        actionCreate = new QAction(MainWindow);
        actionCreate->setObjectName(QString::fromUtf8("actionCreate"));
        actionCreate->setCheckable(true);
        actionCreate->setChecked(true);
        actionDelete = new QAction(MainWindow);
        actionDelete->setObjectName(QString::fromUtf8("actionDelete"));
        actionDelete->setCheckable(true);
        actionMove = new QAction(MainWindow);
        actionMove->setObjectName(QString::fromUtf8("actionMove"));
        actionMove->setCheckable(true);
        actionEdit = new QAction(MainWindow);
        actionEdit->setObjectName(QString::fromUtf8("actionEdit"));
        actionEdit->setCheckable(true);
        actionEdit->setChecked(true);
        actionSdnController = new QAction(MainWindow);
        actionSdnController->setObjectName(QString::fromUtf8("actionSdnController"));
        actionSdnController->setCheckable(true);
        actionSdnController->setChecked(false);
        actionMake_Full_Connection = new QAction(MainWindow);
        actionMake_Full_Connection->setObjectName(QString::fromUtf8("actionMake_Full_Connection"));
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionText = new QAction(MainWindow);
        actionText->setObjectName(QString::fromUtf8("actionText"));
        actionWeights_Matrix = new QAction(MainWindow);
        actionWeights_Matrix->setObjectName(QString::fromUtf8("actionWeights_Matrix"));
        actionAlign_Vertically = new QAction(MainWindow);
        actionAlign_Vertically->setObjectName(QString::fromUtf8("actionAlign_Vertically"));
        actionAlign_Horizontally = new QAction(MainWindow);
        actionAlign_Horizontally->setObjectName(QString::fromUtf8("actionAlign_Horizontally"));
        actionRemove_Marks = new QAction(MainWindow);
        actionRemove_Marks->setObjectName(QString::fromUtf8("actionRemove_Marks"));
        actionCreate_optimal_path = new QAction(MainWindow);
        actionCreate_optimal_path->setObjectName(QString::fromUtf8("actionCreate_optimal_path"));
        actionNN_ABC_8_8_8 = new QAction(MainWindow);
        actionNN_ABC_8_8_8->setObjectName(QString::fromUtf8("actionNN_ABC_8_8_8"));
        actionRandomMetric = new QAction(MainWindow);
        actionRandomMetric->setObjectName(QString::fromUtf8("actionRandomMetric"));
        actionNN_GA_8_8_8 = new QAction(MainWindow);
        actionNN_GA_8_8_8->setObjectName(QString::fromUtf8("actionNN_GA_8_8_8"));
        actionNN_GA_8_8_8->setCheckable(false);
        actionShow_results = new QAction(MainWindow);
        actionShow_results->setObjectName(QString::fromUtf8("actionShow_results"));
        actionShow_chart = new QAction(MainWindow);
        actionShow_chart->setObjectName(QString::fromUtf8("actionShow_chart"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy1);
        scrollArea->setWidgetResizable(true);
        scrollContents = new QWidget();
        scrollContents->setObjectName(QString::fromUtf8("scrollContents"));
        scrollContents->setGeometry(QRect(0, 0, 1366, 1024));
        gridLayout_2 = new QGridLayout(scrollContents);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        networkMapView = new NetworkMapView(scrollContents);
        networkMapView->setObjectName(QString::fromUtf8("networkMapView"));
        sizePolicy1.setHeightForWidth(networkMapView->sizePolicy().hasHeightForWidth());
        networkMapView->setSizePolicy(sizePolicy1);
        networkMapView->setMinimumSize(QSize(1366, 1024));
        networkMapView->setMouseTracking(false);
        networkMapView->setContextMenuPolicy(Qt::NoContextMenu);
        networkMapView->setTextInteractionFlags(Qt::NoTextInteraction);

        gridLayout_2->addWidget(networkMapView, 0, 0, 1, 1);

        scrollArea->setWidget(scrollContents);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 1);

        terminal = new QTextBrowser(centralWidget);
        terminal->setObjectName(QString::fromUtf8("terminal"));
        terminal->setMaximumSize(QSize(16777215, 200));

        gridLayout->addWidget(terminal, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1000, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuConverter = new QMenu(menuBar);
        menuConverter->setObjectName(QString::fromUtf8("menuConverter"));
        menuOptions = new QMenu(menuBar);
        menuOptions->setObjectName(QString::fromUtf8("menuOptions"));
        menuShow_metric = new QMenu(menuOptions);
        menuShow_metric->setObjectName(QString::fromUtf8("menuShow_metric"));
        menuInstruments = new QMenu(menuBar);
        menuInstruments->setObjectName(QString::fromUtf8("menuInstruments"));
        menuActions = new QMenu(menuBar);
        menuActions->setObjectName(QString::fromUtf8("menuActions"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuConverter->menuAction());
        menuBar->addAction(menuInstruments->menuAction());
        menuBar->addAction(menuActions->menuAction());
        menuBar->addAction(menuOptions->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSaveAs);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuConverter->addAction(actionCreateMnDataFile);
        menuConverter->addAction(actionWeights_Matrix);
        menuOptions->addAction(actionShowPorts);
        menuOptions->addAction(menuShow_metric->menuAction());
        menuOptions->addAction(actionRandomMetric);
        menuOptions->addAction(actionShow_results);
        menuOptions->addAction(actionShow_chart);
        menuShow_metric->addAction(actionDisplayDelay);
        menuShow_metric->addAction(actionDisplayBandwidth);
        menuShow_metric->addAction(actionDisplayPacketLoss);
        menuInstruments->addAction(actionSdnController);
        menuInstruments->addAction(actionSwitch);
        menuInstruments->addAction(actionHost);
        menuInstruments->addAction(actionLink);
        menuInstruments->addAction(actionText);
        menuInstruments->addAction(actionEdit);
        menuActions->addAction(actionMake_Full_Connection);
        menuActions->addAction(actionAlign_Vertically);
        menuActions->addAction(actionAlign_Horizontally);
        menuActions->addAction(actionRemove_Marks);
        menuActions->addAction(actionCreate_optimal_path);
        menuActions->addAction(actionNN_ABC_8_8_8);
        menuActions->addAction(actionNN_GA_8_8_8);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "SDNLoadBalancer", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open ...", nullptr));
#if QT_CONFIG(shortcut)
        actionOpen->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        actionCreateMnDataFile->setText(QCoreApplication::translate("MainWindow", "Mininet Script ...", nullptr));
#if QT_CONFIG(shortcut)
        actionCreateMnDataFile->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+M", nullptr));
#endif // QT_CONFIG(shortcut)
        actionShowPorts->setText(QCoreApplication::translate("MainWindow", "Show ports", nullptr));
#if QT_CONFIG(shortcut)
        actionShowPorts->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+P", nullptr));
#endif // QT_CONFIG(shortcut)
        actionCreateNetworkMap->setText(QCoreApplication::translate("MainWindow", "Network Map ...", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
#if QT_CONFIG(shortcut)
        actionSave->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSaveAs->setText(QCoreApplication::translate("MainWindow", "Save as ...", nullptr));
        actionDisplayDelay->setText(QCoreApplication::translate("MainWindow", "Delay", nullptr));
#if QT_CONFIG(shortcut)
        actionDisplayDelay->setShortcut(QCoreApplication::translate("MainWindow", "Shift+D", nullptr));
#endif // QT_CONFIG(shortcut)
        actionDisplayBandwidth->setText(QCoreApplication::translate("MainWindow", "Bandwidth", nullptr));
#if QT_CONFIG(shortcut)
        actionDisplayBandwidth->setShortcut(QCoreApplication::translate("MainWindow", "Shift+B", nullptr));
#endif // QT_CONFIG(shortcut)
        actionDisplayPacketLoss->setText(QCoreApplication::translate("MainWindow", "Packet Loss Rate", nullptr));
#if QT_CONFIG(shortcut)
        actionDisplayPacketLoss->setShortcut(QCoreApplication::translate("MainWindow", "Shift+P", nullptr));
#endif // QT_CONFIG(shortcut)
        actionHost->setText(QCoreApplication::translate("MainWindow", "Host", nullptr));
#if QT_CONFIG(shortcut)
        actionHost->setShortcut(QCoreApplication::translate("MainWindow", "H", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSwitch->setText(QCoreApplication::translate("MainWindow", "Switch", nullptr));
#if QT_CONFIG(shortcut)
        actionSwitch->setShortcut(QCoreApplication::translate("MainWindow", "S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionLink->setText(QCoreApplication::translate("MainWindow", "Link", nullptr));
#if QT_CONFIG(shortcut)
        actionLink->setShortcut(QCoreApplication::translate("MainWindow", "L", nullptr));
#endif // QT_CONFIG(shortcut)
        actionCreate->setText(QCoreApplication::translate("MainWindow", "Create", nullptr));
        actionDelete->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        actionMove->setText(QCoreApplication::translate("MainWindow", "Move", nullptr));
        actionEdit->setText(QCoreApplication::translate("MainWindow", "Edit", nullptr));
#if QT_CONFIG(shortcut)
        actionEdit->setShortcut(QCoreApplication::translate("MainWindow", "E", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSdnController->setText(QCoreApplication::translate("MainWindow", "Controller", nullptr));
#if QT_CONFIG(shortcut)
        actionSdnController->setShortcut(QCoreApplication::translate("MainWindow", "C", nullptr));
#endif // QT_CONFIG(shortcut)
        actionMake_Full_Connection->setText(QCoreApplication::translate("MainWindow", "Full Connection", nullptr));
#if QT_CONFIG(shortcut)
        actionMake_Full_Connection->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+F", nullptr));
#endif // QT_CONFIG(shortcut)
        actionNew->setText(QCoreApplication::translate("MainWindow", "New", nullptr));
#if QT_CONFIG(shortcut)
        actionNew->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionText->setText(QCoreApplication::translate("MainWindow", "Text", nullptr));
#if QT_CONFIG(shortcut)
        actionText->setShortcut(QCoreApplication::translate("MainWindow", "T", nullptr));
#endif // QT_CONFIG(shortcut)
        actionWeights_Matrix->setText(QCoreApplication::translate("MainWindow", "Metric Data ...", nullptr));
        actionAlign_Vertically->setText(QCoreApplication::translate("MainWindow", "Align Vertically", nullptr));
#if QT_CONFIG(shortcut)
        actionAlign_Vertically->setShortcut(QCoreApplication::translate("MainWindow", "Shift+V", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAlign_Horizontally->setText(QCoreApplication::translate("MainWindow", "Align Horizontally", nullptr));
#if QT_CONFIG(shortcut)
        actionAlign_Horizontally->setShortcut(QCoreApplication::translate("MainWindow", "Shift+H", nullptr));
#endif // QT_CONFIG(shortcut)
        actionRemove_Marks->setText(QCoreApplication::translate("MainWindow", "Remove Marks", nullptr));
        actionCreate_optimal_path->setText(QCoreApplication::translate("MainWindow", "Create paths", nullptr));
        actionNN_ABC_8_8_8->setText(QCoreApplication::translate("MainWindow", "NN+ABC+8-8-8", nullptr));
        actionRandomMetric->setText(QCoreApplication::translate("MainWindow", "RandomMetric", nullptr));
        actionNN_GA_8_8_8->setText(QCoreApplication::translate("MainWindow", "NN+GA+8-8-8", nullptr));
        actionShow_results->setText(QCoreApplication::translate("MainWindow", "Show results", nullptr));
        actionShow_chart->setText(QCoreApplication::translate("MainWindow", "Show chart", nullptr));
        networkMapView->setText(QString());
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuConverter->setTitle(QCoreApplication::translate("MainWindow", "Export", nullptr));
        menuOptions->setTitle(QCoreApplication::translate("MainWindow", "Options", nullptr));
        menuShow_metric->setTitle(QCoreApplication::translate("MainWindow", "Show metric", nullptr));
        menuInstruments->setTitle(QCoreApplication::translate("MainWindow", "Tools", nullptr));
        menuActions->setTitle(QCoreApplication::translate("MainWindow", "Actions", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
