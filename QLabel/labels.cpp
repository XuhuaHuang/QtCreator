/*****************************************************************//**
 * \file   labels.cpp
 * \brief  usage of various labels, including interactive and prixmap
 * 
 * \author Xuhua Huang
 * \date   March 2021
 *********************************************************************/

#include "labels.h"

labels::labels(QWidget *parent)
    : QWidget(parent)
{
    vbox = new QVBoxLayout();

    // interactable label
    label1 = new QLabel("<a href=\"http://www.youtube.com/watch?v=yMe7mlRv8UE/\">"
                        "These Pretzels are making me thristy!</a>");
    label1->setTextFormat(Qt::RichText);
    label1->setTextInteractionFlags(Qt::TextBrowserInteraction);
    label1->setOpenExternalLinks(true);

    // label 2 is a picture of a smiley face
    label2 = new QLabel();
    pic = new QPixmap("smiley.png");
    label2->setPixmap(*pic);

    // add two labels and set the layout
    vbox->addWidget(label1);
    vbox->addWidget(label2);
    setLayout(vbox);

    // QString type object the signal emits with will be passed automatically to custom slot
    connect(label1, SIGNAL(linkHovered(QString)), this, SLOT(dispHovlink(QString)));
}

labels::~labels()
{
}

void labels::dispHovlink(QString argString){
        QMessageBox::information(this, "Link Hovered", argString);
}
