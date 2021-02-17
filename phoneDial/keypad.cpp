/*****************************************************************//**
 * \file   keypad.cpp
 * \brief  Contains implementation for class "keyPad"
 * 
 * \author Xuhua Huang
 * \date   February 2021
 *********************************************************************/

#include "keypad.h"

keyPad::keyPad(QWidget *parent)
    : QWidget(parent)
{
    createLayout(); // private function within keyPad class

    // connect signals to custom slot
    connect(button[0],SIGNAL(clicked()),this,SLOT(button0Clicked()));
    connect(button[1],SIGNAL(clicked()),this,SLOT(button1Clicked()));
    connect(button[2],SIGNAL(clicked()),this,SLOT(button2Clicked()));
    connect(button[3],SIGNAL(clicked()),this,SLOT(button3Clicked()));
    connect(button[4],SIGNAL(clicked()),this,SLOT(button4Clicked()));
    connect(button[5],SIGNAL(clicked()),this,SLOT(button5Clicked()));
    connect(button[6],SIGNAL(clicked()),this,SLOT(button6Clicked()));
    connect(button[7],SIGNAL(clicked()),this,SLOT(button7Clicked()));
    connect(button[8],SIGNAL(clicked()),this,SLOT(button8Clicked()));
    connect(button[9],SIGNAL(clicked()),this,SLOT(button9Clicked()));
}

keyPad::~keyPad()
{
}

void keyPad::createLayout()
{
    gridLayout = new QGridLayout();

    // initialize and layout buttons with a forloop
    for(int i=1; i<10 ; i++)
    {
        button[i] = new QPushButton(QString::number(i));
        gridLayout->addWidget(button[i],((i-1)/3),((i-1)%3));
    }

    // initialize button 0 at the bottom of created layout
    button[0] = new QPushButton(QString::number(0));

    // add created widget and set layout
    gridLayout->addWidget(button[0],3,1); // (x, y) = (3, 1)
    setLayout(gridLayout);
}

// button clicked
void keyPad::button0Clicked(){
    qDebug() << "Button 0 was clicked.\n";
    emit digitClicked(0);
}
void keyPad::button1Clicked(){
    qDebug() << "Button 1 was clicked.\n";
    emit digitClicked(1);
}
void keyPad::button2Clicked(){
    qDebug() << "Button 2 was clicked.\n";
    emit digitClicked(2);
}
void keyPad::button3Clicked(){
    qDebug() << "Button 3 was clicked.\n";
    emit digitClicked(3);
}
void keyPad::button4Clicked(){
    qDebug() << "Button 4 was clicked.\n";
    emit digitClicked(4);
}
void keyPad::button5Clicked(){
    qDebug() << "Button 5 was clicked.\n";
    emit digitClicked(5);
}
void keyPad::button6Clicked(){
    qDebug() << "Button 6 was clicked.\n";
    emit digitClicked(6);
}
void keyPad::button7Clicked(){
    qDebug() << "Button 7 was clicked.\n";
    emit digitClicked(7);
}
void keyPad::button8Clicked(){
    qDebug() << "Button 8 was clicked.\n";
    emit digitClicked(8);
}
void keyPad::button9Clicked(){
    qDebug() << "Button 9 was clicked.\n";
    emit digitClicked(9);
}
