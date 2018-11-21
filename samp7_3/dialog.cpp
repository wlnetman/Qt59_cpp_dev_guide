#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "请选择要打开的文件", QDir::currentPath()
                                                    ,"文本文件 (*.txt);");
    if(filename.isEmpty())
        return;

    ui->edFile->setText(filename);
}

void Dialog::on_btnDir_clicked()
{
    QString dirname = QFileDialog::getExistingDirectory(this, "打开目录");
    if(dirname.isEmpty())
        return;
    ui->edFile->setText(dirname);

}
