#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    void paintEvent(QPaintEvent *event);
    void paintComposition();
    void paintComposition2();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
