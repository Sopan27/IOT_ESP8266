/*
Experiment No.   :   11
Statement       :   To test all IOs on ESP8266 Witty Cloud Development Board.
Date of Exp.    :   xx/xx/xxxx
Author          :   Sopan Mendhe (A-20)
*/

#include <ESP8266WiFi.h> //include ESP8266 library
//Define all the pins
#define led 2   
#define red 15   
#define green 12 
#define blue 13  
#define ldr A0   

void setup() {
  Serial.begin(9600); 
  WiFi.begin("realme", "9834442927"); // Connect to WiFi network
  while (WiFi.status() != WL_CONNECTED) { 
    Serial.print(".");
    delay(200); 
  }
  Serial.println("Wifi Connected"); 
  Serial.println(WiFi.localIP()); 
  
  // Set pin modes for IO testing
  pinMode(led, OUTPUT);   
  pinMode(red, OUTPUT);   
  pinMode(green, OUTPUT); 
  pinMode(blue, OUTPUT);  
  pinMode(ldr, INPUT);    
}

void loop() {
  // Test LED
  digitalWrite(led, HIGH); 
  delay(500);             
  digitalWrite(led, LOW);  
  delay(500);              

  // Test RGB LEDs
  digitalWrite(red, HIGH);   
  delay(500);                 
  digitalWrite(red, LOW);    
  digitalWrite(green, HIGH); 
  delay(500);                 
  digitalWrite(green, LOW); 
  digitalWrite(blue, HIGH);  
  delay(500);                 
  digitalWrite(blue, LOW);   

  // Read LDR value
  int ldrValue = analogRead(ldr);
  Serial.print("LDR Value: ");   
  Serial.println(ldrValue);       
  
  delay(2000); // Delay between each test
}
