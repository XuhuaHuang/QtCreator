#ifndef SERIALMONITOR_H
#define SERIALMONITOR_H

#include <QMainWindow>

class SerialMonitor : public QMainWindow
{
    Q_OBJECT

public:
    SerialMonitor(QWidget *parent = nullptr);
    ~SerialMonitor();
};
#endif // SERIALMONITOR_H
