#ifndef ALARM_H
#define ALARM_H

#include <QDebug>
#include <QWidget>
#include <QSpinBox>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSlider>
#include <QTime>
#include <QTimer>
#include <QMediaPlayer>

class Alarm : public QWidget
{
    Q_OBJECT

public:
    Alarm(QWidget *parent = nullptr);
    ~Alarm();
public slots:
    void setAlarmTime();
    void setHour(int userHour) { hour = userHour; }
    void setMinute(int userMinute) { minute = userMinute; }
    void compareTime();
    void soundAlarm();

    void snoozeAlarm();
    void stopAlarm();
    void setAlarmVolume(int volume) { alarmVolume = volume; }
private:
    // funtionality related variable
    QLabel *separater;
    QLabel *status;
    QLabel *volume;
    QPushButton *setAlarmbtn;
    QPushButton *snoozebtn;     // snooze the alarm
    QPushButton *stopbtn;       // stop the alarm
    QSlider *volumebar;         // control the volume of the alarm
    QSpinBox *hourBox;
    QSpinBox *minuteBox;
    QTimer *timer;
    QMediaPlayer *player;

    // status variable
    QTime alarmTime;
    QTime currentTime;
    unsigned int hour, minute;
    bool snoozed;
    bool activated;
    unsigned int alarmVolume;

    // layout manager
    QHBoxLayout *timeHbox;
    QHBoxLayout *volumeHbox;
    QHBoxLayout *btnHbox;
    QVBoxLayout *vbox;

    void drawApp();
};
#endif // ALARM_H
