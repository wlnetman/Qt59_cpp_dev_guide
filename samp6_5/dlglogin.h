#ifndef DLGLOGIN_H
#define DLGLOGIN_H

#include <QDialog>
#include <QMouseEvent>
#include <QPoint>
#include <QSettings>
#include <QDir>
#include <QCryptographicHash>

namespace Ui {
class DlgLogin;
}

class DlgLogin : public QDialog
{
    Q_OBJECT

public:
    explicit DlgLogin(QWidget *parent = nullptr);
    ~DlgLogin();

private:
    Ui::DlgLogin *ui;

    QSettings *settings_;
    bool moving_= false;
    QPoint lastPos_;
    QString name_;
    QString pwd_;
    void iniSettings();
    void readSettings();
    void writeSettings();
    QString encrypt(const QString &pwd);
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
private slots:
    void on_btnOK_clicked();
};

#endif // DLGLOGIN_H
