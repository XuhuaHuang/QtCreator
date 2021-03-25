#include "alarm.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Alarm w;
    w.show();
    return a.exec();
}
