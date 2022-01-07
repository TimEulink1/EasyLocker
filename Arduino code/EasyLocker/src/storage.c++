#include <Arduino.h>
#include <EEPROM.h>
int code[4] = {0, 0, 0, 4};

//Met deze functie sla je de code op en het EEPROM gehuigen
void writeIntArrayIntoEEPROM(int code[])
{
  int addressIndex = 0;
  for (int i = 0; i < 4; i++) 
  {
    EEPROM.write(addressIndex, code[i] >> 8);
    EEPROM.write(addressIndex + 1, code[i] & 0xFF);
    addressIndex += 2;
  }
}
//Met deze functie lees je wat er in het adres staat
void readIntArrayFromEEPROM( int numbers[], int arraySize)
{
  int addressIndex = 0;
  for (int i = 0; i < arraySize; i++)
  {
    numbers[i] = (EEPROM.read(addressIndex) << 8) + EEPROM.read(addressIndex + 1);
    addressIndex += 2;
  }
}
//Met deze functie haal je de code op
int* getSavedCode()
{
  readIntArrayFromEEPROM(code, 4);
  return code;
}
//Deze functie laat de huidige opgeslagen code zien in de seriele monitor
void EEPROMsetup() 
{
  readIntArrayFromEEPROM(code, 4);
  for (int i = 0; i < 4; i++)
  {
    Serial.println(code[i]);
  }
}
