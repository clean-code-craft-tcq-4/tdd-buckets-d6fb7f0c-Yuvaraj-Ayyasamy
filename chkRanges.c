#include "chkRanges.h"

int ranges = 0;
int chrgSession[] = {3, 3, 5, 4, 10, 11, 12};
int sizeOfchrgSess = sizeof(chrgSession) / sizeof(chrgSession[0]);
int rangeCount[3] = {0};

void chkrange() {
    checkRange(chrgSession,sizeOfchrgSess);
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
            printf("count is %d\n", rangeCount[index]);
    }
}
