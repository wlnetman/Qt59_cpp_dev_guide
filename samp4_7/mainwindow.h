#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QListWidget>
#include <QMainWindow>
#include <QMenu>
#include <QToolBar>
#include <QToolButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private:
    void setActionForButton();
    void createSelectionPopMenu();

private slots:
    void on_actListIni_triggered();

    void on_actListClear_triggered();

    void on_actListInsert_triggered();

    void on_actListDelete_triggered();

    void on_actListAppend_triggered();

    void on_actSelAll_triggered();

    void on_listWidget_currentItemChanged(QListWidgetItem* current, QListWidgetItem* previous);

    void on_actSelNone_triggered();

    void on_actInvs_triggered();

    void on_listWidget_customContextMenuRequested(const QPoint& pos);

private:
    Ui::MainWindow* ui;
};

#endif // MAINWINDOW_H
