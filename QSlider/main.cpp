#include "sliders.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    sliders w;
    w.show();
    return a.exec();
}
