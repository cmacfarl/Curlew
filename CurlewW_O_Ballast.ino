// Project Curlew - Block

// Servo.Steering
#include <Servo.h>
Servo servo1;
const int ServopotPin = A1;
int val;

// Motor Propulsion
const int DIR_A = 5;
const int DIR_B = 4;
const int PWM = 6;
const int switchPin = 3;
const int MotorpotPin = A0;

void setup() 
{
  // Servo.Setup
  servo1.attach(9);

  // Motor.Setup
  pinMode(DIR_A, OUTPUT);
  pinMode(DIR_B, OUTPUT);
  pinMode(PWM, OUTPUT);
  pinMode(switchPin, INPUT);
}

void handleServo()
{
  // Servo Ops
  val = analogRead(ServopotPin) ;
  val = map(val, 0, 1023, 0, 180);
  servo1.write(val);
  delay(20);
}

void handleMotor()
{
  // Motor Ops
  int speed = analogRead(MotorpotPin) / 4;

  if (digitalRead(switchPin) == HIGH) {
    forward(speed);
  } else {
    reverse(speed);
  }
}

void forward(int spd)
{
  digitalWrite(DIR_A, HIGH);
  digitalWrite(DIR_B, LOW);
  analogWrite(PWM, spd);
}

void reverse(int spd)
{
  digitalWrite(DIR_A, LOW);
  digitalWrite(DIR_B, HIGH);
  analogWrite(PWM, spd);
}

void loop() 
{ 
  handleServo();
  handleMotor();
}

