/********************************************************************************
** Form generated from reading UI file 'loadchart.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADCHART_H
#define UI_LOADCHART_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>

QT_BEGIN_NAMESPACE

class Ui_LoadChart
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *LoadChart)
    {
        if (LoadChart->objectName().isEmpty())
            LoadChart->setObjectName(QString::fromUtf8("LoadChart"));
        LoadChart->resize(583, 398);
        buttonBox = new QDialogButtonBox(LoadChart);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(370, 350, 181, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(LoadChart);
        QObject::connect(buttonBox, SIGNAL(accepted()), LoadChart, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), LoadChart, SLOT(reject()));

        QMetaObject::connectSlotsByName(LoadChart);
    } // setupUi

    void retranslateUi(QDialog *LoadChart)
    {
        LoadChart->setWindowTitle(QApplication::translate("LoadChart", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoadChart: public Ui_LoadChart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADCHART_H
