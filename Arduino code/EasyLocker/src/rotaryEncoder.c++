#include <Arduino.h>
#define INPUTA  6
#define INPUTB  7
int aLastState = 0;
int bLastState = 0;
int aNewState;
int bNewState;
int counter = 0;

//hier wordt er voor gezorgd dat alle pinnen naar de juiste modus worden gezet en ook de laatste status wordt uitgelezen
void rotarySetup()
{
    pinMode(INPUTA, INPUT);
    pinMode(INPUTB, INPUT);
    aLastState = digitalRead(INPUTA);
    bLastState = digitalRead(INPUTB);
}
//hier wordt de counter weer naar 0 gezet door de main
void setValue(int newValue){
  counter = newValue;
}

//hier wordt de status van de pinnen met elkaar vergeleken om te kijken of deze veranderd.
//als deze status is veranderd wordt er een variabele omhoog of omlaag geteld.
int getValue()
{
  aNewState = digitalRead(INPUTA);
  bNewState = digitalRead(INPUTB);

  if (aNewState != aLastState)
  {
    if(bNewState != aNewState && counter >= 1)
    { 
      counter--;
    }
    else
    {
      if(bNewState != bLastState && counter < 18)
      {
      counter++;
      }
    }
    bLastState = bNewState;
    aLastState = aNewState;
  }
  return counter;
}