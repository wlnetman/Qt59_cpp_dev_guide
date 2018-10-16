#include "qwdialog.h"
#include "ui_qwdialog.h"

QWDialog::QWDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QWDialog)
{
    ui->setupUi(this);

    connect(ui->rBtnBlue, &QRadioButton::clicked, this, &QWDialog::setTextFontColor);
    connect(ui->rBtnRed, &QRadioButton::clicked, this, &QWDialog::setTextFontColor);
    connect(ui->rBtnBlack, &QRadioButton::clicked, this, &QWDialog::setTextFontColor);
}

QWDialog::~QWDialog()
{
    delete ui;
}

void QWDialog::on_chkBoxUnder_clicked(bool checked)
{
    QFont font = ui->txtEdit->font();
    font.setUnderline(checked);
    ui->txtEdit->setFont(font);
}

void QWDialog::on_chkBoxItalic_clicked(bool checked)
{
    QFont font = ui->txtEdit->font();
    font.setItalic(checked);
    ui->txtEdit->setFont(font);
}

void QWDialog::on_chkBoxBold_clicked(bool checked)
{
    QFont font = ui->txtEdit->font();
    font.setBold(checked);
    ui->txtEdit->setFont(font);
}

void QWDialog::setTextFontColor()
{
    QPalette plet = ui->txtEdit->palette();
    if(ui->rBtnBlue->isChecked())
        plet.setColor(QPalette::Text, Qt::blue);
    else if(ui->rBtnRed->isChecked())
        plet.setColor(QPalette::Text, Qt::red);
    else if(ui->rBtnBlack->isChecked())
        plet.setColor(QPalette::Text, Qt::black);
    ui->txtEdit->setPalette(plet);
}
