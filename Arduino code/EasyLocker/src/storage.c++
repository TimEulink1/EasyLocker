#include <Arduino.h>
#include <EEPROM.h>
int code[4] = {0, 0, 0, 4};

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

void readIntArrayFromEEPROM( int numbers[], int arraySize)
{
  int addressIndex = 0;
  for (int i = 0; i < arraySize; i++)
  {
    numbers[i] = (EEPROM.read(addressIndex) << 8) + EEPROM.read(addressIndex + 1);
    addressIndex += 2;
  }
}
int* getSavedCode()
{
  readIntArrayFromEEPROM(code, 4);
  return code;
}

void EEPROMsetup() 
{
  readIntArrayFromEEPROM(code, 4);
  for (int i = 0; i < 4; i++)
  {
    Serial.println(code[i]);
  }
}
