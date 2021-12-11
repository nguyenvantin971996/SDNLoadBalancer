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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_TableMetric
{
public:
    QTableWidget *tableWidget;
    QTextEdit *textEdit;
    QDialogButtonBox *buttonBox;
    QSlider *horizontalSlider;
    QLabel *label;

    void setupUi(QDialog *TableMetric)
    {
        if (TableMetric->objectName().isEmpty())
            TableMetric->setObjectName(QString::fromUtf8("TableMetric"));
        TableMetric->resize(700, 700);
        tableWidget = new QTableWidget(TableMetric);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 10, 680, 640));
        textEdit = new QTextEdit(TableMetric);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setEnabled(true);
        textEdit->setGeometry(QRect(140, 660, 41, 31));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy);
        buttonBox = new QDialogButtonBox(TableMetric);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(490, 660, 171, 31));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        horizontalSlider = new QSlider(TableMetric);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(190, 660, 281, 31));
        horizontalSlider->setContextMenuPolicy(Qt::DefaultContextMenu);
        horizontalSlider->setMaximum(30);
        horizontalSlider->setValue(30);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setInvertedAppearance(false);
        horizontalSlider->setInvertedControls(false);
        horizontalSlider->setTickPosition(QSlider::TicksBothSides);
        label = new QLabel(TableMetric);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 660, 121, 31));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(TableMetric);
        QObject::connect(buttonBox, SIGNAL(accepted()), TableMetric, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), TableMetric, SLOT(reject()));

        QMetaObject::connectSlotsByName(TableMetric);
    } // setupUi

    void retranslateUi(QDialog *TableMetric)
    {
        TableMetric->setWindowTitle(QApplication::translate("TableMetric", "Result of evolutionary algorithm", nullptr));
        textEdit->setHtml(QApplication::translate("TableMetric", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">30</p></body></html>", nullptr));
        label->setText(QApplication::translate("TableMetric", "Max of jitter (%) =", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TableMetric: public Ui_TableMetric {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLEMETRIC_H
