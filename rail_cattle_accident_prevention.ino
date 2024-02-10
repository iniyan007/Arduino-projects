#include <Servo.h>

const int trigPin = 3;
const int echoPin = 5;
const int servoMotorPin = 6;
Servo servoMotor;
long duration;
int distance;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  servoMotor.attach(servoMotorPin);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  if (distance < 15) {
    moveServo(90);
  } else {
    moveServo(0);
  }
  delay(400);
}
void moveServo(int angle) {
  servoMotor.write(angle);
  delay(1000);
}
