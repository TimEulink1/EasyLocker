#include <Arduino.h>
#include <Servo.h>
unsigned long time = 0;

void waitForOpen()
{
    int waittime = 5;
    time = millis();
    while(millis() < time + waittime){}
}
Servo myservo;

int pos = 0;    // variable to store the servo position

void setupServo() {
   myservo.attach(A5);
}

void kluisOpen()
{
     for (pos = 0; pos <= 180; pos += 1)
     {
     myservo.write(pos);
     waitForOpen();
 }
}

 void kluisDicht()
 {
     for (pos = 180; pos >= 0; pos -= 1) 
     {
     myservo.write(pos);
     waitForOpen();
   }
 }