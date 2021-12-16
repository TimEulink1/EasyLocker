#include <Arduino.h>
#include <sevenSegment.h>

#define PIN_SHIFT 8
#define PIN_STORE 9
#define PIN_DATA 10

byte count= 0;
  // int ledPattern[8] = {0, 1, 1, 1, 1, 1, 1, 1};


void setup() {
  Serial.begin(9600);
  setupSevenSegments();
}

void loop()
{
  displayOn();
}
