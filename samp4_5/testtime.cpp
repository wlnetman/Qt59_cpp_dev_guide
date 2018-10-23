#include "testtime.h"
#include "ui_testtime.h"
#include <QDate>
#include <QDateTime>
#include <QTime>

TestTime::TestTime(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::TestTime)
{
    ui->setupUi(this);

    setWindowTitle("时间和定时器");
    setWindowFlags(Qt::WindowStaysOnTopHint);

    // 关联定时器
    fTimer = new QTimer(this);
    fTimer->stop();
    fTimer->setInterval(1000); // 定是周期1000毫秒
    connect(fTimer, &QTimer::timeout, this, &TestTime::on_timer_timeout);
}

TestTime::~TestTime()
{
    delete ui;
}

void TestTime::on_calendar_clicked(const QDate& date)
{
    QString str = date.toString("yyyy年MM月dd日");
    ui->edSelected->setText(str);
}

void TestTime::on_btnTimeNow_clicked()
{
    QDateTime local(QDateTime::currentDateTime());
    QTime t = local.time();
    ui->spinTime->setTime(t);
    QDate d = local.date();
    ui->dateEdit->setDate(d);
    ui->dateTimeEdit->setDateTime(local);
}

void TestTime::on_timer_timeout()
{
    QTime curTime = QTime::currentTime();
    ui->lcdHour->display(curTime.hour());
    ui->lcdMuite->display(curTime.minute());
    ui->lcdSecond->display(curTime.second());

    int va = ui->progressBar->value();
    va++;
    if (va > 100)
        va = 0;
    ui->progressBar->setValue(va);
}

void TestTime::on_btStart_clicked()
{
    fTimer->start();
    fTimeCounter.start();
    ui->btStart->setEnabled(false);
    ui->btStop->setEnabled(true);
    ui->btnSetInter->setEnabled(true);
}

void TestTime::on_btStop_clicked()
{
    fTimer->stop();
    int tmMsec = fTimeCounter.elapsed();
    int ms = tmMsec % 1000;
    int sec = tmMsec / 1000;
    QString str = QString::asprintf("流逝时间: %d 秒， %d 毫秒", sec, ms);
    ui->labTimer->setText(str);
    ui->btStart->setEnabled(true);
    ui->btStop->setEnabled(false);
    ui->btnSetInter->setEnabled(true);
}
