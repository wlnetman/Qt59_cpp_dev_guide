#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setPalette(QPalette(Qt::white));
    setAutoFillBackground(true);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::nomualPaint()
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::TextAntialiasing);

    int W = this->width();
    int H = this->height();

    QRect rect(W/4, H/4, W/2, H/2);

    QPen pen;
    pen.setWidth(3);
    pen.setColor(Qt::red);
    pen.setCapStyle(Qt::FlatCap);
    pen.setJoinStyle(Qt::BevelJoin);

    painter.setPen(pen);

    QBrush brush;
    brush.setColor(Qt::yellow);
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);
    painter.drawRect(rect);
}

void Widget::texturePaint()
{
    QPainter painter(this);
    int W = this->width();
    int H = this->height();

    QRect rect(W/5, H/5, W/3, H/3);

    QPen pen;
    pen.setWidth(3);
    pen.setColor(Qt::red);
    pen.setStyle(Qt::SolidLine);
    painter.setPen(pen);

    QPixmap texturePixmap(":images/images/timg.jpg");
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setTexture(texturePixmap);
    painter.setBrush(brush);
    painter.drawRect(rect);
}

void Widget::spreadPaint()
{
    QPainter painter(this);
    int W = this->width();
    int H = this->height();

    QRect rect(W/8, H/8, W/4, H/4);

    QRadialGradient radialGrad(W/2, H/2, qMax(W/8, H/8), W/2, H/2);
    radialGrad.setColorAt(0, Qt::green);
    radialGrad.setColorAt(1, Qt::blue);
    radialGrad.setSpread(QGradient::ReflectSpread);
    painter.setBrush(radialGrad);

    painter.drawRect(this->rect());
}

void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    nomualPaint();

    texturePaint();

    //spreadPaint();
}
