/*****************************************************************//**
 * \file   serialterm.h
 * \brief  contains class definition to create a minimal serial port
 *         with Qt Creator
 *
 * \author Xuhua Huang
 * \date   April 2021
 *********************************************************************/

#ifndef SERIALTERM_H
#define SERIALTERM_H

// include header to open a serial port
// configure, read and write to it
#include <QtSerialPort/QSerialPort>
// header primarily used to identify available serial ports in the system
#include <QtSerialPort/QSerialPortInfo>

#include <QWidget>
#include <QString>
#include <QList>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QTextEdit>
#include <QMessageBox>
#include <QIcon>
#include <QComboBox>

class serialTerm : public QWidget
{
    Q_OBJECT
public:
    serialTerm(QWidget *parent = 0);
    ~serialTerm();
    // method that draws the form
    void drawForm(void);
    // finds all serial ports
    void enumerateSerPorts(void);
public slots: //custom slot methods
    void addAvailablePorts(void);
    // connect to serial port
    void serConnect(void);
    // disconnect from serial port
    void serDisConnect(void);
    // transmit data available in TX buffer
    void serSendTxBuff(void);
    // clear TX buffer
    void serClrTxBuff(void);
    // clear RX buffer
    void serClrRxBuff(void);
    // receive and display data in RX buffer
    void dispRxData(void);
private:
    // declare required pointer variables
    // SerilaPort object
    QSerialPort *serial;
    // implicitly shared object i.e. no parent/child relationship
    QList<QSerialPortInfo> serinfo;
    // various buttons
    QPushButton *conbtn, *disconbtn, *txbtn, *clrtxbtn, *clrrxbtn;

    // available ports and baud rate
    QPushButton *listbtn; // list all available ports
    QHBoxLayout *hboxportrate; // hbox contains ports and baud rate
    QComboBox *portsbox; // show available serial ports
    QComboBox *baudrate; // contains baud rate list
    QStringList baudRateList = {"1200", "2400", "4800", "9600", "19200", "38400"};

    QTextEdit *rxbuff, *txbuff;
    QLabel *statuslbl, *txlbl, *rxlbl;
    QVBoxLayout *vboxbuff;
    QHBoxLayout *hboxbtns, *txhbox, *rxhbox;
};
#endif // SERIALTERM_H
