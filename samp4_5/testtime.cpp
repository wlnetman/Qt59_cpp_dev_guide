#include "testtime.h"
#include "ui_testtime.h"

TestTime::TestTime(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestTime)
{
    ui->setupUi(this);

    setWindowTitle("时间和定时器");
    setWindowFlags(Qt::WindowStaysOnTopHint);
    QRect rec = geometry();
    rec.moveLeft(920);
    setGeometry(rec);
}

TestTime::~TestTime()
{
    delete ui;
}
