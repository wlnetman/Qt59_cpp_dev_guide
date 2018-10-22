#ifndef TESTTIME_H
#define TESTTIME_H

#include <QWidget>

namespace Ui {
class TestTime;
}

class TestTime : public QWidget
{
    Q_OBJECT

public:
    explicit TestTime(QWidget *parent = nullptr);
    ~TestTime();

private slots:
    void on_calendar_clicked(const QDate &date);

    void on_btnTimeNow_clicked();

private:
    Ui::TestTime *ui;
};

#endif // TESTTIME_H
