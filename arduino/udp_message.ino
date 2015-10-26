/* Project SI-GAC
 * based on https://www.arduino.cc/en/Tutorial/UDPSendReceiveString 
 */

#include <SPI.h>         // needed for Arduino versions later than 0018
#include <Ethernet.h>
#include <EthernetUdp.h> // UDP library from: bjoern@cs.stanford.edu 12/30/2008

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192, 168, 2, 20);

IPAddress remoteIP(192, 168, 2, 21);
int remotePort = 2000;

char  MessageBuffer[50];

EthernetUDP Udp;

void setup() {
  Ethernet.begin(mac, ip);
  Udp.begin(2000);
  Serial.begin(9600);
  Serial.println("setup");
}

void sendString(char string[]) {
    Udp.beginPacket(remoteIP, remotePort);
    Udp.write(string);
    Udp.endPacket();
}

void loop(){
    delay(500); /* ms */	
    sprintf(MessageBuffer, "Arduino on %20lu\n", micros());
    Serial.println(MessageBuffer);
    sendString(MessageBuffer);
}
