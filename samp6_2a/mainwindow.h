#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QCloseEvent>
#include <QTableView>
#include <QStandardItemModel>
#include <QStandardItem>
#include "qwdialogheaders.h"
#include "qwdialoglocate.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setDlgLocateNull();


public slots:
    void setACellText(int row,int col, QString text);

    void setDlgLocateEnable(bool enable);

    void closeEvent(QCloseEvent *event);

signals:
    void cellIndexChange(int rowNo, int colNo);

private slots:
    void on_actionactSetRowAndCol_triggered();

    void on_actLocate_triggered();

    void on_tableView_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;

    QStandardItemModel *theModel;
    QItemSelectionModel *theSelection;

    QWDialogHeaders *dialog_ = nullptr;
    QWDialogLocate *locate_;
};

#endif // MAINWINDOW_H
