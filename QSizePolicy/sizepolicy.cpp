/*****************************************************************//**
 * \file   sizepolicy.cpp
 * \brief  created two buttons with different size policy
 *
 * \author Xuhua Huang
 * \date   March 2021
 *********************************************************************/

#include "sizepolicy.h"

sizePolicy::sizePolicy(QWidget* parent)
	: QWidget(parent)
{
	// instantiate two new buttons
	btn1 = new QPushButton("hello");
	btn2 = new QPushButton("how are you");

	// set two buttons with different size policies
	// "hello" button is set to a fixed size
	// will not expand when application window expands
	btn1->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	// "how are you" button is set to expanding size
	// will expand when application window expands
	btn2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	// new vertical layout manager
	vbox = new QVBoxLayout();
	vbox->addWidget(btn1);
	vbox->addSpacing(2);
	vbox->addWidget(btn2);
	setLayout(vbox);
}

sizePolicy::~sizePolicy()
{
}
