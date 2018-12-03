#include "qwgraphicsview.h"
#include "ui_qwgraphicsview.h"

QWGraphicsView::QWGraphicsView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QWGraphicsView)
{
    ui->setupUi(this);
}

QWGraphicsView::~QWGraphicsView()
{
    delete ui;
}

void QWGraphicsView::mouseMoveEvent(QMouseEvent *event)
{
    QPoint point = event->pos();
    emit mouseMovePoint(point);
    QGraphicsView::mouseMoveEvent(event);
}

void QWGraphicsView::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        QPoint point = event->pos();
        emit mouseClicked(point);
    }
    QGraphicsView::mousePressEvent(event);
}


