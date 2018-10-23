#ifndef TESTTIME_H
#define TESTTIME_H

#include <QTime>
#include <QTimer>
#include <QWidget>

namespace Ui {
class TestTime;
}

class TestTime : public QWidget {
    Q_OBJECT

public:
    explicit TestTime(QWidget* parent = nullptr);
    ~TestTime();

private slots:
    void on_calendar_clicked(const QDate& date);

    void on_btnTimeNow_clicked();
    void on_timer_timeout(); // 定时器溢出处理
    void on_btStart_clicked();

    void on_btStop_clicked();

private:
    Ui::TestTime* ui;
    QTimer* fTimer; //定时器
    QTime fTimeCounter; // 计时器
};

#endif // TESTTIME_H
