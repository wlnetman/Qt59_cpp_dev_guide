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

    ui->tableView->setItemDelegateForColumn(3, &intSpinDelegate);

    // 创建状态栏代码
    labCurFile = new QLabel("当前文件：");
    ui->statusbar->addWidget(labCurFile);
    labCellPos = new QLabel("当前单元格：");
    ui->statusbar->addWidget(labCellPos);
    labCellText = new QLabel("单元格内容：");
    ui->statusbar->addWidget(labCellText);
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

void MainWindow::on_actOpen_triggered()
{
    QString curPath = QCoreApplication::applicationDirPath();
    QString aFileName = QFileDialog::getOpenFileName(this, "打开一个数据文件",
                                                     curPath, "井数据文件(*.txt);;所有文件(*.*)");
    if(aFileName.isEmpty())
        return;
    QStringList fFileContext;
    QFile aFile(aFileName);
    if(aFile.open(QIODevice::ReadOnly |QIODevice::Text)){
        QTextStream aStream(&aFile);
        ui->plainTextEdit->clear();
        while ( !aStream.atEnd()) {
            QString str = aStream.readLine();
            //qDebug()<< i++ <<":" <<str;
            ui->plainTextEdit->appendPlainText(str);
            fFileContext.append(str);
        }
        aFile.close();
        this->labCurFile->setText("当前文件：" + aFileName);
        iniModelFromStringList(fFileContext);
    }

}

void MainWindow::iniModelFromStringList(QStringList &aFileContext)
{
    // 设置总行数
    int rowCnt = aFileContext.count();
    standModel->setRowCount(rowCnt);

    //设置标题
    QString header = aFileContext.at(0);
    QStringList headerList = header.split(QRegExp("\\s+"), QString::SkipEmptyParts);
    standModel->setHorizontalHeaderLabels(headerList);
    standModel->setColumnCount(headerList.count());
    ui->comboBox->addItems(headerList);
    //qDebug() << "row: "<< rowCnt<< "column:"<< headerList.count();

    QStandardItem* item;
    for(int i = 1; i<rowCnt-1; i++){
        QStringList line = aFileContext.at(i).split(QRegExp("\\s+"), QString::SkipEmptyParts);
        for(int j=0; j< line.size(); j++)
        {
            item = new QStandardItem(line.at(j));
            standModel->setItem(i, j, item);
        }
        //qDebug()<< "line:" <<line.count();
    }
}

void MainWindow::on_actAppend_triggered()
{
    int rowCount = standModel->rowCount();
    QList<QStandardItem*> itemList;
    for(int i=0; i<standModel->columnCount(); i++){
        QStandardItem* item = new QStandardItem(QString::asprintf("Item%d", i));
        itemList<<item;
    }
    standModel->insertRow(rowCount, itemList);
    QModelIndex currIndex = standModel->index(standModel->rowCount()-1,0);
    selectModel->setCurrentIndex(currIndex, QItemSelectionModel::Select);
}

void MainWindow::on_actInsert_triggered()
{
    QList<QStandardItem*> itemList;
    for(int i=0; i<standModel->columnCount(); i++){
        QStandardItem* item = new QStandardItem(QString::asprintf("Item%d", i));
        itemList<<item;
    }
    QModelIndex index = selectModel->currentIndex();
    int row = index.row();
    standModel->insertRow(row, itemList);
}

void MainWindow::on_actDelete_triggered()
{
    QModelIndex index = selectModel->currentIndex();
    int row = index.row();
    standModel->removeRow(row);
}

void MainWindow::on_actAlignLeft_triggered()
{
    for(int i=1; i<standModel->rowCount(); i++){
        for(int j=0; j<standModel->columnCount(); j++){
            QStandardItem *item = standModel->item(i,j);
            if(item != nullptr)
                item->setTextAlignment(Qt::AlignLeft);
        }
    }
}

void MainWindow::on_actAlignRight_triggered()
{
    for(int i=1; i<standModel->rowCount(); i++){
        for(int j=0; j<standModel->columnCount(); j++){
            QStandardItem *item = standModel->item(i,j);
            if( item != nullptr)
                item->setTextAlignment(Qt::AlignRight);
        }
    }
}
