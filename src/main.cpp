#include <Arduino.h>

#include "include/IO-Kit.h"

Output LED = 11;

void setup() {}

void loop() {
  LED = LOW;
  delay(500);
  LED.pwmSet(10);
  delay(500);
}