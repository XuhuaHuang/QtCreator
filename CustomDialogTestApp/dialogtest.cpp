/*****************************************************************//**
 * \file   dialogtest.cpp
 * \brief  implementation file
 * 
 * \author Xuhua Huang
 * \date   April 2021
 *********************************************************************/

#include "dialogtest.h"

DialogTest::DialogTest(QWidget *parent)
    : QWidget(parent)
{
    /* INITIALIZATION */
    modalbtn = new QPushButton("Modal Dialog"),
    modelessbtn = new  QPushButton("ModelessDialog");
    slider = new QSlider(Qt::Horizontal);
    slider->setMinimum(0);
    slider->setMaximum(99);
    label = new QLabel();
    hbox = new QHBoxLayout();
    vbox = new QVBoxLayout();

    /* ADD ELEMENTS */
    hbox->addWidget(modalbtn);
    hbox->addWidget(modelessbtn);
    vbox->addWidget(slider);
    vbox->addWidget(label);
    vbox->addLayout(hbox);
    setLayout(vbox);
    setFixedSize(330, 90);

    /* INITIALIZE CUSTOM DIALOG */
    modaldialog = new CustomDialog(this);
    modelessdialog = new CustomDialog(this);

    /* CONENCT SIGNALS AND SLOTs */
    connect(modalbtn, SIGNAL(clicked()), this, SLOT(activateModal()));
    connect(modelessbtn, SIGNAL(clicked()), this, SLOT(activateModeless()));

    connect(slider, SIGNAL(valueChanged(int)), this, SLOT(updateAppValue(int)));
    connect(slider, SIGNAL(valueChanged(int)), modelessdialog, SLOT(updateDialogValue(int)));

    connect(modaldialog, SIGNAL(dialogValueChanged(int)), this, SLOT(updateAppValue(int)));
    connect(modelessdialog, SIGNAL(dialogValueChanged(int)), this, SLOT(updateAppValue(int)));
}

DialogTest::~DialogTest() {}

void DialogTest::activateModal(void)
{
    modaldialog->updateDialogValue(slider->value());
    if(modaldialog->exec() == QDialog::Accepted )
        qDebug() << "You Pressed the 'OK' button on the modal dialog" << endl;
    else
        qDebug() << "You Pressed the 'Cancel' button on the modal dialog" << endl;
}

void DialogTest::activateModeless(void)
{
    modelessdialog->updateDialogValue(slider->value());
    modelessdialog->show();
    modelessdialog->raise();
    modelessdialog->activateWindow();

    if(modelessdialog->result()== QDialog::Accepted )
        qDebug() << "You Pressed the 'OK' button on the modeless dialog" << endl;
    else if(modelessdialog->result()== QDialog::Rejected )
        qDebug() << "You Pressed the 'Cancel' button on the modeless dialog" << endl;
}

void DialogTest::updateAppValue(int num)
{
    label->setText(QString::number(num));
    slider->setValue(num);
}
