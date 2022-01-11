#include <Arduino.h>
#include <Servo.h>
#define OPEN 180
#define CLOSE 0
#define SERVOPIN A1
Servo myservo;

//hier wordt de servo geinitialiseerd aan de juiste pin
void setupServo() 
{
  myservo.attach(SERVOPIN);
}
//Met deze functie kan je de servo 180 graden later draai en dan is de kluis open
void kluisOpen()
{
  myservo.write(OPEN);
}
//Met deze functie 
void kluisDicht()
{
  myservo.write(CLOSE);
}