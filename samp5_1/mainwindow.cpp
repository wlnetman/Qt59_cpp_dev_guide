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
    //ui->tableView->setModel(model);

    connect(ui->treeView, &QTreeView::clicked,
            ui->listView, &QListView::setRootIndex);
    //connect(ui->treeView, &QTreeView::clicked,
    //        ui->tableView, &QTableView::setRootIndex);
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

void MainWindow::on_listView_doubleClicked(const QModelIndex &index)
{
    QString filePath = model->filePath(index);
    readFileToItem(filePath);
}

void MainWindow::on_treeView_doubleClicked(const QModelIndex &index)
{
    QString filePath = model->filePath(index);
    readFileToItem(filePath);
}

void MainWindow::readFileToItem(QString filePath)
{
    QFileInfo info(filePath);
    if(info.isDir())
        return;
    QFile file(filePath);
    file.open(QIODevice::ReadOnly | QIODevice::Text);

    ui->comboBox->clear();
    ui->listWidget->clear();
    char buf[1024];
    qint64 lineLength = file.readLine(buf, sizeof(buf));
    if (lineLength == -1)
        return;
    QString line = QString::fromLocal8Bit(buf);
    line = line.trimmed();
    QStringList list = line.split(QRegExp("\\s+"));
    for(int i=0; i<list.size(); i++){
        ui->comboBox->addItem(list.at(i));
        ui->listWidget->addItem(list.at(i));
    }
}
