#include "completeclock.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CompleteClock w;
    w.show();
    return a.exec();
}
