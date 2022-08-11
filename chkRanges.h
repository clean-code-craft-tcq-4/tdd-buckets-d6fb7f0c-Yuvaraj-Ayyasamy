#include <stdio.h>
#include <assert.h>

struct data
{
    int id;
    char range[10];
    int count;
}s;

extern int rangeCount[];
extern int chrgSession[];
extern int rangeCount[];

void checkrange();
void countRange(int array[], int size);
void printRange(int array[], int size);
void swapValues(int* value1, int* value2);
void addInExcel(int array[]);
int partition(int array[], int lowIndex, int highIndex);
void sortRange(int array[], int lowIndex, int highIndex);
