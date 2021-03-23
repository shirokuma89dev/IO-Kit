#ifndef IS_IOKIT_INCLUDED

#define IS_IOKIT_INCLUDED

class Output {
 public:
  Output(int pin);

  void set(bool val);

  Output& operator=(bool val);

 private:
  int _pinNumber;
};

#endif