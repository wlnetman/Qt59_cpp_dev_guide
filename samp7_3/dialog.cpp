#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::showButtonTitle()
{
    QPushButton *pbt = static_cast<QPushButton*>(sender());
    ui->textEdit->append("\n" + pbt->text());
}

void Dialog::on_directoryChanged(const QString path)
{
    ui->textEdit->append(path);
    ui->textEdit->append("目录发生了变化\n");
}

void Dialog::on_fileChanged(const QString path)
{
    ui->textEdit->append(path);
    ui->textEdit->append("文件发生了变化\n");
}

void Dialog::on_pushButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "请选择要打开的文件", QDir::currentPath()
                                                    ,"文本文件 (*.txt);;所有文件(*.*)");
    if(filename.isEmpty())
        return;

    ui->edFile->setText(filename);
}

void Dialog::on_btnDir_clicked()
{
    QString dirname = QFileDialog::getExistingDirectory(this, "打开目录");
    if(dirname.isEmpty())
        return;
    ui->edDir->setText(dirname);
}


void Dialog::on_btnAbsoluteFile_clicked()
{
    showButtonTitle();

    QString fname = ui->edFile->text();
    QFileInfo info(fname);
    ui->textEdit->append(info.absoluteFilePath());
}

void Dialog::on_btnBaseName_clicked()
{
    showButtonTitle();

    QFileInfo info(ui->edFile->text());
    ui->textEdit->append(info.baseName());
}


void Dialog::on_pushButton_6_clicked()
{
    showButtonTitle();

    QFileInfo info(ui->edFile->text());
    ui->textEdit->append(info.absolutePath());
}

void Dialog::on_pushButton_5_clicked()
{
    showButtonTitle();

    QFileInfo info(ui->edFile->text());
    ui->textEdit->append(info.fileName());
}

void Dialog::on_pushButton_7_clicked()
{
    showButtonTitle();

    QFileInfo info(ui->edFile->text());
    ui->textEdit->append(info.filePath());
}

void Dialog::on_pushButton_11_clicked()
{
    showButtonTitle();

    QFileInfo info(ui->edFile->text());
    ui->textEdit->append(info.path());
}

void Dialog::on_pushButton_9_clicked()
{
    showButtonTitle();

    QFileInfo info(ui->edFile->text());
    ui->textEdit->append(info.suffix());
}

void Dialog::on_pushButton_10_clicked()
{
    showButtonTitle();

    QFileInfo info(ui->edFile->text());
    ui->textEdit->append(info.isDir()?"TRUE":"FALSE");
}

void Dialog::on_pushButton_12_clicked()
{
    showButtonTitle();

    QFileInfo info(ui->edFile->text());
    ui->textEdit->append(info.completeSuffix());
}

void Dialog::on_pushButton_2_clicked()
{
    showButtonTitle();

    QString str = QApplication::applicationDirPath();
    ui->textEdit->append(str);
}

void Dialog::on_pushButton_3_clicked()
{
    showButtonTitle();

    QString str = QApplication::applicationFilePath();
    ui->textEdit->append(str);
}

void Dialog::on_pushButton_4_clicked()
{
    showButtonTitle();

    QStringList strlist = QApplication::libraryPaths();
    foreach(QString str, strlist)
        ui->textEdit->append(str);
}

void Dialog::on_pushButton_14_clicked()
{
    showButtonTitle();

    QApplication::exit();
}

void Dialog::on_pushButton_8_clicked()
{
    showButtonTitle();

    QApplication::setOrganizationName("Dashi");
    QString str = QApplication::organizationName();
    ui->textEdit->append(str);
}

void Dialog::on_pushButton_15_clicked()
{
    showButtonTitle();

    QFile f(ui->edFile->text());
    ui->textEdit->append(f.exists()?"EXISTS" :"Not EXISTES");
}

void Dialog::on_pushButton_16_clicked()
{
    showButtonTitle();

    QFile f(ui->edFile->text());
    ui->textEdit->append(QString::number(f.size()));
}

void Dialog::on_pushButton_17_clicked()
{
    showButtonTitle();

    ui->textEdit->append("监听目录 :" + ui->edDir->text() + "\n");
    watcher_.addPath(ui->edDir->text());
    watcher_.addPath(ui->edFile->text());

    connect(&watcher_, &QFileSystemWatcher::directoryChanged,
            this, &Dialog::on_directoryChanged);
    connect(&watcher_, &QFileSystemWatcher::fileChanged,
            this, &Dialog::on_fileChanged);
}

void Dialog::on_pushButton_18_clicked()
{
    showButtonTitle();

    ui->textEdit->append("监听目录 :" + ui->edDir->text() + "\n");
    watcher_.removePath(ui->edDir->text());
    watcher_.removePath(ui->edFile->text());

    disconnect(&watcher_, &QFileSystemWatcher::directoryChanged,
            this, &Dialog::on_directoryChanged);
    disconnect(&watcher_, &QFileSystemWatcher::fileChanged,
            this, &Dialog::on_fileChanged);
}
