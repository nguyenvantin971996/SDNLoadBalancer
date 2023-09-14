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
    int k_row = 6;
    QString N[k_row];
    QString Max[k_row];
    int K_paths[k_row];
    QList<double> Ds[k_row];
    QList<double> I[k_row];
    QList<double> AV[k_row];
    QList<double> SD[k_row];
    QList<double> MxVL[k_row];
    QList<double> MnVL[k_row];
    double J[k_row];
    double CD[k_row];
    double sum[k_row];
    QList<QList<double>> wires[k_row];
    QString filename="../wires.txt";
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(0, "error", file.errorString());
    }
    QTextStream in(&file);
    int u = -1;
    while(!in.atEnd())
    {
        QString line = in.readLine();
        QStringList linelist;
        linelist = line.split(",");
        if(line[0]=="a")
        {
            u++;
            N[u] = linelist[1];
            Max[u] = linelist[2];
            continue;
        }
        else
        {
            double s = 0;
            QList<double> w;
            for(int x=linelist.count()-1;x>=0;x--)
            {
                double r = linelist.at(x).toDouble();
                s+=r;
                w.append(r);
            }
            sum[u] += 1/s;
            CD[u] += s;
            Ds[u].append(s);
            wires[u].append(w);
        }
    }
    for(int u=0;u<=k_row-1;u++)
    {
        if(Ds[u][Ds[u].count()-2]==Ds[u][Ds[u].count()-1])
        {
            double ss = 0;
            for(int x=0;x<=Ds[u].count()-3;x++)
            {
                double t2 = 100*(1/Ds[u][x])/sum[u];
                t2 = round( t2 * 10.0 ) / 10.0;
                ss+=t2;
                I[u].append(t2);
            }

            double tt = round((100-ss)*10.0/2)/10.0;
            I[u].append(tt);
            I[u].append(100-ss-tt);
        }
        else
        {
            double ss = 0;
            for(int x=0;x<=Ds[u].count()-2;x++)
            {
                double t2 = 100*(1/Ds[u][x])/sum[u];
                t2 = round( t2 * 10.0 ) / 10.0;
                ss+=t2;
                I[u].append(t2);
            }

                I[u].append(100-ss);
        }
    }
    for(int u=0;u<=k_row-1;u++)
    {
        for(int x=0;x<=Ds[u].count()-1;x++)
        {
            double t3 = Ds[u][x]/(wires[u][x].count());
            t3 = round( t3 * 10.0 ) / 10.0;
            AV[u].append(t3);
        }
    }
    for(int u=0;u<=k_row-1;u++)
    {
        for(int x=0;x<=Ds[u].count()-1;x++)
        {
            double t4 = Ds[u][x]/(wires[u][x].count());
            double sum_2 = 0;
            for(int y=0;y<=wires[u][x].count()-1;y++)
            {
                sum_2+= (t4-wires[u][x][y])*(t4-wires[u][x][y]);
            }
            double sdd = sqrt(sum_2/(wires[u][x].count()));
            sdd = round( sdd * 10.0 ) / 10.0;
            SD[u].append(sdd);
        }
    }
    for(int u=0;u<=k_row-1;u++)
    {
        for(int x=0;x<=Ds[u].count()-1;x++)
        {
            double mx = 0;
            double mn = 99999;
            for(int y=0;y<=wires[u][x].count()-1;y++)
            {
                if(mx<=wires[u][x][y]){
                    mx = wires[u][x][y];
                };
                if(mn>=wires[u][x][y])
                {
                    mn = wires[u][x][y];
                }
            }
            MxVL[u].append(mx);
            MnVL[u].append(mn);
        }
    }
    for(int u=0;u<=k_row-1;u++)
    {
        double jj = (1-Ds[u][0]/Ds[u][Ds[u].count()-1])*100;
        J[u] = round( jj * 100.0 ) / 100.0;
    }
    int num_row = 0;
    for(int u=0;u<=k_row-1;u++)
    {
        num_row += Ds[u].count();
        K_paths[u] = Ds[u].count();
    }
    ui->tableWidget->setRowCount(num_row);
    ui->tableWidget->setColumnCount(11);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "N" << "Max" << "K_paths" << "CD" << "Ds" << "I, %" << "AV" << "SD"<< "MxVL" << "MnVL" << "J, %");
    ui->tableWidget->setSpan(0, 0, Ds[0].count()+Ds[1].count(), 1);
    ui->tableWidget->setSpan(0, 1, Ds[0].count(), 1);
    ui->tableWidget->setSpan(0, 2, Ds[0].count(), 1);
    ui->tableWidget->setSpan(0, 3, Ds[0].count(), 1);
    ui->tableWidget->setSpan(0, 10, Ds[0].count(), 1);
    ui->tableWidget->setSpan(Ds[0].count(), 1, Ds[1].count(), 1);
    ui->tableWidget->setSpan(Ds[0].count(), 2, Ds[1].count(), 1);
    ui->tableWidget->setSpan(Ds[0].count(), 3, Ds[1].count(), 1);
    ui->tableWidget->setSpan(Ds[0].count(), 10, Ds[1].count(), 1);
    ui->tableWidget->setSpan(Ds[0].count()+Ds[1].count(), 0, Ds[2].count()+Ds[3].count(), 1);
    ui->tableWidget->setSpan(Ds[0].count()+Ds[1].count(), 1, Ds[2].count(), 1);
    ui->tableWidget->setSpan(Ds[0].count()+Ds[1].count(), 2, Ds[2].count(), 1);
    ui->tableWidget->setSpan(Ds[0].count()+Ds[1].count(), 3, Ds[2].count(), 1);
    ui->tableWidget->setSpan(Ds[0].count()+Ds[1].count(), 10, Ds[2].count(), 1);
    ui->tableWidget->setSpan(Ds[0].count()+Ds[1].count()+Ds[2].count(), 1, Ds[3].count(), 1);
    ui->tableWidget->setSpan(Ds[0].count()+Ds[1].count()+Ds[2].count(), 2, Ds[3].count(), 1);
    ui->tableWidget->setSpan(Ds[0].count()+Ds[1].count()+Ds[2].count(), 3, Ds[3].count(), 1);
    ui->tableWidget->setSpan(Ds[0].count()+Ds[1].count()+Ds[2].count(), 10, Ds[3].count(), 1);
    ui->tableWidget->setSpan(Ds[0].count()+Ds[1].count()+Ds[2].count()+Ds[3].count(), 0, Ds[4].count()+Ds[5].count(), 1);
    ui->tableWidget->setSpan(Ds[0].count()+Ds[1].count()+Ds[2].count()+Ds[3].count(), 1, Ds[4].count(), 1);
    ui->tableWidget->setSpan(Ds[0].count()+Ds[1].count()+Ds[2].count()+Ds[3].count(), 2, Ds[4].count(), 1);
    ui->tableWidget->setSpan(Ds[0].count()+Ds[1].count()+Ds[2].count()+Ds[3].count(), 3, Ds[4].count(), 1);
    ui->tableWidget->setSpan(Ds[0].count()+Ds[1].count()+Ds[2].count()+Ds[3].count(), 10, Ds[4].count(), 1);
    ui->tableWidget->setSpan(Ds[0].count()+Ds[1].count()+Ds[2].count()+Ds[3].count()+Ds[4].count(), 1, Ds[5].count(), 1);
    ui->tableWidget->setSpan(Ds[0].count()+Ds[1].count()+Ds[2].count()+Ds[3].count()+Ds[4].count(), 2, Ds[5].count(), 1);
    ui->tableWidget->setSpan(Ds[0].count()+Ds[1].count()+Ds[2].count()+Ds[3].count()+Ds[4].count(), 3, Ds[5].count(), 1);
    ui->tableWidget->setSpan(Ds[0].count()+Ds[1].count()+Ds[2].count()+Ds[3].count()+Ds[4].count(), 10, Ds[5].count(), 1);
    int xxx = 0;
    for(int u=0;u<=k_row-1;u++)
    {
        QTableWidgetItem *item2 = new QTableWidgetItem(tr("%1").arg(N[u]));
        item2->setTextAlignment( Qt::AlignCenter );
        ui->tableWidget->setItem(xxx,0,item2);
        xxx+=Ds[u].count();
    }
    int xxx1 = 0;
    for(int u=0;u<=k_row-1;u++)
    {
        QTableWidgetItem *item2 = new QTableWidgetItem(tr("%1").arg(Max[u]));
        item2->setTextAlignment( Qt::AlignCenter );
        ui->tableWidget->setItem(xxx1,1,item2);
        xxx1+=Ds[u].count();
    }
    int xx = 0;
    for(int u=0;u<=k_row-1;u++)
    {
        QTableWidgetItem *item2 = new QTableWidgetItem(tr("%1").arg(K_paths[u]));
        item2->setTextAlignment( Qt::AlignCenter );
        ui->tableWidget->setItem(xx,2,item2);
        xx+=Ds[u].count();
    }
    int x1 = 0;
    for(int u=0;u<=k_row-1;u++)
    {
        QTableWidgetItem *item2 = new QTableWidgetItem(tr("%1").arg(CD[u]));
        item2->setTextAlignment( Qt::AlignCenter );
        ui->tableWidget->setItem(x1,3,item2);
        x1+=Ds[u].count();
    }
    QList<double> Ds_2;
    for(int u=0;u<=k_row-1;u++)
    {
        for(int x=0;x<=Ds[u].count()-1;x++)
        {
            Ds_2.append(Ds[u][x]);
        }
    }
    for(int j=0;j<ui->tableWidget->rowCount();j++)
    {
        QTableWidgetItem *itm = new QTableWidgetItem(tr("%1").arg(Ds_2[j]));
        itm->setTextAlignment( Qt::AlignCenter );
        ui->tableWidget->setItem(j,4,itm);
    }
    QList<double> I_2;
    for(int u=0;u<=k_row-1;u++)
    {
        for(int x=0;x<=I[u].count()-1;x++)
        {
            I_2.append(I[u][x]);
        }
    }
    for(int j=0;j<ui->tableWidget->rowCount();j++)
    {
        QTableWidgetItem *itm = new QTableWidgetItem(tr("%1").arg(I_2[j]));
        itm->setTextAlignment( Qt::AlignCenter );
        ui->tableWidget->setItem(j,5,itm);
    }
    QList<double> AV_2;
    for(int u=0;u<=k_row-1;u++)
    {
        for(int x=0;x<=AV[u].count()-1;x++)
        {
            AV_2.append(AV[u][x]);
        }
    }
    for(int j=0;j<ui->tableWidget->rowCount();j++)
    {
        QTableWidgetItem *itm = new QTableWidgetItem(tr("%1").arg(AV_2[j]));
        itm->setTextAlignment( Qt::AlignCenter );
        ui->tableWidget->setItem(j,6,itm);
    }
    QList<double> SD_2;
    for(int u=0;u<=k_row-1;u++)
    {
        for(int x=0;x<=SD[u].count()-1;x++)
        {
            SD_2.append(SD[u][x]);
        }
    }
    for(int j=0;j<ui->tableWidget->rowCount();j++)
    {
        QTableWidgetItem *itm = new QTableWidgetItem(tr("%1").arg(SD_2[j]));
        itm->setTextAlignment( Qt::AlignCenter );
        ui->tableWidget->setItem(j,7,itm);
    }

    QList<double> MxVL_2;
    for(int u=0;u<=k_row-1;u++)
    {
        for(int x=0;x<=MxVL[u].count()-1;x++)
        {
            MxVL_2.append(MxVL[u][x]);
        }
    }
    for(int j=0;j<ui->tableWidget->rowCount();j++)
    {
        QTableWidgetItem *itm = new QTableWidgetItem(tr("%1").arg(MxVL_2[j]));
        itm->setTextAlignment( Qt::AlignCenter );
        ui->tableWidget->setItem(j,8,itm);
    }

    QList<double> MnVL_2;
    for(int u=0;u<=k_row-1;u++)
    {
        for(int x=0;x<=MnVL[u].count()-1;x++)
        {
            MnVL_2.append(MnVL[u][x]);
        }
    }
    for(int j=0;j<ui->tableWidget->rowCount();j++)
    {
        QTableWidgetItem *itm = new QTableWidgetItem(tr("%1").arg(MnVL_2[j]));
        itm->setTextAlignment( Qt::AlignCenter );
        ui->tableWidget->setItem(j,9,itm);
    }
    int x2 = 0;
    for(int u=0;u<=k_row-1;u++)
    {
        QTableWidgetItem *item2 = new QTableWidgetItem(tr("%1").arg(J[u]));
        item2->setTextAlignment( Qt::AlignCenter );
        ui->tableWidget->setItem(x2,10,item2);
        x2+=Ds[u].count();
    }
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

TableMetric::~TableMetric()
{
    delete ui;
}

void TableMetric::on_horizontalSlider_valueChanged(int value)
{
    int k_row = 6;
    QString N[k_row];
    QString Max[k_row];
    int K_paths[k_row];
    QList<double> Ds[k_row];
    QList<double> I[k_row];
    QList<double> AV[k_row];
    QList<double> SD[k_row];
    QList<double> MxVL[k_row];
    QList<double> MnVL[k_row];
    double J[k_row];
    double CD[k_row];
    double sum[k_row];
    QList<QList<double>> wires[k_row];
    QString filename="../wires.txt";
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(0, "error", file.errorString());
    }
    QTextStream in(&file);
    int u = -1;
    while(!in.atEnd())
    {
        QString line = in.readLine();
        QStringList linelist;
        linelist = line.split(",");
        if(line[0]=="a")
        {
            u++;
            N[u] = linelist[1];
            Max[u] = linelist[2];
            continue;
        }
        else
        {
            double s = 0;
            QList<double> w;
            for(int x=linelist.count()-1;x>=0;x--)
            {
                double r = linelist.at(x).toDouble();
                s+=r;
                w.append(r);
            }
            if(Ds[u].count()!=0)
            {
                if(Ds[u].count()==value)
                {
                    continue;
                }
            }
            sum[u] += 1/s;
            CD[u] += s;
            Ds[u].append(s);
            wires[u].append(w);
        }
    }
    for(int u=0;u<=k_row-1;u++)
    {
        if(Ds[u][Ds[u].count()-2]==Ds[u][Ds[u].count()-1])
        {
            double ss = 0;
            for(int x=0;x<=Ds[u].count()-3;x++)
            {
                double t2 = 100*(1/Ds[u][x])/sum[u];
                t2 = round( t2 * 10.0 ) / 10.0;
                ss+=t2;
                I[u].append(t2);
            }

            double tt = round((100-ss)*10.0/2)/10.0;
            I[u].append(tt);
            I[u].append(100-ss-tt);
        }
        else
        {
            double ss = 0;
            for(int x=0;x<=Ds[u].count()-2;x++)
            {
                double t2 = 100*(1/Ds[u][x])/sum[u];
                t2 = round( t2 * 10.0 ) / 10.0;
                ss+=t2;
                I[u].append(t2);
            }

                I[u].append(100-ss);
        }
    }
    for(int u=0;u<=k_row-1;u++)
    {
        for(int x=0;x<=Ds[u].count()-1;x++)
        {
            double t3 = Ds[u][x]/(wires[u][x].count());
            t3 = round( t3 * 10.0 ) / 10.0;
            AV[u].append(t3);
        }
    }
    for(int u=0;u<=k_row-1;u++)
    {
        for(int x=0;x<=Ds[u].count()-1;x++)
        {
            double t4 = Ds[u][x]/(wires[u][x].count());
            double sum_2 = 0;
            for(int y=0;y<=wires[u][x].count()-1;y++)
            {
                sum_2+= (t4-wires[u][x][y])*(t4-wires[u][x][y]);
            }
            double sdd = sqrt(sum_2/(wires[u][x].count()));
            sdd = round( sdd * 10.0 ) / 10.0;
            SD[u].append(sdd);
        }
    }
    for(int u=0;u<=k_row-1;u++)
    {
        for(int x=0;x<=Ds[u].count()-1;x++)
        {
            double mx = 0;
            double mn = 99999;
            for(int y=0;y<=wires[u][x].count()-1;y++)
            {
                if(mx<=wires[u][x][y]){
                    mx = wires[u][x][y];
                };
                if(mn>=wires[u][x][y])
                {
                    mn = wires[u][x][y];
                }
            }
            MxVL[u].append(mx);
            MnVL[u].append(mn);
        }
    }
    for(int u=0;u<=k_row-1;u++)
    {
        double jj = (1-Ds[u][0]/Ds[u][Ds[u].count()-1])*100;
        J[u] = round( jj * 100.0 ) / 100.0;
    }
    int num_row = 0;
    for(int u=0;u<=k_row-1;u++)
    {
        num_row += Ds[u].count();
        K_paths[u] = Ds[u].count();
    }
    ui->tableWidget->setRowCount(num_row);
    ui->tableWidget->setColumnCount(11);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "N" << "Max" << "K_paths" << "CD" << "Ds" << "I, %" << "AV" << "SD"<< "MxVL" << "MnVL" << "J, %");
    ui->tableWidget->setSpan(0, 0, Ds[0].count()+Ds[1].count(), 1);
    ui->tableWidget->setSpan(0, 1, Ds[0].count(), 1);
    ui->tableWidget->setSpan(0, 2, Ds[0].count(), 1);
    ui->tableWidget->setSpan(0, 3, Ds[0].count(), 1);
    ui->tableWidget->setSpan(0, 10, Ds[0].count(), 1);
    ui->tableWidget->setSpan(Ds[0].count(), 1, Ds[1].count(), 1);
    ui->tableWidget->setSpan(Ds[0].count(), 2, Ds[1].count(), 1);
    ui->tableWidget->setSpan(Ds[0].count(), 3, Ds[1].count(), 1);
    ui->tableWidget->setSpan(Ds[0].count(), 10, Ds[1].count(), 1);
    ui->tableWidget->setSpan(Ds[0].count()+Ds[1].count(), 0, Ds[2].count()+Ds[3].count(), 1);
    ui->tableWidget->setSpan(Ds[0].count()+Ds[1].count(), 1, Ds[2].count(), 1);
    ui->tableWidget->setSpan(Ds[0].count()+Ds[1].count(), 2, Ds[2].count(), 1);
    ui->tableWidget->setSpan(Ds[0].count()+Ds[1].count(), 3, Ds[2].count(), 1);
    ui->tableWidget->setSpan(Ds[0].count()+Ds[1].count(), 10, Ds[2].count(), 1);
    ui->tableWidget->setSpan(Ds[0].count()+Ds[1].count()+Ds[2].count(), 1, Ds[3].count(), 1);
    ui->tableWidget->setSpan(Ds[0].count()+Ds[1].count()+Ds[2].count(), 2, Ds[3].count(), 1);
    ui->tableWidget->setSpan(Ds[0].count()+Ds[1].count()+Ds[2].count(), 3, Ds[3].count(), 1);
    ui->tableWidget->setSpan(Ds[0].count()+Ds[1].count()+Ds[2].count(), 10, Ds[3].count(), 1);
    ui->tableWidget->setSpan(Ds[0].count()+Ds[1].count()+Ds[2].count()+Ds[3].count(), 0, Ds[4].count()+Ds[5].count(), 1);
    ui->tableWidget->setSpan(Ds[0].count()+Ds[1].count()+Ds[2].count()+Ds[3].count(), 1, Ds[4].count(), 1);
    ui->tableWidget->setSpan(Ds[0].count()+Ds[1].count()+Ds[2].count()+Ds[3].count(), 2, Ds[4].count(), 1);
    ui->tableWidget->setSpan(Ds[0].count()+Ds[1].count()+Ds[2].count()+Ds[3].count(), 3, Ds[4].count(), 1);
    ui->tableWidget->setSpan(Ds[0].count()+Ds[1].count()+Ds[2].count()+Ds[3].count(), 10, Ds[4].count(), 1);
    ui->tableWidget->setSpan(Ds[0].count()+Ds[1].count()+Ds[2].count()+Ds[3].count()+Ds[4].count(), 1, Ds[5].count(), 1);
    ui->tableWidget->setSpan(Ds[0].count()+Ds[1].count()+Ds[2].count()+Ds[3].count()+Ds[4].count(), 2, Ds[5].count(), 1);
    ui->tableWidget->setSpan(Ds[0].count()+Ds[1].count()+Ds[2].count()+Ds[3].count()+Ds[4].count(), 3, Ds[5].count(), 1);
    ui->tableWidget->setSpan(Ds[0].count()+Ds[1].count()+Ds[2].count()+Ds[3].count()+Ds[4].count(), 10, Ds[5].count(), 1);
    int xxx = 0;
    for(int u=0;u<=k_row-1;u++)
    {
        QTableWidgetItem *item2 = new QTableWidgetItem(tr("%1").arg(N[u]));
        item2->setTextAlignment( Qt::AlignCenter );
        ui->tableWidget->setItem(xxx,0,item2);
        xxx+=Ds[u].count();
    }
    int xxx1 = 0;
    for(int u=0;u<=k_row-1;u++)
    {
        QTableWidgetItem *item2 = new QTableWidgetItem(tr("%1").arg(Max[u]));
        item2->setTextAlignment( Qt::AlignCenter );
        ui->tableWidget->setItem(xxx1,1,item2);
        xxx1+=Ds[u].count();
    }
    int xx = 0;
    for(int u=0;u<=k_row-1;u++)
    {
        QTableWidgetItem *item2 = new QTableWidgetItem(tr("%1").arg(K_paths[u]));
        item2->setTextAlignment( Qt::AlignCenter );
        ui->tableWidget->setItem(xx,2,item2);
        xx+=Ds[u].count();
    }
    int x1 = 0;
    for(int u=0;u<=k_row-1;u++)
    {
        QTableWidgetItem *item2 = new QTableWidgetItem(tr("%1").arg(CD[u]));
        item2->setTextAlignment( Qt::AlignCenter );
        ui->tableWidget->setItem(x1,3,item2);
        x1+=Ds[u].count();
    }
    QList<double> Ds_2;
    for(int u=0;u<=k_row-1;u++)
    {
        for(int x=0;x<=Ds[u].count()-1;x++)
        {
            Ds_2.append(Ds[u][x]);
        }
    }
    for(int j=0;j<ui->tableWidget->rowCount();j++)
    {
        QTableWidgetItem *itm = new QTableWidgetItem(tr("%1").arg(Ds_2[j]));
        itm->setTextAlignment( Qt::AlignCenter );
        ui->tableWidget->setItem(j,4,itm);
    }
    QList<double> I_2;
    for(int u=0;u<=k_row-1;u++)
    {
        for(int x=0;x<=I[u].count()-1;x++)
        {
            I_2.append(I[u][x]);
        }
    }
    for(int j=0;j<ui->tableWidget->rowCount();j++)
    {
        QTableWidgetItem *itm = new QTableWidgetItem(tr("%1").arg(I_2[j]));
        itm->setTextAlignment( Qt::AlignCenter );
        ui->tableWidget->setItem(j,5,itm);
    }
    QList<double> AV_2;
    for(int u=0;u<=k_row-1;u++)
    {
        for(int x=0;x<=AV[u].count()-1;x++)
        {
            AV_2.append(AV[u][x]);
        }
    }
    for(int j=0;j<ui->tableWidget->rowCount();j++)
    {
        QTableWidgetItem *itm = new QTableWidgetItem(tr("%1").arg(AV_2[j]));
        itm->setTextAlignment( Qt::AlignCenter );
        ui->tableWidget->setItem(j,6,itm);
    }
    QList<double> SD_2;
    for(int u=0;u<=k_row-1;u++)
    {
        for(int x=0;x<=SD[u].count()-1;x++)
        {
            SD_2.append(SD[u][x]);
        }
    }
    for(int j=0;j<ui->tableWidget->rowCount();j++)
    {
        QTableWidgetItem *itm = new QTableWidgetItem(tr("%1").arg(SD_2[j]));
        itm->setTextAlignment( Qt::AlignCenter );
        ui->tableWidget->setItem(j,7,itm);
    }

    QList<double> MxVL_2;
    for(int u=0;u<=k_row-1;u++)
    {
        for(int x=0;x<=MxVL[u].count()-1;x++)
        {
            MxVL_2.append(MxVL[u][x]);
        }
    }
    for(int j=0;j<ui->tableWidget->rowCount();j++)
    {
        QTableWidgetItem *itm = new QTableWidgetItem(tr("%1").arg(MxVL_2[j]));
        itm->setTextAlignment( Qt::AlignCenter );
        ui->tableWidget->setItem(j,8,itm);
    }

    QList<double> MnVL_2;
    for(int u=0;u<=k_row-1;u++)
    {
        for(int x=0;x<=MnVL[u].count()-1;x++)
        {
            MnVL_2.append(MnVL[u][x]);
        }
    }
    for(int j=0;j<ui->tableWidget->rowCount();j++)
    {
        QTableWidgetItem *itm = new QTableWidgetItem(tr("%1").arg(MnVL_2[j]));
        itm->setTextAlignment( Qt::AlignCenter );
        ui->tableWidget->setItem(j,9,itm);
    }
    int x2 = 0;
    for(int u=0;u<=k_row-1;u++)
    {
        QTableWidgetItem *item2 = new QTableWidgetItem(tr("%1").arg(J[u]));
        item2->setTextAlignment( Qt::AlignCenter );
        ui->tableWidget->setItem(x2,10,item2);
        x2+=Ds[u].count();
    }
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    // install signal handlers
      QObject::connect(ui->horizontalSlider, &QSlider::sliderMoved,
        [&](int value) {
    #if 0 // not so nice -> delayed
          ui->horizontalSlider->setToolTip(QString("%1").arg(value));
    #else // better
          QToolTip::showText(QCursor::pos(), QString("%1").arg(value), nullptr);
    #endif // 0
        });
      QString s = QString::number(value);
      ui->lineEdit->setText(s);
      ui->lineEdit->setAlignment(Qt::AlignCenter);
}
