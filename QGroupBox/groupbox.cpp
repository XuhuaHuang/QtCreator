/*****************************************************************//**
 * \file   groupbox.cpp
 * \brief  example on group boxes
 * 
 * \author Xuhua Huang
 * \date   March 2021
 *********************************************************************/

#include "groupbox.h"

groupbox::groupbox(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Group Boxes"); // window title

    // initialize private attributess
    comedy = false;
    action = true;
    horror = false;

    // group box 1
    groupBox1 = new QGroupBox("Your Favourite Sport");
    groupBox1->setCheckable(true);
    groupBox1->setChecked(false);

    radio1 = new QRadioButton("Hockey");
    radio2 = new QRadioButton("Football");
    radio3 = new QRadioButton("Basketball");
    radio1->setChecked(true);

    vbox1 = new QVBoxLayout;
    vbox1->addWidget(radio1);
    vbox1->addWidget(radio2);
    vbox1->addWidget(radio3);
    vbox1->addStretch(1);

    groupBox1->setLayout(vbox1);
    groupBox1->setFlat(false);

    // group box 2
    groupBox2 = new QGroupBox("Your Favourite Movie Genres");
    groupBox2->setCheckable(true);
    groupBox2->setChecked(true);

    checkBox1 = new QCheckBox("Comedy");
    checkBox2 = new QCheckBox("Action");
    checkBox2->setChecked(true);
    checkBox3 = new QCheckBox("Horror");

    vbox2 = new QVBoxLayout;
    vbox2->addWidget(checkBox1);
    vbox2->addWidget(checkBox2);
    vbox2->addWidget(checkBox3);
    vbox2->addStretch(1);
    groupBox2->setLayout(vbox2);

    // place two group boxes with grid layout
    // use grid layout to set the window layout
    grid = new QGridLayout;
    grid->addWidget(groupBox1,0,0);
    grid->addWidget(groupBox2,0,1);
    setLayout(grid);

    // connect signals and slots
    // radio buttons and radioBtnStnChanged(bool)
    connect(radio1,SIGNAL(toggled(bool)),this,SLOT(radioBtnStnChanged(bool)));
    connect(radio2,SIGNAL(toggled(bool)),this,SLOT(radioBtnStnChanged(bool)));
    connect(radio3,SIGNAL(toggled(bool)),this,SLOT(radioBtnStnChanged(bool)));

    // connect groupbox and groupBxChanged(bool)
    connect(groupBox1,SIGNAL(toggled(bool)),this,SLOT(groupBxChanged(bool))) ;
    connect(groupBox2,SIGNAL(toggled(bool)),this,SLOT(groupBxChanged(bool))) ;

    // connect checkbox and chkBxStnChanged(bool)
    connect(checkBox1,SIGNAL(toggled(bool)),this,SLOT(chkBxStnChanged(bool)));
    connect(checkBox2,SIGNAL(toggled(bool)),this,SLOT(chkBxStnChanged(bool)));
    connect(checkBox3,SIGNAL(toggled(bool)),this,SLOT(chkBxStnChanged(bool)));
}

groupbox::~groupbox()
{
}

void groupbox::radioBtnStnChanged(bool check){

    QRadioButton *radbtn = (QRadioButton *)sender();

    if((radbtn->text() == "Hockey") && check) {
        QMessageBox::information(this,"Favourite Sport","Your favourite sport is Hockey" );
    }
    else if((radbtn->text() == "Football") && check ) {
        QMessageBox::information(this,"Favourite Sport","Your favourite sport is Football" );
    }
    else if((radbtn->text() == "Basketball") && check ) {
        QMessageBox::information(this,"Favourite Sport","Your favourite sport is Basketball" );
    }
}

void groupbox::groupBxChanged(bool check){
    QGroupBox *grpbx = (QGroupBox *)sender();

    if((grpbx->title() == "Your Favourite Sport") && check )
        QMessageBox::information(this,"GroupBox State","\"Your Favourite Sport\" groupbox is activated" );
    if((grpbx->title() == "Your Favourite Movie Genres") && check )
        QMessageBox::information(this,"GroupBox State","\"Your Favourite Movie Genres\" groupbox is activated" );
}

void groupbox::chkBxStnChanged(bool check){
    // capture the signature of the checkbox
    QCheckBox *chkbx = (QCheckBox *)sender();
    QString msg;

    // compare and assign value for later on display message
    if(chkbx->text() == "Comedy")
        comedy = check;
    if(chkbx->text() == "Action")
        action = check;
    if(chkbx->text() == "Horror")
        horror = check;

    // match condition with message for QMessageBox
    if(comedy && action && horror)
        msg = "You enjoy the comedy, action and horror genres";
    else if(comedy && action)
        msg = "You enjoy the comedy and action genres";
    else if(comedy && horror)
        msg = "You enjoy the comedy and horror genres";
    else if(action && horror)
        msg = "You enjoy the action and horror genres";
    else if(comedy)
        msg = "You enjoy the comedy genre";
    else if(action)
        msg = "You enjoy the action genre";
    else if(horror)
        msg = "You enjoy the horror genre";

    QMessageBox::information(this,"Favourite Movie Genre",msg);
}
