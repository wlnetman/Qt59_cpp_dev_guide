#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QPixmap>
#include <QRadialGradient>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget() Q_DECL_OVERRIDE;

private:
    void nomualPaint();
    void texturePaint();
    void spreadPaint();

    void customPaint();
private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
