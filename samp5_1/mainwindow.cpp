#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model = new QFileSystemModel(this);
    model->setRootPath(QDir::currentPath());
    ui->treeView->setModel(model);
    ui->listView->setModel(model);
    ui->tableView->setModel(model);

    connect(ui->treeView, &QTreeView::clicked,
            ui->listView, &QListView::setRootIndex);
    connect(ui->treeView, &QTreeView::clicked,
            ui->tableView, &QTableView::setRootIndex);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_treeView_clicked(const QModelIndex &index)
{
    ui->chkIsDir->setChecked(model->isDir(index));
    ui->labPath->setText(model->filePath(index));
    ui->labFileName->setText(model->fileName(index));
    ui->labFileType->setText(model->type(index));
    int sz = model->size(index)/1024;
    if(sz < 1024){
        ui->labSize->setText(QString("%1 KB").arg(sz));
    } else {
        ui->labSize->setText(QString::asprintf("%.1f MB", sz/1024.0));
    }
}
