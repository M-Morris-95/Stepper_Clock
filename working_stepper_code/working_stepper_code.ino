#include <Arduino.h> 
#include "MyStepper.h"

const int stepsPerRevolution = 2000;  // change this to fit the number of steps per revolution
// for your motor

// initialize the stepper library on pins 5 through 7:
Stepper myStepper(stepsPerRevolution, 4,5,6,7);

void setup() {
  Serial.begin(9600);
}

void loop() {
  myStepper.setSpeed(30);
  // step one revolution  in one direction:
  Serial.println("clockwise");
  myStepper.step(2000);
  // delay(500);

  // // step one revolution in the other direction:
  // Serial.println("counterclockwise");
  // myStepper.step(-stepsPerRevolution);
  // delay(500);
}