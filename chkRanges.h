#include <stdio.h>
#include <assert.h>

extern int rangeCount[];
extern int chrgSession[];

void checkrange();
void countRange(int array[], int size);
void printRange(int array[], int size);
void swapValues(int* value1, int* value2);
bool compareRange(int CurPosVal, int IncPosVal, int CurPosIncVal);
int partition(int array[], int lowIndex, int highIndex);
void sortRange(int array[], int lowIndex, int highIndex);
