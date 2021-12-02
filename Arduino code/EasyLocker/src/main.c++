#include <Arduino.h>
#include <test.h>
#define onboard 13

void setup()
{
  //setup code
  Serial.begin(9600);
  pinMode (onboard,OUTPUT);
}

void loop()
{
  // put your main code here, to run repeatedly:
  digitalWrite(onboard, LOW);
  test();
  digitalWrite(onboard, HIGH);
  delay(1000);
}
