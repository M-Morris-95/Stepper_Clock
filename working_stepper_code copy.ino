#include <Arduino.h>
#include <Stepper.h>

// Define motor control pins
const int motorPin1 = 4; // IN1 on the DRV8833
const int motorPin2 = 5; // IN2 on the DRV8833
const int motorPin3 = 6; // IN3 on the DRV8833
const int motorPin4 = 7; // IN4 on the DRV8833

// Define the stepping sequence for half-stepping
// For DRV8833, each IN pin pair drives one coil
// IN1-IN2 drives coil A, IN3-IN4 drives coil B
const byte halfStepSequence[8][4] = {
  {HIGH, LOW, HIGH, LOW},
  {HIGH, LOW, LOW, LOW},
  {HIGH, LOW, LOW, HIGH},
  {LOW, LOW, LOW, HIGH},
  {LOW, HIGH, LOW, HIGH},
  {LOW, HIGH, LOW, LOW},
  {LOW, HIGH, HIGH, LOW},
  {HIGH, HIGH, HIGH, LOW}
};

int stepIndex = 0; // Current step in the sequence
int stepsPerRevolution = 2000; // Number of steps per full revolution

// Set the speed of the stepper
unsigned long stepDelay = 10; // Delay between steps in milliseconds for speed control

void setup() {
  // Initialize all motor control pins as outputs
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
}

void loop() {
  // Go through the steps in the sequence
  for(int step = 0; step < stepsPerRevolution; ++step) {
    // Go to the next step in the sequence
    takeStep(stepIndex % 8);
    stepIndex++;

    // Wait for a short period to control the speed of the motor
    delay(stepDelay);
  }
}

void takeStep(int thisStep) {
  // Set the motor pins according to the half-step sequence
  digitalWrite(motorPin1, halfStepSequence[thisStep][0]);
  digitalWrite(motorPin2, halfStepSequence[thisStep][1]);
  digitalWrite(motorPin3, halfStepSequence[thisStep][2]);
  digitalWrite(motorPin4, halfStepSequence[thisStep][3]);
}
