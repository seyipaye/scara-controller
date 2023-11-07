#include <Arduino.h>

// #include <AccelStepper.h>

// AccelStepper stepper(1, 12, 13); // Defaults to AccelStepper::FULL4WIRE (4 pins) on 2, 3, 4, 5

// void test_setup()
// {
//     Serial.println("dsdsds");
//     stepper.setMaxSpeed(1000);
//     stepper.setSpeed(50);
// }

// void test_loop()
// {
//     stepper.runSpeed();
// }



const int StepX = 2;
const int DirX = 5;
const int StepY = 3;
const int DirY = 6;
const int StepZ = 4;
const int DirZ = 7;
const int StepA = 12;
const int DirA = 13;

void test_setup()
{
    pinMode(StepX, OUTPUT);
    pinMode(DirX, OUTPUT);
    pinMode(StepY, OUTPUT);
    pinMode(DirY, OUTPUT);
    pinMode(StepZ, OUTPUT);
    pinMode(DirZ, OUTPUT);
    pinMode(StepA, OUTPUT);
    pinMode(DirA, OUTPUT);
}

void test_loop()
{
    digitalWrite(DirX, HIGH); // set direction, HIGH for clockwise, LOW for anticlockwise
    digitalWrite(DirY, HIGH);
    digitalWrite(DirZ, HIGH);
    digitalWrite(DirA, HIGH);

    for (int x = 0; x < 200; x++)
    { // loop for 200 steps
        digitalWrite(StepX, HIGH);
        delayMicroseconds(500);
        digitalWrite(StepX, LOW);
        delayMicroseconds(500);
    }
    delay(1000); // delay for 1 second

    for (int x = 0; x < 200; x++)
    { // loop for 200 steps
        digitalWrite(StepY, HIGH);
        delayMicroseconds(500);
        digitalWrite(StepY, LOW);
        delayMicroseconds(500);
    }
    delay(1000); // delay for 1 second

    for (int x = 0; x < 200; x++)
    { // loop for 200 steps
        digitalWrite(StepZ, HIGH);
        delayMicroseconds(500);
        digitalWrite(StepZ, LOW);
        delayMicroseconds(500);
    }
    delay(1000); // delay for 1 second
}
