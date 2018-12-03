#ifndef QWGRAPHICSVIEW_H
#define QWGRAPHICSVIEW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QGraphicsView>

namespace Ui {
class QWGraphicsView;
}

class QWGraphicsView : public QMainWindow
        ,public QGraphicsView
{
    Q_OBJECT

public:
    explicit QWGraphicsView(QWidget *parent = nullptr);
    ~QWGraphicsView();

protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent* event);

private:
    Ui::QWGraphicsView *ui;

signals:
    void mouseMovePoint(QPoint point);
    void mouseClicked(QPoint point);

};

#endif // QWGRAPHICSVIEW_H
