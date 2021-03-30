#ifndef COMPLETECLOCK_H
#define COMPLETECLOCK_H

#include <QWidget>

class CompleteClock : public QWidget
{
    Q_OBJECT

public:
    CompleteClock(QWidget *parent = nullptr);
    ~CompleteClock();
};
#endif // COMPLETECLOCK_H
