#include "sizepolicy.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    sizePolicy w;
    w.show();
    return a.exec();
}
