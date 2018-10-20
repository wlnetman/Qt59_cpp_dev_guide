#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 置顶
    setWindowFlags(Qt::WindowStaysOnTopHint);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pBtnCalc_clicked()
{
    QString num = ui->edNum->text();
    QString price = ui->edPrice->text();
    qint64 total = num.toInt()*price.toInt();
    ui->edTotal->setText(QString::number(total));
}

void MainWindow::on_pBtnDec_clicked()
{
    QString strDec = ui->edDec->text();
    QString strHex = QString::number(strDec.toInt(),16);
    ui->edHex->setText(strHex.toUpper());
    QString strBin = QString::number(strDec.toInt(),2);
    ui->edBin->setText(strBin);
}

void MainWindow::on_pBtnBin_clicked()
{
    QString strBin = ui->edBin->text();
    bool ok = true;
    qint64 strInt = strBin.toInt(&ok, 2);
    ui->edDec->setText(QString::number(strInt));

    QString strHex = QString::number(strInt, 16);
    ui->edHex->setText(strHex.toUpper());
}

void MainWindow::on_pBtnHex_clicked()
{
    QString strHex = ui->edHex->text();
    bool ok = true;
    qint64 strInt = strHex.toInt(&ok, 16);

    ui->edDec->setText(QString::number(strInt));

    QString strBin = QString::number(strInt,2);
    ui->edBin->setText(strBin);
}
