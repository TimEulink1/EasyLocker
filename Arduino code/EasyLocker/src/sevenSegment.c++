#include <Arduino.h>
/*
    binaire volgorde is 5-4-3-2
*/
const byte numPins = 4;
byte pins[] = {2, 3, 4, 5};
//diplay 1=6, 2=7, 3=8
byte displays[] = {6, 7, 8};
//diplayNumbers
int display1Number = 0;
int display2Number = 0;
int display3Number = 0;


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

void showDisplay1(){
    digitalWrite(displays[2], LOW);
    digitalWrite(displays[3], LOW);
    convertToBinary(display1Number);
    digitalWrite(displays[1], HIGH);
}

void showDisplay2(){
    digitalWrite(displays[1], LOW);
    digitalWrite(displays[3], LOW);
    convertToBinary(display2Number);
    digitalWrite(displays[2], HIGH);
}

void showDisplay3(){
    digitalWrite(displays[1], LOW);
    digitalWrite(displays[2], LOW);
    convertToBinary(display3Number);
    digitalWrite(displays[3], HIGH);
}

void displayOn(){
    showDisplay1;
    showDisplay2;
    showDisplay3;
}

void displayOff(){
    digitalWrite(displays[1], LOW);
    digitalWrite(displays[2], LOW);
    digitalWrite(displays[3], LOW);
}
