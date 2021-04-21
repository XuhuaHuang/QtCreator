/*****************************************************************//**
 * \file   main.cpp
 * \brief  main function to test CustomDialog in a QWidget application
 * 
 * \author Xuhua Huang
 * \date   April 2021
 *********************************************************************/

#include "dialogtest.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DialogTest w;
    w.show();
    return a.exec();
}
