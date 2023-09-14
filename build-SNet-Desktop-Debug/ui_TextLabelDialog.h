/********************************************************************************
** Form generated from reading UI file 'TextLabelDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEXTLABELDIALOG_H
#define UI_TEXTLABELDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_TextLabelDialog
{
public:
    QGridLayout *gridLayout;
    QTextEdit *txtTextArea;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *TextLabelDialog)
    {
        if (TextLabelDialog->objectName().isEmpty())
            TextLabelDialog->setObjectName(QString::fromUtf8("TextLabelDialog"));
        TextLabelDialog->resize(381, 183);
        gridLayout = new QGridLayout(TextLabelDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        txtTextArea = new QTextEdit(TextLabelDialog);
        txtTextArea->setObjectName(QString::fromUtf8("txtTextArea"));

        gridLayout->addWidget(txtTextArea, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(TextLabelDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1);


        retranslateUi(TextLabelDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), TextLabelDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), TextLabelDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(TextLabelDialog);
    } // setupUi

    void retranslateUi(QDialog *TextLabelDialog)
    {
        TextLabelDialog->setWindowTitle(QApplication::translate("TextLabelDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TextLabelDialog: public Ui_TextLabelDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEXTLABELDIALOG_H
