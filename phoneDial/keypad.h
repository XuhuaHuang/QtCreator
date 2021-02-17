/*****************************************************************//**
 * \file   keypad.h
 * \brief  Header file for class keyPad with QWidget
 * 
 * \author Xuhua Huang
 * \date   February 2021
 *********************************************************************/

#ifndef KEYPAD_H
#define KEYPAD_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QDebug>

class keyPad : public QWidget
{
    Q_OBJECT

public:
    keyPad(QWidget *parent = nullptr);
    ~keyPad();

signals:
    void digitClicked(int digit);

private slots:
    // slot gets executed every time a signal is emitted
    void button0Clicked();
    void button1Clicked();
    void button2Clicked();
    void button3Clicked();
    void button4Clicked();
    void button5Clicked();
    void button6Clicked();
    void button7Clicked();
    void button8Clicked();
    void button9Clicked();

private:
    // private function to create layout
    void createLayout(void);

    // layout pointer and pushbutton
    QGridLayout *gridLayout;
    QPushButton *button[10];

};
#endif // KEYPAD_H
