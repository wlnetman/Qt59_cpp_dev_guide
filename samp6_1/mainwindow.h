#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnOpenDir_clicked();

    void on_btnClear_clicked();

    void on_btnOpenFiles_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
