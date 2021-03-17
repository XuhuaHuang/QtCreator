#ifndef UDPEXAMPLE_H
#define UDPEXAMPLE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>
#include <QValidator>
#include <QRegExpValidator>
#include <QJsonObject>
#include <QJsonDocument>
#include <QDebug>
#include <QtNetwork>
#include <QUdpSocket>

class UDPExample : public QWidget
{
    Q_OBJECT

public:
    UDPExample(QWidget *parent = nullptr);
    ~UDPExample();

public slots:
    void sendJsonUdp(void);
    void readUDPDataReceived(void);

private:
    // private function to draw app
    void drawApp();

    // layout manager
    QVBoxLayout *vbox, *vboxlbl, *vboxfield;
    QHBoxLayout *hbox;

    // label for user to enter information, network port and display status
    QLabel *namelbl, *staddrlbl, *provlbl, *postlbl, *countrylbl, *senderiplbl, *senderportlbl, *recvstatuslbl;
    // added label to contain the user's favorite quote
    QLabel *quotelbl;

    // text edit field, send button and status message related to mentioned properties
    QLineEdit *nameedt, *straddredt, *postedt, *countryedt, *senderipedt, *senderportedt;
    // added text editting field to contain the user's favorite quote
    QLineEdit *quoteedt;

    QPushButton *sendbtn;
    QComboBox *provbox;

    // postal code requires validation
    QRegExpValidator *postalcoderegexp;
    QUdpSocket *udpSocket;

    // variable to count the times of successful send/receive
    int okcount;
};
#endif // UDPEXAMPLE_H
