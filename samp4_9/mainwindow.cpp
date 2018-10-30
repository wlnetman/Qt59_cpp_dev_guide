#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->splitterMain);
    labCellIndex = new QLabel("当前单元格坐标: ", this);
    labCellIndex->setMinimumWidth(250);
    labCellType = new QLabel("当前单元格类型: ", this);
    labCellType->setMinimumWidth(200);
    labStudID = new QLabel("学生ID: ", this);
    labStudID->setMinimumWidth(200);
    ui->statusbar->addWidget(labCellIndex);
    ui->statusbar->addWidget(labCellType);
    ui->statusbar->addWidget(labStudID);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnSetHeader_clicked()
{
    QTableWidgetItem *headerItem;
    QStringList headerText;
    headerText<<"姓 名"<<"性 别"<< "出生日期"<<"民 族"<<"分 数"<< "是否党员";
    ui->tableInfo->setColumnCount(headerText.count());
    for(int i =0; i<ui->tableInfo->columnCount();i++){
        headerItem = new QTableWidgetItem(headerText.at(i));
        QFont font = headerItem->font();
        font.setBold(true);
        font.setPointSize(12);
        headerItem->setTextColor(Qt::red);
        headerItem->setFont(font);
        ui->tableInfo->setHorizontalHeaderItem(i, headerItem);
    }
}

void MainWindow::on_btnIniData_clicked()
{
    QString strName,strSex;
    bool isParty = false;
    QDate birth;
    birth.setDate(1987,12,5);
    ui->tableInfo->clearContents();
    int Rows = ui->tableInfo->rowCount();
    for(int i= 0; i<Rows; i++){
        strName = QString::asprintf("学生%d",i);
        if((i%2)==0)
            strSex = "男";
        else
            strSex = "女";
        createItemsARow(i, strName, strSex, birth, "汉族", isParty, 70);
        birth = birth.addDays(30);
        isParty = !isParty;
    }
}

void MainWindow::createItemsARow(int rowNo, QString name, QString sex, QDate birth, QString Nation, bool isPM, int score)
{
    QTableWidgetItem *item;
    QString str;
    quint32 studyid = 201605000;
    item = new QTableWidgetItem(name, MainWindow::ctName);
    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    studyid += rowNo;
    item->setData(Qt::UserRole, QVariant(studyid));
    ui->tableInfo->setItem(rowNo, MainWindow::colName, item);
    QIcon icon;
    if(sex=="男")
        icon.addFile(":/images/images/man.png");
    else
        icon.addFile(":/images/images/woman.png");
    item= new QTableWidgetItem(sex, MainWindow::ctSex);
    item->setIcon(icon);
    item->setTextAlignment(Qt::AlignHCenter |Qt::AlignVCenter);
    ui->tableInfo->setItem(rowNo, MainWindow::colSex, item);

    // 出生日期
    str=birth.toString("yyyy-MM-dd");
    item = new QTableWidgetItem(str, MainWindow::ctBirth);
    item->setTextAlignment(Qt::AlignHCenter |Qt::AlignVCenter);
    ui->tableInfo->setItem(rowNo, MainWindow::colBirth, item);

    // 民族
    item = new QTableWidgetItem(Nation, MainWindow::ctNation);
    item->setTextAlignment(Qt::AlignHCenter |Qt::AlignVCenter);
    ui->tableInfo->setItem(rowNo, MainWindow::colNation, item);

    // 是否党员
    item = new QTableWidgetItem("党员", MainWindow::ctPartyM);
    item->setTextAlignment(Qt::AlignHCenter |Qt::AlignVCenter);
    if(isPM)
        item->setCheckState(Qt::Checked);
    else
        item->setCheckState(Qt::Unchecked);
    item->setBackgroundColor(Qt::yellow);
    ui->tableInfo->setItem(rowNo, MainWindow::colPartyM, item);

    //分数
    str.setNum(score);
    item = new QTableWidgetItem(str, MainWindow::ctScore);
    item->setTextAlignment(Qt::AlignHCenter |Qt::AlignVCenter);
    ui->tableInfo->setItem(rowNo, MainWindow::colScore, item);
}

void MainWindow::on_tableInfo_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn)
{
    Q_UNUSED(previousRow);
    Q_UNUSED(previousColumn);
    QTableWidgetItem* item = ui->tableInfo->item(currentRow, currentColumn);
    if(nullptr == item)
        return;
    labCellIndex->setText(QString::asprintf("当前单元格坐标： %d行, %d列", currentRow,currentColumn));
    item=ui->tableInfo->item(currentRow, MainWindow::colName);
    int ID = item->data(Qt::UserRole).toInt();
    labStudID->setText(QString::asprintf("学生ID: %d", ID));
}

void MainWindow::on_btnInsertRow_clicked()
{
    int cur = ui->tableInfo->currentRow();
    ui->tableInfo->insertRow(cur);
    createItemsARow(cur,"黄中原","男", QDate::fromString("1986-1-1","yyyy-M-d"), "汉族", true, 99);
}

void MainWindow::on_btnAppendRow_clicked()
{
    int cur = ui->tableInfo->rowCount();
    ui->tableInfo->insertRow(cur);
    createItemsARow(cur,"zonm","女", QDate::fromString("1986-1-1","yyyy-M-d"), "汉族", true, 100);
}

void MainWindow::on_btnDeleteRow_clicked()
{
    int cur = ui->tableInfo->currentRow();
    ui->tableInfo->removeRow(cur);
}

void MainWindow::on_chkBoxRowColor_clicked(bool checked)
{
    ui->tableInfo->setAlternatingRowColors(checked);
}
