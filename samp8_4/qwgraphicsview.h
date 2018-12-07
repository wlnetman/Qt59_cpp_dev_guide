#ifndef QWGRAPHICSVIEW_H
#define QWGRAPHICSVIEW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QGraphicsView>

namespace Ui {
class QWGraphicsView;
}

class QWGraphicsView :public QGraphicsView
{
    Q_OBJECT

public:
    QWGraphicsView(QWidget *parent = nullptr);

protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent* event);

signals:
    void mouseMovePoint(QPoint point);
    void mouseClicked(QPoint point);
};

#endif // QWGRAPHICSVIEW_H
