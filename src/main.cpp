#include <Arduino.h>

#include "include/IO-Kit.h"

Output LED = 11;

void setup() {
}

void loop() {
  LED = HIGH;
  delay(500);
  LED = LOW;
  delay(500);
}