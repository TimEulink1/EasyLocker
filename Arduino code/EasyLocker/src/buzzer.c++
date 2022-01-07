#include <Arduino.h>
#define BUZZERPIN A0
unsigned long old_time = 0;
//hier wordt de pin naar de juiste modus gezet
void buzzerSetup()
{
    pinMode(BUZZERPIN, OUTPUT);
}
//deze functie kan worden aangeroepen om de buzzer te activeren en daarbij een tijd mee te geven.
void activateBuzzer(int time)
{   
    old_time = millis();
    while(millis() < old_time + time)
    {
        digitalWrite(BUZZERPIN, HIGH);
    }
    digitalWrite(BUZZERPIN, LOW);
}
