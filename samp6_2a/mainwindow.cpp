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

    theSelection = new QItemSelectionModel(theModel);
    ui->tableView->setSelectionModel(theSelection);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete dialog_;
}

void MainWindow::setACellText(int row, int col, QString text)
{
    QModelIndex index = theModel->index(row , col);
    theSelection->clearSelection();
    theSelection->setCurrentIndex(index, QItemSelectionModel::Select);
    theModel->setData(index, text, Qt::DisplayRole);
}

void MainWindow::setDlgLocateNull()
{
    locate_ = nullptr;
}

void MainWindow::setDlgLocateEnable(bool enable)
{
    ui->actLocate->setEnabled(enable);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton result;
    result = QMessageBox::question(this,
                                    "退出",
                                    "确认退出本程序嘛？",
                                    QMessageBox::Yes|
                                    QMessageBox::No |
                                    QMessageBox::Cancel);
    if( result == QMessageBox::Yes)
        event->accept();
    else
        event->ignore();
}

void MainWindow::on_actionactSetRowAndCol_triggered()
{
    if(dialog_ == nullptr)
        dialog_ = new QWDialogHeaders(this);

    dialog_->setRowColumn(theModel->rowCount(), theModel->columnCount());
    int ret = dialog_->exec();
    if( ret == QDialog::Accepted ){
        int row = dialog_->rowCount();
        int col = dialog_->columnCount();
        theModel->setRowCount(row);
        theModel->setColumnCount(col);
    }
}

void MainWindow::on_actLocate_triggered()
{
    //ui->actLocate->setEnabled(false);

    locate_ = new QWDialogLocate(this);
    locate_->setAttribute(Qt::WA_DeleteOnClose);

    Qt::WindowFlags flags = locate_->windowFlags();
    locate_->setWindowFlags( flags | Qt::WindowStaysOnTopHint);
    QModelIndex curIndex = theSelection->currentIndex();
    if(curIndex.isValid()){
        locate_->setSpinValue(curIndex.row(), curIndex.column());

        // 对话框直接发射信号enable
        connect(locate_, &QWDialogLocate::changeCellText,
                this, &MainWindow::setACellText);
        connect(locate_, &QWDialogLocate::changeActionEvent,
                this, &MainWindow::setDlgLocateEnable);
        connect(this, &MainWindow::cellIndexChange,
                locate_, &QWDialogLocate::setSpinValue);

        locate_->show();
    }
}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    emit cellIndexChange(index.row(), index.column());

    //if(locate_ != nullptr)
    //    locate_->setSpinValue(index.row(), index.column());
}
