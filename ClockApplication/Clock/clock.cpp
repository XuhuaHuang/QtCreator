#include "clock.h"

Clock::Clock(QWidget *parent)
    : QWidget(parent)
{
    // initialize
    setWindowTitle("Digital Clock");
    // set window to frameless
    setWindowFlags(Qt::FramelessWindowHint);
    setStyleSheet("background-color:#40b3ff;");
    //setAttribute(Qt::WA_TranslucentBackground);
    clk = new QLCDNumber();
    clktimer = new QTimer(this);
    vbox = new QVBoxLayout();
    // set text style
    clk->setSegmentStyle(QLCDNumber::Filled);
    // set layout
    vbox->addWidget(clk);
    this->setLayout(vbox);

    connect(clktimer, SIGNAL(timeout()), this, SLOT(showTime()));
    clktimer->start(1000);
    showTime();
    resize(320, 240); // set fixed-size window
}

Clock::~Clock()
{
}

void Clock::showTime()
{
    // get current time and assigned to object
    // time of class QTime
    QTime time = QTime::currentTime();
    // convert to formatted string
    QString text = time.toString("hh:mm");
    // togle hour and minute seperater ":" every second
    if ((time.second() % 2) == 0)
        text[2] = ' ';
    // pass QString as argument to display time
    clk->display(text);
}
