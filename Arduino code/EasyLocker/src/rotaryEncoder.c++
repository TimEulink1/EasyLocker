#include <Arduino.h>
#define INPUTA  6
#define INPUTB  7
int aLastState = 0;
int bLastState = 0;
int aNewState;
int bNewState;
int counter = 0;

void rotarySetup()
{
    pinMode(INPUTA, INPUT);
    pinMode(INPUTB, INPUT);
    aLastState = digitalRead(INPUTA);
    bLastState = digitalRead(INPUTB);

}

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