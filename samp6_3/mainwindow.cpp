#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qformdoc.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("多窗口应用程序");

    ui->tabWidget->setVisible(false);
    ui->tabWidget->clear();
    ui->tabWidget->tabsClosable();
    setCentralWidget(ui->tabWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPixmap map(":/images/images/back.jpg");
    QPainter painter(this);
    painter.drawPixmap(map);
}

void MainWindow::on_actWidgetInsite_triggered()
{
    QFormDoc *form = new QFormDoc(this);
    form->setAttribute(Qt::WA_QuitOnClose);
    int cur = ui->tabWidget->addTab(form,
                                    QString::asprintf("Tab %d", ui->tabWidget->count()));
    ui->tabWidget->setCurrentIndex(cur);
    ui->tabWidget->setVisible(true);
}

void MainWindow::on_actWidget_triggered()
{
    QFormDoc *form = new QFormDoc();
    form->setAttribute(Qt::WA_DeleteOnClose);
    form->setWindowTitle("独立式Widget，无父窗口，关闭时删除");
    form->setWindowFlag(Qt::Window, true);
    form->setWindowOpacity(0.9);
    form->show();
}
