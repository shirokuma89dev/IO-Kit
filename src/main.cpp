#include <Arduino.h>

#include "include/IO-Kit.h"

Output LED1 = 13;

void setup() {}

void loop() {
  LED1 = !LED1;
  delay(300);
}