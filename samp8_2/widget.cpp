#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setPalette(QPalette(Qt::white));
    setAutoFillBackground(true);
    resize(600,300);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::PaintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::TextAntialiasing);

    qreal R = 100;
    const qreal  pi = 3.141592653589;
    qreal deg = pi*72/180;
    QPoint points[5] = {
        QPoint(R,0),
        QPoint(R*std::cos(deg), -R*std::sin(deg)),
        QPoint(R*std::cos(2*deg), -R*std::sin(2*deg)),
        QPoint(R*std::cos(3*deg), -R*std::sin(3*deg)),
        QPoint(R*std::cos(4*deg), -R*std::sin(4*deg))
    };
    QFont font;
    font.setPointSize(12);
    font.setBold(true);
    painter.setFont(font);
    QPen penLine;
    penLine.setWidth(2);
    penLine.setColor(Qt::blue);
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
    painter.translate(100, 120);
    painter.drawPath(starPath);
    painter.drawText(0, 0, "S1");
    painter.restore();

    painter.translate(300, 120);
    painter.scale(0.8, 0.8);
    painter.rotate(90);
    painter.drawPath(starPath);
    painter.drawText(0, 0, "S2");

    painter.resetTransform();
    painter.translate(500, 120);
    painter.rotate(-145);
    painter.drawPath(starPath);
    painter.drawText(0, 0, "S3");
}
