/*****************************************************************//**
 * \file   dialogtest.h
 * \brief  header file to test created CustomDialog in 
 *  QWidget application
 * 
 * \author Xuhua Huang
 * \date   April 2021
 *********************************************************************/

#ifndef DIALOGTEST_H
#define DIALOGTEST_H

#include <QWidget>
#include <QLabel>
#include <QSlider>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include "customdialog.h"

class DialogTest : public QWidget
{
    Q_OBJECT

public:
    explicit DialogTest(QWidget *parent = 0);
    ~DialogTest();

public slots:
    void activateModal(void);
    void activateModeless(void);
    void updateAppValue(int);

private:
    QPushButton *modalbtn, *modelessbtn;
    QSlider *slider;
    QLabel *label;
    QHBoxLayout *hbox;
    QVBoxLayout *vbox;
    CustomDialog *modaldialog;
    CustomDialog *modelessdialog;
};

#endif // DIALOGTEST_H
