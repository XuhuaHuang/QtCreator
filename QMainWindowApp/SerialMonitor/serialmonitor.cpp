/*****************************************************************//**
 * \file   serialmonitor.cpp
 * \brief  contains function definitions for class 'SerialMonitor'
 *  with the ability to save message sent to serial port to a file
 *
 * \author Xuhua Huang
 * \date   April 2021
 *********************************************************************/

#include "serialmonitor.h"

SerialMonitor::SerialMonitor(QWidget *parent)
    : QMainWindow(parent)
{
    drawApplication();
    handleTabPress();
    createAction();
    createMenu();
    connectSignalSlot();
}

SerialMonitor::~SerialMonitor() {}

void SerialMonitor::drawApplication()
{
    /* INITIALIZE ELEMENTS */
    serial = new QSerialPort(this);
    // initialize buttons
    conbtn = new QPushButton("Connect");
    disconbtn = new QPushButton("Disconnect");
    txbtn = new QPushButton("Send");
    clrtxbtn = new QPushButton("Clear Transmit Buffer");
    clrrxbtn = new QPushButton("Clear Receive Buffer");
    listbtn = new QPushButton("List Available Serial Ports");

    portsbox = new QComboBox();
    baudratebox = new QComboBox();
    baudratebox->addItems(baudRateList);

    // text editting field
    rxbuff = new QTextEdit(); // text editting field for RX Buffer
    txbuff = new QTextEdit(); // text editting field for TX Buffer

    // initialize labels
    statuslbl = new QLabel(); // Create status label and displys port status
    statuslbl->setText("Port: Disconnected");
    txlbl = new QLabel("&Tx Buffer"); // label for TX buffer ALT-T moves focus to this control
    rxlbl = new QLabel("&Rx Buffer"); // label for TX buffer ALT-R moves focus to this control
    txlbl->setBuddy(txbuff); // set txbuff as buddy of txlbl
    rxlbl->setBuddy(rxbuff); // set rxbuff as buddy of rxlbl

    // initialize layout managers
    hboxportrate = new QHBoxLayout();   // contains two combo boxes of available ports and baud rate
    vboxbuff = new QVBoxLayout();       // overall layout
    hboxbtns = new QHBoxLayout();       // contains buttons
    txhbox = new QHBoxLayout();         // tranmit
    rxhbox = new QHBoxLayout();         // receive

    /* ADD ELEMENTS TO ELEMENT LAYOUT MANAGER */
    // port combo bax and baud rate
    hboxportrate->addWidget(portsbox);
    hboxportrate->addWidget(baudratebox);
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

    QWidget *serialMonitor = new QWidget;
    serialMonitor->setLayout(vboxbuff);
    setCentralWidget(serialMonitor);

    setWindowTitle("Simple Serial Terminal");
    setWindowIcon(QIcon("./serial.png"));
    setFixedSize(400, 500);
    setToolTip("This is a simple serial terminal application hardwired to 9600 8-N-1.\n"
               "It will connect to the first enumerated serial port");
}

void SerialMonitor::handleTabPress()
{
    /* HANDLE TAB ORDERS AND BEHAVIOUR */
    // ensure that TextEdit objects interprets a tab keypress as focus change
    // & and not part of the textediting inside the control
    rxbuff->setTabChangesFocus(true);
    txbuff->setTabChangesFocus(true);

    // set tab order of the widgets in the application
    // 1 - connect button
    // 2 - disconnect button
    setTabOrder(conbtn, disconbtn);
    // 3 - clear RX buffer button
    setTabOrder(disconbtn, clrrxbtn);
    // 4 - RX buffer
    setTabOrder(clrrxbtn, rxbuff);
    // 5 - send button
    setTabOrder(rxbuff, txbtn);
    // 6 - clear TX buffer button
    setTabOrder(txbtn, clrtxbtn);
}

void SerialMonitor::createMenu()
{

}

void SerialMonitor::createAction()
{

}

void SerialMonitor::connectSignalSlot()
{

}

/* LIST AVAILABLE PORTS */
void SerialMonitor::enumerateSerPorts()
{
    serinfo = QSerialPortInfo::availablePorts();
}

void SerialMonitor::saveFile(const QString &fileName)
{

}

void SerialMonitor::setFileName(const QString &fileName)
{

}

/* PUBLIC SLOTS DEFINED AS FOLLOWED */
void SerialMonitor::addAvailablePorts(void)
{

}

/* CONNECT TO SERIAL PORT */
void SerialMonitor::serialConnect(void)
{
    enumerateSerPorts();
    if(serinfo.count() == 0) // if no ports are found...
    {
        QMessageBox::warning(this, "Error", "No available serial port!");
    }
    else // if at least one port is found...we will use the first port found
    {
        serial->setPort(serinfo[portsbox->currentIndex()]);
        if(serial->isOpen())// if port is already open...
            QMessageBox::warning(this, "Error", "Serial port is already open. Please disconnect first.");
        else // if port is available and not open...open it
        {
            if (serial->open(QIODevice::ReadWrite) == false)
            {
                QMessageBox::warning(this, "Error", "Failed to open port.");
                serial->close(); // if opening port failed close it
            }
            else // if port opened successfully....set its parameters
            {
                if (baudratebox->currentText() == "1200")
                    serial->setBaudRate(QSerialPort::Baud1200);
                else if (baudratebox->currentText() == "2400")
                    serial->setBaudRate(QSerialPort::Baud2400);
                else if (baudratebox->currentText() == "4800")
                    serial->setBaudRate(QSerialPort::Baud4800);
                else if (baudratebox->currentText() == "9600")
                    serial->setBaudRate(QSerialPort::Baud9600);
                else if (baudratebox->currentText() == "19200")
                    serial->setBaudRate(QSerialPort::Baud19200);
                else
                    serial->setBaudRate(QSerialPort::UnknownBaud);

                serial->setDataBits(QSerialPort::Data8); // 8-bit data
                serial->setParity(QSerialPort::NoParity); // no parity
                serial->setFlowControl(QSerialPort::NoFlowControl); // no flow control
                serial->setStopBits(QSerialPort::OneStop); // 1 stop bit
                // update status label
                statuslbl->setText("Port: "
                                 + serinfo[portsbox->currentIndex()].portName()
                                 + " is open at baud rate "
                                 + baudratebox->currentText()
                                 + " bits per second");
            }
        }
    }
}

void SerialMonitor::serialDisconnect(void)
{

}

void SerialMonitor::serialSendTxBuff(void)
{

}

void SerialMonitor::serialClrTxBuff(void)
{

}

void SerialMonitor::serialClrRxBuff(void)
{

}

void SerialMonitor::dispRxData(void)
{

}

void SerialMonitor::save(void)
{

}

void SerialMonitor::saveAs(void)
{

}
