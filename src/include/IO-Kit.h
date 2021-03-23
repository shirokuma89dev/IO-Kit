#ifndef IS_IOKIT_INCLUDED

#define IS_IOKIT_INCLUDED

class Output {
 public:
  Output(int pin);

 private:
  int _pinNumber;
};

#endif