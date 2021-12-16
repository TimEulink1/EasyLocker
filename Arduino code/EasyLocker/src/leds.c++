#include <Arduino.h>
#define REDLED A1
#define GREENLED A2

void ledSetup()
{
    pinMode(REDLED,OUTPUT);
    pinMode(GREENLED,OUTPUT);
}

void turnGreenLedOn()
{
    analogWrite(GREENLED, 255);
}
void turnGreenLedOff()
{
    analogWrite(GREENLED, 0);
}
void turnRedLedOn()
{
    analogWrite(REDLED, 255);
}
void turnRedLedOff()
{
    analogWrite(REDLED, 0);
}
