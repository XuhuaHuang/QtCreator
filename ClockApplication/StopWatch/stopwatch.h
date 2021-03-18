#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QWidget>
#include <QLCDNumber>
#include <QVBoxLayout>
#include <QTimer>
#include <QTime>
#include <QMouseEvent>
#include <QMenu>

class StopWatch : public QWidget
{
    Q_OBJECT

public:
    StopWatch(QWidget *parent = nullptr);
    ~StopWatch();
};
#endif // STOPWATCH_H
