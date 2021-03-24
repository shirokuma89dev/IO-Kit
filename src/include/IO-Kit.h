#ifndef IS_IOKIT_INCLUDED

#define IS_IOKIT_INCLUDED

class Output {
 public:
  Output(int pin);

  void set(bool val);
  void pwmSet(int val);

  float operator=(float val);
  int operator<<=(int val);

  operator bool();

 private:
  int _pinNumber;
  byte _pinStatus;

#ifdef _STM32_DEF_
  bool _pwmExp = false;
#endif

};

#endif