#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setPalette(QPalette(Qt::white));
    setAutoFillBackground(true);
    resize(1024,768);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::TextAntialiasing);

    const qreal  pi = 3.1415;
    qreal R = 100.00;
    qreal deg = pi*72/180;
    QPointF points[5] = {
        QPointF(R,0),
        QPointF(R*std::cos(deg), -R*std::sin(deg)),
        QPointF(R*std::cos(2*deg), -R*std::sin(2*deg)),
        QPointF(R*std::cos(3*deg), -R*std::sin(3*deg)),
        QPointF(R*std::cos(4*deg), -R*std::sin(4*deg))
    };
    QFont font;
    font.setPointSize(12);
    font.setBold(true);
    painter.setFont(font);

    QPen penLine;
    penLine.setWidth(2);
    penLine.setColor(Qt::red);
    penLine.setStyle(Qt::SolidLine);
    penLine.setCapStyle(Qt::FlatCap);
    penLine.setJoinStyle(Qt::BevelJoin);
    painter.setPen(penLine);

    QBrush brush;
    brush.setColor(Qt::yellow);
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);

    QPainterPath starPath;
    starPath.moveTo(points[0]);
    starPath.lineTo(points[2]);
    starPath.lineTo(points[4]);
    starPath.lineTo(points[1]);
    starPath.lineTo(points[3]);
    starPath.closeSubpath();
    starPath.addText(points[0], font, "0");
    starPath.addText(points[1], font, "1");
    starPath.addText(points[2], font, "2");
    starPath.addText(points[3], font, "3");
    starPath.addText(points[4], font, "4");

    painter.save();
    painter.translate(100, 200);
    painter.drawPath(starPath);
    painter.drawText(0, 0, "S1");
    painter.restore();

    painter.translate(300, 120);
    painter.scale(0.5, 0.5);
    painter.rotate(45);
    painter.drawPath(starPath);
    painter.drawText(0, 0, "S2");

    painter.resetTransform();
    painter.translate(500, 120);
    painter.rotate(-145);
    painter.drawPath(starPath);
    painter.drawText(0, 0, "S3");

    base_paint();
}

void Widget::base_paint()
{
    QPainter painter(this);
    int W = this->width();
    int H = this->height();
    QRect rect(W/4, H/4, W/2, H/2);
    QPainterPath path;
    path.addEllipse(rect);
    path.addRect(rect);
    painter.fillPath(path, Qt::green);

    QRect rect2(W/8, H/8, W/4, H/4);
    //painter.fillRect(rect2, Qt::red);

    painter.resetTransform();
    painter.translate(100, 400);
    QRect rect3(W/5, H/5, W/2, H/2);
    int startAngle = 90*16;
    int spanAngle = 90*16;
    painter.drawArc(rect3, startAngle, spanAngle);
    rect3.moveLeft(30);
    painter.drawChord(rect3, startAngle, spanAngle);

    rect3.moveLeft(30);
    painter.drawEllipse(rect3);
}
