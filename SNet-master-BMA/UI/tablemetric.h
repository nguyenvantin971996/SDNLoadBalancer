#ifndef TABLEMETRIC_H
#define TABLEMETRIC_H

#include <QDialog>

namespace Ui {
class TableMetric;
}

class TableMetric : public QDialog
{
    Q_OBJECT

public:
    explicit TableMetric(QWidget *parent = nullptr);
    ~TableMetric();

private slots:
    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::TableMetric *ui;
};

#endif // TABLEMETRIC_H
