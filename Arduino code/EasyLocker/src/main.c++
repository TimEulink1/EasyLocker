#include <Arduino.h>
#include <sevenSegment.h>
#include <rotaryEncoder.h>
#include <buzzer.h>

#define INPUTKNOP 11
int getValueRotaryEncoder();

void setup() {
  pinMode(INPUTKNOP, INPUT);
  rotarySetup();
  buzzerSetup();
  setupSevenSegments();
}

void loop()
{
  while (!digitalRead(INPUTKNOP))
  {
    setDisplay1(getValue()/2);
    displayOn();
  }
  while (digitalRead(INPUTKNOP))
  {
    setValue(0);
  }
  while (!digitalRead(INPUTKNOP))
  {
    setDisplay2(getValue()/2);
    displayOn();
  }
  while (digitalRead(INPUTKNOP))
  {
    setValue(0);
  }
  while (!digitalRead(INPUTKNOP))
  {
    setDisplay3(getValue()/2);
    displayOn();
  }
  while (digitalRead(INPUTKNOP))
  {
    setValue(0);
  }
}
