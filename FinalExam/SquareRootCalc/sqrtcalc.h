/*****************************************************************//**
 * \file   sqrtcalc.h
 * \brief  file contains class declaration related to 
 * a Square Root Calculator
 * 
 * \author Xuhua Huang
 * \date   May 2021
 *********************************************************************/

#ifndef SQRTCALC_H
#define SQRTCALC_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <qmath.h>
#include <QDebug>
#include <QString>
#include <QDoubleValidator>

class SqrtCalc : public QWidget
{
    Q_OBJECT

public:
    SqrtCalc(QWidget *parent = nullptr);
    ~SqrtCalc();

public slots:
    void calcSqrtClicked(); // handle button clicked event

private:
    /* Elements */
    QLabel *result;         // provides calculation results
    QLineEdit *userInput;   // asks for user input
    QPushButton *calcSqrt;  // button clicked to calculate

    /* Layout Managers */
    QHBoxLayout *editAndButton; // contains QLineEdit and QPushButton
    QVBoxLayout *mainlayout;    // contains hbox and QLabel

    // function to update result label
    void updateResultlbl(double, int, double);
};
#endif // SQRTCALC_H
