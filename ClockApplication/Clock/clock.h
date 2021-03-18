#ifndef CLOCK_H
#define CLOCK_H

#include <QWidget>
#include <QLCDNumber>
#include <QVBoxLayout>
#include <QTimer>
#include <QTime>
#include <QMouseEvent>
#include <QMenu>

class Clock : public QWidget
{
    Q_OBJECT

public:
    Clock(QWidget *parent = nullptr);
    ~Clock();
public slots:
    void showTime();    // responsible for displaying time
    void ShowContextMenu(const QPoint& pos); // close app
protected:
    // added mouse event handler
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
private:
    // added two ints to store mouse click coordinate
    int m_nMouseClick_X_Coordinate;     // event->x();
    int m_nMouseClick_Y_Coordinate;     // event->y();
    QTimer *clktimer;   // pointer to a QTimer object
    QLCDNumber *clk;    // pointer to a QLCDNumber object
    QVBoxLayout *vbox;  // vertical layout manager
};
#endif // CLOCK_H
