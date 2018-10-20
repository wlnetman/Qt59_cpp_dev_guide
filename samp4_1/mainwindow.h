#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_pBtnCalc_clicked();

    void on_pBtnDec_clicked();

    void on_pBtnBin_clicked();

    void on_pBtnHex_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
