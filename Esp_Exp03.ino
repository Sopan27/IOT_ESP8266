/*
Experiment No.   :   13
Statement   	:   To use ESP8266 Witty Cloud Development Board as a web server.
Date of Exp.	:   xx/xx/xxxx
Author      	:   Sopan Mendhe (A-20)
*/

#include <ESP8266WiFi.h>

#define led 2      
#define red 15    
#define green 12   
#define blue 13    
#define ldr A0    

WiFiClient client;        
WiFiServer server(80);    // Create a server on port 80

void setup() {
  pinMode(led, OUTPUT);   
  pinMode(red, OUTPUT);   
  pinMode(blue, OUTPUT);  
  pinMode(green, OUTPUT); 

  Serial.begin(9600);    // Start serial communication
  WiFi.begin("realme", "9834442927"); // Connect to WiFi network
  while (WiFi.status() != WL_CONNECTED) { // Wait for connection
    Serial.print(".");
    delay(200);
  }
  Serial.println("Wifi Connected"); 
  Serial.println(WiFi.localIP());  // Print local IP address
  server.begin();                 
}

void loop() {
  client = server.available(); // Check for incoming client requests

  if (client) {
    String request = client.readStringUntil('\n'); // Read the request from the client
    Serial.println(request);                       // Print the request to serial monitor
    request.trim();                                
    
    // Check for specific HTTP requests 
    if (request == "GET /ledON HTTP/1.1") {
      digitalWrite(green, HIGH); // Turn on green LED
    }
    if (request == "GET /ledOFF HTTP/1.1") {
      digitalWrite(green, LOW);  // Turn off green LED
    }
  }
}
