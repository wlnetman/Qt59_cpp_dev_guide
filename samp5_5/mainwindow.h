#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QFileDialog>
#include <QMessageBox>
#include <QSize>
#include <QDir>
#include <QFileInfo>
#include <QSettings>

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
    void on_rbtn800_clicked();

    void on_rbtn400_clicked();

    void on_btnInputDir_clicked();

    void on_btnOutputDir_clicked();

    void on_btnStart_clicked();

    void on_rBtnCurDir_clicked();

private:
    Ui::MainWindow *ui;

    QSettings *settings_;
    QLabel* lab_status_;
    QString input_dir_;
    QString output_dir_;
    qint32  width_;
    qint32  height_;

    qint32  success_;
    qint32  error_;
    bool scaled_image(QString& source, QString& dest, QSize size);

    QString getDestNameFromSource(QString& filename, QSize size);

    QString load_last_dir();
    void save_last_dir(const QString &path);
};

#endif // MAINWINDOW_H
