#include <Arduino.h>
#define PIN_SHIFT 8
#define PIN_STORE 9
#define PIN_DATA 10
#define DELAY 7

/*
    binaire volgorde is 5-4-3-2
*/
int ledPattern[8] = {1, 1, 1, 1, 1, 1, 1, 1};

const byte numPins = 4;
byte pins[] = {2, 3, 4, 5};
//diplayNumbers
int display1Number = 4;
int display2Number = 6;
int display3Number = 9;

void setupSevenSegments(){
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

  pinMode(PIN_STORE, OUTPUT);
  pinMode(PIN_SHIFT, OUTPUT);
  pinMode(PIN_DATA, OUTPUT);
}


void convertToBinary(int number) {
  byte num = number; // Get num from somewhere
  for (byte i=0; i<numPins; i++) {
    byte state = bitRead(num, i);
    digitalWrite(pins[i], state);
    Serial.print(state);
  }
  Serial.println();
}

void setDisplay1(int newNumber){
    display1Number = newNumber;
}

void setDisplay2(int newNumber){
    display2Number = newNumber;
}

void setDisplay3(int newNumber){
    display3Number = newNumber;
}

void writeBitShifter(){
 digitalWrite(PIN_STORE, LOW);

 for (int i=0; i<8; i++) {
    // set shift pin to "wait"
    digitalWrite(PIN_SHIFT, LOW);

    // writing to data pin
    digitalWrite(PIN_DATA, ledPattern[i]);

    // rising slope -> shifting data in the register
    digitalWrite(PIN_SHIFT, HIGH);
  }
  // write whole register to output
  digitalWrite(PIN_STORE, HIGH);
}

void setDisplay(int number){
  switch(number) {
  case 1:
    ledPattern[0] = 1;
    ledPattern[1] = 0;
    ledPattern[2] = 0;
    break;
  case 2:
    ledPattern[0] = 0;
    ledPattern[1] = 1;
    ledPattern[2] = 0;
    break;
  case 3:
    ledPattern[0] = 0;
    ledPattern[1] = 0;
    ledPattern[2] = 1;
    break;
  case 0:
    ledPattern[0] = 0;
    ledPattern[1] = 0;
    ledPattern[2] = 0;
    break;
    
}
}

void displayOn(){
  setDisplay(1);
  convertToBinary(display1Number);
  writeBitShifter();
  delay(DELAY);
  setDisplay(2);
  convertToBinary(display2Number);
  writeBitShifter();
  delay(DELAY);
  setDisplay(3);
  convertToBinary(display3Number);
  writeBitShifter();
  delay(DELAY);
}

void displayOff(){
  setDisplay(0);
  writeBitShifter();
}



