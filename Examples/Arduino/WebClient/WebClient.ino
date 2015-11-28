#include <TaskScheduler.h>

#include <HttpClient.h>
#include <SPI.h>
#include <Ethernet.h>
#include <EthernetClient.h>


#define RED_LED 6
#define GREEN_LED 9
#define LIGHT_SENSOR 0

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

const long int DEVICE_ID = 111111;

const int networkTimeout = 30*1000;
const int networkDelay = 1000;

char server[] = "192.168.0.102";
const char checkPath[] = "/check";
const char readPath[] = "/read";
const char registerPath[] = "/register";

char buf[256];

void Check();
void Read();
void TurnOff();

Task t1(10000, -1, &Check);
Task t2(1000, -1, &Read);
Task turnOff(700, 1, &TurnOff);

Scheduler runner;

void setup() {
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, HIGH);

  Serial.begin(9600);

  while (!Serial) {
    ;
  }
  Serial.println("Connecting to local network...");

  while (Ethernet.begin(mac) != 1) {
    Serial.println("Failed to configure Ethernet using DHCP, trying again in 5 seconds...");
    delay(5000);
  }

  Serial.println("Connected to local network.");
  Serial.print("My IP address: ");
  Serial.println(Ethernet.localIP());
  Serial.print("Gateway address: ");
  Serial.println(Ethernet.gatewayIP());
  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(RED_LED, LOW);

    Register();
    
  runner.init();
  runner.addTask(t1);
  runner.addTask(t2);
  runner.addTask(turnOff);
  t1.enable();
  t2.enable();
}

void loop() {
    runner.execute();
}

void Check() {
  EthernetClient c;
  HttpClient httpClient(c);
  int err = 0;
  err = httpClient.get(server, 1880, checkPath);
  
  if (err == 0) {
    Serial.println("startedRequest ok");

    err = httpClient.responseStatusCode();
    if (err >= 0) {
      Serial.print("Got status code: ");
      Serial.println(err);

      err = httpClient.skipResponseHeaders();
      if (err >= 0) {
        int bodyLen = httpClient.contentLength();
        Serial.print("Content length is: ");
        Serial.println(bodyLen);
        Serial.println();
        Serial.println("Body returned follows:");

        unsigned long timeoutStart = millis();
        char c;
 
        while ( (httpClient.connected() || httpClient.available()) &&
                ((millis() - timeoutStart) < networkTimeout) ) {
          if (httpClient.available()) {
            c = httpClient.read();
            Serial.print(c);

            bodyLen--;
            timeoutStart = millis();
          } else {
            delay(networkDelay);
          }
        }
        Serial.println();
      } else {
        Serial.print("Failed to skip response headers: ");
        Serial.println(err);
      }
    } else {
      Serial.print("Getting response failed: ");
      Serial.println(err);
    }
  } else {
    Serial.print("Connect failed: ");
    Serial.println(err);
  }
  
  httpClient.stop();
  digitalWrite(RED_LED, HIGH);
  turnOff.restart();
}

void TurnOff() {
  digitalWrite(RED_LED, LOW);
  
}

void Register() {
  EthernetClient c;
  HttpClient httpClient(c);
  
  int err = 0;
  String basePath = String(registerPath);
  String path =  String(basePath + "/" + String(DEVICE_ID));
  Serial.println(path);
  path.toCharArray(buf, 256);
  err = httpClient.get(server, 1880, buf);
  
  if (err == 0) {
    Serial.println("startedRequest ok");

    err = httpClient.responseStatusCode();
    if (err >= 0) {
      Serial.print("Got status code: ");
      Serial.println(err);

      err = httpClient.skipResponseHeaders();
      if (err >= 0) {
        int bodyLen = httpClient.contentLength();
        Serial.print("Content length is: ");
        Serial.println(bodyLen);
        Serial.println();
        Serial.println("Body returned follows:");

        unsigned long timeoutStart = millis();
        char c;
 
        while ( (httpClient.connected() || httpClient.available()) &&
                ((millis() - timeoutStart) < networkTimeout) ) {
          if (httpClient.available()) {
            c = httpClient.read();
            Serial.print(c);

            bodyLen--;
            timeoutStart = millis();
          } else {
            delay(networkDelay);
          }
        }
        Serial.println();
      } else {
        Serial.print("Failed to skip response headers: ");
        Serial.println(err);
      }
    } else {
      Serial.print("Getting response failed: ");
      Serial.println(err);
    }
  } else {
    Serial.print("Connect failed: ");
    Serial.println(err);
  }
  
  httpClient.stop();
}

void Read() {
    int reading = analogRead(LIGHT_SENSOR);
    Serial.print("Reading: ");
  Serial.println(reading);
  
  EthernetClient c;
  HttpClient httpClient(c);
  
  int err = 0;
  String basePath = String(readPath);
  String path =  String(basePath + "/" + String(DEVICE_ID) + "/" + String(reading)); // concatenating two strings
  Serial.println(path);
  path.toCharArray(buf, 256);
  err = httpClient.get(server, 1880, buf);
  
  if (err == 0) {
    Serial.println("startedRequest ok");

    err = httpClient.responseStatusCode();
    if (err >= 0) {
      Serial.print("Got status code: ");
      Serial.println(err);

      err = httpClient.skipResponseHeaders();
      if (err >= 0) {
        int bodyLen = httpClient.contentLength();
        Serial.print("Content length is: ");
        Serial.println(bodyLen);
        Serial.println();
        Serial.println("Body returned follows:");

        unsigned long timeoutStart = millis();
        char c;
 
        while ( (httpClient.connected() || httpClient.available()) &&
                ((millis() - timeoutStart) < networkTimeout) ) {
          if (httpClient.available()) {
            c = httpClient.read();
            Serial.print(c);

            bodyLen--;
            timeoutStart = millis();
          } else {
            delay(networkDelay);
          }
        }
        Serial.println();
      } else {
        Serial.print("Failed to skip response headers: ");
        Serial.println(err);
      }
    } else {
      Serial.print("Getting response failed: ");
      Serial.println(err);
    }
  } else {
    Serial.print("Connect failed: ");
    Serial.println(err);
  }
  
  httpClient.stop();
}

