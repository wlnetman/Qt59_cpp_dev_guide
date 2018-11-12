#include "qwdialogheaders.h"
#include "ui_qwdialogheaders.h"

QWDialogHeaders::QWDialogHeaders(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QWDialogHeaders)
{
    ui->setupUi(this);
}

QWDialogHeaders::~QWDialogHeaders()
{
    QMessageBox::information(this, "析构函数", "设置对话框此刻会被删除");
    delete ui;
}

int QWDialogHeaders::rowCount()
{
    return ui->spinBoxRow->value();
}

int QWDialogHeaders::columnCount()
{
    return ui->spinBoxColumn->value();
}

void QWDialogHeaders::setRowColumn(int row, int column)
{
    ui->spinBoxRow->setValue(row);
    ui->spinBoxColumn->setValue(column);
}

