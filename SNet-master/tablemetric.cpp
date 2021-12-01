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
    int K_paths;
    QList<double> Ds;
    QList<double> I;
    QList<double> AV;
    QList<double> SD;
    QList<double> MxVL;
    QList<double> MnVL;
    double J;
    double CD = 0;
    double sum = 0;
    QList<QList<double>> paths;
    QString filename="../wires.txt";
        QFile file(filename);
        if(!file.open(QIODevice::ReadOnly)) {
            QMessageBox::information(0, "error", file.errorString());
        }
        QTextStream in(&file);
        int i=1;
        while(!in.atEnd()){
            double s = 0;
            QString line = in.readLine();
            QString ii = QString::number(i);
            QStringList linelist;
            QList<double> path;
            linelist = line.split(",");
            for(int x=linelist.count()-1;x>=0;x--)
            {
                double r = linelist.at(x).toDouble();
                s+=r;
                path.append(r);
            }
            sum += 1/s;
            CD += s;
            Ds.append(s);
            paths.append(path);
            i++;
        }
        double ss = 0;
        for(int x=0;x<=Ds.count()-2;x++)
        {
            double t2 = 100*(1/Ds[x])/sum;
            t2 = int( t2 * 10.0 ) / 10.0;
            ss+=t2;
            I.append(t2);
        }
        I.append(100-ss);
        for(int x=0;x<=paths.count()-1;x++)
        {
            double t3 = Ds[x]/(paths[x].count());
            t3 = int( t3 * 10.0 ) / 10.0;
            AV.append(t3);
        }
        for(int x=0;x<=paths.count()-1;x++)
        {
            double t4 = Ds[x]/(paths[x].count());
            double sum2 = 0;
            for(int y=0;y<=paths[x].count()-1;y++)
            {
                sum2+= (t4-paths[x][y])*(t4-paths[x][y]);
            }
            double sd = sqrt(sum2/(paths[x].count()));
            sd = int( sd * 10.0 ) / 10.0;
            SD.append(sd);
        }
        for(int x=0;x<=paths.count()-1;x++)
        {
            double mx = 0;
            double mn = 99999;
            for(int y=0;y<=paths[x].count()-1;y++)
            {
                if(mx<=paths[x][y]){
                    mx = paths[x][y];
                };
                if(mn>=paths[x][y]){
                    mn = paths[x][y];
                }
            }
            MxVL.append(mx);
            MnVL.append(mn);
        }
        double jj = (1-Ds[0]/Ds[Ds.count()-1])*100;
        J = int( jj * 100.0 ) / 100.0;
        K_paths = Ds.count();
    ui->tableWidget->setRowCount(Ds.count());
    ui->tableWidget->setColumnCount(9);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "K_paths" << "CD" << "Ds" << "I, %" << "AV" << "SD"<< "MxVL" << "MnVL" << "J, %");
    ui->tableWidget->setSpan(0, 0, Ds.count(), 1);
    ui->tableWidget->setSpan(0, 1, Ds.count(), 1);
    ui->tableWidget->setSpan(0, 8, Ds.count(), 1);

    QTableWidgetItem *item2 = new QTableWidgetItem(tr("%1").arg(K_paths));
    item2->setTextAlignment( Qt::AlignCenter );
    ui->tableWidget->setItem(0,0,item2);

    QTableWidgetItem *itemm = new QTableWidgetItem(tr("%1").arg(CD));
    itemm->setTextAlignment( Qt::AlignCenter );
    ui->tableWidget->setItem(0,1,itemm);

    for(int j=0;j<ui->tableWidget->rowCount();j++)
    {
        QTableWidgetItem *itm = new QTableWidgetItem(tr("%1").arg(Ds[j]));
        itm->setTextAlignment( Qt::AlignCenter );
        ui->tableWidget->setItem(j,2,itm);
    }
    for(int j=0;j<ui->tableWidget->rowCount();j++)
    {
        QTableWidgetItem *itm = new QTableWidgetItem(tr("%1").arg(I[j]));
        itm->setTextAlignment( Qt::AlignCenter );
        ui->tableWidget->setItem(j,3,itm);
    }
    for(int j=0;j<ui->tableWidget->rowCount();j++)
    {
        QTableWidgetItem *itm = new QTableWidgetItem(tr("%1").arg(AV[j]));
        itm->setTextAlignment( Qt::AlignCenter );
        ui->tableWidget->setItem(j,4,itm);
    }
    for(int j=0;j<ui->tableWidget->rowCount();j++)
    {
        QTableWidgetItem *itm = new QTableWidgetItem(tr("%1").arg(SD[j]));
        itm->setTextAlignment( Qt::AlignCenter );
        ui->tableWidget->setItem(j,5,itm);
    }
    for(int j=0;j<ui->tableWidget->rowCount();j++)
    {
        QTableWidgetItem *itm = new QTableWidgetItem(tr("%1").arg(MxVL[j]));
        itm->setTextAlignment( Qt::AlignCenter );
        ui->tableWidget->setItem(j,6,itm);
    }
    for(int j=0;j<ui->tableWidget->rowCount();j++)
    {
        QTableWidgetItem *itm = new QTableWidgetItem(tr("%1").arg(MnVL[j]));
        itm->setTextAlignment( Qt::AlignCenter );
        ui->tableWidget->setItem(j,7,itm);
    }
    QTableWidgetItem *item = new QTableWidgetItem(tr("%1").arg(J));
    item->setTextAlignment( Qt::AlignCenter );
    ui->tableWidget->setItem(0,8,item);
}

TableMetric::~TableMetric()
{
    delete ui;
}

void TableMetric::on_horizontalSlider_valueChanged(int value)
{
    int K_paths;
    QList<double> Ds;
    QList<double> I;
    QList<double> AV;
    QList<double> SD;
    QList<double> MxVL;
    QList<double> MnVL;
    double J;
    double CD = 0;
    double sum = 0;
    QList<QList<double>> paths;
    QString filename="../wires.txt";
        QFile file(filename);
        if(!file.open(QIODevice::ReadOnly)) {
            QMessageBox::information(0, "error", file.errorString());
        }
        QTextStream in(&file);
        int i=1;
        while(!in.atEnd()){
            double s = 0;
            QString line = in.readLine();
            QString ii = QString::number(i);
            QStringList linelist;
            QList<double> path;
            linelist = line.split(",");
            for(int x=linelist.count()-1;x>=0;x--)
            {
                double r = linelist.at(x).toDouble();
                s+=r;
                path.append(r);
            }
            if(Ds.count()!=0)
            {
                if(s>100*Ds[0]/(100-value))
                {
                    break;
                }
            }
            sum += 1/s;
            CD += s;
            Ds.append(s);
            paths.append(path);
            i++;
        }
        double ss = 0;
        for(int x=0;x<=Ds.count()-2;x++)
        {
            double t2 = 100*(1/Ds[x])/sum;
            t2 = int( t2 * 10.0 ) / 10.0;
            ss+=t2;
            I.append(t2);
        }
        I.append(100-ss);
        for(int x=0;x<=paths.count()-1;x++)
        {
            double t3 = Ds[x]/(paths[x].count());
            t3 = int( t3 * 10.0 ) / 10.0;
            AV.append(t3);
        }
        for(int x=0;x<=paths.count()-1;x++)
        {
            double t4 = Ds[x]/(paths[x].count());
            double sum2 = 0;
            for(int y=0;y<=paths[x].count()-1;y++)
            {
                sum2+= (t4-paths[x][y])*(t4-paths[x][y]);
            }
            double sd = sqrt(sum2/(paths[x].count()));
            sd = int( sd * 10.0 ) / 10.0;
            SD.append(sd);
        }
        for(int x=0;x<=paths.count()-1;x++)
        {
            double mx = 0;
            double mn = 99999;
            for(int y=0;y<=paths[x].count()-1;y++)
            {
                if(mx<=paths[x][y]){
                    mx = paths[x][y];
                };
                if(mn>=paths[x][y]){
                    mn = paths[x][y];
                }
            }
            MxVL.append(mx);
            MnVL.append(mn);
        }
        double jj = (1-Ds[0]/Ds[Ds.count()-1])*100;
        J = int( jj * 100.0 ) / 100.0;
        K_paths = Ds.count();
    ui->tableWidget->setRowCount(Ds.count());
    ui->tableWidget->setColumnCount(9);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "K_paths" << "CD" << "Ds" << "I, %" << "AV" << "SD"<< "MxVL" << "MnVL" << "J, %");
    ui->tableWidget->setSpan(0, 0, Ds.count(), 1);
    ui->tableWidget->setSpan(0, 1, Ds.count(), 1);
    ui->tableWidget->setSpan(0, 8, Ds.count(), 1);

    QTableWidgetItem *item2 = new QTableWidgetItem(tr("%1").arg(K_paths));
    item2->setTextAlignment( Qt::AlignCenter );
    ui->tableWidget->setItem(0,0,item2);

    QTableWidgetItem *itemm = new QTableWidgetItem(tr("%1").arg(CD));
    itemm->setTextAlignment( Qt::AlignCenter );
    ui->tableWidget->setItem(0,1,itemm);
    for(int j=0;j<ui->tableWidget->rowCount();j++)
    {
        QTableWidgetItem *itm = new QTableWidgetItem(tr("%1").arg(Ds[j]));
        itm->setTextAlignment( Qt::AlignCenter );
        ui->tableWidget->setItem(j,2,itm);
    }
    for(int j=0;j<ui->tableWidget->rowCount();j++)
    {
        QTableWidgetItem *itm = new QTableWidgetItem(tr("%1").arg(I[j]));
        itm->setTextAlignment( Qt::AlignCenter );
        ui->tableWidget->setItem(j,3,itm);
    }
    for(int j=0;j<ui->tableWidget->rowCount();j++)
    {
        QTableWidgetItem *itm = new QTableWidgetItem(tr("%1").arg(AV[j]));
        itm->setTextAlignment( Qt::AlignCenter );
        ui->tableWidget->setItem(j,4,itm);
    }
    for(int j=0;j<ui->tableWidget->rowCount();j++)
    {
        QTableWidgetItem *itm = new QTableWidgetItem(tr("%1").arg(SD[j]));
        itm->setTextAlignment( Qt::AlignCenter );
        ui->tableWidget->setItem(j,5,itm);
    }
    for(int j=0;j<ui->tableWidget->rowCount();j++)
    {
        QTableWidgetItem *itm = new QTableWidgetItem(tr("%1").arg(MxVL[j]));
        itm->setTextAlignment( Qt::AlignCenter );
        ui->tableWidget->setItem(j,6,itm);
    }
    for(int j=0;j<ui->tableWidget->rowCount();j++)
    {
        QTableWidgetItem *itm = new QTableWidgetItem(tr("%1").arg(MnVL[j]));
        itm->setTextAlignment( Qt::AlignCenter );
        ui->tableWidget->setItem(j,7,itm);
    }
    QTableWidgetItem *item = new QTableWidgetItem(tr("%1").arg(J));
    item->setTextAlignment( Qt::AlignCenter );
    ui->tableWidget->setItem(0,8,item);
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
      ui->textEdit->setText(s);
      ui->textEdit->setAlignment(Qt::AlignCenter);
}
