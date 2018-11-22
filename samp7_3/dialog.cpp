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

void Dialog::showButtonTitle()
{
    QPushButton *pbt = static_cast<QPushButton*>(sender());
    ui->textEdit->append(pbt->text());
}

void Dialog::on_pushButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "请选择要打开的文件", QDir::currentPath()
                                                    ,"文本文件 (*.txt);;所有文件(*.*)");
    if(filename.isEmpty())
        return;

    ui->edFile->setText(filename);
}

void Dialog::on_btnDir_clicked()
{
    QString dirname = QFileDialog::getExistingDirectory(this, "打开目录");
    if(dirname.isEmpty())
        return;
    ui->edDir->setText(dirname);
}


void Dialog::on_btnAbsoluteFile_clicked()
{
    showButtonTitle();

    QString fname = ui->edFile->text();
    QFileInfo info(fname);
    ui->textEdit->append(info.absoluteFilePath());
}

void Dialog::on_btnBaseName_clicked()
{
    showButtonTitle();

    QFileInfo info(ui->edFile->text());
    ui->textEdit->append(info.baseName());
}


void Dialog::on_pushButton_6_clicked()
{
    showButtonTitle();

    QFileInfo info(ui->edFile->text());
    ui->textEdit->append(info.absolutePath());
}

void Dialog::on_pushButton_5_clicked()
{
    showButtonTitle();

    QFileInfo info(ui->edFile->text());
    ui->textEdit->append(info.fileName());
}

void Dialog::on_pushButton_7_clicked()
{
    showButtonTitle();

    QFileInfo info(ui->edFile->text());
    ui->textEdit->append(info.filePath());
}

void Dialog::on_pushButton_11_clicked()
{
    showButtonTitle();

    QFileInfo info(ui->edFile->text());
    ui->textEdit->append(info.path());
}
