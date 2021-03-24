#include <Arduino.h>

#include "include/IO-Kit.h"

Output LED = 11;
Output LED2 = 10;

void setup() {}

void loop() {
  LED <<= LED2 <<= 50;
  delay(500);

  LED = LED2 = LOW;
  delay(500);
}