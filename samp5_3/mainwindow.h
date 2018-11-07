#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QItemSelectionModel>
#include <QStandardItemModel>

namespace Ui {
class MainWindow;
}

#define FixedColumnCount 6
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_currentChanged(const QModelIndex &current, const QModelIndex &previous);

private:
    Ui::MainWindow *ui;

    QLabel *labCurFile;
    QLabel *labCellPos;
    QLabel *labCellText;
    QStandardItemModel *standModel;
    QItemSelectionModel *selectModel;

    void iniModelFromStringList(QString &);
};

#endif // MAINWINDOW_H
