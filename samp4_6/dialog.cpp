#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    QIcon icon;
    icon.addFile(":/images/icons/aim.ico");
    ui->comboBox->clear();
    for (int i = 0; i < 20; i++) {
        ui->comboBox->addItem(icon, QString::asprintf("Item %d", i));
    }
}

void Dialog::on_btnIni2_clicked()
{
    QMap<QString, int> city_zone;
    city_zone.insert("重庆", 23);
    city_zone.insert("北京", 10);
    city_zone.insert("上海", 21);
    city_zone.insert("天津", 22);
    city_zone.insert("天水", 938);
    ui->comboBox_2->clear();
    foreach (const QString& str, city_zone.keys())
        ui->comboBox_2->addItem(str, city_zone.value(str));
}
