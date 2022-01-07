#include <Arduino.h>
#define REDLED A2
#define GREENLED A1

void ledSetup()
{
    pinMode(REDLED,OUTPUT);
    pinMode(GREENLED,OUTPUT);
}

void turnGreenLedOn()
{
    digitalWrite(GREENLED, HIGH);
}
void turnGreenLedOff()
{
    digitalWrite(GREENLED, LOW);
}
void turnRedLedOn()
{
    digitalWrite(REDLED, HIGH);
}
void turnRedLedOff()
{
    digitalWrite(REDLED, LOW);
}
