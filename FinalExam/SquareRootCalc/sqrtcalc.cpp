/*****************************************************************//**
 * \file   sqrtcalc.cpp
 * \brief  file contains function definition for declared
 * Square Root Calculator
 *
 * \author 1879700
 * \date   May 2021
 *********************************************************************/

#include "sqrtcalc.h"

SqrtCalc::SqrtCalc(QWidget *parent)
    : QWidget(parent)
{
    /* Initialize QLineEdit to Obtain User Input to Clculate */
    userInput = new QLineEdit();
    // set validator to accept 3 deciaml places
    userInput->setValidator(new QDoubleValidator(
                                -std::numeric_limits<double>::infinity(),
                                std::numeric_limits<double>::infinity(),
                                3)
                            );
    calcSqrt = new QPushButton("Calculate Square Root");
    result = new QLabel();

    /* Initialize HBox and add QLineEdit and QPushButton */
    editAndButton = new QHBoxLayout();
    editAndButton->addWidget(userInput);
    editAndButton->addWidget(calcSqrt);

    /* Initialize VBox, add HBox, and Set Layout */
    mainlayout = new QVBoxLayout();
    mainlayout->addLayout(editAndButton);
    mainlayout->addWidget(result);

    /* Handle Window Element Visuals */
    this->setLayout(mainlayout);
    this->setWindowTitle("Square Root Calculator");
    this->setWindowIcon(QIcon("../calculator.png"));
    this->setFixedSize(310, 110);

    /* Connect Signal and Slot */
    // when the QPushButton 'calcSqrt' is pushed
    // slot 'calcSqrtClicked()' is invoked
    // note that function to update label will be called in slot 'caclSqrtClicked()'
    connect(calcSqrt, SIGNAL(clicked()), this, SLOT(calcSqrtClicked()));
}

SqrtCalc::~SqrtCalc()
{
}

void SqrtCalc::calcSqrtClicked()
{
    double original = userInput->text().toDouble();
    double oldGuess = 0.5 * original;
    double newGuess = 0;
    int timesIterated = 0;
    double error = 1.0;

    while(error > 1e-3)
    {
        newGuess = 0.5 * (oldGuess + (original / oldGuess));
        error = qFabs(oldGuess - newGuess);
        oldGuess = newGuess;

        timesIterated++;
    }

    updateResultlbl(newGuess, timesIterated, error);
}

void SqrtCalc::updateResultlbl(double calcResult, int iterations, double error)
{
    result->setText("Square roor of " + QString::number(userInput->text().toDouble()*1.0) + " is " + QString::number(calcResult*1.0) + ".\n"
                    + "Result converged in " + QString::number(iterations + 1) + " iterations.\n"
                    + "Error is " + QString::number(error*1.0) + ".");
}
