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

void MainWindow::on_actOpen_triggered()
{
    QString fname = QFileDialog::getOpenFileName(this, "打开", "C:/temp/", "CVS文件(*.cvs)");
    if(fname.isEmpty())
        return;

    QFile f(fname);
    bool bret = f.open(QFile::ReadOnly | QFile::Text);
    if(!bret)
        return;
    QTextStream str(&f);
    QString line = str.readLine();

}
