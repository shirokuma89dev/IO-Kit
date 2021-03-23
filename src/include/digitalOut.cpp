#include "Arduino.h"
#include "IO-Kit.h"

Output::Output(int pin) {
  this->_pinNumber = pin;
  pinMode(this->_pinNumber, OUTPUT);
}

void Output::set(bool val) { digitalWrite(this->_pinNumber, val); }

Output& Output::operator=(bool val) {
  this->set(val);
  return *this;
}
