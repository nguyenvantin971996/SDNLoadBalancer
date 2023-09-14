#include "MainWindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>
#include <QFileDialog>
#include <QTime>
#include "tablemetric.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>

QT_CHARTS_USE_NAMESPACE
MainWindow::MainWindow(QWidget * parent) :
    QMainWindow(parent), ui(new Ui::MainWindow), openedFilePath(QString())
{
    ui->setupUi(this);
    setupComponents();
    QObject::connect(ui->networkMapView,
                     SIGNAL(signalMouseLeftButtonReleased(QPoint)),
                     this,
                     SLOT(mouseLeftButtonReleaseEventOccured(QPoint)));
    QObject::connect(ui->networkMapView,
                     SIGNAL(signalMouseLeftButtonPressed(QPoint)),
                     this,
                     SLOT(mouseLeftButtonPressEventOccured(QPoint)));
    QObject::connect(ui->networkMapView,
                     SIGNAL(signalMouseMoved(QPoint)),
                     this,
                     SLOT(mouseMoveEventOccured(QPoint)));
    QObject::connect(ui->networkMapView,
                     SIGNAL(signalMouseDoubleClicked(QPoint)),
                     this,
                     SLOT(mouseDoubleClickEvent(QPoint)));
}

void MainWindow::setupComponents()
{
    metricGroupInMenu = new QActionGroup(this);
    toolsGroupInMenu = new QActionGroup(this);
    toolsGroup = new QActionGroup(this);
    metricGroupInMenu->addAction(ui->actionDisplayDelay);
    metricGroupInMenu->addAction(ui->actionDisplayBandwidth);
    metricGroupInMenu->addAction(ui->actionDisplayPacketLoss);
    toolsGroupInMenu->addAction(ui->actionSdnController);
    toolsGroupInMenu->addAction(ui->actionHost);
    toolsGroupInMenu->addAction(ui->actionSwitch);
    toolsGroupInMenu->addAction(ui->actionLink);
    toolsGroupInMenu->addAction(ui->actionEdit);

    setupInstrumentsToolBar();
    setupUtilitiesToolBar();
}

void MainWindow::setupInstrumentsToolBar()
{
    toolsToolBar = new QToolBar("toolsToolBar");
    toolsToolBar->setIconSize(QSize(64, 64));
    actionSdnController = toolsToolBar->addAction(QPixmap(":images/controller.png"), "Controller (C)", this, SLOT(on_actionSdnController_triggered()));
    actionSdnController->setCheckable(true);
    toolsGroup->addAction(actionSdnController);
    actionSwitch = toolsToolBar->addAction(QPixmap(":images/switch.png"), "Switch (S)", this, SLOT(on_actionSwitch_triggered()));
    actionSwitch->setCheckable(true);
    toolsGroup->addAction(actionSwitch);
    actionHost = toolsToolBar->addAction(QPixmap(":images/host.png"), "Host (H)", this, SLOT(on_actionHost_triggered()));
    actionHost->setCheckable(true);
    toolsGroup->addAction(actionHost);
    actionLink = toolsToolBar->addAction(QPixmap(":images/link.png"), "Link (L)", this, SLOT(on_actionLink_triggered()));
    actionLink->setCheckable(true);
    toolsGroup->addAction(actionLink);
    actionText = toolsToolBar->addAction(QPixmap(":images/text.png"), "Text (T)", this, SLOT(on_actionText_triggered()));
    actionText->setCheckable(true);
    toolsGroup->addAction(actionText);
    toolsToolBar->addSeparator();
    actionEdit = toolsToolBar->addAction(QPixmap(":images/edit.png"), "Edit (E)", this, SLOT(on_actionEdit_triggered()));
    actionEdit->setCheckable(true);
    actionEdit->setChecked(true);
    toolsGroup->addAction(actionEdit);
    addToolBar(Qt::LeftToolBarArea, toolsToolBar);
}

void MainWindow::setupUtilitiesToolBar()
{
    utilitiesToolBar = new QToolBar("utilitiesToolBar");
    utilitiesToolBar->setIconSize(QSize(64, 64));
    utilitiesToolBar->addAction(QPixmap(":images/new.png"), "New", this, SLOT(on_actionNew_triggered()));
    utilitiesToolBar->addAction(QPixmap(":images/open.png"), "Open...", this, SLOT(on_actionOpen_triggered()));
    utilitiesToolBar->addAction(QPixmap(":images/save.png"), "Save...", this, SLOT(on_actionSave_triggered()));
    utilitiesToolBar->addAction(QPixmap(":images/save_as.png"), "Save as...", this, SLOT(on_actionSaveAs_triggered()));
    utilitiesToolBar->addAction(QPixmap(":images/python.png"), "Export Mininet Script", this, SLOT(on_actionCreateMnDataFile_triggered()));
    utilitiesToolBar->addSeparator();
    utilitiesToolBar->addAction(QPixmap(":images/fullConnection.png"), "Full Connection", this, SLOT(on_actionMake_Full_Connection_triggered()));
    addToolBar(Qt::RightToolBarArea, utilitiesToolBar);
}

void MainWindow::prepareTerminal()
{
    ui->terminal->clear();
}

QString MainWindow::getFileNameFromOpenedFilePath()
{
    return openedFilePath.split("/").last();
}

void MainWindow::updateWindowTitle()
{
    this->setWindowTitle(QString("SDNLoadBalancer [") +
                         getFileNameFromOpenedFilePath() +
                         QString("]"));
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    int keyCode = event->key();
    switch(keyCode)
    {
        case Qt::Key_Delete:
            emit signalHandleKeyDeletePressEvent();
            break;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionSdnController_triggered()
{
    ui->actionSdnController->setChecked(true);
    actionSdnController->setChecked(true);
    emit signalPrepareSdnController();
}

void MainWindow::on_actionHost_triggered()
{
    ui->actionHost->setChecked(true);
    actionHost->setChecked(true);
    emit signalPrepareHost();
}

void MainWindow::on_actionSwitch_triggered()
{
    ui->actionSwitch->setChecked(true);
    actionSwitch->setChecked(true);
    emit signalPrepareSwitch();
}

void MainWindow::on_actionLink_triggered()
{
    ui->actionLink->setChecked(true);
    actionLink->setChecked(true);
    emit signalPrepareLink();
}

void MainWindow::on_actionEdit_triggered()
{
    ui->actionEdit->setChecked(true);
    actionEdit->setChecked(true);
    emit signalChangeStateToEdit();
}

void MainWindow::on_actionText_triggered()
{
    ui->actionText->setChecked(true);
    actionText->setChecked(true);
    emit signalPrepareTextLabel();
}

void MainWindow::on_actionShowPorts_triggered(bool checked)
{
    emit signalShowPorts(checked);
}

void MainWindow::on_actionDisplayDelay_triggered()
{
    emit signalShowDelay();
}

void MainWindow::on_actionDisplayBandwidth_triggered()
{
    emit signalShowBandwidth();
}

void MainWindow::on_actionDisplayPacketLoss_triggered()
{
    emit signalShowPacketLossRate();
}

void MainWindow::on_actionCreateMnDataFile_triggered()
{
    QString filePath = QFileDialog::getSaveFileName(this,
                                                    "Save MiniNet Script",
                                                    "../topo.py",
                                                    "Python files (*.py)");
    if (!filePath.isEmpty())
    {
        emit signalCreateMininetScript(filePath);
    }
}

void MainWindow::mouseLeftButtonReleaseEventOccured(QPoint cursorPosition)
{
    emit signalHandleMouseReleaseEvent(cursorPosition);
}

void MainWindow::mouseLeftButtonPressEventOccured(QPoint cursorPosition)
{
    emit signalHandleMousePressEvent(mapFrom(this, cursorPosition));
}

void MainWindow::mouseMoveEventOccured(QPoint cursorPosition)
{
    emit signalHandleMouseMoveEvent(cursorPosition);
}

void MainWindow::mouseDoubleClickEvent(QPoint cursorPosition)
{
    emit signalHandleDoubleClickEvent(cursorPosition);
}

void MainWindow::refreshNetworkMapView(QPixmap image)
{
    ui->networkMapView->refresh(image);
}

void MainWindow::showMessage(QString message)
{
    ui->terminal->append(QTime::currentTime().toString() +
                         QString(" [Controller] ") + message);
}

void MainWindow::on_actionSaveAs_triggered()
{
    openedFilePath = QFileDialog::getSaveFileName(this,
                                                  "Save topology",
                                                  "../topology.sdn.xml",
                                                  "Xml files (*.xml)");
    if (!openedFilePath.isEmpty())
    {
        emit signalSaveNetworkMap(openedFilePath);
        updateWindowTitle();
    }
}

void MainWindow::on_actionSave_triggered()
{
    if (openedFilePath.isEmpty())
    {
        on_actionSaveAs_triggered();
    }
    else
    {
        emit signalSaveNetworkMap(openedFilePath);
        updateWindowTitle();
    }
}

void MainWindow::on_actionOpen_triggered()
{
    openedFilePath = QFileDialog::getOpenFileName(this,
                                                  "Open topology file",
                                                  "../topology.sdn.xml",
                                                  "Xml files (*.xml)");
    if (!openedFilePath.isEmpty())
    {
        emit signalLoadNetworkMap(openedFilePath);
        updateWindowTitle();
    }
}

void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::on_actionMake_Full_Connection_triggered()
{
    emit signalConnectSdnController();
}

void MainWindow::on_actionNew_triggered()
{
    openedFilePath = QString();
    updateWindowTitle();
    emit signalClearNetworkMap();
}

void MainWindow::on_actionWeights_Matrix_triggered()
{
    QString filePath = QFileDialog::getSaveFileName(this,
                                                    "Save Metric Data",
                                                    "../metric_data.txt",
                                                    "Text files (*.txt)");
    if (!filePath.isEmpty())
    {
        emit signalCreateWeightMatrix(filePath);
    }
}

void MainWindow::on_actionAlign_Horizontally_triggered()
{
    emit signalAlignHorizontally();
}

void MainWindow::on_actionAlign_Vertically_triggered()
{
    emit signalAlignVertically();
}

void MainWindow::on_actionRemove_Marks_triggered()
{
    emit signalRemoveMarks();
}

void MainWindow::on_actionCreate_optimal_path_triggered()
{
    QList<QList<int>> paths;
    QString filename="../demo.txt";
        QFile file(filename);
        if(!file.open(QIODevice::ReadOnly)) {
            QMessageBox::information(0, "error", file.errorString());
        }
        QTextStream in(&file);
        int i=1;
        while(!in.atEnd()){
            QString line = in.readLine();
            QString pathOutPut = "Path[";
            QString ii = QString::number(i);
            pathOutPut = pathOutPut +ii+"]: ";
            QStringList linelist;
            QList<int> path;
            linelist = line.split(",");
            for(int x=0;x<=linelist.count()-2;x++)
            {
                path.append(linelist.at(x).toInt());
                pathOutPut=pathOutPut+" "+linelist.at(x);
            }
            pathOutPut=pathOutPut+" with cost: "+linelist.at(linelist.count()-1);
            ui->terminal->append(pathOutPut);
            paths.append(path);
            i++;
        }
        ui->terminal->append("==============================================================");
        file.close();
        emit signalVisualizePaths(paths);
}

void MainWindow::on_actionNN_GA_triggered()
{
    QString pathss = "..";
       QString  command("python");
       QStringList params = QStringList() << "12_12.py";

       QProcess *process = new QProcess();
       process->startDetached(command, params, pathss);
       process->waitForFinished();
       process->close();
       QMessageBox msgBox;
       msgBox.setText("Prediction path has been finished!!!");
       msgBox.exec();
}


void MainWindow::on_actionRandomMetric_triggered()
{
    emit signalRemoveMarks();
    emit signalRandomMetric();
}


void MainWindow::on_actionNN_GA_8_8_8_triggered()
{
    QString pathss = "..";
       QString  command("python");
       QStringList params = QStringList() << "NN_GA_8_8_8.py";

       QProcess *process = new QProcess();
       process->startDetached(command, params, pathss);
       process->waitForFinished();
       process->close();
       QMessageBox msgBox;
       msgBox.setText("Prediction path has been finished!!!");
       msgBox.exec();
}


void MainWindow::on_actionNN_ABC_8_8_8_triggered()
{
    QString pathss = "..";
       QString  command("python");
       QStringList params = QStringList() << "NN_ABC_8_8_8.py";

       QProcess *process = new QProcess();
       process->startDetached(command, params, pathss);
       process->waitForFinished();
       process->close();
       QMessageBox msgBox;
       msgBox.setText("Prediction path has been finished!!!");
       msgBox.exec();
}


void MainWindow::on_actionShow_results_triggered()
{
    tablemetric = new TableMetric(this);
    tablemetric->show();
}

void MainWindow::on_actionShow_chart_triggered()
{
    QMainWindow *window = new QMainWindow(this);
    QWidget *pic = new QWidget(this);
    openedFilePath = QFileDialog::getOpenFileName(this,
                                                  "Open file",
                                                  "../*.png",
                                                  "Image files (*.png)");
    if (!openedFilePath.isEmpty())
    {
        QString st = "image: url("+openedFilePath+")";
        pic->setStyleSheet(st);
        window->setCentralWidget(pic);
        window->resize(1000, 1000);
        window->show();
    }
}
