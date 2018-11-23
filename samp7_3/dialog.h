#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QFileDialog>
#include <QDir>
#include <QPushButton>
#include <QFileSystemWatcher>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButton_clicked();

    void on_btnDir_clicked();


    void on_btnAbsoluteFile_clicked();

    void on_btnBaseName_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_18_clicked();

private:
    Ui::Dialog *ui;

    QFileSystemWatcher watcher_;
    void showButtonTitle();
public slots:
    void on_directoryChanged(const QString path);
    void on_fileChanged(const QString path);
};

#endif // DIALOG_H
