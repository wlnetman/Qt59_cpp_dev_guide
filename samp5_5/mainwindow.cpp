#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    lab_status_ = new QLabel("请开始你的表演");
    ui->statusbar->addWidget(lab_status_);

    setWindowTitle("有爱的照片批处理工具");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_rbtn1200_clicked()
{
    ui->edWidth->setText(QString::number(1200));
    ui->edHeight->setText(QString::number(900));
}

void MainWindow::on_rbtn800_clicked()
{
    ui->edWidth->setText(QString::number(800));
    ui->edHeight->setText(QString::number(600));
}

void MainWindow::on_rbtn400_clicked()
{
    ui->edWidth->setText(QString::number(400));
    ui->edHeight->setText(QString::number(300));
}

void MainWindow::on_btnInputDir_clicked()
{
    QString curPath = QDir::currentPath();
    QString dir = QFileDialog::getExistingDirectory(this, tr("选择要处理的照片目录"),
                                                     curPath,
                                                     QFileDialog::ShowDirsOnly
                                                     | QFileDialog::DontResolveSymlinks);
    ui->edInputDir->setText(dir);
    ui->plainTextEdit->appendPlainText("选择目录:" +dir);
}

void MainWindow::on_btnOutputDir_clicked()
{
    QString curPath = QDir::currentPath();
    QString inputDir = ui->edInputDir->text();
    if(!inputDir.isEmpty())
        curPath = inputDir;

    QString dir = QFileDialog::getExistingDirectory(this, tr("选择照片处理后保存的目录"),
                                                     curPath,
                                                     QFileDialog::ShowDirsOnly
                                                     | QFileDialog::DontResolveSymlinks);
    ui->edOutputDir->setText(dir);
    ui->plainTextEdit->appendPlainText("输出目录:" +dir);
}

bool MainWindow::scaled_image(QString &source, QString &dest, QSize size)
{
    QImage source_img;
    bool ret = source_img.load(source);
    if(!ret){
        ui->plainTextEdit->appendPlainText("错误的图片:" + source);
        return false;
    }

    // TODO: 图片转换又三种模式，缩放，保持最大高，保持最大宽
    QImage dest_img = source_img.scaled( size, Qt::IgnoreAspectRatio);
    if(dest_img.isNull()){
        ui->plainTextEdit->appendPlainText("图片转换出错:" + source);
        return false;
    }

    ret = dest_img.save(dest);
    if( !ret ){
        ui->plainTextEdit->appendPlainText("图片保存出错:" + source);
        return false;
    }

    ui->plainTextEdit->appendPlainText("图片处理成功:" + dest);
    return true;
}

//   C:\temp\pic_source\白鹿原.jpg
//-->C:\temp\pic_source\白鹿原_800x600.jpg
// ***图片都是三个字母的文件名后缀，简单替换: . -> 800x600. 即可
QString MainWindow::getDestNameFromSource(QString &filename, QSize size)
{
    QString pre_add;
    pre_add = QString::asprintf("_%dx%d.",size.width(), size.height());

    QString dest_filename = filename;
    dest_filename.replace(filename.size()-4, 1, pre_add);

    //ui->plainTextEdit->appendPlainText(filename + "->");
    //ui->plainTextEdit->appendPlainText(dest_filename);

    return dest_filename;
}

void MainWindow::on_btnStart_clicked()
{
    input_dir_  = ui->edInputDir->text();
    output_dir_ = ui->edOutputDir->text();
    width_      = ui->edWidth->text().toInt();
    height_     = ui->edHeight->text().toInt();

    if(input_dir_.isEmpty() || output_dir_.isEmpty()){
        QMessageBox::critical(this, "找不到对象", "请选择要处理的图片目录");
        return;
    }

    QSize size(width_, height_);
    if( size.isEmpty() ){
        QMessageBox::critical(this, "长宽错误", "请输入正确的长宽");
        return;
    }

    QDir source_dir(input_dir_);
    QDir dest_dir(output_dir_);
    if( !source_dir.exists()|| !dest_dir.exists()){
        QMessageBox::critical(this, "别瞎写", "输入的图片目录不存在");
        return;
    }

    success_ = 0;
    error_ = 0;

    QStringList files = source_dir.entryList(QDir::Files);
    for(int i=0; i<files.size(); i++){
        QString source_filename = files.at(i);
        QString dest_filename = getDestNameFromSource(source_filename, size);

        // TODO: 覆盖存在文件提醒
        QString source_pathfile = source_dir.filePath(source_filename);
        QString dest_pathfile = dest_dir.filePath(dest_filename);
        bool ret = scaled_image(source_pathfile, dest_pathfile, size);

        ret ? success_++: error_++;

        lab_status_->setText(QString("正在处理：").arg(source_pathfile));
    }

    lab_status_->setText(QString("处理完成！成功：%1个,失败：%2个").
                                 arg(success_).arg(error_));
}
