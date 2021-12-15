#include <Arduino.h>
/*
    binaire volgorde is 5-4-3-2
*/

const byte numPins = 4;
byte pins[] = {2, 3, 4, 5};
//diplay 1=6, 2=7, 3=8
byte displays[] = {6, 7, 8};
//diplayNumbers
int display1Number = 4;
int display2Number = 6;
int display3Number = 9;


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
  Serial.println("showDisplay1");
    digitalWrite(displays[1], LOW);
    digitalWrite(displays[2], LOW);
    convertToBinary(display1Number);
    digitalWrite(6, displays[0]);
}

void showDisplay2(){
  Serial.println("showDisplay2");
    digitalWrite(displays[0], LOW);
    digitalWrite(displays[2], LOW);
    convertToBinary(display2Number);
    digitalWrite(displays[1], HIGH);
}

void showDisplay3(){
  Serial.println("showDisplay3");
    digitalWrite(displays[0], LOW);
    digitalWrite(displays[1], LOW);
    convertToBinary(display3Number);
    digitalWrite(displays[2], HIGH);
}

void displayOn(){
    showDisplay1();
    showDisplay2();
    showDisplay3();
}

void displayOff(){
    digitalWrite(displays[1], LOW);
    digitalWrite(displays[2], LOW);
    digitalWrite(displays[3], LOW);
}
