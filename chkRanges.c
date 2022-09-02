#include "chkRanges.h"

int chrgSession[] = {3, 3, 5, 4, 10, 11, 12};

void checkrange() {
    int sizeOfchrgSess = sizeof(chrgSession) / sizeof(chrgSession[0]);
    int rangeCount[3] = {1, 1, 1};
    int sizeOfRngCnt = sizeof(rangeCount) / sizeof(rangeCount[0]);
    sortRange(chrgSession, 0, sizeOfchrgSess-1);
    countRange(chrgSession, rangeCount, sizeOfchrgSess);
    printRange(rangeCount, sizeOfRngCnt-1);
}

void swapValues(int* value1, int* value2) 
{ 
    int temp = *value1; 
    *value1 = *value2;
    *value2 = temp; 
}   

int partition(int array[], int lowIndex, int highIndex) 
{ 
    int pivotElement = array[highIndex];
    int i = (lowIndex - 1);
    for (int index = lowIndex; index <= highIndex- 1; index++) {
        if (array[index] <= pivotElement) {
            i++;
            swapValues(&array[i], &array[index]);
        }
    }
    swapValues(&array[i + 1], &array[highIndex]);
    return (i + 1);
} 

void sortRange(int array[], int lowIndex, int highIndex)
{  
    if (lowIndex < highIndex) {
        int pivot = partition(array, lowIndex, highIndex);
        sortRange(array, lowIndex, pivot - 1);
        sortRange(array, pivot + 1, highIndex);
    }
} 

bool compareRange(int CurPosVal, int IncPosVal, int CurPosIncVal)
{
    bool limit1 = (IncPosVal == CurPosVal);
    bool limit2 = (IncPosVal == CurPosIncVal);
    return (limit1 || limit2);
}

void countRange(int array[], int rangeCount[], int size)
{  
    int index;
    int ranges = 0;
    for(index=0; index<size; index++) {
        if (compareRange(array[index], array[index+1], (array[index]+1))) {
            rangeCount[ranges] += 1;
        }
        else {
            ranges++;
        }
    }
}

void printRange(int array[], int size)
{
    int lowIndex = 0;
    int highIndex;
    printf("Range,\t Readings\n");
    for(int index =0; index<size; index++, lowIndex+=(array[index]+1)) {
        highIndex = lowIndex + (array[index]-1);
        printf("%d-%d,\t %d\n", chrgSession[lowIndex], chrgSession[highIndex], array[index]);
    }
}
