#ifndef CONTROLLERDIALOG_H
#define CONTROLLERDIALOG_H

#include <QDialog>
#include "SdnController.h"

namespace Ui {
class ControllerDialog;
}

class ControllerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ControllerDialog(SdnController* controller, QWidget *parent = 0);
    ~ControllerDialog();

private:
    SdnController *controller;
    Ui::ControllerDialog *ui;

    void SetWindowProperties();

private slots:
    virtual void accept();
};

#endif // CONTROLLERDIALOG_H
