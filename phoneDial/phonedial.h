/*****************************************************************//**
 * \file   phonedial.h
 * \brief  Using created keypad to simulate a dial app
 * 
 * \author Xuhua Huang
 * \date   February 2021
 *********************************************************************/

#ifndef PHONEDIAL_H
#define PHONEDIAL_H

#include "keypad.h"
#include <QLineEdit> // added library
#include <QKeyEvent>

class phoneDial : public QWidget
{
    Q_OBJECT

private:
    QVBoxLayout *vbox;
    keyPad *myKeyPad;
    QLineEdit *numEdit;
    QPushButton *clear;

public slots:
    void dialEvent(int);
    void keyPressEvent(QKeyEvent *event);

public:
    phoneDial(QWidget *parent = nullptr);
    ~phoneDial();
};
#endif // PHONEDIAL_H
