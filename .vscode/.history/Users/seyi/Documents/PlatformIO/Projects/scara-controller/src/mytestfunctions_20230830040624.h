#include <Arduino.h>

AccelStepper stepper; // Defaults to AccelStepper::FULL4WIRE (4 pins) on 2, 3, 4, 5

void setup()
{
    stepper.setMaxSpeed(1000);
    stepper.setSpeed(50);
}

void loop()
{
    stepper.runSpeed();
}