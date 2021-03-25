#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QWidget>
#include <QLCDNumber>
#include <QVBoxLayout>
#include <QTimer>
#include <QTime>
#include <QMouseEvent>
#include <QPushButton>

class StopWatch : public QWidget
{
    Q_OBJECT

public:
    StopWatch(QWidget *parent = nullptr);
    ~StopWatch();
public slots:
    void start();
    void stop();
    void increment();
private:
    unsigned int minute, second, milliSec;

    QTimer *stopwatch;
    QLCDNumber *lcd;

    QPushButton *startbtn;
    QPushButton *stopbtn;

    QHBoxLayout *hbox;
    QVBoxLayout *vbox;
};
#endif // STOPWATCH_H
