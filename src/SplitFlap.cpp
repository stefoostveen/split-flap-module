#include "Arduino.h"
#include "SplitFlap.h"

SplitFlap::SplitFlap(int pin1, int pin2, int pin3, int pin4, int phome, int nflaps)
{
    _pin1 = pin1;
    _pin2 = pin2;
    _pin3 = pin3;
    _pin4 = pin4;
    _phome = phome;
    _nflaps = nflaps;
    pinMode(_phome, INPUT_PULLUP);
    stepper = AccelStepper(AccelStepper::HALF4WIRE, _pin1, _pin2, _pin3, _pin4);
}

    void SplitFlap::home(std::function<int()> cb ){
    
    }
    
    void SplitFlap::set(std::function<int()> cb){

    }

    void SplitFlap::run(){
        stepper.run();

    }
