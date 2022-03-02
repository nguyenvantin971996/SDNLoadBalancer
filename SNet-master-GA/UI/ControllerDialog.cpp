#include "ControllerDialog.h"
#include "ui_ControllerDialog.h"

ControllerDialog::ControllerDialog(SdnController* controller, QWidget *parent) :
    QDialog(parent), controller(controller), ui(new Ui::ControllerDialog)
{
    ui->setupUi(this);
    SetWindowProperties();
}

ControllerDialog::~ControllerDialog()
{
    delete ui;
}

void ControllerDialog::SetWindowProperties()
{
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    this->setWindowTitle(QString("Controller %0").arg(controller->getName()));
    ui->txtIpAddress->setText(controller->getIp());
    ui->txtPort->setText(controller->getPort());
}

void ControllerDialog::accept()
{
    controller->setIp(ui->txtIpAddress->text());
    controller->setPort(ui->txtPort->text());
    done(QDialog::Accepted);
}
