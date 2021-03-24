#include <Arduino.h>

#include "include/IO-Kit.h"

Output LED1 = 13;
Output LED2 = 10;

void setup() {}

void loop() {
  LED1 = LED2 = .6;
  delay(500);
  LED1 = LED2 = LOW;
  delay(500);
}