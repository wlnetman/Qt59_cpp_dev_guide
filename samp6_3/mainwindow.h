#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QPainter>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void paintEvent(QPaintEvent* event);

private slots:
    void on_actWidgetInsite_triggered();

    void on_actWidget_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
