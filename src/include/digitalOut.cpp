#include "Arduino.h"
#include "IO-Kit.h"

Output::Output(int pin) {
  this->_pinNumber = pin;
  pinMode(this->_pinNumber, OUTPUT);
}

void Output::set(bool val) {
#ifdef _STM32_DEF_
  if (!this->_pwmExp) {
    digitalWrite(this->_pinNumber, val);
  } else {
    analogWrite(this->_pinNumber, val * 255);
  }
#else
  digitalWrite(this->_pinNumber, val);
#endif

  this->_pinStatus = val;
  this->_isPwmUsed = false;
}

void Output::pwmSet(int val) {
  analogWrite(this->_pinNumber, val);
  this->_pinPwmStatus = val;
  this->_isPwmUsed = true;

  if (!this->_pwmExp) {
    this->_pwmExp = true;
  }
}

bool Output::operator=(bool val) {
  this->set(val);
  return val;
}

int Output::operator<<=(int val) {
  this->pwmSet(val);
  return val;
}

Output::operator bool() { return _pinStatus; }