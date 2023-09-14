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
    int K_paths[3] = {0, 0, 0};
    QList<double> Ds[3];
    QList<double> I[3];
    QList<double> AV[3];
    QList<double> SD[3];
    QList<double> MxVL[3];
    QList<double> MnVL[3];
    double J[3] = {0, 0 , 0};
    double CD[3] = {0, 0 , 0};
    double sum[3] = {0, 0 , 0};
    QList<QList<double>> wires[3];
    QString filename="../wires.txt";
    QFile file(filename);
    QString col_0 = "Algorithm";
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
        if(line[0]=="N")
        {
            col_0 = "Parameters";
        }
        if(line[0]=="A" || line[0]=="G" || line[0]=="F" || line[0]=="N")
        {
            u++;
            for(int x=0;x<=linelist.count()-1;x++)
            {
                Parameters[u] = Parameters[u] + "\n" + linelist[x];
            }
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
    for(int u=0;u<=2;u++)
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
    for(int u=0;u<=2;u++)
    {
        for(int x=0;x<=Ds[u].count()-1;x++)
        {
            double t3 = Ds[u][x]/(wires[u][x].count());
            t3 = round( t3 * 10.0 ) / 10.0;
            AV[u].append(t3);
        }
    }
    for(int u=0;u<=2;u++)
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
    for(int u=0;u<=2;u++)
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
    for(int u=0;u<=2;u++)
    {
        double jj = (1-Ds[u][0]/Ds[u][Ds[u].count()-1])*100;
        J[u] = round( jj * 100.0 ) / 100.0;
    }
    int num_row = 0;
    for(int u=0;u<=2;u++)
    {
        num_row += Ds[u].count();
        K_paths[u] = Ds[u].count();
    }
    ui->tableWidget->setRowCount(num_row);
    ui->tableWidget->setColumnCount(10);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << col_0 << "K_paths" << "CD" << "Ds" << "I, %" << "AV" << "SD"<< "MxVL" << "MnVL" << "J, %");
    ui->tableWidget->setSpan(0, 0, Ds[0].count(), 1);
    ui->tableWidget->setSpan(0, 1, Ds[0].count(), 1);
    ui->tableWidget->setSpan(0, 2, Ds[0].count(), 1);
    ui->tableWidget->setSpan(0, 9, Ds[0].count(), 1);
    ui->tableWidget->setSpan(Ds[0].count(), 0, Ds[1].count(), 1);
    ui->tableWidget->setSpan(Ds[0].count(), 1, Ds[1].count(), 1);
    ui->tableWidget->setSpan(Ds[0].count(), 2, Ds[1].count(), 1);
    ui->tableWidget->setSpan(Ds[0].count(), 9, Ds[1].count(), 1);
    ui->tableWidget->setSpan(Ds[0].count()+Ds[1].count(), 0, Ds[2].count(), 1);
    ui->tableWidget->setSpan(Ds[0].count()+Ds[1].count(), 1, Ds[2].count(), 1);
    ui->tableWidget->setSpan(Ds[0].count()+Ds[1].count(), 2, Ds[2].count(), 1);
    ui->tableWidget->setSpan(Ds[0].count()+Ds[1].count(), 9, Ds[2].count(), 1);
    int xxx = 0;
    for(int u=0;u<=2;u++)
    {
        QTableWidgetItem *item2 = new QTableWidgetItem(tr("%1").arg(Parameters[u]));
        item2->setTextAlignment( Qt::AlignCenter );
        ui->tableWidget->setItem(xxx,0,item2);
        xxx+=Ds[u].count();
    }
    int xx = 0;
    for(int u=0;u<=2;u++)
    {
        QTableWidgetItem *item2 = new QTableWidgetItem(tr("%1").arg(K_paths[u]));
        item2->setTextAlignment( Qt::AlignCenter );
        ui->tableWidget->setItem(xx,1,item2);
        xx+=Ds[u].count();
    }
    int x1 = 0;
    for(int u=0;u<=2;u++)
    {
        QTableWidgetItem *item2 = new QTableWidgetItem(tr("%1").arg(CD[u]));
        item2->setTextAlignment( Qt::AlignCenter );
        ui->tableWidget->setItem(x1,2,item2);
        x1+=Ds[u].count();
    }
    QList<double> Ds_2;
    for(int u=0;u<=2;u++)
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
        ui->tableWidget->setItem(j,3,itm);
    }
    QList<double> I_2;
    for(int u=0;u<=2;u++)
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
        ui->tableWidget->setItem(j,4,itm);
    }
    QList<double> AV_2;
    for(int u=0;u<=2;u++)
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
        ui->tableWidget->setItem(j,5,itm);
    }
    QList<double> SD_2;
    for(int u=0;u<=2;u++)
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
        ui->tableWidget->setItem(j,6,itm);
    }
    QList<double> MxVL_2;
    for(int u=0;u<=2;u++)
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
        ui->tableWidget->setItem(j,7,itm);
    }
    QList<double> MnVL_2;
    for(int u=0;u<=2;u++)
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
        ui->tableWidget->setItem(j,8,itm);
    }
    int x2 = 0;
    for(int u=0;u<=2;u++)
    {
        QTableWidgetItem *item2 = new QTableWidgetItem(tr("%1").arg(J[u]));
        item2->setTextAlignment( Qt::AlignCenter );
        ui->tableWidget->setItem(x2,9,item2);
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
    QString Parameters[3];
    int K_paths[3] = {0, 0, 0};
    QList<double> Ds[3];
    QList<double> I[3];
    QList<double> AV[3];
    QList<double> SD[3];
    QList<double> MxVL[3];
    QList<double> MnVL[3];
    double J[3] = {0, 0 , 0};
    double CD[3] = {0, 0 , 0};
    double sum[3] = {0, 0 , 0};
    QList<QList<double>> wires[3];
    QString filename="../wires.txt";
    QFile file(filename);
    QString col_0 = "Algorithm";
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
        if(line[0]=="N")
        {
            col_0 = "Parameters";
        }
        if(line[0]=="A" || line[0]=="G" || line[0]=="F" || line[0]=="N")
        {
            u++;
            for(int x=0;x<=linelist.count()-1;x++)
            {
                Parameters[u] = Parameters[u] + "\n" + linelist[x];
            }
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
    for(int u=0;u<=2;u++)
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
    for(int u=0;u<=2;u++)
    {
        for(int x=0;x<=Ds[u].count()-1;x++)
        {
            double t3 = Ds[u][x]/(wires[u][x].count());
            t3 = round( t3 * 10.0 ) / 10.0;
            AV[u].append(t3);
        }
    }
    for(int u=0;u<=2;u++)
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
    for(int u=0;u<=2;u++)
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
    for(int u=0;u<=2;u++)
    {
        double jj = (1-Ds[u][0]/Ds[u][Ds[u].count()-1])*100;
        J[u] = round( jj * 100.0 ) / 100.0;
    }
    int num_row = 0;
    for(int u=0;u<=2;u++)
    {
        num_row += Ds[u].count();
        K_paths[u] = Ds[u].count();
    }
    ui->tableWidget->setRowCount(num_row);
    ui->tableWidget->setColumnCount(10);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << col_0 << "K_paths" << "CD" << "Ds" << "I, %" << "AV" << "SD"<< "MxVL" << "MnVL" << "J, %");
    ui->tableWidget->setSpan(0, 0, Ds[0].count(), 1);
    ui->tableWidget->setSpan(0, 1, Ds[0].count(), 1);
    ui->tableWidget->setSpan(0, 2, Ds[0].count(), 1);
    ui->tableWidget->setSpan(0, 9, Ds[0].count(), 1);
    ui->tableWidget->setSpan(Ds[0].count(), 0, Ds[1].count(), 1);
    ui->tableWidget->setSpan(Ds[0].count(), 1, Ds[1].count(), 1);
    ui->tableWidget->setSpan(Ds[0].count(), 2, Ds[1].count(), 1);
    ui->tableWidget->setSpan(Ds[0].count(), 9, Ds[1].count(), 1);
    ui->tableWidget->setSpan(Ds[0].count()+Ds[1].count(), 0, Ds[2].count(), 1);
    ui->tableWidget->setSpan(Ds[0].count()+Ds[1].count(), 1, Ds[2].count(), 1);
    ui->tableWidget->setSpan(Ds[0].count()+Ds[1].count(), 2, Ds[2].count(), 1);
    ui->tableWidget->setSpan(Ds[0].count()+Ds[1].count(), 9, Ds[2].count(), 1);
    int xxx = 0;
    for(int u=0;u<=2;u++)
    {
        QTableWidgetItem *item2 = new QTableWidgetItem(tr("%1").arg(Parameters[u]));
        item2->setTextAlignment( Qt::AlignCenter );
        ui->tableWidget->setItem(xxx,0,item2);
        xxx+=Ds[u].count();
    }
    int xx = 0;
    for(int u=0;u<=2;u++)
    {
        QTableWidgetItem *item2 = new QTableWidgetItem(tr("%1").arg(K_paths[u]));
        item2->setTextAlignment( Qt::AlignCenter );
        ui->tableWidget->setItem(xx,1,item2);
        xx+=Ds[u].count();
    }
    int x1 = 0;
    for(int u=0;u<=2;u++)
    {
        QTableWidgetItem *item2 = new QTableWidgetItem(tr("%1").arg(CD[u]));
        item2->setTextAlignment( Qt::AlignCenter );
        ui->tableWidget->setItem(x1,2,item2);
        x1+=Ds[u].count();
    }
    QList<double> Ds_2;
    for(int u=0;u<=2;u++)
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
        ui->tableWidget->setItem(j,3,itm);
    }
    QList<double> I_2;
    for(int u=0;u<=2;u++)
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
        ui->tableWidget->setItem(j,4,itm);
    }
    QList<double> AV_2;
    for(int u=0;u<=2;u++)
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
        ui->tableWidget->setItem(j,5,itm);
    }
    QList<double> SD_2;
    for(int u=0;u<=2;u++)
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
        ui->tableWidget->setItem(j,6,itm);
    }
    QList<double> MxVL_2;
    for(int u=0;u<=2;u++)
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
        ui->tableWidget->setItem(j,7,itm);
    }
    QList<double> MnVL_2;
    for(int u=0;u<=2;u++)
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
        ui->tableWidget->setItem(j,8,itm);
    }
    int x2 = 0;
    for(int u=0;u<=2;u++)
    {
        QTableWidgetItem *item2 = new QTableWidgetItem(tr("%1").arg(J[u]));
        item2->setTextAlignment( Qt::AlignCenter );
        ui->tableWidget->setItem(x2,9,item2);
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
