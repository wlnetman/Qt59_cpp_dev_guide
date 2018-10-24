#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actListIni_triggered()
{
    QIcon aIcon;
    aIcon.addFile(":/images/images/icons/ball_blue.ico");
    bool chk = ui->chkBoxListEditable->isChecked();

    ui->listWidget->clear();
    for (int i = 0; i < 10; i++) {
        QListWidgetItem* aItem = new QListWidgetItem(ui->listWidget);
        aItem->setIcon(aIcon);
        aItem->setText(QString::asprintf("Item %d", i));
        aItem->setCheckState(Qt::Checked);
        if(chk)
            aItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEditable
                           |Qt::ItemIsUserCheckable |Qt::ItemIsEnabled);
        else
            aItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsUserCheckable
                           |Qt::ItemIsEnabled);
    }
}

void MainWindow::on_actListClear_triggered()
{
    ui->listWidget->clear();
}

void MainWindow::on_actListInsert_triggered()
{
    QIcon aIcon;
    aIcon.addFile(":/images/images/icons/ball_blue.ico");
    QListWidgetItem* aItem = new QListWidgetItem();
    aItem->setIcon(aIcon);
    aItem->setText(QString::asprintf("Insert Item "));
    aItem->setCheckState(Qt::Checked);
    if(ui->chkBoxListEditable->isChecked())
        aItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEditable
                       |Qt::ItemIsUserCheckable |Qt::ItemIsEnabled);
    else
        aItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsUserCheckable
                       |Qt::ItemIsEnabled);
    int cur = ui->listWidget->currentRow();
    ui->listWidget->insertItem(cur, aItem);
    ui->listWidget->setCurrentItem(aItem);
}

void MainWindow::on_actListAppend_triggered()
{
    QIcon aIcon;
    aIcon.addFile(":/images/images/icons/ball_blue.ico");
    QListWidgetItem* aItem = new QListWidgetItem();
    aItem->setIcon(aIcon);
    aItem->setText(QString::asprintf("add Item "));
    aItem->setCheckState(Qt::Checked);
    if(ui->chkBoxListEditable->isChecked())
        aItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEditable
                       |Qt::ItemIsUserCheckable |Qt::ItemIsEnabled);
    else
        aItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsUserCheckable
                       |Qt::ItemIsEnabled);
    ui->listWidget->addItem(aItem);
    ui->listWidget->setCurrentItem(aItem);
}

void MainWindow::on_actListDelete_triggered()
{
    int cur = ui->listWidget->currentRow();
    QListWidgetItem *item = ui->listWidget->takeItem(cur);
    delete item;
}
