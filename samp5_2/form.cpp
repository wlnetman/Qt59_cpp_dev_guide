#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    QStringList theStr;
    theStr<<"北京"<<"重庆"<<"深圳"<<"杭州"<<"广州";
    theModel = new QStringListModel(this);
    theModel->setStringList(theStr);
    ui->listView->setModel(theModel);
    ui->listView->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::SelectedClicked);
}

Form::~Form()
{
    delete ui;
}

void Form::on_btnAdd_clicked()
{
    theModel->insertRow(theModel->rowCount());
    QModelIndex index = theModel->index(theModel->rowCount()-1, 0);
    theModel->setData(index, "new item", Qt::DisplayRole);
    ui->listView->setCurrentIndex(index);
}

void Form::on_btnInsert_clicked()
{
    QModelIndex index = ui->listView->currentIndex();
    theModel->insertRow(index.row());
    theModel->setData(index, "Insert Item", Qt::DisplayRole);
    ui->listView->setCurrentIndex(index);
}

void Form::on_btnDel_clicked()
{
    QModelIndex index = ui->listView->currentIndex();
    theModel->removeRow(index.row());
}

void Form::on_btnClear_clicked()
{
    theModel->removeRows(0, theModel->rowCount());
}

void Form::on_btnShowText_clicked()
{
    QStringList content = theModel->stringList();
    ui->plainTextEdit->clear();
    for(int i=0; i<content.count(); i++)
        ui->plainTextEdit->appendPlainText(content.at(i));
}

void Form::on_listView_clicked(const QModelIndex &index)
{
    QString info;
    info.asprintf("当前条目：row=%d, column=%d", index.row(), index.column());
}

void Form::on_btnTextClear_clicked()
{
    ui->plainTextEdit->clear();
}
