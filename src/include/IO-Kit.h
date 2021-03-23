#ifndef IS_IOKIT_INCLUDED

#define IS_IOKIT_INCLUDED

class Output {
 public:
  Output(int pin);

  void set(bool val);
  void pwmSet(int val);

  Output& operator=(bool val);

 private:
  int _pinNumber;
  bool _pinStatus;
  bool _pinPwmStatus;
  bool _pwmExp = false;
};

#endif