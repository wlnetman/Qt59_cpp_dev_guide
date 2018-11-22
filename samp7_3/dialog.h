#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QFileDialog>
#include <QDir>
#include <QPushButton>

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

private:
    Ui::Dialog *ui;

    void showButtonTitle();
};

#endif // DIALOG_H
