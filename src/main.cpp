#include <Arduino.h>

#include "include/IO-Kit.h"

Output LED = 11;
Output LED2 = 13;

void setup() {}

void loop() {
  LED2 = LED = !LED;
  delay(500);
}