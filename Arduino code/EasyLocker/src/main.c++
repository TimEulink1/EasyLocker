#include <Arduino.h>
#include <sevenSegment.h>
#include <rotaryEncoder.h>
#include <buzzer.h>

#define INPUTKNOP 3
int getValueRotaryEncoder();

byte count= 0;
  // int ledPattern[8] = {0, 1, 1, 1, 1, 1, 1, 1};


void setup() {
  pinMode(INPUTKNOP, INPUT);
  Serial.begin(9600);
  rotarySetup();
  buzzerSetup();
  activateBuzzer();
  setupSevenSegments();
}

void loop()
{

  // while(!digitalRead(INPUTKNOP))
  // {
  // }
  
  Serial.println(getValueRotaryEncoder());

  displayOn();

}

int getValueRotaryEncoder()
{ 
  int value = getValue()/2;
  return value;
}