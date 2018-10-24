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
    QListWidget* aItem;
    QIcon aIcon;
    aIcon.addFile(":/images/incons/check.png");
    bool chk = ui->chkBoxListEditable->isChecked();

    ui->listWidget->clear();
    for (int i = 0; i < 10; i++) {
    }
}
