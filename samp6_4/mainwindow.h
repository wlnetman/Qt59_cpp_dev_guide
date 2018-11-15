#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMdiSubWindow>
#include <QMdiArea>
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

    void on_actDoc_Open_triggered();

    void on_actCopy_triggered();

    void on_actCascade_triggered();

    void on_actTile_triggered();


    void on_actMdi_triggered(bool checked);

    void on_mdiArea_subWindowActivated(QMdiSubWindow *arg1);

    void on_actPaste_triggered();

    void on_actDoc_New_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
