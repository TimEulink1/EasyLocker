#include <Arduino.h>
#include <Servo.h>
#define OPEN 180
#define CLOSE 0
#define SERVOPIN A5
Servo myservo;

void setupServo() 
{
  myservo.attach(SERVOPIN);
}

void kluisOpen()
{
  myservo.write(OPEN);
}

void kluisDicht()
{
  myservo.write(CLOSE);
}