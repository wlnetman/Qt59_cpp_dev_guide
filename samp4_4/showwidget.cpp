#include "showwidget.h"
#include "ui_showwidget.h"

ShowWidget::ShowWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShowWidget)
{
    ui->setupUi(this);

    setWindowTitle("显示组件");
    setWindowFlags(Qt::WindowStaysOnTopHint);

    connect(ui->SliderGreen, &QSlider::valueChanged, this, &ShowWidget::on_SliderRed_valueChanged);
    connect(ui->SliderBlue, &QSlider::valueChanged, this, &ShowWidget::on_SliderRed_valueChanged);
    connect(ui->SliderAphla, &QSlider::valueChanged, this, &ShowWidget::on_SliderRed_valueChanged);
}

ShowWidget::~ShowWidget()
{
    delete ui;
}

void ShowWidget::on_SliderRed_valueChanged(int value)
{
    Q_UNUSED(value);
    QColor color;
    int red = ui->SliderRed->value();
    int green = ui->SliderGreen->value();
    int blue = ui->SliderBlue->value();
    int alpha = ui->SliderAphla->value();
    color.setRgb(red, green, blue, alpha);
    QPalette pal = ui->textEdit->palette();
    pal.setColor(QPalette::Base, color);
    ui->textEdit->setPalette(pal);
}
