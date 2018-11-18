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

QFile* MainWindow::openFile(QIODevice::OpenMode flag)
{
    QString cur = QDir::currentPath();
    QString path = QFileDialog::getOpenFileName(this, "打开", cur, "文本文件 (*.txt);;代码文件 (*.h,*.cpp)");
    QFile* file = new QFile(path);
    if( !file->open(flag) ){
        QMessageBox::critical(this, "错误", "打开失败");
        return file;
    };
    return file;
}

void MainWindow::on_actQFileOpen_triggered()
{
    QFile* pFile = openFile(QIODevice::ReadOnly | QIODevice::Text);
    if(pFile != nullptr){
        QTextCodec *codec = QTextCodec::codecForName("UTF-8");
        QString string = codec->toUnicode(pFile->readAll());
        ui->edQFile->setPlainText(string);
        ui->tabWidget->setCurrentIndex(0);
        pFile->close();
    }
}

void MainWindow::on_actQFileSave_triggered()
{
    QString str = ui->edQFile->toPlainText();
    QString fname = QFileDialog::getSaveFileName(this, "文件另存为", QDir::currentPath(), "所有文件(*.*)");
    QFile f(fname);
    bool ret = f.open(QIODevice::WriteOnly | QIODevice::Text);
    if( !ret ){
        QMessageBox::critical(this, "错误", "保存失败");
        return;
    }
    f.write(str.toUtf8(), str.length());
    f.close();
    QMessageBox::information(this, "成功", "保存成功");
}

void MainWindow::on_actQTextOpen_triggered()
{
    QFile* pFile = openFile(QIODevice::ReadOnly | QIODevice::Text);
    if(pFile != nullptr){
        ui->edQTextStream->clear();

        QTextStream text(pFile);
        while( !text.atEnd() ){
            QString line = text.readLine();
            ui->edQTextStream->append(line);
        }
        ui->tabWidget->setCurrentIndex(1);
        pFile->close();
    }
}

void MainWindow::on_actQTextSave_triggered()
{
    QString str = ui->edQTextStream->toPlainText();
    QString fname = QFileDialog::getSaveFileName(this, "文件另存为", QDir::currentPath(), "所有文件(*.*)");
    QFile f(fname);
    bool ret = f.open(QIODevice::WriteOnly | QIODevice::Text);
    if( !ret ){
        QMessageBox::critical(this, "错误", "保存失败");
        return;
    }
    QTextStream steam(&f);
    steam.setAutoDetectUnicode(true);
    steam<<str;
    f.close();
    QMessageBox::information(this, "成功", "保存成功");
}
