#include "helloGUI.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    helloGUI w;
    w.show();
    return a.exec();
}
