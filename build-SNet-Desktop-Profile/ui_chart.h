/********************************************************************************
** Form generated from reading UI file 'chart.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHART_H
#define UI_CHART_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Chart
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Chart)
    {
        if (Chart->objectName().isEmpty())
            Chart->setObjectName(QString::fromUtf8("Chart"));
        Chart->resize(800, 600);
        menubar = new QMenuBar(Chart);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        Chart->setMenuBar(menubar);
        centralwidget = new QWidget(Chart);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Chart->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Chart);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Chart->setStatusBar(statusbar);

        retranslateUi(Chart);

        QMetaObject::connectSlotsByName(Chart);
    } // setupUi

    void retranslateUi(QMainWindow *Chart)
    {
        Chart->setWindowTitle(QApplication::translate("Chart", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Chart: public Ui_Chart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHART_H
