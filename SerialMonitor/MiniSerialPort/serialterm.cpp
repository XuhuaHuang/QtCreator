/*****************************************************************//**
 * \file   serialterm.cpp
 * \brief  contains function definitions for class "serialTerm"
 *         building a minimal serial port terminal
 *
 * \author Xuhua Huang
 * \date   April 2021
 *********************************************************************/

#include "serialterm.h"

serialTerm::serialTerm(QWidget *parent)
    : QWidget(parent)
{
    // call function to draw the applicaiton
    drawForm();

    /* CONNECT BUTTONS AND SLOTS */
    // e.g. when connect button is clicked call the serConnect() slot
    connect(conbtn, SIGNAL(clicked()), this, SLOT(serConnect()));
    connect(disconbtn, SIGNAL(clicked()), this, SLOT(serDisConnect()));
    connect(txbtn, SIGNAL(clicked()), this, SLOT(serSendTxBuff()));
    connect(clrrxbtn, SIGNAL(clicked()), this, SLOT(serClrRxBuff()));
    connect(clrtxbtn, SIGNAL(clicked()), this, SLOT(serClrTxBuff()));
    connect(listbtn, SIGNAL(clicked()), this, SLOT(addAvailablePorts()));

    /* CONNECT SERIAL PORT AND SLOT TO DISPLAY DATA */
    // when data is available to be read on the serial port
    // the readyRead() signal is emitted by the QSerialport object 'serial'
    // this in turns activates the dispRxData() slot which reads all
    // available data from the serial port and then displays it in the RX buffer
    connect(serial, SIGNAL(readyRead()), this, SLOT(dispRxData()));
}

serialTerm::~serialTerm() {}

void serialTerm::addAvailablePorts()
{
    enumerateSerPorts(); // save a list of available ports info in serinfo
    for (int i = 0; i < serinfo.count(); i++)
        portsbox->insertItem(i, serinfo[i].portName());
}

/* DRAW APPLICATION LAYOUT */
void serialTerm::drawForm(void)
{
    /* INITIALIZE ELEMENTS */
    serial = new QSerialPort(this);
    // initialize buttons
    conbtn = new QPushButton("Connect"); // create connect button
    disconbtn = new QPushButton("Disconnect"); // create disconnect button
    txbtn = new QPushButton("Send"); // create send button
    clrtxbtn = new QPushButton("Clear Tx Buffer"); // create clear TX buffer button
    clrrxbtn = new QPushButton("Clear Rx Buffer"); // create clear RX buffer button

    listbtn = new QPushButton("List Available Serial Ports");
    portsbox = new QComboBox();
    baudrate = new QComboBox();
    baudrate->addItems(baudRateList);

    // text editting field
    rxbuff = new QTextEdit(); // create RX Buffer
    txbuff = new QTextEdit(); // create TX Buffer

    // initialize labels
    statuslbl = new QLabel(); // Create status label...displys port status
    statuslbl->setText("Port: Disconnected");
    txlbl = new QLabel("&Tx Buffer"); // label for TX buffer ALT-T moves focus to this control
    rxlbl = new QLabel("&Rx Buffer"); // label for TX buffer ALT-R moves focus to this control
    rxlbl->setBuddy(rxbuff); // set rxbuff as buddy of rxlbl
    txlbl->setBuddy(txbuff); // set txbuff as buddy of txlbl

    // initialize layout managers
    hboxportrate = new QHBoxLayout(); // contains two combo boxes of available ports and baud rate
    vboxbuff = new QVBoxLayout();
    hboxbtns = new QHBoxLayout();
    txhbox = new QHBoxLayout();
    rxhbox = new QHBoxLayout();

    /* ADD ELEMENTS TO ELEMENT LAYOUT MANAGER */
    // port combo bax and baud rate
    hboxportrate->addWidget(portsbox);
    hboxportrate->addWidget(baudrate);
    // add RX and TX elemetns to correponding layout manager
    txhbox->addWidget(txlbl); txhbox->addWidget(txbtn); txhbox->addWidget(clrtxbtn);
    rxhbox->addWidget(rxlbl); rxhbox->addWidget(clrrxbtn);
    // add buttons to hbox
    hboxbtns->addWidget(conbtn); hboxbtns->addWidget(disconbtn);

    /* SET APPLICATION LAYOUT */
    // add lauout managers and widgets to application layout manager
    vboxbuff->addWidget(listbtn); // click to see available serial ports
    vboxbuff->addLayout(hboxportrate); // list all available ports

    vboxbuff->addWidget(statuslbl);
    vboxbuff->addLayout(hboxbtns);
    vboxbuff->addLayout(rxhbox);
    vboxbuff->addWidget(rxbuff);
    vboxbuff->addLayout(txhbox);
    vboxbuff->addWidget(txbuff);
    setLayout(vboxbuff);
    setWindowTitle("Simple Serial Terminal"); // sets window title
    resize(400, 500); // set fixed-size window
    // set tool tip
    setToolTip("This is a simple serial terminal application hardwired to 9600 8-N-1.\n"
               "It will connect to the first enumerated serial port");
    // set application icon
    setWindowIcon(QIcon("serial.png"));

    /* HANDLE TAB ORDERS AND BEHAVIOUR */
    // ensure that TextEdit objects interprets a tab keypress as focus change
    // & and not part of the textediting inside the control
    rxbuff->setTabChangesFocus(true);
    txbuff->setTabChangesFocus(true);

    // set tab order of the widgets in the application
    // 1 - connect button // 2 - disconnect button
    setTabOrder(conbtn, disconbtn);
    // 3 - clear RX buffer button
    setTabOrder(disconbtn, clrrxbtn);
    // 4 - RX buffer
    setTabOrder(clrrxbtn, rxbuff);
    // 5 - send button
    setTabOrder(rxbuff, txbtn);
    // 6 - clear TX buffer button
    setTabOrder(txbtn, clrtxbtn);

    /* EX 2 Reverse Tab Order */
    /* Uncomment to see in action */
    /*
    setTabOrder(clrtxbtn, txbtn);
    setTabOrder(txbtn, rxbuff);
    setTabOrder(rxbuff, clrrxbtn);
    setTabOrder(clrrxbtn, disconbtn);
    setTabOrder(disconbtn, conbtn);
    */
}

/* LIST ALL AVAILABLE PORTS */
void serialTerm::enumerateSerPorts(void )
{
    serinfo = QSerialPortInfo::availablePorts();
}

/* CONNECT TO SERIAL PORT */
void serialTerm::serConnect(void)
{
    // enumerateSerPorts(); // save a list of available ports info in serinfo
    if(serinfo.count() == 0) // if no ports are found...
    {
        QMessageBox::warning(this, "Oops!", "No available serial port!");
    }
    else // if at least one port is found...we will use the first port found
    {
        // serial->setPort(serinfo[0]);
        serial->setPort(serinfo[portsbox->currentIndex()]);
        if(serial->isOpen())// if port is already open...
            QMessageBox::warning(this,"Oops!","Serial port is already open. Please disconnect first.");
        else // if port is available and not open...open it
        {
            if (serial->open(QIODevice::ReadWrite) == false)
            {
                QMessageBox::warning(this,"Oops!","Failed to open port.");
                serial->close(); // if opening port failed close it
            }
            else // if port opened successfully....set its parameters
            {
                if (baudrate->currentText() == "1200")
                    serial->setBaudRate(QSerialPort::Baud1200);
                else if (baudrate->currentText() == "2400")
                    serial->setBaudRate(QSerialPort::Baud2400);
                else if (baudrate->currentText() == "4800")
                    serial->setBaudRate(QSerialPort::Baud4800);
                else if (baudrate->currentText() == "9600")
                    serial->setBaudRate(QSerialPort::Baud9600);
                else if (baudrate->currentText() == "19200")
                    serial->setBaudRate(QSerialPort::Baud19200);
                else
                    serial->setBaudRate(QSerialPort::UnknownBaud);

                // serial->setBaudRate(QSerialPort::Baud9600); // BaudRate //,QSerialPort::AllDirections);
                serial->setDataBits(QSerialPort::Data8); // 8-bit data
                serial->setParity(QSerialPort::NoParity); // no parity
                serial->setFlowControl(QSerialPort::NoFlowControl); // no flow control
                serial->setStopBits(QSerialPort::OneStop); // 1 stop bit
                // update status label
                statuslbl->setText("Port: " + serinfo[0].portName() + " is open "
                                 + "at baud rate " + baudrate->currentText() + " bits per second");
            }
        }
    }
}

/* DISCONNECT FROM SERIAL PORT */
void serialTerm::serDisConnect(void)
{
    if (serial->isOpen()==false)
        QMessageBox::warning(this,"Oops!","Serial port is already closed!");
    else
    {
        serial->close(); // close port
        statuslbl->setText("Port: " + serinfo[0].portName() + " is disconnected"); // update status label
    }
}

/* TRANSMIT SERIAL BUFFER */
void serialTerm::serSendTxBuff(void)
{
    if (serial->isOpen() == false) // if the port is not open
        QMessageBox::warning(this,"Oops!", "Port is not open.");
    else if (txbuff->toPlainText().count() == 0)
        QMessageBox::warning(this,"Oops!", "Transmit Buffer is Empty.");
    else // if port is open and data is available in the transmit buffer
        serial->write(txbuff->toPlainText().toStdString().c_str()); // write TX buffer contents to serial port
    // convert to plain text, then to C++ string, then to C style string
}

/* CLEAR TRANSMIT BUFFER */
void serialTerm::serClrTxBuff(void)
{
    txbuff->clear(); // clear RX buffer
}

/* CLEAR RECEIVE BUFFER */
void serialTerm::serClrRxBuff(void)
{
    rxbuff->clear();// clear TX buffer
}

/* DISPLAY RECEIVED DATA */
// Everytime data is received by the serial port...the "readyRead()" signal
// is emitted by the QSerialPort object.
// This signal is then connected to the dispRXData slot method below
// which reads the data on the serial port and displays them in the RX buffer
void serialTerm::dispRxData(void)
{
    rxbuff->insertPlainText(QString(serial->readAll()));
    // convert return type of function readAll() to a QString object
    // then insert as plain text
}
