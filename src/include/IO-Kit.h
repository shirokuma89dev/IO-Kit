#ifndef IS_IOKIT_INCLUDED

#define IS_IOKIT_INCLUDED

class Output {
 public:
  Output(int pin);

  void set(bool val);
  void pwmSet(int val);

  bool operator=(bool val);
  int operator<<(int val);

  operator bool();

 private:
  int _pinNumber;
  bool _pinStatus;
  int _pinPwmStatus;
  bool _pwmExp = false;

  bool _isPwmUsed = false;
};

#endif