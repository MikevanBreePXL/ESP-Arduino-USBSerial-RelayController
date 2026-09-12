#include <Arduino.h>
#include <ESP8266WiFi.h>

#define RELAY_PIN 16
// GPIO16, Not recommended for use; it is high/active on boot before void setup() is called, which may cause the relay to turn on unexpectedly. Consider using a different GPIO pin for the relay control.
#define RELAY_ON HIGH
#define RELAY_OFF LOW
// Definitions for improving code readability.

void setup() {
  // code here runs once: 
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
  // code here runs repeatedly:
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