#include "stopwatch.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StopWatch w;
    w.show();
    return a.exec();
}
