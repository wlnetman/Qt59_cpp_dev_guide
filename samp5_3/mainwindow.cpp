#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->splitter);
    standModel = new QStandardItemModel(2, FixedColumnCount, this);
    selectModel = new QItemSelectionModel(standModel);
    connect( selectModel, &QItemSelectionModel::currentChanged,
             this, &MainWindow::on_currentChanged);
    ui->tableView->setModel(standModel);
    ui->tableView->setSelectionModel(selectModel);
    ui->tableView->setSelectionMode(QAbstractItemView::ExtendedSelection);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectItems);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_currentChanged(const QModelIndex &current, const QModelIndex &previous)
{
    Q_UNUSED(previous);
    if(current.isValid()){
        labCellPos->setText(QString::asprintf("当前单元格：%d行，%d列", current.row(), current.column()));
        QStandardItem *aItem = standModel->itemFromIndex(current);
        this->labCellText->setText("单元格内容：" + aItem->text() );
        QFont font = aItem->font();
        ui->actBold->setCheckable(font.bold());
    }
}
