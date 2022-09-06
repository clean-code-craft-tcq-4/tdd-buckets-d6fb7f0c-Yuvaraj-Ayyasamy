#include <stdio.h>
#include <assert.h>

//extern int chrgSession[];
//int chrgSession[] = {3, 3, 5, 4, 10, 11, 12};
//int rangeCount[3] = {1, 1, 1};

void checkRange(int chrgSession[], int rangeCount[]);
void countRange(int array[], int rangeCount[], int size);
void printRange(int array[], int size);
void swapValues(int* value1, int* value2);
bool compareRange(int CurPosVal, int IncPosVal, int CurPosIncVal);
int partition(int array[], int lowIndex, int highIndex);
void sortRange(int array[], int lowIndex, int highIndex);
