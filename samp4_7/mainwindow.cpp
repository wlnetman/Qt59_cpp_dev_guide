#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setActionForButton();
    createSelectionPopMenu();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setActionForButton()
{
    ui->tBtnListIni->setDefaultAction(ui->actListIni);
    ui->tBtnListClear->setDefaultAction(ui->actListClear);
    ui->tBtnListINsert->setDefaultAction(ui->actListInsert);
    ui->tBtnListAppend->setDefaultAction(ui->actListAppend);
    ui->tBtnListDelete->setDefaultAction(ui->actListAppend);
    ui->tBtnSelAll->setDefaultAction(ui->actSelAll);
    ui->tBtnSelNone->setDefaultAction(ui->actSelNone);
    ui->tBtnSelInvs->setDefaultAction(ui->actInvs);
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
        if (chk)
            aItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEditable
                | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
        else
            aItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsUserCheckable
                | Qt::ItemIsEnabled);
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
    if (ui->chkBoxListEditable->isChecked())
        aItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEditable
            | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
    else
        aItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsUserCheckable
            | Qt::ItemIsEnabled);
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
    if (ui->chkBoxListEditable->isChecked())
        aItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEditable
            | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
    else
        aItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsUserCheckable
            | Qt::ItemIsEnabled);
    ui->listWidget->addItem(aItem);
    ui->listWidget->setCurrentItem(aItem);
}

void MainWindow::on_actListDelete_triggered()
{
    int cur = ui->listWidget->currentRow();
    QListWidgetItem* item = ui->listWidget->takeItem(cur);
    delete item;
}

void MainWindow::on_actSelAll_triggered()
{
    int cnt = ui->listWidget->count();
    for (int i = 0; i < cnt; i++) {
        QListWidgetItem* aItem = ui->listWidget->item(i);
        aItem->setCheckState(Qt::Checked);
    }
}

void MainWindow::on_actSelNone_triggered()
{
    int cnt = ui->listWidget->count();
    for (int i = 0; i < cnt; i++) {
        QListWidgetItem* aItem = ui->listWidget->item(i);
        aItem->setCheckState(Qt::Unchecked);
    }
}

void MainWindow::on_listWidget_currentItemChanged(QListWidgetItem* current, QListWidgetItem* previous)
{
    QString str;
    if (current != nullptr) {
        if (previous == nullptr)
            str = "当前项: " + current->text();
        else
            str = "前一项" + previous->text();
        ui->editCutItemText->setText(str);
    }
}

void MainWindow::on_actInvs_triggered()
{
    int cnt = ui->listWidget->count();
    for (int i = 0; i < cnt; i++) {
        QListWidgetItem* aItem = ui->listWidget->item(i);
        if (aItem->checkState() == Qt::Unchecked)
            aItem->setCheckState(Qt::Checked);
        else
            aItem->setCheckState(Qt::Unchecked);
    }
}

void MainWindow::createSelectionPopMenu()
{
    QMenu* menuSelection = new QMenu(this);
    menuSelection->addAction(ui->actSelNone);
    menuSelection->addAction(ui->actSelAll);
    menuSelection->addAction(ui->actInvs);

    // tBtnSelectItem
    ui->tBtnSelectItem->setPopupMode(QToolButton::MenuButtonPopup);
    ui->tBtnSelectItem->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    ui->tBtnSelectItem->setDefaultAction(ui->actSelPopMenu);
    ui->tBtnSelectItem->setMenu(menuSelection);

    //
    QToolButton* aBtn = new QToolButton(this);
    aBtn->setPopupMode(QToolButton::InstantPopup);
    aBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    aBtn->setMenu(menuSelection);
    ui->mainToolBar->addWidget(aBtn);
    ui->mainToolBar->addSeparator();
    ui->mainToolBar->addAction(ui->actQuit);
}

void MainWindow::on_listWidget_customContextMenuRequested(const QPoint& pos)
{
    Q_UNUSED(pos);

    QMenu* menuList = new QMenu(this);
    menuList->addAction(ui->actListIni);
    menuList->addAction(ui->actListClear);
    menuList->addAction(ui->actListInsert);
    menuList->addAction(ui->actListAppend);
    menuList->addAction(ui->actListDelete);
    menuList->addSeparator();
    menuList->addAction(ui->actSelAll);
    menuList->addAction(ui->actSelNone);
    menuList->addAction(ui->actInvs);
    menuList->exec(QCursor::pos());
    delete menuList;
}
