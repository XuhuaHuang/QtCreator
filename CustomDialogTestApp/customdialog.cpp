/*****************************************************************//**
 * \file   customdialog.cpp
 * \brief  implementation to create a CustomDialog object
 *
 * \author Xuhua Huang
 * \date   April 2021
 *********************************************************************/

#include "customdialog.h"

CustomDialog::CustomDialog(QWidget *parent)
    : QDialog(parent)
{
    /* INITIALIZE QSpinBox and QSlider to represent integer value */
    spinbox = new QSpinBox();
    spinbox->setMinimum(0);
    spinbox->setMaximum(99);
    slider = new QSlider(Qt::Horizontal);
    slider->setMinimum(0);
    slider->setMaximum(99);

    label = new QLabel();
    dialogbtns = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
                                      Qt::Horizontal);

    /* ADD elements to layout manager and set application layout */
    vbox = new QVBoxLayout();
    vbox->addWidget(spinbox);
    vbox->addWidget(slider);
    vbox->addWidget(label);
    vbox->addWidget(dialogbtns);

    /* CONNECT signals and slots */
    /* Handle value changes */
    connect(spinbox, SIGNAL(valueChanged(int)), this, SLOT(updateDialogValue(int)));
    connect(slider, SIGNAL(valueChanged(int)), this, SLOT(updateDialogValue(int)));
    /* Handle user actions */
    connect(dialogbtns, SIGNAL(accepted()), this, SLOT(accept()));
    connect(dialogbtns, SIGNAL(rejected()), this, SLOT(reject()));

    /* ADD MENUBAR, FILE MENU AND ACTION TO QUIT */
    menuBar = new QMenuBar();
    fileMenu = new QMenu(tr("&File"));
    quitAct = new QAction(tr("Quit"), this);
    quitAct->setStatusTip(tr("Quit application"));
    quitAct->setShortcuts(QKeySequence::Quit);
    connect(quitAct, SIGNAL(triggered()), this, SLOT(close()));
    fileMenu->addAction(quitAct);

    menuBar->addMenu(fileMenu);
    vbox->setMenuBar(menuBar);
    setLayout(vbox);
}

CustomDialog::~CustomDialog() {}

void CustomDialog::updateDialogValue(int num){
    slider->setValue(num);
    spinbox->setValue(num);
    label->setText(QString::number(num));
    emit dialogValueChanged(num);
}
