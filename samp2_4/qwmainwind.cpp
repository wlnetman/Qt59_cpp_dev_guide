#include "qwmainwind.h"
#include "ui_qwmainwind.h"

QWMainWind::QWMainWind(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QWMainWind)
{
    ui->setupUi(this);
}

QWMainWind::~QWMainWind()
{
    delete ui;
}
