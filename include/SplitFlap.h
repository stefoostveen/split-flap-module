#ifndef SplitFlap_h
#define SplitFlap_h

#include "Arduino.h"
#include "AccelStepper.h"

class SplitFlap
{
  public:
    SplitFlap(int pin1, int pin2, int pin3, int pin4, int phome, int nflaps);
    void home(std::function<int()> cb );
    void set(std::function<int()> cb);
    void run();
  private:
    int _pin1;
    int _pin2;
    int _pin3;
    int _pin4;
    int _phome;
    int _nflaps;

    int _curpos;
    AccelStepper stepper;
    const int stepsPerRevolution = 2048;
};

#endif
