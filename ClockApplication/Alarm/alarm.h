#ifndef ALARM_H
#define ALARM_H

#include <QWidget>

class Alarm : public QWidget
{
    Q_OBJECT

public:
    Alarm(QWidget *parent = nullptr);
    ~Alarm();
};
#endif // ALARM_H
