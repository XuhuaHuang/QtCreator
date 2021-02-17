/*****************************************************************//**
 * \file   phonedial.cpp
 * \brief  Contains implementation for extra QLineEdit and QKeyEvent
 * 
 * \author Xuhua Huang
 * \date   February 2021
 *********************************************************************/

#include "phonedial.h"

phoneDial::phoneDial(QWidget *parent)
    : QWidget(parent)
{
    // initialize
    vbox = new QVBoxLayout();
    myKeyPad = new keyPad();
    numEdit = new QLineEdit();
    clear = new QPushButton("Clear");

    // add elements to vertical layout manager
    vbox->addWidget(numEdit);
    vbox->addWidget(myKeyPad);
    vbox->addWidget(clear);
    setLayout(vbox);

    // connect events and slots
    connect(myKeyPad, SIGNAL(digitClicked(int)), this, SLOT(dialEvent(int)));
    connect(clear, SIGNAL(clicked()), numEdit, SLOT(clear()));
}

phoneDial::~phoneDial()
{
}

void phoneDial::dialEvent(int btnPressed)
{
    QString btnStr = QString::number(btnPressed);
    numEdit->insert(btnStr);
}

void phoneDial::keyPressEvent(QKeyEvent *event)
{
    int keyVal = event->key(); // convert to integer for int
    if(keyVal >= 0x30 && keyVal <= 0x39) // compare
        numEdit->insert(event->text()); // input to QLineEdit
}
