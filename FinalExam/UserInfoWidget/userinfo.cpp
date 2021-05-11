#include "userinfo.h"

UserInfo::UserInfo(QWidget *parent)
    : QWidget(parent)
{
    initElements();
    setAppLayout();
}

UserInfo::~UserInfo()
{
}

void UserInfo::initElements()
{
    firstNamelbl = new QLabel("First Name:");
    lastNamelbl = new QLabel("Last Name:");
    stAddrlbl = new QLabel("Street Address:");
    citylbl = new QLabel("City:");

    firstNameedt = new QLineEdit();
    lastNameedt = new QLineEdit();
    stAddredt = new QLineEdit();
    cityedt = new QLineEdit();

    provlbl = new QLabel("Province");
    provcbb = new QComboBox();
    provcbb->addItems(provStrList);

    postlbl = new QLabel("Postal Code");
    postedt = new QLineEdit();
    postalcoderegexp = new QRegExpValidator(QRegExp("[A-Z]{1}[0-9]{1}[A-Z]{1}" // char-int-char
                                                    "[0-9]{1}[A-Z]{1}[0-9]{1}")); // int-char-int
    postedt->setValidator(postalcoderegexp);

    readOnlyRst = new QTextEdit();

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
    this->setFixedSize(400, 450);
}

void UserInfo::okbtnClicked()
{

}
