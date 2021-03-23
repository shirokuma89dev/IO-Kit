#ifndef IS_IOKIT_INCLUDED

#define IS_IOKIT_INCLUDED

class IO {
 public:
  IO(int pin);
  IO(int pin, int mode);

 private:
  int _pin;
};

#endif