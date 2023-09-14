/********************************************************************************
** Form generated from reading UI file 'LinkDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LINKDIALOG_H
#define UI_LINKDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_LinkDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *lblBandwidth;
    QLineEdit *txtBandwidth;
    QLabel *lblDelay;
    QLineEdit *txtDelay;
    QLabel *lblPacketLoss;
    QLineEdit *txtPacketLoss;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *LinkDialog)
    {
        if (LinkDialog->objectName().isEmpty())
            LinkDialog->setObjectName(QString::fromUtf8("LinkDialog"));
        LinkDialog->setWindowModality(Qt::NonModal);
        LinkDialog->resize(240, 167);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/link.png"), QSize(), QIcon::Normal, QIcon::Off);
        LinkDialog->setWindowIcon(icon);
        gridLayout = new QGridLayout(LinkDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lblBandwidth = new QLabel(LinkDialog);
        lblBandwidth->setObjectName(QString::fromUtf8("lblBandwidth"));

        gridLayout->addWidget(lblBandwidth, 0, 0, 1, 1);

        txtBandwidth = new QLineEdit(LinkDialog);
        txtBandwidth->setObjectName(QString::fromUtf8("txtBandwidth"));

        gridLayout->addWidget(txtBandwidth, 0, 1, 1, 1);

        lblDelay = new QLabel(LinkDialog);
        lblDelay->setObjectName(QString::fromUtf8("lblDelay"));

        gridLayout->addWidget(lblDelay, 1, 0, 1, 1);

        txtDelay = new QLineEdit(LinkDialog);
        txtDelay->setObjectName(QString::fromUtf8("txtDelay"));

        gridLayout->addWidget(txtDelay, 1, 1, 1, 1);

        lblPacketLoss = new QLabel(LinkDialog);
        lblPacketLoss->setObjectName(QString::fromUtf8("lblPacketLoss"));

        gridLayout->addWidget(lblPacketLoss, 2, 0, 1, 1);

        txtPacketLoss = new QLineEdit(LinkDialog);
        txtPacketLoss->setObjectName(QString::fromUtf8("txtPacketLoss"));

        gridLayout->addWidget(txtPacketLoss, 2, 1, 1, 1);

        buttonBox = new QDialogButtonBox(LinkDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 3, 0, 1, 2);


        retranslateUi(LinkDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), LinkDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), LinkDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(LinkDialog);
    } // setupUi

    void retranslateUi(QDialog *LinkDialog)
    {
        LinkDialog->setWindowTitle(QApplication::translate("LinkDialog", "Dialog", nullptr));
        lblBandwidth->setText(QApplication::translate("LinkDialog", "Bandwidth (Mbit\\s)", nullptr));
        lblDelay->setText(QApplication::translate("LinkDialog", "Delay (ms)", nullptr));
        lblPacketLoss->setText(QApplication::translate("LinkDialog", "Packet Loss Rate (%)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LinkDialog: public Ui_LinkDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LINKDIALOG_H
