#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QFile* MainWindow::OpenFile(QIODevice::OpenMode flag)
{
    QString cur = QDir::currentPath();
    QString path = QFileDialog::getOpenFileName(this, "打开", cur, "代码文件 (*.h,*.cpp);文本文件 (*.txt);");
    QFile* file = new QFile(path);
    if( !file->open(flag) ){
        QMessageBox::critical(this, "错误", "打开失败");
        return file;
    };
    return file;
}

void MainWindow::on_actQFileOpen_triggered()
{
    QFile* pFile = OpenFile(QIODevice::ReadOnly | QIODevice::Text);
    if(pFile != nullptr){
        ui->edQFile->setPlainText(pFile->readAll());
        ui->tabWidget->setCurrentIndex(0);
        pFile->close();
    }
}

void MainWindow::on_actQFileSave_triggered()
{

}
