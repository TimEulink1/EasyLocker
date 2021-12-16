#include <Arduino.h>

#define BUZZERPIN 13
unsigned long old_time = 0;
int period = 1000;

void buzzerSetup()
{
    pinMode(BUZZERPIN, OUTPUT);


}
void activateBuzzer()
{   old_time = millis();

    while(millis() < old_time + period)
    {
        digitalWrite(BUZZERPIN, HIGH);
    }

    
}