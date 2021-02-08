#include "pushbutton.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    pushButton w;
    w.show();
    return a.exec();
}
