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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_TableMetric
{
public:
    QGridLayout *gridLayout;
    QTableWidget *tableWidget;
    QLabel *label;
    QLineEdit *lineEdit;
    QSlider *horizontalSlider;

    void setupUi(QDialog *TableMetric)
    {
        if (TableMetric->objectName().isEmpty())
            TableMetric->setObjectName(QString::fromUtf8("TableMetric"));
        TableMetric->resize(1000, 1800);
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

        gridLayout->addWidget(tableWidget, 0, 0, 1, 4);

        label = new QLabel(TableMetric);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 1, 0, 1, 1);

        lineEdit = new QLineEdit(TableMetric);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEnabled(true);
        sizePolicy2.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy2);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Ubuntu"));
        font1.setPointSize(12);
        lineEdit->setFont(font1);
        lineEdit->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit, 1, 1, 1, 1);

        horizontalSlider = new QSlider(TableMetric);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setFont(font);
        horizontalSlider->setContextMenuPolicy(Qt::DefaultContextMenu);
        horizontalSlider->setMaximum(10);
        horizontalSlider->setValue(10);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setInvertedAppearance(false);
        horizontalSlider->setInvertedControls(false);
        horizontalSlider->setTickPosition(QSlider::TicksBothSides);

        gridLayout->addWidget(horizontalSlider, 1, 2, 1, 1);


        retranslateUi(TableMetric);

        QMetaObject::connectSlotsByName(TableMetric);
    } // setupUi

    void retranslateUi(QDialog *TableMetric)
    {
        TableMetric->setWindowTitle(QApplication::translate("TableMetric", "Result of evolutionary algorithm", nullptr));
        label->setText(QApplication::translate("TableMetric", "K_paths =", nullptr));
        lineEdit->setText(QApplication::translate("TableMetric", "10", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TableMetric: public Ui_TableMetric {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLEMETRIC_H
