#ifndef SplitFlapModule_h
#define SplitFlapModule_h

#include "Arduino.h"
#include "AccelStepper.h"

class SplitFlapModule
{
  public:
    SplitFlapModule(int pin1, int pin2, int pin3, int pin4, int phome, int nflaps);
    void home();
    void set(int pos, bool block = false);
    void run();
    int curpos;
  private:
    void homeInterrupt();
    int _pin1;
    int _pin2;
    int _pin3;
    int _pin4;
    int _phome;
    int _nflaps;

    AccelStepper stepper;
    const int speed = 100;
    const int stepsPerRevolution = 2048;
    const int direction = 1;
};

#endif
