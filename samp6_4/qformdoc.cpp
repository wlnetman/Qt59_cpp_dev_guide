#include "qformdoc.h"
#include "ui_qformdoc.h"

QFormDoc::QFormDoc(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QFormDoc)
{
    ui->setupUi(this);
    setWindowTitle("New Doc");
    setAttribute(Qt::WA_DeleteOnClose);

    QToolBar* locToolBar = new QToolBar("文档", this);
    locToolBar->addAction(ui->actOpen);
    locToolBar->addAction(ui->actFont);
    locToolBar->addSeparator();

    locToolBar->addAction(ui->actCopy);
    locToolBar->addAction(ui->actCut);
    locToolBar->addAction(ui->actPaster);
    locToolBar->addAction(ui->actUndo);
    locToolBar->addAction(ui->actRepeat);
    locToolBar->addSeparator();

    locToolBar->addAction(ui->actClose);
    locToolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    QVBoxLayout *layout=  new QVBoxLayout();
    layout->addWidget(locToolBar);
    layout->addWidget(ui->plainTextEdit);
    layout->setContentsMargins(2,2,2,2);
    layout->setSpacing(2);

    this->setLayout(layout);
}

QFormDoc::~QFormDoc()
{
    QMessageBox::information(this, "消息", "析构函数");
    delete ui;
}

void QFormDoc::on_actOpen_triggered()
{
    QString curPath = QDir::currentPath();
    QString fileName = QFileDialog::getOpenFileName(this,
         "Open Text", curPath, "Text Files (*.txt *.h *.cpp)");
    if(fileName.isEmpty())
        return;

    ui->plainTextEdit->clear();
    QFile afile(fileName);
    afile.open(QFile::ReadOnly);
    QTextStream text(&afile);
    while (!text.atEnd()) {
        QString line = text.readLine();
        ui->plainTextEdit->appendPlainText(line);
    }
}

void QFormDoc::on_actFont_triggered()
{
    bool ret = true;
    QFont fnew = QFontDialog::getFont(&ret, this);
    if( ret ){
        ui->plainTextEdit->setFont(fnew);
    }
}

void QFormDoc::loadFromFile(QString &filename)
{
    if(filename.isEmpty())
        return;

    ui->plainTextEdit->clear();
    QFile afile(filename);
    afile.open(QFile::ReadOnly);
    QTextStream text(&afile);
    ui->plainTextEdit->setPlainText(text.readAll());
    afile.close();
    current_file_ = filename;

    QFileInfo info(current_file_);
    QString str = info.fileName();
    setWindowTitle(str);
    is_fileopened_ = true;
}

QString QFormDoc::currentFileName()
{
    return current_file_;
}

void QFormDoc::setEditFont()
{
    QFont font = ui->plainTextEdit->font();
    bool ret = true;
    QFont newFont = QFontDialog::getFont(&ret, font);
    if(ret)
        ui->plainTextEdit->setFont(newFont);
}

void QFormDoc::textCut()
{
    ui->plainTextEdit->cut();
}

void QFormDoc::textCopy()
{
    ui->plainTextEdit->copy();
}

void QFormDoc::textPaste()
{
    ui->plainTextEdit->paste();
}
