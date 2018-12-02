#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    //paintComposition();

    paintComposition2();
}

void Widget::paintComposition()
{
    QPainter painter(this);
    int W = width();
    int H = height();
    int side = qMin(W, H);
    QRect rect( (W-side)/2, (H-side)/2, side, side);
    painter.drawRect(rect);
    painter.setViewport(rect);
    painter.setWindow( -100, -100, 200, 200);
    painter.setRenderHint(QPainter::Antialiasing);

    QPen pen;
    pen.setWidth(1);
    pen.setColor(Qt::red);
    pen.setStyle(Qt::SolidLine);
    painter.setPen(pen);
    for(int i = 0; i < 36; i++){
        painter.drawEllipse(QPoint(50,0), 50, 50);
        painter.rotate(10);
    }
}

void Widget::paintComposition2()
{
    QPainter painter(this);
    int W = width();
    int H = height();
    int side = qMin(W, H);
    QRect rect( (W-side)/2, (H-side)/2, side, side);
    painter.drawRect(rect);
    painter.setViewport(rect);
    painter.setWindow( -100, -100, 200, 200);
    painter.setRenderHint(QPainter::Antialiasing);

    QPen pen;
    pen.setWidth(1);
    pen.setColor(Qt::red);
    pen.setStyle(Qt::SolidLine);
    painter.setPen(pen);
    QLinearGradient lineargrad(0, 0, 100, 0);
    lineargrad.setColorAt(0, Qt::yellow);
    lineargrad.setColorAt(1, Qt::green);
    lineargrad.setSpread(QGradient::PadSpread);
    painter.setBrush(lineargrad);

    // 设置复合模式
    //painter.setCompositionMode(QPainter::RasterOp_NotSourceXorDestination);
    painter.setCompositionMode(QPainter::CompositionMode_Difference);
    //painter.setCompositionMode(QPainter::CompositionMode_Exclusion);
    for(int i = 0; i < 36; i++){
        painter.drawEllipse(QPoint(50,0), 50, 50);
        painter.rotate(10);
    }
}
