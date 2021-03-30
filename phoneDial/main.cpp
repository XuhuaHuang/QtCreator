#include "phonedial.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    phoneDial w;
    w.show();
    return a.exec();
}
