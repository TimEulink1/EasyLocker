#include <Arduino.h>

#define BUZZERPIN A0
unsigned long old_time = 0;

void buzzerSetup()
{
    pinMode(BUZZERPIN, OUTPUT);
}
void activateBuzzer(int time)
{   
    old_time = millis();
    while(millis() < old_time + time)
    {
        analogWrite(BUZZERPIN, 200);
    }
}

void disableBuzzer(){
    analogWrite(BUZZERPIN,0);
}
