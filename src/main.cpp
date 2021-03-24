#include <Arduino.h>

#include "include/IO-Kit.h"

Output LED1 = 13;
Output LED2 = 10;

void setup() {
  Serial.begin(9600);
  LED1 = LED2 = 0.1;
  Serial.println(LED2);
  delay(1500);
}

void loop() {
  LED1 = LED2 = !LED1;
  Serial.println(LED2);
  delay(500);
  // LED1 = LED2 = LOW;
  // delay(500);
}