#include "tablemetric.h"
#include "ui_tablemetric.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <math.h>
#include <QToolTip>
TableMetric::TableMetric(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TableMetric)
{
    ui->setupUi(this);
    QString Parameters[3];
    QString Hyperparameters[3];
//    QString running_time[3];
    QList<QList<QString>> Acc;
    QString filename="../wires.txt";
    QFile file(filename);
    QString col_0 = "Type of recurrent neural network";
    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(0, "error", file.errorString());
    }
    QTextStream in(&file);
    int u1 = -1;
    int u2 = -1;
    int u3 = -1;
    while(!in.atEnd())
    {
        QString line = in.readLine();
        QStringList linelist;
        linelist = line.split(",");
        if(line[0]=="N")
        {
            col_0 = "Parameters";
        }
        if(line[0]=="[")
        {
            u2++;
            Hyperparameters[u2] = line;
            continue;
        }
        if(line[0]=="A" || line[0]=="G" || line[0]=="S" || line[0]=="L")
        {
            u1++;
            for(int x=0;x<=linelist.count()-1;x++)
            {
                Parameters[u1] = Parameters[u1] + "\n" + linelist[x];
            }
            continue;
        }
//        else if(linelist.count()==1)
//        {
//            u3++;
//            running_time[u3] = line;
//            continue;
//        }
        else
        {
            QList<QString> w;
            for(int x=0;x<=linelist.count()-1;x++)
            {
                w.append(linelist[x]);
            }
            Acc.append(w);
        }
    }

    int num_row = 5;
    ui->tableWidget->setRowCount(num_row);
//    ui->tableWidget->setColumnCount(13);
    ui->tableWidget->setColumnCount(12);
    ui->tableWidget->setSpan(0, 0, 2, 1);
    ui->tableWidget->setSpan(0, 1, 2, 1);
//    ui->tableWidget->setSpan(0, 12, 2, 1);
    ui->tableWidget->setSpan(0, 2, 1, 5);
    ui->tableWidget->setSpan(0, 7, 1, 5);
    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->horizontalHeader()->setVisible(false);
    QTableWidgetItem *item = new QTableWidgetItem(col_0);
    item->setTextAlignment( Qt::AlignCenter);
    ui->tableWidget->setItem(0, 0, item);
    QTableWidgetItem *itemh = new QTableWidgetItem("Found hyperparameters");
    itemh->setTextAlignment( Qt::AlignCenter);
    ui->tableWidget->setItem(0, 1, itemh);
    QTableWidgetItem *item2 = new QTableWidgetItem("Training accuracy (%)");
    item2->setTextAlignment( Qt::AlignCenter);
    ui->tableWidget->setItem(0, 2, item2);
    QTableWidgetItem *item3 = new QTableWidgetItem("Testing accuracy (%)");
    item3->setTextAlignment( Qt::AlignCenter);
    ui->tableWidget->setItem(0, 7, item3);
//    QTableWidgetItem *item4 = new QTableWidgetItem("Running time (s)");
//    item4->setTextAlignment( Qt::AlignCenter);
//    ui->tableWidget->setItem(0, 12, item4);
    QString pth[10] = {"Path 1", "Path 2", "Path 3", "Path 4", "All paths", "Path 1", "Path 2", "Path 3", "Path 4", "All paths"};
    for(int u=0;u<=9;u++)
        {
            QTableWidgetItem *item3 = new QTableWidgetItem(pth[u]);
            item3->setTextAlignment( Qt::AlignCenter);
            ui->tableWidget->setItem(1, u+2, item3);
        }
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setColumnWidth(0, 250);
    ui->tableWidget->setColumnWidth(1, 350);
//    ui->tableWidget->setColumnWidth(12, 150);
    for(int u=2;u<=11;u++)
    {
        ui->tableWidget->setColumnWidth(u, 80);
    }
    for(int u=2;u<=4;u++)
    {
        QTableWidgetItem *item = new QTableWidgetItem(Parameters[u-2]);
        item->setTextAlignment( Qt::AlignCenter);
        ui->tableWidget->setItem(u, 0, item);
        QTableWidgetItem *itemm = new QTableWidgetItem(Hyperparameters[u-2]);
        itemm->setTextAlignment( Qt::AlignCenter);
        ui->tableWidget->setItem(u, 1, itemm);
//        QTableWidgetItem *itemr = new QTableWidgetItem(running_time[u-2]);
//        itemr->setTextAlignment( Qt::AlignCenter);
//        ui->tableWidget->setItem(u, 12, itemr);
        for(int k=2;k<=11;k++)
        {
            QTableWidgetItem *itm = new QTableWidgetItem(Acc[u-2][k-2]);
            itm->setTextAlignment( Qt::AlignCenter);
            ui->tableWidget->setItem(u, k, itm);
        }
    }
}

TableMetric::~TableMetric()
{
    delete ui;
}

void TableMetric::on_horizontalSlider_valueChanged(int value)
{

}
