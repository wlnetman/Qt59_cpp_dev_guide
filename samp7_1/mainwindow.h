#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextCodec>

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
    void on_actQFileOpen_triggered();

    void on_actQFileSave_triggered();

    void on_actQTextOpen_triggered();

    void on_actQTextSave_triggered();

private:
    Ui::MainWindow *ui;

private:
    QFile* openFile(QIODevice::OpenMode flag);
};

#endif // MAINWINDOW_H
