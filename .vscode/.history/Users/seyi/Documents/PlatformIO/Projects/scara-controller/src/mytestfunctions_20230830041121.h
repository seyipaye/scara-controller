#include <Arduino.h>
#include <AccelStepper.h>

AccelStepper stepper(1, 12, 13); // Defaults to AccelStepper::FULL4WIRE (4 pins) on 2, 3, 4, 5

void test_setup()
{
    Serial.println("dsdsds");
    stepper.setMaxSpeed(1000);
    stepper.setSpeed(50);
}

void test_loop()
{
    stepper.runSpeed();
}