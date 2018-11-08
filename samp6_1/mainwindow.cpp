#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("标准对话框的使用");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnClear_clicked()
{
    ui->plainTextEdit->clear();
}

void MainWindow::on_btnOpenDir_clicked()
{
    QString curPath = QDir::currentPath();
    QString dlgTitle = "选择一个文件";
    QString filter= "文本文件(*.txt);;图片文件(*.jpg *.png);;所有文件(*.*)";
    QString afileName = QFileDialog::getOpenFileName(this, dlgTitle, curPath, filter);
    if(!afileName.isEmpty())
        ui->plainTextEdit->appendPlainText(afileName);
}


void MainWindow::on_btnOpenFiles_clicked()
{
    QString curPath = QDir::currentPath();
}
