/*****************************************************************//**
 * \file   main.cpp
 * \brief  file handling event loop
 * 
 * \author Xuhua Huang
 * \date   May 2021
 *********************************************************************/

#include "userinfo.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UserInfo w;
    w.show();
    return a.exec();
}
