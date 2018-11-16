#include "dlglogin.h"
#include "ui_dlglogin.h"

DlgLogin::DlgLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgLogin)
{
    ui->setupUi(this);

    ui->editPasswd->setEchoMode(QLineEdit::Password);
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowFlags(Qt::SplashScreen);

    iniSettings();
    readSettings();
}

DlgLogin::~DlgLogin()
{
    delete ui;
}

void DlgLogin::iniSettings()
{
    QString path = QDir::currentPath();
    QString inifile = QString::asprintf("%1_.ini").arg(QApplication::applicationName());
    QFileInfo info(inifile);

    settings_ = new QSettings(inifile, QSettings::IniFormat);
    if( !info.exists()){
        writeSettings();
    }
}

void DlgLogin::readSettings()
{
    settings_->beginGroup("users");
    name_ = settings_->value("name").toString();
    pwd_   = settings_->value("password").toString();
}

void DlgLogin::writeSettings()
{
    settings_->beginGroup("users");
    settings_->setValue("name","dashi");
    settings_->setValue("password", encrypt("123456"));
    settings_->endGroup();
}

QString DlgLogin::encrypt(const QString &pwd)
{
    QByteArray btArr;
    btArr.append(pwd);
    QCryptographicHash hash(QCryptographicHash::Md5);
    hash.addData(btArr);
    QByteArray ret = hash.result();
    return ret.toHex();
}

void DlgLogin::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        moving_ = true;
        lastPos_ = event->globalPos() - pos();
    }
    return QDialog::mousePressEvent(event);
}

void DlgLogin::mouseMoveEvent(QMouseEvent *event)
{
    if(moving_ && (event->buttons() && Qt::LeftButton) &&
       (event->globalPos() - lastPos_).manhattanLength() > QApplication::startDragDistance())
    {
        move(event->globalPos() - lastPos_);
        lastPos_ = event->globalPos() - pos();
    }
    return QDialog::mouseMoveEvent(event);
}

void DlgLogin::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event)

    moving_ = false;
}

void DlgLogin::on_btnOK_clicked()
{
    QString username = ui->editUser->text().trimmed();
    QString password = ui->editPasswd->text().trimmed();
    QString encrp = encrypt(password);
    if( name_ == username && pwd_ == encrp){
        return accept();
    }
    return reject();
}
