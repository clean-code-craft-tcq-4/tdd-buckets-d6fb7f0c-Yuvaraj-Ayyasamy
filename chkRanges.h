#include <stdio.h>
#include <assert.h>

extern int ampList[];

int AddCurrentAmpList(int A2DConvertData);
void checkRange(int chrgSession[], int sizeOfchrgSess, int rangeCount[], int sizeOfRngCnt);
void countRange(int array[], int rangeCount[], int size);
void printRange(int chrgSession[], int array[], int size);
void swapValues(int* value1, int* value2);
bool compareRange(int CurPosVal, int IncPosVal, int CurPosIncVal);
int partition(int array[], int lowIndex, int highIndex);
void sortRange(int array[], int lowIndex, int highIndex);
