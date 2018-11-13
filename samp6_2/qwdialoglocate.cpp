#include "qwdialoglocate.h"
#include "ui_qwdialoglocate.h"
#include "mainwindow.h"

QWDialogLocate::QWDialogLocate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QWDialogLocate)
{
    ui->setupUi(this);

    setWindowTitle("单元格定位对话框");
}

QWDialogLocate::~QWDialogLocate()
{
    delete ui;
}

void QWDialogLocate::setSpinValue(int rowNo, int colNo)
{
    ui->spinBoxRow->setValue(rowNo);
    ui->spinBoxCol->setValue(colNo);
}

void QWDialogLocate::closeEvent(QCloseEvent *event)
{
    Q_UNUSED(event);

    MainWindow *parWin = static_cast<MainWindow*>(parentWidget());
    parWin->setDlgLocateNull();
}

void QWDialogLocate::on_btnSetText_clicked()
{
    int row = ui->spinBoxRow->value();
    int col = ui->spinBoxCol->value();
    QString text = ui->lineEdit->text();

    MainWindow *parWindow = static_cast<MainWindow*>(parentWidget());
    parWindow->setACellText(row, col, text);
}
