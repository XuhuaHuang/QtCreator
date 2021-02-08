#include "eventexample.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    eventExample w;
    w.show();
    return a.exec();
}
