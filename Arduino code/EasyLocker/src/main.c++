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

int savedCode[4] = {0,0,0,0};
int enteredCode[4] = {0,0,0,0};

int getValueRotaryEncoder();
void wait()
{
  time_now = millis();
  while(millis() < time_now + waittime){}
}
void enterCode()
{
    while (!digitalRead(INPUTKNOP))
  {
    enteredCode[0]= getValue()/2;
    setDisplay1(enteredCode[0]);
    displayOn();
  }

  wait();

  while (digitalRead(INPUTKNOP))
  {
    setValue(0);
  }

  wait();

  while (!digitalRead(INPUTKNOP))
  {
    enteredCode[1]= getValue()/2;
    setDisplay2(enteredCode[1]);
    displayOn();
  }

  wait();

  while (digitalRead(INPUTKNOP))
  {
    setValue(0);
  }

  wait();

  while (!digitalRead(INPUTKNOP))
  {
    enteredCode[2]= getValue()/2;
    setDisplay3(enteredCode[2]);
    displayOn();
  }

  wait();

  while (digitalRead(INPUTKNOP))
  {
    setValue(0);
  }

  wait();

  while (!digitalRead(INPUTKNOP))
  {
    enteredCode[3]= getValue()/2;
    setDisplay4(enteredCode[3]);
    displayOn();
  }

  wait();

  while (digitalRead(INPUTKNOP))
  {
    setValue(0);
  }
  wait();
  
}

void setup() {
  pinMode(INPUTKNOP, INPUT);
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);
  Serial.begin(9600);
  rotarySetup();
  buzzerSetup();
  ledSetup();
  setupSevenSegments();
  EEPROMsetup();

//hier ophalen van de code uit het geheugen


}

void loop()
{
  enterCode();
  while(!digitalRead(A4))
  {
    
  }
  
}
