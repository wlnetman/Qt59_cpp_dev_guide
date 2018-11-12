#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QTableView>
#include <QStandardItemModel>
#include <QStandardItem>

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
    void on_actionactSetRowAndCol_triggered();

private:
    Ui::MainWindow *ui;

    QStandardItemModel *theModel;
};

#endif // MAINWINDOW_H
