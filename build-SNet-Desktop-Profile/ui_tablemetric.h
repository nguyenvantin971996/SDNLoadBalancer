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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TableMetric
{
public:
    QTableWidget *tableWidget;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSlider *horizontalSlider;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *TableMetric)
    {
        if (TableMetric->objectName().isEmpty())
            TableMetric->setObjectName(QString::fromUtf8("TableMetric"));
        TableMetric->resize(871, 524);
        tableWidget = new QTableWidget(TableMetric);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 10, 851, 461));
        widget = new QWidget(TableMetric);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(11, 481, 851, 31));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        horizontalSlider = new QSlider(widget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setContextMenuPolicy(Qt::DefaultContextMenu);
        horizontalSlider->setMaximum(30);
        horizontalSlider->setValue(30);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setInvertedAppearance(false);
        horizontalSlider->setInvertedControls(false);
        horizontalSlider->setTickPosition(QSlider::TicksBothSides);

        horizontalLayout->addWidget(horizontalSlider);


        horizontalLayout_2->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(widget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_2->addWidget(buttonBox);


        retranslateUi(TableMetric);
        QObject::connect(buttonBox, SIGNAL(accepted()), TableMetric, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), TableMetric, SLOT(reject()));

        QMetaObject::connectSlotsByName(TableMetric);
    } // setupUi

    void retranslateUi(QDialog *TableMetric)
    {
        TableMetric->setWindowTitle(QApplication::translate("TableMetric", "Result of evolutionary algorithm", nullptr));
        label->setText(QApplication::translate("TableMetric", "Jitter (%)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TableMetric: public Ui_TableMetric {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLEMETRIC_H
