#include <Arduino.h>

#include "include/IO-Kit.h"

Output LED1 = 13;
Output LED2 = 10;

Input SW1(PC13, OPEN);
Input AnalogIN1(A1, OPEN);

void setup() { Serial.begin(9600); }

void loop() {
  LED1 = LED2 = !LED1;
  Serial.println(AnalogIN1);
  delay(100);
}