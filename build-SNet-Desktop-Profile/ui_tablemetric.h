/********************************************************************************
** Form generated from reading UI file 'tablemetric.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLEMETRIC_H
#define UI_TABLEMETRIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_TableMetric
{
public:
    QGridLayout *gridLayout;
    QTableWidget *tableWidget;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *TableMetric)
    {
        if (TableMetric->objectName().isEmpty())
            TableMetric->setObjectName(QString::fromUtf8("TableMetric"));
        TableMetric->resize(763, 524);
        gridLayout = new QGridLayout(TableMetric);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tableWidget = new QTableWidget(TableMetric);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        gridLayout->addWidget(tableWidget, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(TableMetric);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1);


        retranslateUi(TableMetric);
        QObject::connect(buttonBox, SIGNAL(accepted()), TableMetric, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), TableMetric, SLOT(reject()));

        QMetaObject::connectSlotsByName(TableMetric);
    } // setupUi

    void retranslateUi(QDialog *TableMetric)
    {
        TableMetric->setWindowTitle(QApplication::translate("TableMetric", "Result of evolutionary algorithm", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TableMetric: public Ui_TableMetric {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLEMETRIC_H
