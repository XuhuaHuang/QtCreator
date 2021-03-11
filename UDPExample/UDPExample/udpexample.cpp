#include "udpexample.h"

UDPExample::UDPExample(QWidget *parent)
    : QWidget(parent)
{
    // call function to draw application
    drawApp();
    okcount = 0;

    // instantiate UDP socket and notify success or not
    udpSocket = new QUdpSocket(this);
    bool result = udpSocket->bind(QHostAddress::AnyIPv4, 8877,QUdpSocket::ShareAddress);
    qDebug() << result;
    if(result){
        qDebug() << "PASS";
    }else{
        qDebug() << "FAIL";
    }

    // connect signals and slots
    connect(udpSocket, SIGNAL(readyRead()), this, SLOT(readUDPDataReceived()));
    connect(sendbtn, SIGNAL(clicked()), this, SLOT(sendJsonUdp()));
}

UDPExample::~UDPExample()
{
}

void UDPExample::sendJsonUdp(void)
{
    QJsonObject objJson;

    // insert key-value pairs to the JSON object
    objJson.insert("Name",nameedt->text());
    objJson.insert("Street Address",straddredt->text());
    objJson.insert("Province",provbox->currentText());
    objJson.insert("Postal Code",postedt->text());
    objJson.insert("Country",countryedt->text());
    objJson.insert("Acknowledged", "??");

    // convert JSON object to JSON document
    QJsonDocument docJson;
    docJson.setObject(objJson);

    // convert JSON document to byte array
    QByteArray byteArray = docJson.toJson(QJsonDocument::Compact);
    qDebug() << byteArray << endl;

    unsigned short port = senderportedt->text().toUShort();
    QHostAddress address;
    address.setAddress(senderipedt->text());
    // writeDatagram(what_to_send, size, target_IP, port);
    udpSocket->writeDatagram(byteArray.data(),byteArray.size(),
                             address, port);
} // send JSON serialization package over UDP

void UDPExample::readUDPDataReceived(void){
    qDebug() << "received datagram" << endl;

    while (udpSocket->hasPendingDatagrams()) {
        qDebug() << "found pending datagram" << endl;
        QNetworkDatagram datagram = udpSocket->receiveDatagram();
        qDebug() << datagram.data() << endl ;

        QJsonDocument document = QJsonDocument::fromJson(datagram.data());
        QJsonObject jsonObj = document.object();

        QString ackMsg = jsonObj["Acknowledged"].toString();
        qDebug() << ackMsg << endl;
        if(ackMsg == "OK")
            okcount++; // increment
        recvstatuslbl->setText("Received: " + ackMsg + " " + QString::number(okcount));
    }
} // end reading received UDP data

void UDPExample::drawApp()
{
    // create layout managers
    vboxlbl = new QVBoxLayout(); // dedicated to manage labels
    vboxfield = new QVBoxLayout(); // dedicated to manage text editing field
    vbox = new QVBoxLayout();
    hbox = new QHBoxLayout();

    // create new labels
    namelbl =       new QLabel("Name:           ");
    staddrlbl =     new QLabel("Street Address: ");
    provlbl =       new QLabel("Province:       ");
    postlbl =       new QLabel("Postal Code:    ");
    countrylbl =    new QLabel("Country:        ");
    senderiplbl =   new QLabel("Sender IP:      ");
    senderportlbl = new QLabel("Sender Port:    ");
    recvstatuslbl = new QLabel("Received:       ");

    // creat text editing field corresponding to labels
    // name and street address
    nameedt = new QLineEdit();
    straddredt = new QLineEdit();

    postedt = new QLineEdit();
    // postal code validator
    postalcoderegexp = new QRegExpValidator(QRegExp("[A-Za-z]{1}[0-9]{1}[A-Za-z]{1}" // char-int-char
                                                    "[0-9]{1}[A-Za-z]{1}[0-9]{1}")); // int-char-int
    postedt->setValidator(postalcoderegexp);

    countryedt = new QLineEdit();
    countryedt->setReadOnly(true);
    countryedt->setText("Canada"); // can not change to other countries than Canada

    // province combo box and province list
    provbox = new QComboBox();
    QStringList provStrList = {"AB", "BC", "MB", "NB", "NL", "NS","NT","NU", "ON", "PE","QC", "SK","YT"};
    provbox->addItems(provStrList);senderipedt = new QLineEdit();

    //senderipedt->setText("192.168.0.105");
    senderportedt = new QLineEdit();
    //senderportedt->setText("2390");
    sendbtn = new QPushButton("Send Address");

    // add all labels to label manager
    vboxlbl->addWidget(namelbl);
    vboxlbl->addWidget(staddrlbl);
    vboxlbl->addWidget(provlbl);
    vboxlbl->addWidget(postlbl);
    vboxlbl->addWidget(countrylbl);
    vboxlbl->addWidget(senderiplbl);
    vboxlbl->addWidget(senderportlbl);

    // add all text editing field to text field manager
    vboxfield->addWidget(nameedt);
    vboxfield->addWidget(straddredt);
    vboxfield->addWidget(provbox);
    vboxfield->addWidget(postedt);
    vboxfield->addWidget(countryedt);
    vboxfield->addWidget(senderipedt);
    vboxfield->addWidget(senderportedt);

    // add label and field manager to overall layout and set
    hbox->addLayout(vboxlbl);
    hbox->addLayout(vboxfield);
    vbox->addLayout(hbox);
    vbox->addWidget(sendbtn);
    vbox->addWidget(recvstatuslbl);
    setLayout(vbox);
}
