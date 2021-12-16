#include <Arduino.h>
#include <sevenSegment.h>

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
