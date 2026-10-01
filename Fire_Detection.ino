#include <Servo.h>

Servo waterServo;  // Servo motor for aiming water nozzle

// Fire sensor pins
const int sensorLeftPin = A0;
const int sensorCenterPin = A1;
const int sensorRightPin = A2;

// Fire detection threshold (adjust for decreasing values)
const int fireThreshold = 300;

void setup() {
  // Initialize servo and serial communication
  waterServo.attach(3);  // Servo connected to pin 3
  Serial.begin(9600);
  Serial.println("Fire Detection and Servo Control System Initialized");
}

void loop() {
  // Read sensor values
  int leftSensorValue = analogRead(sensorLeftPin);
  int centerSensorValue = analogRead(sensorCenterPin);
  int rightSensorValue = analogRead(sensorRightPin);

  // Print sensor readings for debugging
  Serial.print("Left: ");
  Serial.print(leftSensorValue);
  Serial.print(" Center: ");
  Serial.print(centerSensorValue);
  Serial.print(" Right: ");
  Serial.println(rightSensorValue);

  // Determine direction of fire and rotate servo accordingly
  if (leftSensorValue < fireThreshold) {
    Serial.println("Fire detected on the LEFT!");
    waterServo.write(0);  // Rotate servo to the left position
  } 
  else if (centerSensorValue < fireThreshold) {
    Serial.println("Fire detected at the CENTER!");
    waterServo.write(90);  // Rotate servo to the center position
  } 
  else if (rightSensorValue < fireThreshold) {
    Serial.println("Fire detected on the RIGHT!");
    waterServo.write(180);  // Rotate servo to the right position
  } 
  else {
    Serial.println("No fire detected.");
  }

  delay(500);  // Delay for sensor stability
}
