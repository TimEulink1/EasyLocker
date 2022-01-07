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
int wait = 5;

void setupSevenSegments(){
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void convertToBinary(int number) {
  byte num = number; // Get num from somewhere
  for (byte i=0; i<numPins; i++) {
    byte state = bitRead(num, i);
    digitalWrite(pins[i], state);
  }
}

void setDisplay1Value(int newNumber){
    display1Value = newNumber;
}

void setDisplay2Value(int newNumber){
    display2Value = newNumber;
}

void setDisplay3Value(int newNumber){
    display3Value = newNumber;
}

void setDisplay4Value(int newNumber){
    display4Value = newNumber;
}

void updateShiftRegister()
{
   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, LSBFIRST, shiftregister);
   digitalWrite(latchPin, HIGH);
}

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

void displayOff(){
  bitSet(shiftregister, 0);
  updateShiftRegister();
}
