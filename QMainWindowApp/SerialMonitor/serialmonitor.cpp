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
    : QMainWindow(parent),
      curFileName(""),
      firstSave(true)
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

    setWindowTitle("Serial Monitor");
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

void SerialMonitor::createAction()
{
    /* FILE */
    saveRxBuff = new QAction(QIcon("images/save.png"), "&Save RX Buffer", this);
    saveRxBuff->setShortcuts(QKeySequence::Save);
    saveRxBuff->setStatusTip("Save received buffer to a document");
    connect(saveRxBuff, SIGNAL(triggered()), this, SLOT(save()));

    saveRxBuffAs = new QAction(QIcon("images/saveAs.png"), "&Save RX Buffer As", this);
    saveRxBuffAs->setShortcuts(QKeySequence::SaveAs);
    saveRxBuffAs->setStatusTip("Save received buffer with a specified document name");
    connect(saveRxBuffAs, SIGNAL(triggered()), this, SLOT(saveAs()));

    /* To show About information */
    aboutAct = new QAction(QIcon("images/about.png"), "&About", this);
    aboutAct->setStatusTip("Show About information");
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));

    /* To exit the application */
    exitAct = new QAction(QIcon("images/exit.png"), "E&xit", this);
    exitAct->setShortcuts(QKeySequence::Quit);
    exitAct->setStatusTip("Exit the application");
    connect(exitAct, SIGNAL(triggered()), qApp, SLOT(closeAllWindows()));

    /* CONNECTION */
    connectSerial = new QAction(QIcon("images/connect.png"), "Connect", this);
    connectSerial->setStatusTip("Connect to selected seial port");
    connect(connectSerial, SIGNAL(triggered()), this, SLOT(serialConnect()));

    disconnectSerial = new QAction(QIcon("images/disconnect.png"), "Disconnect", this);
    connectSerial->setStatusTip("Disconnect from seial port");
    connect(disconnectSerial, SIGNAL(triggered()), this, SLOT(serialDisconnect()));
}

void SerialMonitor::createMenu()
{
    /* FILE MENU */
    fileMenu = menuBar()->addMenu("&File");
    fileMenu->addAction(saveRxBuff);
    fileMenu->addAction(saveRxBuffAs);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);
    fileMenu->addAction(aboutAct);

    /* CONNECTION */
    connectionMenu = menuBar()->addMenu("&Connection");
    connectionMenu->addAction(connectSerial);
    connectionMenu->addAction(disconnectSerial);
}

void SerialMonitor::connectSignalSlot()
{
    /* CONNECT BUTTONS AND SLOTS */
    // e.g. when connect button is clicked call the serConnect() slot
    connect(listbtn, SIGNAL(clicked()), this, SLOT(addAvailablePorts()));
    connect(conbtn, SIGNAL(clicked()), this, SLOT(serialConnect()));
    connect(disconbtn, SIGNAL(clicked()), this, SLOT(serialDisconnect()));
    connect(txbtn, SIGNAL(clicked()), this, SLOT(serialSendTxBuff()));
    connect(clrrxbtn, SIGNAL(clicked()), this, SLOT(serialClrRxBuff()));
    connect(clrtxbtn, SIGNAL(clicked()), this, SLOT(serialClrTxBuff()));

    /* CONNECT SERIAL PORT AND SLOT TO DISPLAY DATA */
    // when data is available to be read on the serial port
    // the readyRead() signal is emitted by the QSerialport object 'serial'
    // this in turns activates the dispRxData() slot which reads all
    // available data from the serial port and then displays it in the RX buffer
    connect(serial, SIGNAL(readyRead()), this, SLOT(dispRxData()));
}

/* LIST AVAILABLE PORTS */
void SerialMonitor::enumerateSerPorts()
{
    serinfo = QSerialPortInfo::availablePorts();
}

void SerialMonitor::saveFile(const QString& fileName)
{
    setFileName(fileName);
    firstSave = false;

    QFile file(fileName); // pass the pointer to overloaded QTextStream contructor
    if (!fileName.isEmpty() && !file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("SDI"),
                             tr("Cannot write file %1:\n%2.")
                             .arg(fileName)
                             .arg(file.errorString()));
        return;
    }

    /* Create QFile object with Provided File Name to Write to File */
    QTextStream out(&file); // pass the pointer to overloaded QTextStream contructor
    out << rxbuff->toPlainText() << endl;
    statusBar()->showMessage(tr("File saved"), 2000);
    file.close();
}

void SerialMonitor::setFileName(const QString& fileName)
{
    if(fileName.isEmpty())
        curFileName = "Untitled";
    else
        curFileName = fileName;
}

/* PUBLIC SLOTS DEFINED AS FOLLOWED */
/* ADD AVAILABLE PORTS TO COMBOBOX */
void SerialMonitor::addAvailablePorts(void)
{
    // qDebug() << "Add available port invoked. List button working";
    enumerateSerPorts(); // save a list of available ports / update info in serinfo
    for (int i = 0; i < serinfo.count(); i++)
        portsbox->insertItem(i, (serinfo[i]).portName());
}

/* CONNECT TO SERIAL PORT */
void SerialMonitor::serialConnect(void)
{
    enumerateSerPorts();
    if(serinfo.count() == 0) // if no ports are found...
    {
        QMessageBox::warning(this, "Error", "No available serial port.");
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
                                 + serial->portName()
                                 + " is open at baud rate "
                                 + serial->baudRate()
                                 + " bits per second");
            } // end condition: port open successfully
        } // end using serial port
    } // end looking for at least 1 serial port
}

/* DISCONNECT FROM SERIAL PORT */
void SerialMonitor::serialDisconnect(void)
{
    if (serial->isOpen()==false)
        QMessageBox::warning(this, "Error", "Serial port is already closed.");
    else
    {
        serial->close();
        statuslbl->setText("Port: " + serial->portName() + " is disconnected"); // update status label
    }
}

/* TRANSMIT SERIAL BUFFER */
void SerialMonitor::serialSendTxBuff(void)
{
    if (serial->isOpen() == false) // if the port is not open
        QMessageBox::warning(this, "Error", "Port is not open.");
    else if (txbuff->toPlainText().count() == 0)
        QMessageBox::warning(this, "Error", "Transmit buffer is empty.");
    else // if port is open and data is available in the transmit buffer
        serial->write(txbuff->toPlainText().toStdString().c_str()); // write TX buffer contents to serial port
    // convert to plain text, then to C++ string, then to C style string
}

/* CLEAR TRANSMIT BUFFER */
void SerialMonitor::serialClrTxBuff(void)
{
    txbuff->clear(); // clear Receive buffer Text Editing Field
}

/* CLEAR RECEIVE BUFFER */
void SerialMonitor::serialClrRxBuff(void)
{
    rxbuff->clear(); // clear Transmit buffer Text Editing Field
}

/* DISPLAY RECEIVED DATA */
// Everytime data is received by the serial port...the "readyRead()" signal
// is emitted by the QSerialPort object.
// This signal is then connected to the dispRXData slot method below
// which reads the data on the serial port and displays them in the RX buffer
void SerialMonitor::dispRxData(void)
{
    rxbuff->insertPlainText(QString(serial->readAll()));
    // convert return type of function readAll() to a QString object
    // then insert as plain text
}

/* SLOT save() & saveAs() */
/* INVOKE FUNCTION saveFile(const QString& fileName) */
void SerialMonitor::save(void)
{
    if (firstSave)
        saveAs();
    else if (!firstSave)
        saveFile(curFileName);
}

void SerialMonitor::saveAs(void)
{
    /* Added "All Files" and "Text Files" filter when saving a file */
    QString defaultSaveFilter = tr("Text Files (*.txt)");
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Save RX Buffer As"), "C:/untitled.txt",
                                                    tr("All Files (*.*);;Text Files (*.txt)"),
                                                    &defaultSaveFilter);
    saveFile(fileName);
}
