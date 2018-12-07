#include "qwgraphicsview.h"

QWGraphicsView::QWGraphicsView(QWidget *parent)
{
    Q_UNUSED(parent);
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


