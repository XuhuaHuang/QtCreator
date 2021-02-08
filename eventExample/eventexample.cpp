#include "eventexample.h"

eventExample::eventExample(QWidget *parent)
    : QWidget(parent)
{
}

eventExample::~eventExample()
{
}

void eventExample::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape)
        this->close();
    else
        QMessageBox::information(this, "Event example", // title
                                 "You pressed key \"" + event->text() + "\" on your keyboard.", // message
                                 QMessageBox::Ok, QMessageBox::Ok); // option
}

void eventExample::mouseDoubleClickEvent(QMouseEvent *event)
{
    if (event->button() == Qt::RightButton)
        mouseClickedInfo("right button");
    else if (event->button() == Qt::LeftButton)
        mouseClickedInfo("left button");
    else if (event->button() == Qt::MiddleButton)
        mouseClickedInfo("middle button");
    else
        mouseClickedInfo("no button");
}


void eventExample::mouseClickedInfo(QString str)
{
    QMessageBox::information(this, "Mouse Button Double Clicked", // title
                             "You pressed the \"" + str + "\" on your mouse.", // message
                             QMessageBox::Ok, QMessageBox::Ok); // option
}
