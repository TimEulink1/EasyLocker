//Authors:
//Tim Eulink
//Dave Huinink
//Twan Wieggers
//Max Huizing

#include <Arduino.h>
#include <sevenSegment.h>
#include <rotaryEncoder.h>
#include <buzzer.h>
#include <leds.h>
#include <storage.h>
#include <gate.h>

#define INPUTKNOP 11
#define BUTTON1 A3
#define BUTTON2 A4
#define waittime 50
unsigned long time_now = 0;
int stap = 0;
int mistake = 0;

int savedCode[4] = {0,0,0,0};
int enteredCode[4] = {0,0,0,0};

int getValueRotaryEncoder();
//deze functie kan worden aangeroepen om het programma 50 miliseconden te laten wachten
void wait()
{
  time_now = millis();
  while(millis() < time_now + waittime){}
}
//hier wordt code opgehaald van de knop
void enterCode()
{
  setDisplay1Value(0);
  setDisplay2Value(0);
  setDisplay3Value(0);
  setDisplay4Value(0);
    while (!digitalRead(INPUTKNOP))
  {
    enteredCode[0]= getValue()/2;
    setDisplay1Value(enteredCode[0]);
    displayOn();
  }
  wait();

  while (digitalRead(INPUTKNOP))
  {
    setValue(0);
    displayOff();
    activateBuzzer(5);
  }

  wait();

  while (!digitalRead(INPUTKNOP))
  {
    enteredCode[1]= getValue()/2;
    setDisplay2Value(enteredCode[1]);
    displayOn();
  }

  wait();

  while (digitalRead(INPUTKNOP))
  {
    setValue(0);
    displayOff();
    activateBuzzer(5);
  }

  wait();

  while (!digitalRead(INPUTKNOP))
  {
    enteredCode[2]= getValue()/2;
    setDisplay3Value(enteredCode[2]);
    displayOn();
  }

  wait();

  while (digitalRead(INPUTKNOP))
  {
    setValue(0);
    displayOff();
    activateBuzzer(5);
  }

  wait();

  while (!digitalRead(INPUTKNOP))
  {
    enteredCode[3]= getValue()/2;
    setDisplay4Value(enteredCode[3]);
    displayOn();
  }
  wait();

  while (digitalRead(INPUTKNOP))
  {
    setValue(0);
    displayOff();
    activateBuzzer(5);
  }

  wait();
}
//hier wordt de code vergeleken met de code die al is opgeslagen in het geheugen
bool compareCode(){
  if (enteredCode[0] == savedCode[0] && enteredCode[1] == savedCode[1] && enteredCode[2] == savedCode[2] && enteredCode[3] == savedCode[3])
  {
    return true;
  }
  else{
    return false;
  }
}
//hier worden alle setups van de verschillende classes aangeroepen en worden ook de pinnen naar de juiste modus gezet
void setup() {
  pinMode(INPUTKNOP, INPUT);
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);
  Serial.begin(9600);
  rotarySetup();
  buzzerSetup();
  ledSetup();
  setupSevenSegments();
  EEPROMsetup();
  turnRedLedOn();
  kluisDicht();
  setupServo();
}

void loop()
 {
  displayOn();
  //hier wordt de code opgehaald uit het geheugen
  savedCode[0] = getSavedCode()[0];
  savedCode[1] = getSavedCode()[1];
  savedCode[2] = getSavedCode()[2];
  savedCode[3] = getSavedCode()[3];
  //hier wordt gekeken of er 5 keer fout de code is ingevuld
  if (mistake == 5)
  {
    stap = 9;
  }

  switch(stap) {
    //wij beginnen met het ophalen van de functie voor het invullen van de code
  case 0:
    enterCode();
    stap = 2;
    break;
    //hier wordt de functie aangeroepen voor het vergelijken van de code
    case 2:
      if(compareCode())
      {
        activateBuzzer(15);
        stap = 3;
      }
      else
      {
        stap = 0;
        mistake++;
        if(mistake == 5)
        {}
        else
        {
          displayOff(); 
          activateBuzzer(2000);
        }
      }
    break;
    //als de code klopt dan worden hier de juiste leds aan en uit gezet en wordt de servo aangestuurd dat deze open mag
    case 3:
      turnRedLedOff();
      turnGreenLedOn();
      kluisOpen();
      stap = 4;
      break;
    //hier is de kluis geopend en wordt er opnieuw gevraagd om een code intevullen deze code wordt dan de nieuwe code voor de kluis
    case 4:
      enterCode();
      stap = 5;
      break;
      //hier wordt er gewacht voor het bevestigen van de nieuwe code.
    case 5:
      if(digitalRead(A4)){
        displayOn();
        activateBuzzer(15);
        stap = 6;
      }
      else if(digitalRead(A3)){
        stap = 4;
      }
      break;
    //hier worden de juiste leds naar de juist waarde gezet en wordt de ingevulde code in het geheugen geschreven.
    case 6:
      writeIntArrayIntoEEPROM(enteredCode);
      kluisDicht();
      turnRedLedOn();
      turnGreenLedOff();
      displayOn();
      stap = 0;
      break;
      //hier wordt de mistake code aangeroepen als deze namelijk 5 keer fout is gegaan gaat de buzzer piepen en gaat de led knipperen
    case 9:
      for (int i = 0; i < 10; i++)
      {
        displayOff();
        activateBuzzer(100);
        turnRedLedOn();
        wait();
        turnRedLedOff();
      }
      mistake=0;
      stap = 0;
  }
}
