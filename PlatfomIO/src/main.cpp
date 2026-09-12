#include <Arduino.h>
#include <ESP8266WiFi.h>

#define RELAY_PIN 16
#define RELAY_ON HIGH
#define RELAY_OFF LOW

// put function declarations here:
// int myFunction(int, int);

void setup() {
  // put your setup code here, to run once: 
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, RELAY_OFF);
  WiFi.mode(WIFI_OFF); // Disable WiFi to save power
  WiFi.forceSleepBegin(); // Put WiFi in sleep mode
  Serial.begin(115200);
  while (!Serial) {
    delay(1); // wait for serial port to connect. Needed for native USB port only
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    String command = Serial.readStringUntil('\n');
    command.trim();
    command.toLowerCase();
    if (command == "toggle") {
      digitalWrite(RELAY_PIN, RELAY_ON);
      delay(250);
      digitalWrite(RELAY_PIN, RELAY_OFF);
    } else {
      Serial.println("Unknown command");
    }
  }
  delay(10);
}

// put function definitions here:
// int myFunction(int x, int y) {
//   return x + y;
// }