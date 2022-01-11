#include <Arduino.h>
#define latchPin 8
#define clockPin 9
#define dataPin 10
byte shiftregister = 0;

const byte numPins = 4;
byte pins[] = {2, 3, 4, 5};
//diplayNumbers
int display1Value = 0;
int display2Value = 0;
int display3Value = 0;
int display4Value = 0;

int currentDislay = 0;
unsigned long oldTime = 0;
int wait = 2;

// hier wordt de sevenSegment classe geïnitialiseerd
void setupSevenSegments(){
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

// hier wordt de waarde van het display omgezet in binair en door middel van 4 outputs verstuurd naar 7447
void convertToBinary(int number) {
  byte num = number; // Get num from somewhere
  for (byte i=0; i<numPins; i++) {
    byte state = bitRead(num, i);
    digitalWrite(pins[i], state);
  }
}

// hier wordt de waarde van het eerste display geschreven
void setDisplay1Value(int newNumber){
    display1Value = newNumber;
}

// hier wordt de waarde van het tweede display geschreven
void setDisplay2Value(int newNumber){
    display2Value = newNumber;
}

// hier wordt de waarde van het derde display geschreven
void setDisplay3Value(int newNumber){
    display3Value = newNumber;
}

// hier wordt de waarde van het vierde display geschreven
void setDisplay4Value(int newNumber){
    display4Value = newNumber;
}

//hier wordt het shiftregister geupdate naar de juiste display
void updateShiftRegister()
{
   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, LSBFIRST, shiftregister);
   digitalWrite(latchPin, HIGH);
}

// dit is de cyclus die de sevenSegment displays een voor een laat zien
void displayOn(){
  if(currentDislay == 0 || (currentDislay == 4 && millis() > (oldTime + wait))){
    shiftregister = 0;
    currentDislay = 1;
    oldTime = millis();
    convertToBinary(display1Value);
    bitSet(shiftregister, 7);
    updateShiftRegister();
  }
  if(currentDislay == 1 && millis() > (oldTime + wait)){
    shiftregister = 0;
    currentDislay = 2;
    oldTime = millis();
    convertToBinary(display4Value);
    bitSet(shiftregister, 6);
    updateShiftRegister();
  }
  if(currentDislay == 2 && millis() > (oldTime + wait)){
    shiftregister = 0;
    currentDislay = 3;
    oldTime = millis();
    convertToBinary(display3Value);
    bitSet(shiftregister, 5);
    updateShiftRegister();
  }
  if(currentDislay == 3 && millis() > (oldTime + wait)){
    shiftregister = 0;
    currentDislay = 4;
    oldTime = millis();
    convertToBinary(display2Value);
    bitSet(shiftregister, 4);
    updateShiftRegister();
  }
}

// turns all displays off
void displayOff(){
  bitSet(shiftregister, 0);
  updateShiftRegister();
}
