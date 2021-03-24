#ifndef IS_IOKIT_INCLUDED

#define IS_IOKIT_INCLUDED

#define PULLUP 1
#define OPEN 0

class Output {
 public:
  Output(int pin);

  void set(bool val);
  void setPWM(int val);

  float operator=(float val);
  int operator<<=(int val);

  operator float();

 private:
  int _pinNumber;
  byte _pinStatus;

#ifdef _STM32_DEF_
  bool _pwmExp = false;
#endif
};

class Input {
 public:
  Input(int pin);
  Input(int pin, bool pullup);

  bool digital(void);

 private:
  int _pinNumber;
  byte _pinStatus;
};

#endif