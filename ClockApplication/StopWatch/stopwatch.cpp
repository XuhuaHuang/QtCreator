#include "stopwatch.h"

StopWatch::StopWatch(QWidget *parent)
    : QWidget(parent)
{
    // initialize
    setWindowTitle("Stop Watch");
    // change the background color
    setStyleSheet("background-color:#848484;"); // dark grey

    lcd = new QLCDNumber();
    lcd->setSegmentStyle(QLCDNumber::Filled);   // filled text style
    lcd->setSegmentStyle(QLCDNumber::Flat);     // flat text style

    stopwatch = new QTimer(this);
    vbox = new QVBoxLayout();

    // set layout
    vbox->addWidget(lcd);
    this->setLayout(vbox);
}

StopWatch::~StopWatch()
{
}
