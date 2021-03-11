#include "customsignal.h"

customSignal::customSignal(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *vbox = new QVBoxLayout();

    // initialize label and button
    label = new QLabel("Hello Qt world!");
    // label->setFont(QFont("Times New Roman", 10));
    button = new QPushButton("Click me!");

    // add label and butotn to vertical layout manager
    vbox->addWidget(label);
    vbox->addWidget(button);
    setLayout(vbox);

    flag = 0;
    count = 0;

    // connect signals and slots
    connect(button, SIGNAL(clicked()), this, SLOT(changeLabelText()));
    connect(this, SIGNAL(counterInc(int)), this, SLOT(dispNumTimes(int)));
}

customSignal::~customSignal()
{
}

void customSignal::changeLabelText()
{
    if (flag == 0)
    {
        label->setText("Qt is awesome!");
        flag = 1;
    }
    else if(flag == 1)
    {
        label->setText("Hello Qt world!");
        flag = 0;
    }

    count++; // increment thge count variable
    emit counterInc(count); // emit the counterInc signal
    // pass the counter value as a parameter

}

void customSignal::dispNumTimes(int times)
{
    QMessageBox::information(this, "Display Count", // title
                             "The button has been pressed " + QString::number(times) + " times.", // message
                             QMessageBox::Ok,QMessageBox::Ok); // option
}
