/*****************************************************************//**
 * \file   userinfo.cpp
 * \brief  file contains function definition for 
 * declared class "UserInfo"
 * 
 * \author Xuhua Huang
 * \date   May 2021
 *********************************************************************/

#include "userinfo.h"

UserInfo::UserInfo(QWidget *parent)
    : QWidget(parent)
{
    /* Call Private Functions to Initialize and Draw Layout */
    initElements();
    setAppLayout();

    /* Connect Signals and Slots */
    connect(okbtn, SIGNAL(clicked()), this, SLOT(okbtnClicked()));
    connect(quitbtn, SIGNAL(clicked()), qApp, SLOT(quit()));
}

UserInfo::~UserInfo()
{
}

void UserInfo::initElements()
{
    /* Various Labels */
    firstNamelbl = new QLabel("First Name:");
    lastNamelbl = new QLabel("Last Name:");
    stAddrlbl = new QLabel("Street Address:");
    citylbl = new QLabel("City:");

    /* Various Inline Text Edit Fields */
    firstNameedt = new QLineEdit();
    lastNameedt = new QLineEdit();
    stAddredt = new QLineEdit();
    cityedt = new QLineEdit();

    /* Handle Province ComboBox */
    provlbl = new QLabel("Province");
    provcbb = new QComboBox();
    provcbb->addItems(provStrList);

    /* Handle Postal Code with Regular Expression Validator */
    postlbl = new QLabel("Postal Code");
    postedt = new QLineEdit();
    postalcoderegexp = new QRegExpValidator(QRegExp("[A-Z]{1}[0-9]{1}[A-Z]{1}[\\s]"  // char-int-char
                                                    "[0-9]{1}[A-Z]{1}[0-9]{1}")); // int-char-int
    postedt->setValidator(postalcoderegexp);

    /* Reald Only Text Edit Field */
    /* Place Holder to Insert Texts when 'OK' Button is Clicked */
    readOnlyRst = new QTextEdit();

    /* 'OK' and 'QUIT' Button */
    okbtn = new QPushButton("OK");
    quitbtn = new QPushButton("Quit");
}

void UserInfo::setAppLayout()
{
    lblEdtLayout = new QGridLayout();
    lblEdtLayout->addWidget(firstNamelbl, 0, 0);
    lblEdtLayout->addWidget(firstNameedt, 0, 1);
    lblEdtLayout->addWidget(lastNamelbl, 1, 0);
    lblEdtLayout->addWidget(lastNameedt, 1, 1);
    lblEdtLayout->addWidget(stAddrlbl, 2, 0);
    lblEdtLayout->addWidget(stAddredt, 2, 1);
    lblEdtLayout->addWidget(citylbl, 3, 0);
    lblEdtLayout->addWidget(cityedt, 3, 1);

    provPsthbox = new QHBoxLayout();
    provPsthbox->addWidget(provlbl);
    provPsthbox->addWidget(provcbb);
    provPsthbox->addWidget(postlbl);
    provPsthbox->addWidget(postedt);

    btnhbox = new QHBoxLayout();
    btnhbox->addWidget(okbtn);
    btnhbox->addWidget(quitbtn);

    mainLayout = new QVBoxLayout();
    mainLayout->addLayout(lblEdtLayout);
    mainLayout->addLayout(provPsthbox);
    mainLayout->addLayout(btnhbox);
    mainLayout->addWidget(readOnlyRst);

    this->setLayout(mainLayout);
    this->setWindowTitle("User Information Widget");
    this->setWindowIcon(QIcon("../info.png"));
    this->setFixedSize(350, 450);
}

void UserInfo::okbtnClicked()
{
    /* Check Content of Each Input Field */
    if(firstNameedt->text() == NULL || lastNameedt->text() == NULL
            || stAddredt->text() == NULL || postedt->text() == NULL)
        readOnlyRst->setText("Please double check one or more invalid input(s).");
    else /* Inputs Verified */
    {
        // insert text in hard-coded format
        readOnlyRst->setText(firstNameedt->text() + " " + lastNameedt->text() + "\n"
                             + stAddredt->text() + "\n"
                             + cityedt->text() + ", " + provcbb->currentText() + "\n"
                             + postedt->text());
    }
    readOnlyRst->setReadOnly(true);
}
