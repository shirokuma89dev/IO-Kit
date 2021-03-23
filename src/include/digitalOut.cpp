#include "Arduino.h"
#include "IO-Kit.h"

Output::Output(int pin) {
  this->_pinNumber = pin;
  pinMode(this->_pinNumber, OUTPUT);
}