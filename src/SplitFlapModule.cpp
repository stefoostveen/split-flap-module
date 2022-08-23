#include "Arduino.h"
#include "SplitFlapModule.h"

SplitFlapModule::SplitFlapModule(int pin1, int pin2, int pin3, int pin4, int phome, int nflaps)
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

void SplitFlapModule::home()
{
    int homing = direction; // determine the direction in which the motor should run
    stepper.setMaxSpeed(100.0);
    stepper.setAcceleration(100.0);
    while (digitalRead(_phome))
    {                       
        stepper.move(homing);
        homing += direction; // determine next step as a subtraction or addition of 1
        stepper.run();
        delay(5);
    }
    stepper.setCurrentPosition(0);
}

void SplitFlapModule::set(int pos, bool block)
{
    curpos = round(stepsPerRevolution/_nflaps);
    stepper.setSpeed(speed*direction);
    if(block){
        stepper.runToPosition();
    }else{
        stepper.moveTo(curpos);
    }

}

void SplitFlapModule::homeInterrupt(){
    stepper.setCurrentPosition(0);
}

void SplitFlapModule::run()
{
    stepper.run();
    if(!stepper.isRunning()){
        stepper.disableOutputs();
    }
}
