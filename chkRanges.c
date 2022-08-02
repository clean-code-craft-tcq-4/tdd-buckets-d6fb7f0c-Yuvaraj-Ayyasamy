#include "chkRanges.h"

int ranges = 0;
int chrgSession[] = {3, 3, 5, 4, 10, 11, 12};
int rangeCount[3] = {0};

void chkrange() {
    int sizeOfchrgSess = sizeof(chrgSession) / sizeof(chrgSession[0]);
    sortRange(chrgSession, 0, sizeOfchrgSess);
    checkRange(chrgSession,sizeOfchrgSess);
}

void swapValues(int* value1, int* value2) 
{ 
    int temp = *value1; 
    *value1 = *value2;
    *value2 = temp; 
}   

int partition (int array[], int lowIndex, int highIndex) 
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
        // Separately sort elements before & after partition
        quickSort(array, lowIndex, pivot - 1);
        quickSort(array, pivot + 1, highIndex);
    }
} 

int *checkRange(int *array, int size)
{  
    int index;
    for(index=0; index<size; index++) {
        if ((array[index+1] == (array[index] + 1)) || (array[index+1] == array[index])) {
            rangeCount[ranges] = rangeCount[ranges]+1;
        }
        else {
            ranges++;
        }
    }
    printRange();
    return rangeCount;
}

void printRange()
{  
    int index;
    for(index=0; index<=ranges; index++) {
            printf("count[%d] is %d\n", index, rangeCount[index]);
    }
}
