// hide or show a label

#include "pushbutton.h"

pushButton::pushButton(QWidget *parent)
    : QWidget(parent)
{
    // initialize various pointers to object with new keyword
    vbox = new QVBoxLayout();
    label = new QLabel("Hello world");
    button = new QPushButton("Click Me");
    quitButton = new QPushButton("Close");
    flag = 1; // initialize the boolean flag

    // add label and button to the vertical layout manager
    vbox->addWidget(label);
    vbox->addWidget(button);
    vbox->addWidget(quitButton);
    setLayout(vbox);

    // associate signal and SLOT
    // SLOT can be roughly understood as functions
    // connect(button, &QPushButton::clicked, this, &CodeExample::buttonPressed);
    connect(button, SIGNAL(clicked()), this, SLOT(buttonPressed()));

    // implementation of quitButton
    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
}

pushButton::~pushButton()
{
}

void pushButton::buttonPressed(){
    if (flag == 0)
    {
        label->setText("Hello world");
        label->show();
        flag = 1;
        // button->setText("Click Me");
    }
    else if (flag == 1)
    {
        label->setText("Qt is awesome");
        label->show();
        flag = 0;
        // button->setText("Click Me");
    }
}
