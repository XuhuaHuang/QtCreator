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

private:
    QTimer *stopwatch;
    QLCDNumber *lcd;
    QVBoxLayout *vbox;
};
#endif // STOPWATCH_H
