void writeIntArrayIntoEEPROM(int address, int code[], int arraySize);
void readIntArrayFromEEPROM(int address, int numbers[], int arraySize);
void EEPROMsetup();
int* getSavedCode();