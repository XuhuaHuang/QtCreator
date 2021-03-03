/*****************************************************************//**
 * \file   pushbuttons.cpp
 * \brief  different push button styles and practices
 *
 * \author Xuhua Huang
 * \date   March 2021
 *********************************************************************/

#include "pushbuttons.h"

pushbuttons::pushbuttons(QWidget* parent)
	: QWidget(parent)
{
	hbox = new QHBoxLayout();

	// initialize 4 different buttons
	clickbtn = new QPushButton("ClickMe!");
	clickbtn->setDefault(true);
	togglebtn = new QPushButton("ToggleMe!");
	togglebtn->setCheckable(true);
	flatbtn = new QPushButton("I'm Flat!!");
	flatbtn->setFlat(true);
	iconbtn = new QPushButton("Icon Button");
	iconbtn->setIcon(QIcon("smiley.png"));
	iconbtn->setIconSize(QSize(15, 15));

	// add pushbuttons to horizontal layout manager
	hbox->addWidget(clickbtn);
	hbox->addWidget(togglebtn);
	hbox->addWidget(flatbtn);
	hbox->addWidget(iconbtn);

	// set layout with hbox
	setLayout(hbox);

	// connect button signals to custon slot
	connect(clickbtn, SIGNAL(clicked()), this, SLOT(btnClicked()));
	connect(iconbtn, SIGNAL(clicked()), this, SLOT(btnClicked()));
	connect(flatbtn, SIGNAL(clicked()), this, SLOT(btnClicked()));
	connect(togglebtn, SIGNAL(clicked()), this, SLOT(btnClicked()));
}

pushbuttons::~pushbuttons()
{
}

void pushbuttons::btnClicked() {

	// capture the signature of the button and compare
	// to send corresponding message to the user
	QPushButton* sigbutton = (QPushButton*)sender();

	if (sigbutton->text() == "Icon Button")
		QMessageBox::information(this, "Icon Button Clicked", "You clicked the icon clickable button");
	else if (sigbutton->isFlat())
		QMessageBox::information(this, "Flat Button Clicked", "You clicked the flat clickable button");
	else if (sigbutton->isDefault())
		QMessageBox::information(this, "Default Button Clicked", "You clicked the default clickable button");
	else if (sigbutton->isCheckable())
		QMessageBox::information(this, "Button Toggled", QString("Button state is %1!").arg(togglebtn->isChecked()));
}
