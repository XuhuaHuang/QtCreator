#include "stopwatch.h"

StopWatch::StopWatch(QWidget *parent)
    : QWidget(parent),
      minute(0),
      second(0),
      milliSec(0)
{
    // initialize
    setWindowTitle("Stop Watch");
    // change the background color
    setStyleSheet("background-color:#848484;"); // dark grey

    lcd = new QLCDNumber();
    lcd->setDigitCount(12);
    lcd->setSegmentStyle(QLCDNumber::Filled);   // filled text style
    lcd->setSegmentStyle(QLCDNumber::Flat);     // flat text style

    stopwatch = new QTimer(this);
    stopwatch->start(10);
    QString timeText = "00:00:00";
    lcd->display(timeText);

    startbtn = new QPushButton("Start");
    stopbtn = new QPushButton("Stop");
    hbox = new QHBoxLayout();
    vbox = new QVBoxLayout();

    // set layout
    hbox->addWidget(startbtn); hbox->addWidget(stopbtn);
    vbox->addWidget(lcd);
    vbox->addLayout(hbox);
    this->setLayout(vbox);
    setFixedSize(500, 240);

    // connect signals and slots
    connect(startbtn, SIGNAL(clicked()), this, SLOT(start()));
    connect(stopbtn, SIGNAL(clicked()), this, SLOT(stop()));
}

StopWatch::~StopWatch()
{
}

void StopWatch::start()
{
    connect(stopwatch, SIGNAL(timeout()), this, SLOT(increment()));
}

void StopWatch::stop()
{
    disconnect(stopwatch, SIGNAL(timeout()), this, SLOT(increment()));
}

void StopWatch::increment()
{
    milliSec++;
    if (milliSec > 99)
    {
        milliSec = 0;
        second++;
    }
    if (second > 59)
    {
        second = 0;
        minute++;
    }
    if (minute > 59)
    {
        minute = 0;
        second = 0;
        milliSec = 0;
    }
    const QString diff = QString("%1:%2:%3")
                                        .arg(minute, 2, 10, QChar('0'))
                                        .arg(second, 2, 10, QChar('0'))
                                        .arg(milliSec, 2, 10, QChar('0'));
    lcd->display(diff);
}
