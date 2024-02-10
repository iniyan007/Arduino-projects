#include <Servo.h>

const int trigPin = ;
const int echoPin = 10;
const int servoMotorPin = 6;

Servo servoMotor;

void setup() {
  Serial.begin(9600);
  servoMotor.attach(servoMotorPin);
}

void loop() {
  int moistureLevel = analogRead(moistureSensorPin);

  if (moistureLevel > moistureThreshold) {
    moveServo(90);
    Serial.println("Soil is dry. Watering required.");
  } else {
    moveServo(0);
    Serial.println("Soil is wet. No watering needed.");
  }

  delay(300);
}

void moveServo(int angle) {
  servoMotor.write(angle);
  delay(1000);
}