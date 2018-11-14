#include "qformdoc.h"
#include "ui_qformdoc.h"

QFormDoc::QFormDoc(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QFormDoc)
{
    ui->setupUi(this);
}

QFormDoc::~QFormDoc()
{
    QMessageBox::information(this, "消息", "析构函数");
    delete ui;
}

void QFormDoc::on_actOpen_triggered()
{

}
