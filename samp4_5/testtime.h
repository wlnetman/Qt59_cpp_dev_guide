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

private:
    Ui::TestTime *ui;
};

#endif // TESTTIME_H
