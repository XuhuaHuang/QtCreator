#include "serialterm.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    serialTerm w;
    w.show();
    return a.exec();
}
