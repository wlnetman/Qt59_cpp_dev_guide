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
    delete ui;
}

int QWDialogHeaders::rowCount()
{
    return ui->
}
