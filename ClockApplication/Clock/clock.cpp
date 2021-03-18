#include "clock.h"

Clock::Clock(QWidget *parent)
    : QWidget(parent)
{
    // initialize
    setWindowTitle("Digital Clock");
    // set window to frameless
    setWindowFlags(Qt::FramelessWindowHint);
    // change the background color
    setStyleSheet("background-color:#848484;"); // dark grey
    setAttribute(Qt::WA_TranslucentBackground);
    // line above set the frame closer to the edge of the window

    clk = new QLCDNumber();
    clktimer = new QTimer(this);
    vbox = new QVBoxLayout();
    clk->setSegmentStyle(QLCDNumber::Filled);   // filled text style
    clk->setSegmentStyle(QLCDNumber::Flat);     // flat text style

    // added context menu to close applicatin without frame
    // refer to a QPoint object which contains the coordinates
    setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, SIGNAL(customContextMenuRequested(const QPoint&)),
            this, SLOT(ShowContextMenu(const QPoint&)));

    // set layout
    vbox->addWidget(clk);
    this->setLayout(vbox);

    connect(clktimer, SIGNAL(timeout()), this, SLOT(showTime()));
    clktimer->start(1000);
    showTime();
    resize(320, 240); // set fixed-size window
}

Clock::~Clock()
{
}

// function responsible for displaying time
void Clock::showTime()
{
    // get current time and assigned to object
    // time of class QTime
    QTime time = QTime::currentTime();
    // convert to formatted string
    QString text = time.toString("hh:mm");
    // togle hour and minute seperater ":" every second
    if ((time.second() % 2) == 0)
        text[2] = ' ';
    // pass QString as argument to display time
    clk->display(text);
}

// added function definition to handle mouse event
// button pressed event
void Clock::mousePressEvent(QMouseEvent *event) {
    // update attributes associated to window position
    m_nMouseClick_X_Coordinate = event->x();
    m_nMouseClick_Y_Coordinate = event->y();
}

// mouse moved event
void Clock::mouseMoveEvent(QMouseEvent *event) {
    move(event->globalX()-m_nMouseClick_X_Coordinate,
         event->globalY()-m_nMouseClick_Y_Coordinate);
}

void Clock::ShowContextMenu(const QPoint& pos)
{
    // create a context menu with Quit button
    QMenu contextMenu(tr("Context menu"), this);
    contextMenu.setStyleSheet("background-color:purple");
    QAction quitAction("Quit", this);
    connect(&quitAction, SIGNAL(triggered()), this, SLOT(close()));
    contextMenu.addAction(&quitAction);     // add action to context menu
    contextMenu.exec(mapToGlobal(pos));
}
