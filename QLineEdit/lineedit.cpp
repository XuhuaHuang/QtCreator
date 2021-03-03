/*****************************************************************//**
 * \file   lineedit.cpp
 * \brief  text fields with QValidator and regular expression
 * 
 * \author Xuhua Huang
 * \date   March 2021
 *********************************************************************/

#include "lineedit.h"

lineEdit::lineEdit(QWidget *parent)
    : QWidget(parent)
{
    // layout managers
    hbox1 = new QHBoxLayout();
    hbox2 = new QHBoxLayout();
    hbox3 = new QHBoxLayout();
    hbox4 = new QHBoxLayout();
    vbox = new QVBoxLayout();

    // buttons
    intbtn = new QPushButton("Press to verify integer number");
    dblbtn = new QPushButton("Press to verify double number");
    regexpbtn = new QPushButton("Press to verify phone number");

    // labels
    intlbl = new QLabel ("Enter an int between 0 & 999: ");
    dblelbl = new QLabel ("Enter a double between 0 & 10 with three decimal places: ");
    regexplbl = new QLabel ("Enter a phone number (613-xxx-xxxx)");
    output = new QLabel();

    // validators
    // integer: from 0 to 999
    intv = new QIntValidator(0, 999, this);
    // double: from 0 to 999 with 3 decimal places
    dblv = new QDoubleValidator(0.000, 9.999, 3, this);
    dblv->setNotation(QDoubleValidator::StandardNotation);
    // regular expression
    QRegExp regExp("613-[0-9]{3}-[0-9]{4}");
    regexpv = new QRegExpValidator(regExp,this);
    // 19-[0-9]{2}-[0-12]{2}-[0-31]{2}

    // create text fields and link them to validators
    intledt = new QLineEdit();
    dbleledt = new QLineEdit();
    regexpledt = new QLineEdit();
    intledt->setValidator(intv);
    dbleledt->setValidator(dblv);
    regexpledt->setValidator(regexpv);

    // layout management
    hbox1->addWidget(intlbl);hbox1->addWidget(intledt);
    hbox2->addWidget(dblelbl);hbox2->addWidget(dbleledt);
    hbox3->addWidget(regexplbl);hbox3->addWidget(regexpledt);
    hbox4->addWidget(intbtn);hbox4->addWidget(dblbtn);hbox4->addWidget(regexpbtn);
    vbox->addLayout(hbox1);
    vbox->addLayout(hbox2);
    vbox->addLayout(hbox3);
    vbox->addLayout(hbox4);
    setLayout(vbox);

    // connect signals and slots
    connect (intbtn,SIGNAL(clicked()),this,SLOT(intdata()));
    connect (dblbtn,SIGNAL(clicked()),this,SLOT(dbledata()));
    connect (regexpbtn,SIGNAL(clicked()),this,SLOT(regexpdata()));
}

lineEdit::~lineEdit()
{
}

void lineEdit::intdata(void){
    QMessageBox::information(this,"","You have entered: " + intledt->text());
}
void lineEdit::dbledata(void){
    QMessageBox::information(this,"","You have entered: " + dbleledt->text());
}
void lineEdit::regexpdata(void){
    QMessageBox::information(this,"","You have entered: " + regexpledt->text());
}
