#include <Arduino.h>
#define onboard 13

void setup()
{
  //setup code
  pinMode (onboard,OUTPUT);
}

void loop()
{
  // put your main code here, to run repeatedly:
  digitalWrite(onboard, LOW);
  delay(1000);
  digitalWrite(onboard, HIGH);
  delay(1000);
}