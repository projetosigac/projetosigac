/* Project SI-GAC
 * based on https://www.arduino.cc/en/Tutorial/UDPSendReceiveString 
 */

#include <SPI.h>         // needed for Arduino versions later than 0018
#include <Ethernet.h>
#include <EthernetUdp.h> // UDP library from: bjoern@cs.stanford.edu 12/30/2008
#include <TaskScheduler.h>

#define RED_LED 6
#define GREEN_LED 9
#define LIGHT_SENSOR 0

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192, 168, 0, 102);

IPAddress remoteIP(192, 168, 0, 174);
int remotePort = 2000;

char packetBuffer[UDP_TX_PACKET_MAX_SIZE];  //buffer to hold incoming packet,
char  MessageBuffer[50];

EthernetUDP Udp;

void TurnOff();
void Read();

Task readTask(2000, -1, &Read);

Scheduler runner;

void setup() {
  Serial.begin(9600);
  
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, HIGH);

  Serial.println("Connecting to local network...");
  while (Ethernet.begin(mac) != 1) {
    Serial.println("Failed to configure Ethernet using DHCP, trying again in 5 seconds...");
    delay(5000);
  }
  Serial.println("Connected to local network.");
  Serial.print("My IP address: ");
  Serial.println(Ethernet.localIP());
  
  Udp.begin(2000);
  
  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(RED_LED, LOW);
  
  runner.init();
  runner.addTask(readTask);
  readTask.enable();
}

void sendString(char string[]) {
    Udp.beginPacket(remoteIP, remotePort);
    Udp.write(string);
    Udp.endPacket();
}

void loop(){
    int packetSize = Udp.parsePacket();
  if (packetSize) {
    Serial.print("Received packet of size ");
    Serial.println(packetSize);
    Serial.print("From ");
    IPAddress remote = Udp.remoteIP();
    for (int i = 0; i < 4; i++) {
      Serial.print(remote[i], DEC);
      if (i < 3) {
        Serial.print(".");
      }
    }
    Serial.print(", port ");
    Serial.println(Udp.remotePort());
  
    // read the packet into packetBufffer
    Udp.read(packetBuffer, UDP_TX_PACKET_MAX_SIZE);
    Serial.println("Contents:");
    Serial.println(packetBuffer);
  }
    runner.execute();
}

void Read()
{
  int reading = analogRead(LIGHT_SENSOR);
  Serial.print("Reading: ");
  Serial.println(reading);

  sprintf(MessageBuffer, "%d", reading);
  sendString(MessageBuffer);
  digitalWrite(RED_LED, HIGH);
  delay(500);
  digitalWrite(RED_LED, LOW);
}
