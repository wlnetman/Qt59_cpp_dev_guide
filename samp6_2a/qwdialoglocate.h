#ifndef QWDIALOGLOCATE_H
#define QWDIALOGLOCATE_H

#include <QDialog>
#include <QCloseEvent>
#include <QShowEvent>

namespace Ui {
class QWDialogLocate;
}

class QWDialogLocate : public QDialog
{
    Q_OBJECT

public:
    explicit QWDialogLocate(QWidget *parent = nullptr);
    ~QWDialogLocate();

public slots:
    void setSpinValue(int rowNo, int colNo);

private:
    void closeEvent(QCloseEvent *event);
    void showEvent(QShowEvent *event);

private slots:
    void on_btnSetText_clicked();

signals:
    void changeActionEvent(bool enable);
    void changeCellText(int row, int col, QString &text);

private:
    Ui::QWDialogLocate *ui;
};

#endif // QWDIALOGLOCATE_H
