#include <Arduino.h>
#include <sevenSegment.h>
#include <rotaryEncoder.h>
#include <buzzer.h>
#include <leds.h>
#include <storage.h>

#define INPUTKNOP 11
#define BUTTON1 A3
#define BUTTON2 A4
int waittime = 50;
unsigned long time_now = 0;

int firstDigitCode = 0;
int secondDigitCode = 0;
int thirdDigitCode = 0;

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

//hier ophalen van de code uit het geheugen


}

void loop()
{
  
  while (!digitalRead(INPUTKNOP))
  {
    setDisplay1(getValue()/2);
    displayOn();
  }
  time_now = millis();
  while(millis() < time_now + waittime){}
  while (digitalRead(INPUTKNOP))
  {
    setValue(0);
  }
  time_now = millis();
  while(millis() < time_now + waittime){}
  while (!digitalRead(INPUTKNOP))
  {
    setDisplay2(getValue()/2);
    displayOn();
  }
  time_now = millis();
  while(millis() < time_now + waittime){}
  while (digitalRead(INPUTKNOP))
  {
    setValue(0);
  }
  time_now = millis();
  while(millis() < time_now + waittime){}
  while (!digitalRead(INPUTKNOP))
  {
    setDisplay3(getValue()/2);
    displayOn();
  }
  time_now = millis();
  while(millis() < time_now + waittime){}
  while (digitalRead(INPUTKNOP))
  {
    setValue(0);
  }
  time_now = millis();
  while(millis() < time_now + waittime){}
}
