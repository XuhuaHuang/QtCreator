#include "customsignal.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    customSignal w;
    w.setWindowTitle("Custom Signal and Slot");
    w.show();
    return a.exec();
}
