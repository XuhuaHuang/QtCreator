#include "tabdialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TabDialog w("tabdialog.cpp");
    w.show();
    return a.exec();
}
