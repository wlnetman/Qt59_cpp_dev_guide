#include <QDate>
#include <QDateTime>
#include <QTime>
#include "testtime.h"
#include "ui_testtime.h"

TestTime::TestTime(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestTime)
{
    ui->setupUi(this);

    setWindowTitle("时间和定时器");
    setWindowFlags(Qt::WindowStaysOnTopHint);
}

TestTime::~TestTime()
{
    delete ui;
}

void TestTime::on_calendar_clicked(const QDate &date)
{
    QString str = date.toString("yyyy-'mm-'dd");
    ui->edSelected->setText(str);
}

void TestTime::on_btnTimeNow_clicked()
{
    QDateTime local(QDateTime::currentDateTime());
    QTime t = local.time();
    ui->spinTime->setValue(t.msec());
    QDate d = local.date();
    ui->cbDate->addItem(d.toString());
}
