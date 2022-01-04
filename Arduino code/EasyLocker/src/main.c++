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
int stap = 0;

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

bool compareCode(){
  if (enteredCode == savedCode){
    return true;
  }
  else{
    return false;
  }
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
  savedCode[0] = getSavedCode()[0];
  savedCode[1] = getSavedCode()[1];
  savedCode[2] = getSavedCode()[2];
  savedCode[3] = getSavedCode()[3];

  switch(stap) {
  case 0:
    enterCode();
    stap = 1;
    break;
  case 1:
    if(digitalRead(A4)){
      stap = 2;
    }
    else if(digitalRead(A3)){
      stap = 0;
    }
    break;
    case 2:
      if(compareCode){
        Serial.println("gelukt!");
      }
      else{
        Serial.println("niet gelukt!");
      }
    break;
  }
}
