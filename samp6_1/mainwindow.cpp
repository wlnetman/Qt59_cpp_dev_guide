#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("标准对话框的使用");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnClear_clicked()
{
    ui->plainTextEdit->clear();
}

void MainWindow::on_btnOpenDir_clicked()
{
    QString curPath = QDir::currentPath();
    QString dlgTitle = "选择一个文件";
    QString filter= "文本文件(*.txt);;图片文件(*.jpg *.png);;所有文件(*.*)";
    QString afileName = QFileDialog::getOpenFileName(this, dlgTitle, curPath, filter);
    if(!afileName.isEmpty())
        ui->plainTextEdit->appendPlainText(afileName);
}


void MainWindow::on_btnOpenFiles_clicked()
{
    QString curPath = QDir::currentPath();
    QString dlgTitle="选择一个或者多个文件";
    QString filter = "所有文件(*.*)";
    QStringList files = QFileDialog::getOpenFileNames(this, dlgTitle, curPath, filter);
    QString file;
    foreach(file, files){
        ui->plainTextEdit->appendPlainText(file);
    }
}

void MainWindow::on_btnSelectDir_clicked()
{
    QString dlgTitle = "选择一个目录";
    QString cur_path = QDir::currentPath();
    QString select_dir = QFileDialog::getExistingDirectory(
                this, dlgTitle, cur_path, QFileDialog::ShowDirsOnly);
    if(!select_dir.isEmpty())
        ui->plainTextEdit->appendPlainText(select_dir);
}

void MainWindow::on_btnSaveFile_clicked()
{
    QString dlgTitle = "保存文件";
}

void MainWindow::on_btnSelectColor_clicked()
{
    QColor color = QColorDialog::getColor(Qt::white, this, "请选择颜色");
    QString str;
    str = str.asprintf("RGB:%d,%d,%d",color.red(),color.green(),color.blue());
    ui->plainTextEdit->appendPlainText(str);
}

void MainWindow::on_btnSelectFont_clicked()
{
    bool get = true;
    QFont font = QFontDialog::getFont(&get,this);
    if(get){
        ui->plainTextEdit->appendPlainText(font.toString());
    }
}

void MainWindow::on_btnInputStr_clicked()
{
    bool ok;
    QString text = QInputDialog::getText(this, "QInputDialog::getText()",
                                         "User name:", QLineEdit::Normal,
                                         QDir::home().dirName(), &ok);
    if (ok && !text.isEmpty())
        ui->plainTextEdit->appendPlainText(text);
}

void MainWindow::on_btnInputInt_clicked()
{
    qint32 age = QInputDialog::getInt(this, "QInputDialog::getInt()",
                                         "Age:", 100);
    ui->plainTextEdit->appendPlainText(QString::number(age));
}

void MainWindow::on_btnInputFloat_clicked()
{
    double height = QInputDialog::getDouble(this, "QInputDialog::getfloat()",
                                         "身高:", 188.00);
    ui->plainTextEdit->appendPlainText(QString("$%1").arg(height));
}

void MainWindow::on_btnCombobox_clicked()
{
    QStringList items;
    items << tr("Spring") << tr("Summer") << tr("Fall") << tr("Winter");

    bool ok;
    QString item = QInputDialog::getItem(this, tr("QInputDialog::getItem()"),
                                         tr("Season:"), items, 0, false, &ok);
    if (ok && !item.isEmpty())
        ui->plainTextEdit->appendPlainText(item);
}

void MainWindow::on_btnQuestion_clicked()
{
    QMessageBox::question(this,"question", "Text");
}

void MainWindow::on_btnInfo_clicked()
{
    QMessageBox::information(this,"information", "Text");
}

void MainWindow::on_btnWarning_clicked()
{
    QMessageBox::warning(this,"information", "Text");
}

void MainWindow::on_btnCritical_clicked()
{
    QMessageBox::critical(this,"information", "Text");
}

void MainWindow::on_btnAbout_clicked()
{
    QMessageBox::about(this, "About", "大师");
}

void MainWindow::on_btnAboutQt_clicked()
{
    QMessageBox::aboutQt(this, "About Qt");
}
