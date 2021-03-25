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

class Alarm : public QWidget
{
    Q_OBJECT

public:
    Alarm(QWidget *parent = nullptr);
    ~Alarm();
public slots:

private:
    // funtionality related variable
    QLabel *separater;
    QLabel *status;
    QLabel *setVolume;
    QPushButton *setAlarmbtn;
    QPushButton *snoozebtn;     // snooze the alarm
    QPushButton *stopbtn;       // stop the alarm
    QSlider *volumebar;         // control the volume of the alarm
    QSpinBox *hourBox;
    QSpinBox *minuteBox;

    // status variable
    unsigned int hour, minute;
    bool snoozed;
    bool activated;

    // layout manager
    QHBoxLayout *timeHbox;
    QHBoxLayout *volumeHbox;
    QHBoxLayout *btnHbox;
    QVBoxLayout *vbox;
};
#endif // ALARM_H
