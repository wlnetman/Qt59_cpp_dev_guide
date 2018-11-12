#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qwdialogheaders.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    theModel = new QStandardItemModel(2,2, this);
    ui->tableView->setModel(theModel);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionactSetRowAndCol_triggered()
{
    QWDialogHeaders *dialog = new QWDialogHeaders(this);
    dialog->setRowColumn(theModel->rowCount(), theModel->columnCount());
    int ret = dialog->exec();
    if( ret == QDialog::Accepted ){
        int row = dialog->rowCount();
        int col = dialog->columnCount();
        theModel->setRowCount(row);
        theModel->setColumnCount(col);
    }
    delete dialog;
}
