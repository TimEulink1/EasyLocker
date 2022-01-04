#include <Arduino.h>
#include <EEPROM.h>
const int STARTING_EEPROM_ADDRESS = 1;
const int arraySize = 4;
int code[arraySize] = {0, 0, 0, 0};

void writeIntArrayIntoEEPROM(int address, int code[], int arraySize)
{
  int addressIndex = address;
  for (int i = 0; i < arraySize; i++) 
  {
    EEPROM.write(addressIndex, code[i] >> 8);
    EEPROM.write(addressIndex + 1, code[i] & 0xFF);
    addressIndex += 2;
  }
}

void readIntArrayFromEEPROM(int address, int numbers[], int arraySize)
{
  int addressIndex = address;
  for (int i = 0; i < arraySize; i++)
  {
    numbers[i] = (EEPROM.read(addressIndex) << 8) + EEPROM.read(addressIndex + 1);
    addressIndex += 2;
  }
}

void EEPROMsetup() {
  writeIntArrayIntoEEPROM(STARTING_EEPROM_ADDRESS, code, arraySize);
  int newNumbers[arraySize];
  readIntArrayFromEEPROM(STARTING_EEPROM_ADDRESS, newNumbers, arraySize);
  for (int i = 0; i < arraySize; i++)
  {
    Serial.println(newNumbers[i]);
  }
}
