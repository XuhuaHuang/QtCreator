/*****************************************************************//**
 * \file   main.cpp
 * \brief  simple console application that reads the contents of a file
 *  called �hello.txt� in one directory above the work directory
 *  and copies its contents into another file called �helloagain.txt�
 *  located in the work directory. 
 * 
 * \author Xuhua Huang
 * \date   April 2021
 *********************************************************************/

#include <QCoreApplication>
#include <QTextStream>
#include <QFile>
#include <QDebug>

int main(void)
{
    QFile data("../hello.txt");
    QString line;

    if (data.open(QFile::ReadOnly)) {
        QTextStream in(&data);
        QTextStream out(stdout);

        in.setCodec("UTF-8");
        out.setCodec("UTF-8");

        out << "Start printing content of file \"hello.txt\"" << endl
            << "Content will be copied to file named \"helloAgain.txt\"" << endl
            << "Any pre-existing file with the same name will be removed\n\n";

        do {
            line = in.readLine();
            out << line << endl;
        } while (!line.isNull());
    } // end rerading and printing content to console

    if (QFile::exists("../helloAgain.txt")) {
        QFile::remove("../helloAgain.txt");
        QFile::copy("../hello.txt", "../helloAgain.txt");
        qDebug() << "Finished printing and copying\n";
    }

    data.close();
}
