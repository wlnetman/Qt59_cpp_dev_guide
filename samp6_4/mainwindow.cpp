#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qformdoc.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("MDI程序示例");

    setCentralWidget(ui->mdiArea);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPixmap map(":/images/images/summer.jpg");
    QPainter painter(this);
    int left = 0;
    int top = ui->toolBar->height();
    int right = this->width();
    int bottom= this->height()-ui->toolBar->height()-ui->statusbar->height();

    painter.drawPixmap(left, top, right, bottom ,map);
}

void MainWindow::on_actDoc_New_triggered()
{
    QFormDoc* formDoc = new QFormDoc(this);
    ui->mdiArea->addSubWindow(formDoc);
    formDoc->show();
}

void MainWindow::on_actDoc_Open_triggered()
{
    QFormDoc *formDoc;
    if(ui->mdiArea->subWindowList().count()>0){
        formDoc = static_cast<QFormDoc*>(ui->mdiArea->activeSubWindow()->widget());
    } else {
        formDoc = new QFormDoc();
        ui->mdiArea->addSubWindow(formDoc);
    }

    QString cur_path = QDir::currentPath();
    QString fname = QFileDialog::getOpenFileName(this,
                    "打开一个文件", cur_path, "文本文件 (*.h,*.cpp);CPP文件(*.txt)");
    if(fname.isEmpty())
        return;

    formDoc->loadFromFile(fname);
    formDoc->show();

    ui->actCopy->setEnabled(true);
    ui->actCut->setEnabled(true);
    ui->actPaste->setEnabled(true);
    ui->actClose->setEnabled(true);
}


void MainWindow::on_actCascade_triggered()
{
    ui->mdiArea->cascadeSubWindows();
}

void MainWindow::on_actTile_triggered()
{
    ui->mdiArea->tileSubWindows();
}

void MainWindow::on_actMdi_triggered(bool checked)
{
    if(checked){
        ui->mdiArea->setViewMode(QMdiArea::TabbedView);
        ui->mdiArea->setTabsClosable(true);
        ui->actCascade->setEnabled(false);
        ui->actTile->setEnabled(false);
    } else {
        ui->mdiArea->setViewMode(QMdiArea::SubWindowView);
        ui->actCascade->setEnabled(true);
        ui->actTile->setEnabled(true);
    }
}

void MainWindow::on_mdiArea_subWindowActivated(QMdiSubWindow *arg1)
{
    Q_UNUSED(arg1)

    if(ui->mdiArea->subWindowList().count() == 0) {
        ui->actCut->setEnabled(false);
        ui->actCopy->setEnabled(false);
        ui->actPaste->setEnabled(false);
        ui->statusbar->clearMessage();
    } else {
        QFormDoc* form = static_cast<QFormDoc*>( ui->mdiArea->activeSubWindow()->widget());
        ui->statusbar->showMessage(form->currentFileName());
    }
}

void MainWindow::on_actCopy_triggered()
{
    QFormDoc *form = static_cast<QFormDoc*>(ui->mdiArea->activeSubWindow()->widget());
    form->textCut();
}

void MainWindow::on_actPaste_triggered()
{
    QFormDoc *form = static_cast<QFormDoc*>(ui->mdiArea->activeSubWindow()->widget());
    form->textPaste();
}


