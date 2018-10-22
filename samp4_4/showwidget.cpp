#include "showwidget.h"
#include "ui_showwidget.h"

ShowWidget::ShowWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShowWidget)
{
    ui->setupUi(this);
}

ShowWidget::~ShowWidget()
{
    delete ui;
}
