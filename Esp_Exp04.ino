/*
Experiment No.   :   14
Statement  	 :   To make ESP8266 Witty Cloud Development Board as an access point (AP)/hotspot.
Date of Exp. :   xx/xx/xxxx
Author 		   :   Sopan Mendhe (A-20)
*/


#include <ESP8266WiFi.h>

#define led 2
#define red 15
#define green 12
#define blue 13
#define ldr A0

WiFiClient client;
WiFiServer server(80);

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
  Serial.begin(9600);
  WiFi.softAP("esp","esp@8266");
  Serial.println();
  Serial.println("Wifi hostspot started");
  Serial.println(WiFi.softAPIP());
  server.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  client = server.available();

  if(client) {
    String request = client.readStringUntil('\n');
    Serial.println(request);
    request.trim();
    if (request =="GET /ledON HTTP/1.1") {
      digitalWrite(green,HIGH);
    }
    if (request =="GET /ledOFF HTTP/1.1") {
      digitalWrite(green,LOW);
    }
  }
}
