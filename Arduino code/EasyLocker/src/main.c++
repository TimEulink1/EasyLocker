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

  // for (int i=0; i<8; i++) {
  //   // set shift pin to "wait"
  //   digitalWrite(PIN_SHIFT, LOW);

  //   // writing to data pin
  //   digitalWrite(PIN_DATA, ledPattern[i]);

  //   // rising slope -> shifting data in the register
  //   digitalWrite(PIN_SHIFT, HIGH);
  // }

  // // write whole register to output
  // digitalWrite(PIN_STORE, HIGH);
}

void loop()
{
  displayOn();
}
