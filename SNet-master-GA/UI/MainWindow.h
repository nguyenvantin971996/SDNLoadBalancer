#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPoint>
#include "NetworkMapView.h"
#include <QActionGroup>
#include "tablemetric.h"
namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionSdnController_triggered();
    void on_actionHost_triggered();
    void on_actionSwitch_triggered();
    void on_actionLink_triggered();
    void on_actionText_triggered();
    void on_actionEdit_triggered();

    void mouseLeftButtonReleaseEventOccured(QPoint cursorPosition);
    void mouseLeftButtonPressEventOccured(QPoint cursorPosition);
    void mouseMoveEventOccured(QPoint cursorPosition);
    void mouseDoubleClickEvent(QPoint cursorPosition);

    void on_actionShowPorts_triggered(bool checked);
    void on_actionDisplayDelay_triggered();
    void on_actionDisplayBandwidth_triggered();
    void on_actionDisplayPacketLoss_triggered();

    void on_actionNew_triggered();
    void on_actionSaveAs_triggered();
    void on_actionSave_triggered();
    void on_actionOpen_triggered();

    void on_actionCreateMnDataFile_triggered();
    void on_actionMake_Full_Connection_triggered();

    void on_actionExit_triggered();
    void on_actionWeights_Matrix_triggered();

    void on_actionAlign_Horizontally_triggered();
    void on_actionAlign_Vertically_triggered();

    void on_actionRemove_Marks_triggered();

    void on_actionCreate_optimal_path_triggered();

    void on_actionNN_GA_triggered();

    void on_actionRandomMetric_triggered();

    void on_actionNN_GA_8_8_8_triggered();

    void on_actionNN_ABC_8_8_8_triggered();

    void on_actionShow_results_triggered();

    void on_actionShow_chart_triggered();

signals:
    void signalConnectSdnController();
    void signalClearNetworkMap();

    void signalHandleMouseReleaseEvent(QPoint);
    void signalHandleMousePressEvent(QPoint);
    void signalHandleMouseMoveEvent(QPoint);
    void signalHandleDoubleClickEvent(QPoint);
    void signalHandleKeyDeletePressEvent();

    void signalChangeStateToEdit();
    void signalPrepareSdnController();
    void signalPrepareHost();
    void signalPrepareSwitch();
    void signalPrepareLink();
    void signalPrepareTextLabel();

    void signalShowPorts(bool);
    void signalShowBandwidth();
    void signalShowDelay();
    void signalShowPacketLossRate();

    void signalCreateMininetScript(QString);
    void signalCreateWeightMatrix(QString);
    void signalRandomMetric();

    void loadRoutes(QString);
    void showRoute(int);
    void hideRoute(int);

    void signalSaveNetworkMap(QString);
    void signalLoadNetworkMap(QString);

    void signalAlignVertically();
    void signalAlignHorizontally();

    void signalRemoveMarks();
    void signalVisualizePath(QList<int>);
    void signalVisualizePaths(QList<QList<int>>);

public slots:
    void refreshNetworkMapView(QPixmap);
    void showMessage(QString message);

private:
    Ui::MainWindow *ui;
    QActionGroup *metricGroupInMenu;
    QActionGroup *toolsGroupInMenu;
    QActionGroup *instrumentGroupInMenu;
    QActionGroup *toolsGroup;
    QAction *actionSdnController;
    QAction *actionHost;
    QAction *actionSwitch;
    QAction *actionLink;
    QAction *actionEdit;
    QAction *actionText;
    QString openedFilePath;
    TableMetric *tablemetric;
    QToolBar *toolsToolBar;
    QToolBar *utilitiesToolBar;

private:
    void setupComponents();
    void setupInstrumentsToolBar();
    void setupUtilitiesToolBar();
    void prepareTerminal();
    QString getFileNameFromOpenedFilePath();
    void updateWindowTitle();

protected:
    virtual void keyPressEvent(QKeyEvent *event);
};

#endif // MAINWINDOW_H
