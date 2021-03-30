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

    player = new QMediaPlayer();
    player->setMedia(QUrl::fromLocalFile("alarm.mp3"));
    currentTime = QTime::currentTime();

    timer = new QTimer(this);
    timer->start(500);  // call function to compare current time and alarm time each time timer emits a timeout() signal

    connect(setAlarmbtn, SIGNAL(clicked()), this, SLOT(setAlarmTime()));
    connect(snoozebtn, SIGNAL(clicked()), this, SLOT(snoozeAlarm()));
    connect(stopbtn, SIGNAL(clicked()), this, SLOT(stopAlarm()));
    connect(timer, SIGNAL(timeout()), this, SLOT(compareTime()));

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
    status = new QLabel();
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
    status->setText(
                QString("Alarm is set to: %1:%2")
                .arg(hour, 2, 10, QChar('0'))
                .arg(minute, 2, 10, QChar('0'))
                );
}

void Alarm::compareTime()
{
    if (currentTime.hour() == (int)hour &&
            currentTime.minute() == (int)minute &&
            activated)
    {
        soundAlarm();
    }
}

// alarm is already certified activated by the time soundAlarm() function is called
void Alarm::soundAlarm()
{
    if (!snoozed && volume != 0)
    {
        player->setVolume(alarmVolume);
        player->play();
    }
    else if (!snoozed && volume == 0)
        status->setText("Volume is set to 0");
}

void Alarm::snoozeAlarm()
{
    player->stop();
    snoozed = true;

    // handle edge cases
    if(currentTime.hour() == (int)hour &&
            currentTime.minute() == (int)minute)
    {
        if (minute < 50)
            minute += 10; // 49 + 10 < 60

        if (minute >= 50) {
            minute -= 50;
            hour++;
            // handle hour edge cases
            if (hour <= 22)
                hour++;
            else if (hour == 23)
                hour = 0;
        }
        alarmTime.setHMS(hour, minute, 0);
    }
    status->setText("Alarm is snoozed for 10 minutes");
}

void Alarm::stopAlarm()
{
    player->stop();
    activated = false;
    status->setText("Alarm is stopped");
}
