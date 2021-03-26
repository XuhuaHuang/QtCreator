#include "alarm.h"

Alarm::Alarm(QWidget *parent)
    : QWidget(parent),
      hour(0),
      minute(0),
      snoozed(false),
      activated(false)
{
    // initialize layout
    setWindowTitle("Alarm");
    // change the background color to dark grey
    setStyleSheet("background-color:#848484;");
    resize(280, 120); // set fixed-size window
    timeHbox = new QHBoxLayout();
    volumeHbox = new QHBoxLayout();
    btnHbox = new QHBoxLayout();
    vbox = new QVBoxLayout();

    // button, spin boxes and label
    separater = new QLabel(":");
    separater->setAlignment(Qt::AlignHCenter);
    status = new QLabel("Alarm status");
    setVolume = new QLabel("Set Volume");
    setAlarmbtn = new QPushButton("Set Alarm");
    snoozebtn = new QPushButton("Snooze Alarm");
    stopbtn = new QPushButton("Stop Alarm");

    volumebar = new QSlider(Qt::Horizontal);
    volumebar->setMinimum(0);
    volumebar->setMaximum(100);

    hourBox = new QSpinBox();
    hourBox->setMinimum(0);
    hourBox->setMaximum(23);

    minuteBox = new QSpinBox();
    minuteBox->setMinimum(0);
    minuteBox->setMaximum(59);

    // add objects to layout and set layout
    timeHbox->addWidget(hourBox);
    timeHbox->addWidget(separater);
    timeHbox->addWidget(minuteBox);
    timeHbox->addWidget(setAlarmbtn);

    volumeHbox->addWidget(setVolume);
    volumeHbox->addWidget(volumebar);

    btnHbox->addWidget(snoozebtn);
    btnHbox->addWidget(stopbtn);

    vbox->addLayout(timeHbox);
    vbox->addLayout(volumeHbox);
    vbox->addWidget(status);
    vbox->addLayout(btnHbox);
    setLayout(vbox);
}

Alarm::~Alarm()
{
}
