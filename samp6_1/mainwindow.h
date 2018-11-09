#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QColorDialog>
#include <QColor>
#include <QFontDialog>
#include <QFont>
#include <QInputDialog>
#include <QMessageBox>

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

    void on_btnSelectDir_clicked();

    void on_btnSaveFile_clicked();

    void on_btnSelectColor_clicked();

    void on_btnSelectFont_clicked();

    void on_btnInputStr_clicked();

    void on_btnInputInt_clicked();

    void on_btnInputFloat_clicked();

    void on_btnCombobox_clicked();

    void on_btnQuestion_clicked();

    void on_btnInfo_clicked();

    void on_btnWarning_clicked();

    void on_btnCritical_clicked();

    void on_btnAbout_clicked();

    void on_btnAboutQt_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
