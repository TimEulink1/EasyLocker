#include <Arduino.h>
#include <sevenSegment.h>
#include <rotaryEncoder.h>
#include <buzzer.h>
int test = 0;

#define INPUTKNOP 3

int getValueRotaryEncoder();

void setup() {
  pinMode(INPUTKNOP, INPUT);
  Serial.begin(9600);
  rotarySetup();
  buzzerSetup();
  activateBuzzer();
  
}

void loop()
{
  // while(!digitalRead(INPUTKNOP))
  // {
  // }
  
  Serial.println(getValueRotaryEncoder());
  
  
}

int getValueRotaryEncoder()
{ 
  int value = getValue()/2;
  return value;
}