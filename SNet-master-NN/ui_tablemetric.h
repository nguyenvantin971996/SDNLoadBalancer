/********************************************************************************
** Form generated from reading UI file 'tablemetric.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLEMETRIC_H
#define UI_TABLEMETRIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_TableMetric
{
public:
    QGridLayout *gridLayout;
    QTableWidget *tableWidget;

    void setupUi(QDialog *TableMetric)
    {
        if (TableMetric->objectName().isEmpty())
            TableMetric->setObjectName(QString::fromUtf8("TableMetric"));
        TableMetric->resize(1430, 800);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TableMetric->sizePolicy().hasHeightForWidth());
        TableMetric->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(12);
        TableMetric->setFont(font);
        gridLayout = new QGridLayout(TableMetric);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tableWidget = new QTableWidget(TableMetric);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy1);
        tableWidget->setFont(font);

        gridLayout->addWidget(tableWidget, 0, 0, 1, 2);


        retranslateUi(TableMetric);

        QMetaObject::connectSlotsByName(TableMetric);
    } // setupUi

    void retranslateUi(QDialog *TableMetric)
    {
        TableMetric->setWindowTitle(QCoreApplication::translate("TableMetric", "Results of NN_GA", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TableMetric: public Ui_TableMetric {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLEMETRIC_H
