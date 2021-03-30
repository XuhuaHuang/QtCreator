#include "alarm.h"

Alarm::Alarm(QWidget *parent)
    : QWidget(parent),
      hour(0),
      minute(0),
      snoozed(false),
      activated(false),
      alarmVolume(0)
{
    // initialize layout
    setWindowTitle("Alarm");
    // change the background color to dark grey
    setStyleSheet("background-color:#848484;");
    resize(280, 120); // set fixed-size window
    drawApp();        // call function to draw the app

    currentTime = QTime::currentTime();

    connect(setAlarmbtn, SIGNAL(clicked()), this, SLOT(setAlarmTime()));
    connect(snoozebtn, SIGNAL(clicked()), this, SLOT(snoozeAlarm()));
    connect(stopbtn, SIGNAL(clicked()), this, SLOT(stopAlarm()));

    connect(volumebar, SIGNAL(valueChanged(int)), this, SLOT(setAlarmVolume(int)));
    connect(hourBox, SIGNAL(valueChanged(int)), this, SLOT(setHour(int)));
    connect(minuteBox, SIGNAL(valueChanged(int)), this, SLOT(setMinute(int)));
}

Alarm::~Alarm()
{
}

void Alarm::drawApp()
{
    timeHbox = new QHBoxLayout();
    volumeHbox = new QHBoxLayout();
    btnHbox = new QHBoxLayout();
    vbox = new QVBoxLayout();

    // button, spin boxes and label
    separater = new QLabel(":");
    separater->setAlignment(Qt::AlignHCenter);
    status = new QLabel("Alarm status");
    volume = new QLabel("Set Volume");
    setAlarmbtn = new QPushButton("Set Alarm");
    snoozebtn = new QPushButton("Snooze Alarm");
    stopbtn = new QPushButton("Stop Alarm");

    volumebar = new QSlider(Qt::Horizontal);
    volumebar->setMinimum(0);
    volumebar->setMaximum(100);

    // hour spin box is limited from 0 to 23
    hourBox = new QSpinBox();
    hourBox->setMinimum(0);
    hourBox->setMaximum(23);

    // minute spin box is limited from 0 to 59
    minuteBox = new QSpinBox();
    minuteBox->setMinimum(0);
    minuteBox->setMaximum(59);

    // add objects to layout and set layout
    timeHbox->addWidget(hourBox);
    timeHbox->addWidget(separater);
    timeHbox->addWidget(minuteBox);
    timeHbox->addWidget(setAlarmbtn);

    volumeHbox->addWidget(volume);
    volumeHbox->addWidget(volumebar);

    btnHbox->addWidget(snoozebtn);
    btnHbox->addWidget(stopbtn);

    vbox->addLayout(timeHbox);
    vbox->addLayout(volumeHbox);
    vbox->addWidget(status);
    vbox->addLayout(btnHbox);
    setLayout(vbox);
}

void Alarm::setAlarmTime()
{
    alarmTime.setHMS(hour, minute, 0);
    if (activated)
    {
        soundAlarm(alarmTime);
    }

}

void Alarm::soundAlarm(const QTime& alarmTime)
{
    if (!snoozed && volume != 0)
    {

    }
}
