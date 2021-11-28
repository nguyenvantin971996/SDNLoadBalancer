#include "TextLabelDialog.h"
#include "ui_TextLabelDialog.h"
#include "TextLabel.h"

TextLabelDialog::TextLabelDialog(TextLabel *textLabel, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TextLabelDialog),
    textLabel(textLabel)
{
    ui->setupUi(this);
    setWindowProperties();
}

TextLabelDialog::~TextLabelDialog()
{
    delete ui;
}

void TextLabelDialog::setWindowProperties()
{
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    this->setWindowTitle("Text");
    ui->txtTextArea->setText(textLabel->getContent());
    ui->txtTextArea->setFont(QFont("any", 11));
}

void TextLabelDialog::accept()
{
    textLabel->setContent(ui->txtTextArea->toPlainText());
    done(QDialog::Accepted);
}
