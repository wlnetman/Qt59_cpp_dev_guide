#ifndef SHOWWIDGET_H
#define SHOWWIDGET_H

#include <QWidget>

namespace Ui {
class ShowWidget;
}

class ShowWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ShowWidget(QWidget *parent = nullptr);
    ~ShowWidget();

private:
    Ui::ShowWidget *ui;
};

#endif // SHOWWIDGET_H
