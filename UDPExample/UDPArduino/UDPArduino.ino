// ================================================================
// ===                         LIBRARY                          ===
// ================================================================
#include <ArduinoJson.h>
#include <SPI.h>
#include <WiFiNINA.h>
#include <WiFiUdp.h>
#include "arduino_secrets.h"

// ================================================================
// ===                    FUNCTION PROTOTYPE                    ===
// ================================================================
void printWifiStatus(void);
void connectToWifi(void);

// ================================================================
// ===                      WiFi STATUS                         ===
// ================================================================
int status = WL_IDLE_STATUS;
// data related to connection is entered in arduino_secrets.h
// character array contains network SSID (name)
char ssid[] = SECRET_SSID;
// network password (use for WPA, or use as key for WEP)
char pass[] = SECRET_PASS;
// network key index number (needed only for WEP)
int keyIndex = 0;

// ================================================================
// ===                     GLOBAL VARIABLE                      ===
// ================================================================
unsigned int localPort = 2390;  // predefined local port to listen on
char packetBuffer[512];         // buffer to hold incoming packet
char  ReplyBuffer[512];         // a string to send back
WiFiUDP Udp;

void setup() {
  //Initialize serial and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  connectToWifi();
  Serial.println("\nStarting connection to server...");
  // if you get a connection, report back via serial:
  Udp.begin(localPort);
  Serial.println("\nConnection established");
}

void loop() {
  // if there's data available, read a packet
  int packetSize = Udp.parsePacket();
  if (packetSize) {
    Serial.print("Received packet of size ");
    Serial.println(packetSize);
    Serial.print("From ");
    IPAddress remoteIp = Udp.remoteIP();
    Serial.print(remoteIp);
    Serial.print(", port ");
    Serial.println(Udp.remotePort());

    // read the packet into packetBufffer
    int len = Udp.read(packetBuffer, 255);
    if (len > 0) {
      packetBuffer[len] = 0;
    }
    
    Serial.println("Contents:");
    Serial.println(packetBuffer);
    DynamicJsonDocument docRx(1024);
    DeserializationError error = deserializeJson(docRx, packetBuffer);

    // Test if parsing succeeds.
    if (error) {
      Serial.print(F("deserializeJson() failed: "));
      Serial.println(error.f_str());
      return;
    }

    // extreact information from UDP packet
    String namestr = docRx["Name"];
    String quotestr = docRx["Quote"]; // X.H. added this line
    String staddrstr = docRx["Street Address"];
    String provstr = docRx["Province"];
    String poststr = docRx["Postal Code"];
    String countrystr = docRx["Country"];

    // print formatted output to serial monitor
    Serial.print("Name: "); Serial.println(namestr);
    Serial.print("Quote: "); Serial.println(quotestr); // X.H. added this line
    Serial.print("Street Address: "); Serial.println(staddrstr);
    Serial.print("Province: "); Serial.println(provstr);
    Serial.print("Postal Code: "); Serial.println(poststr);
    Serial.print("Country: "); Serial.println(countrystr);

    docRx["Acknowledged"] = "OK";
    serializeJson(docRx, ReplyBuffer);
    serializeJson(docRx, Serial);
    
    // send a reply, to the IP address and port that sent us the packet we received
    Udp.beginPacket(Udp.remoteIP(), 8877);
    Udp.write(ReplyBuffer);
    Udp.endPacket();
    delay(1000);
  }
}

void connectToWifi(void) {
  // check for the WiFi module:
  if (WiFi.status() == WL_NO_MODULE) {
    Serial.println("Communication with WiFi module failed!");
    // don't continue
    while (true);
  }

  String fv = WiFi.firmwareVersion();
  if (fv < WIFI_FIRMWARE_LATEST_VERSION) {
    Serial.println("Please upgrade the firmware");
  }

  // attempt to connect to WiFi network:
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    status = WiFi.begin(ssid, pass);

    // wait 10 seconds for connection:
    delay(10000);
  }
  Serial.println("Connected to WiFi");
  printWifiStatus();
}

void printWifiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your board's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("Signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}
