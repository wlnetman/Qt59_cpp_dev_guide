#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QItemSelectionModel>
#include <QStandardItemModel>
#include <QFileDialog>
#include <QTextStream>
#include <QList>
#include <QDebug>
#include "qwintspindelegate.h"

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

    void on_actOpen_triggered();

    void on_actAppend_triggered();

    void on_actInsert_triggered();

    void on_actDelete_triggered();

    void on_actAlignLeft_triggered();

    void on_actAlignRight_triggered();

private:
    Ui::MainWindow *ui;

    QLabel *labCurFile;
    QLabel *labCellPos;
    QLabel *labCellText;
    QStandardItemModel *standModel;
    QItemSelectionModel *selectModel;

    QWIntSpinDelegate intSpinDelegate; // 整数型spinbox

    void iniModelFromStringList(QStringList &);
};

#endif // MAINWINDOW_H
