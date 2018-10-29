#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    LabFileName = new QLabel("");
    ui->statusbar->addWidget(LabFileName);
    this->setCentralWidget(ui->scrollArea);
    iniTree();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::iniTree()
{
    QString dataStr = "";
    ui->treeWidget->clear();
    QIcon icon;
    icon.addFile(":/images/images/folder_picture.png");

    QTreeWidgetItem* item = new QTreeWidgetItem(MainWindow::itTopItem);
    item->setIcon(MainWindow::colItem, icon);
    item->setText(MainWindow::colItem, "图片文件");
    item->setText(MainWindow::colItemType, "type=itTopItem");
    item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsUserCheckable
        | Qt::ItemIsEnabled | Qt::ItemIsTristate);
    item->setData(MainWindow::colItem, Qt::UserRole, QVariant(dataStr));
    ui->treeWidget->addTopLevelItem(item);
}

void MainWindow::on_actAddFolder_triggered()
{
    QString dir = QFileDialog::getExistingDirectory();
    if (!dir.isEmpty()) {
        QTreeWidgetItem* parItem = ui->treeWidget->currentItem();
        addFolderItem(parItem, dir);
    }
}

void MainWindow::addFolderItem(QTreeWidgetItem* parItem, QString dirName)
{
    QIcon icon;
    icon.addFile(":/images/images/addfloder.png");
    QString nodeText = getFinalFolderName(dirName);

    QTreeWidgetItem* item;
    item = new QTreeWidgetItem(MainWindow::itGroupItem);
    item->setIcon(colItem, icon);
    item->setText(colItem, nodeText);
    item->setText(colItemType, "type=itGroupItem");
    item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled
        | Qt::ItemIsAutoTristate);
    item->setCheckState(colItem, Qt::Checked);
    item->setData(colItem, Qt::UserRole, QVariant(dirName));
    parItem->addChild(item);
}

QString MainWindow::getFinalFolderName(const QString& fullPathName)
{
    int cnt = fullPathName.length();
    int i = fullPathName.lastIndexOf("/");
    QString str = fullPathName.right(cnt - i - i);
    return str;
}

void MainWindow::on_actAddFiles_triggered()
{
    QStringList files = QFileDialog::getOpenFileNames(this,
        "选择一个或者多个文件", "C:\\Users\\FuYou\\Pictures\\", "Images (*.png *.xpm *.jpg)");
    if (files.isEmpty())
        return;
    QTreeWidgetItem *parItem, *item;
    item = ui->treeWidget->currentItem();
    if (item->type() == itImageItem)
        parItem = item->parent();
    else
        parItem = item;
    for (int i = 0; i < files.size(); ++i) {
        QString aFileName = files.at(i);
        addImageItem(parItem, aFileName);
    }
}

void MainWindow::addImageItem(QTreeWidgetItem* parent, QString aFileName)
{
    QIcon icon(":/images/images/image.png");
    QString noteText = getFinalFolderName(aFileName);
    QTreeWidgetItem* item;
    item = new QTreeWidgetItem(MainWindow::itImageItem);
    item->setIcon(colItem, icon);
    item->setText(colItem, noteText);
    item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsAutoTristate);
    item->setCheckState(colItem, Qt::Checked);
    item->setData(colItem, Qt::UserRole, QVariant(aFileName));
    parent->addChild(item);
}

void MainWindow::on_treeWidget_currentItemChanged(QTreeWidgetItem* current, QTreeWidgetItem* previous)
{
    Q_UNUSED(previous);
    if (current == nullptr)
        return;
    int var = current->type();
    switch (var) {
    case itTopItem:
        ui->actAddFolder->setEnabled(true);
        ui->actAddFiles->setEnabled(true);
        ui->actDeleteItem->setEnabled(false);
        break;
    case itGroupItem:
        ui->actAddFolder->setEnabled(true);
        ui->actAddFiles->setEnabled(true);
        ui->actDeleteItem->setEnabled(true);
        break;
    case itImageItem:
        ui->actAddFolder->setEnabled(false);
        ui->actAddFiles->setEnabled(true);
        ui->actDeleteItem->setEnabled(true);
        displayImage(current);
        break;
    }
}

void MainWindow::on_actDeleteItem_triggered()
{
    QTreeWidgetItem* item = ui->treeWidget->currentItem();
    QTreeWidgetItem* parItem = item->parent();
    parItem->removeChild(item);
    delete item;
}

void MainWindow::on_actScanItems_triggered()
{
    for (int i = 0; i < ui->treeWidget->topLevelItemCount(); i++) {
        QTreeWidgetItem* item = ui->treeWidget->topLevelItem(i);
        changeItemCaption(item);
    }
}

void MainWindow::changeItemCaption(QTreeWidgetItem* item)
{
    QString str = "xxxx" + item->text(colItem);
    item->setText(colItem, str);
    if (item->childCount() > 0) {
        for (int i = 0; i < item->childCount(); i++) {
            changeItemCaption(item->child(i));
        }
    }
}

void MainWindow::displayImage(QTreeWidgetItem* item)
{
    QString filename = item->data(colItem, Qt::UserRole).toString();
    LabFileName->setText(filename);
    curPixmap.load(filename);
    on_actZoomFitH_triggered();
}

void MainWindow::on_actZoomFitH_triggered()
{
    int H = ui->scrollArea->height();
    int realH = curPixmap.height();
    pixRatio = float(H) / realH;
    QPixmap pix = curPixmap.scaledToHeight(H - 30);
    ui->labPicture->setPixmap(pix);
}

void MainWindow::on_actZoomRealSize_triggered()
{
    pixRatio = 1;
    ui->labPicture->setPixmap(curPixmap);
}

void MainWindow::on_actDockVisible_triggered(bool checked)
{
    //窗体可见
    ui->dockWidget->setVisible(checked);
}

void MainWindow::on_actDockFloat_triggered(bool checked)
{
    // 停靠区浮动
    ui->dockWidget->setFloating(checked);
}

void MainWindow::on_dockWidget_visibilityChanged(bool visible)
{
    ui->actDockVisible->setChecked(visible);
}

void MainWindow::on_dockWidget_topLevelChanged(bool topLevel)
{
    ui->actDockFloat->setChecked(topLevel);
}
