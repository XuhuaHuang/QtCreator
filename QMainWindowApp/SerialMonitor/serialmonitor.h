/*****************************************************************//**
 * \file   serialmonitor.h
 * \brief  application built to communicate with serial devices
 *  with the ability to save message sent to serial port to a file
 *
 * \author Xuhua Huang
 * \date   April 2021
 *********************************************************************/

#ifndef SERIALMONITOR_H
#define SERIALMONITOR_H

/* LAYOUT MANAGER */
#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>

/* UTILITY */
#include <QString>
#include <QList>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QDebug>

/* SERIAL PORT */
// open a serial port: configure, read and write
#include <QtSerialPort/QSerialPort>
// identify available serial ports in the system
#include <QtSerialPort/QSerialPortInfo>

/* ELEMENT HEADER */
#include <QPushButton>
#include <QLabel>
#include <QTextEdit>
#include <QMessageBox>
#include <QIcon>
#include <QComboBox>
#include <QPlainTextEdit>
#include <QAction>
#include <QMenu>
#include <QToolBar>
#include <QMenuBar>
#include <QStatusBar>
#include <QApplication>

class SerialMonitor : public QMainWindow
{
    Q_OBJECT

public:
    SerialMonitor(QWidget *parent = nullptr);
    ~SerialMonitor();

public slots:
    /* Serial port connectivity related slots */
    void addAvailablePorts(void);   // add ports to combobox
    void serialConnect(void);       // connect to serial port
    void serialDisconnect(void);    // disconnect from serial port
    void serialSendTxBuff(void);    // transmit data available in TX buffer
    void serialClrTxBuff(void);     // clear TX buffer
    void serialClrRxBuff(void);     // clear RX buffer
    void dispRxData(void);          // receive and display data in RX buffer

    /* Save to a file functionality related slots */
    void save(void);
    void saveAs(void);
    void about(void) {}

private:
    /* Private functions */
    void drawApplication(void);
    void handleTabPress(void);
    void createAction(void);
    void createMenu(void);
    void connectSignalSlot(void);
    void enumerateSerPorts(void);
    // save file and save as
    void saveFile(const QString &fileName);
    void setFileName(const QString &fileName);

    /* Serial port related private attributes */
    // pointer to 'QSerilaPort' object
    QSerialPort *serial;
    // implicitly shared object i.e. no parent/child relationship
    QList<QSerialPortInfo> serinfo;

    QPushButton *listbtn;       // button -> list all available ports
    QPushButton *conbtn, *disconbtn, *txbtn, *clrtxbtn, *clrrxbtn;

    QHBoxLayout *hboxportrate;  // hbox contains ports and baud rate
    QComboBox *portsbox;        // combo box to show available serial ports
    QComboBox *baudratebox;     // contains baud rate list
    QStringList baudRateList = {"1200", "2400", "4800", "9600", "19200", "38400"};

    QTextEdit *rxbuff, *txbuff;
    QLabel *statuslbl, *txlbl, *rxlbl;

    QVBoxLayout *vboxbuff;      // put buffer related variable
    QHBoxLayout *hboxbtns, *txhbox, *rxhbox;

    /* Added 'File' menu */
    QString curFileName;
    bool firstSave;
    QMenu *fileMenu;
    QAction *saveRxBuff, *saveRxBuffAs; //, *saveAsAct;
    QAction *aboutAct, *exitAct;

    /* Added 'Connection' menu */
    QMenu *connectionMenu;
    QAction *connectSerial, *disconnectSerial;
};
#endif // SERIALMONITOR_H
