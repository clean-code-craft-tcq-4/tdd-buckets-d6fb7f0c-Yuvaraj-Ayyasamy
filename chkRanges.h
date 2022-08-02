#include <stdio.h>
#include <assert.h>

extern int rangeCount[];

void chkrange();
int *checkRange(int *array, int size);
void printRange();
void swapValues(int* value1, int* value2);
int partition(int array[], int lowIndex, int highIndex);
void sortRange(int array[], int lowIndex, int highIndex);
