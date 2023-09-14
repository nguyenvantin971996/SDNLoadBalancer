/********************************************************************************
** Form generated from reading UI file 'ControllerDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROLLERDIALOG_H
#define UI_CONTROLLERDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_ControllerDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *txtIpAddress;
    QLabel *lblPort;
    QLineEdit *txtPort;
    QLabel *lblIpAddress;

    void setupUi(QDialog *ControllerDialog)
    {
        if (ControllerDialog->objectName().isEmpty())
            ControllerDialog->setObjectName(QString::fromUtf8("ControllerDialog"));
        ControllerDialog->resize(318, 136);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/controller.png"), QSize(), QIcon::Normal, QIcon::Off);
        ControllerDialog->setWindowIcon(icon);
        buttonBox = new QDialogButtonBox(ControllerDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(150, 100, 156, 23));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        txtIpAddress = new QLineEdit(ControllerDialog);
        txtIpAddress->setObjectName(QString::fromUtf8("txtIpAddress"));
        txtIpAddress->setEnabled(true);
        txtIpAddress->setGeometry(QRect(90, 10, 219, 25));
        lblPort = new QLabel(ControllerDialog);
        lblPort->setObjectName(QString::fromUtf8("lblPort"));
        lblPort->setGeometry(QRect(10, 50, 31, 21));
        txtPort = new QLineEdit(ControllerDialog);
        txtPort->setObjectName(QString::fromUtf8("txtPort"));
        txtPort->setEnabled(true);
        txtPort->setGeometry(QRect(90, 50, 61, 25));
        lblIpAddress = new QLabel(ControllerDialog);
        lblIpAddress->setObjectName(QString::fromUtf8("lblIpAddress"));
        lblIpAddress->setGeometry(QRect(10, 10, 71, 31));

        retranslateUi(ControllerDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ControllerDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ControllerDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ControllerDialog);
    } // setupUi

    void retranslateUi(QDialog *ControllerDialog)
    {
        ControllerDialog->setWindowTitle(QCoreApplication::translate("ControllerDialog", "Dialog", nullptr));
        lblPort->setText(QCoreApplication::translate("ControllerDialog", "Port", nullptr));
        lblIpAddress->setText(QCoreApplication::translate("ControllerDialog", "IP Address", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ControllerDialog: public Ui_ControllerDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLLERDIALOG_H
