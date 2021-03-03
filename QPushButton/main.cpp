#include "pushbuttons.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    pushbuttons w;
    w.show();
    return a.exec();
}
