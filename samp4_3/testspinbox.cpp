#include "testspinbox.h"
#include "ui_testspinbox.h"

TestSpinBox::TestSpinBox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TestSpinBox)
{
    ui->setupUi(this);

    setWindowTitle("SpinBox测试");
    setWindowFlags(Qt::WindowStaysOnTopHint);
}

TestSpinBox::~TestSpinBox()
{
    delete ui;
}

void TestSpinBox::on_pBtnCacl_clicked()
{
    int num = ui->spinBoxNum->value();
    float price = ui->spinBoxPrice->value();
    float total = num * price;
    ui->spinBoxTotal->setValue(static_cast<double>(total));
}

void TestSpinBox::on_pBtnDec_clicked()
{
    int val = ui->spinBoxDec->value();
    ui->spinBoxBin->setValue(val);
    ui->spinBoxHex->setValue(val);

}

void TestSpinBox::on_pBtnBin_clicked()
{
    int val = ui->spinBoxBin->value();
    ui->spinBoxDec->setValue(val);
    ui->spinBoxHex->setValue(val);
}

void TestSpinBox::on_pBtnHex_clicked()
{
    int val = ui->spinBoxHex->value();
    ui->spinBoxDec->setValue(val);
    ui->spinBoxBin->setValue(val);
}
