#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QLabel>
#include <QResizeEvent>
#include <QBrush>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QGraphicsScene *scene;
    QLabel *labViewCord;
    QLabel *labSceneCord;
    QLabel *labItemCord;
    void iniGraphicsSystem();

protected:
    void resizeEvent(QResizeEvent *event);

private slots:
    void on_mouseMovePoint(QPoint point);
    void on_mouseClicked(QPoint point);

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
