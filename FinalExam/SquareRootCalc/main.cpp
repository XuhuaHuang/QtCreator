#include "sqrtcalc.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SqrtCalc w;
    w.show();
    return a.exec();
}
