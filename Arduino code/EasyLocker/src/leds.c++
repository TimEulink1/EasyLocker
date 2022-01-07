#include <Arduino.h>
#define REDLED A2
#define GREENLED A1
//hier worden de pinnen naar de juiste modus gezet.
void ledSetup()
{
    pinMode(REDLED,OUTPUT);
    pinMode(GREENLED,OUTPUT);
}
//hiermee kan de groene led aan worden gezet
void turnGreenLedOn()
{
    digitalWrite(GREENLED, HIGH);
}
//hiermee kan de groene led uit worden gezet
void turnGreenLedOff()
{
    digitalWrite(GREENLED, LOW);
}
//hieree kan de rode led aan worden gezet
void turnRedLedOn()
{
    digitalWrite(REDLED, HIGH);
}
//hiermee kan de rode led worden uit gezet
void turnRedLedOff()
{
    digitalWrite(REDLED, LOW);
}
