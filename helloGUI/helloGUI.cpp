#include "helloGUI.h"
// various libraries are included in the header file

// helloGUI class constructor
// pointer parent is passed to parent class constructor
helloGUI::helloGUI(QWidget *parent)
    : QWidget(parent)
{
    // instanciate a vertical box layout manager
    QVBoxLayout *vbox = new QVBoxLayout();

    // instantiate a label with "new" keyword and call QLabel constructor
    label = new QLabel("Hello Qt World");
    label->setFont(QFont("Times New Roman", 11));

    // set the background to green and text to white
    label->setStyleSheet("QLabel { background-color : green; color : white; }");

    // create a new label to implement very first hyperlink
    QLabel *label2 = new QLabel();
    showHyperlink(label2); // call function

    // add the label to the layout manager
    vbox->addWidget(label);
    vbox->addWidget(label2); // label2 still exists since it is a pointer

    // notice that there can only be one setLayout(): at the end of the constructor
    this->setLayout(vbox);
}

// helloGUI class destructor is empty since
// all heap objects are deleted by parent class destructor
helloGUI::~helloGUI()
{
}

// content modified by function will stay since it is passed the address
void helloGUI::showHyperlink(QLabel *label)
{
    label->setText("<a href=\"www.qt-project.org/\">Get Started With Qt</a>");
    label->setTextFormat(Qt::RichText);
    label->setTextInteractionFlags(Qt::TextBrowserInteraction);
    label->setOpenExternalLinks(true);
}
