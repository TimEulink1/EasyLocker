#include <Arduino.h>
#include <sevenSegment.h>
#include <rotaryEncoder.h>
#include <buzzer.h>
#include <leds.h>

#define INPUTKNOP 11
#define BUTTON1 A3
#define BUTTON2 A4
int getValueRotaryEncoder();

void setup() {
  pinMode(INPUTKNOP, INPUT);
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);
  Serial.begin(9600);
  rotarySetup();
  buzzerSetup();
  ledSetup();
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
