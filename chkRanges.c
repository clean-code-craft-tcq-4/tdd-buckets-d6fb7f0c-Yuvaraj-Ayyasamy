#include <chkRanges.h>

int *chkrange() {
    return printRange(chrgSession,sizeOfchrgSess);
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
    return rangeCount;
}

void printRange(int *array, int size)
{  
    int index;
    for(index=0; index<=ranges; index++) {
            printf("count is %d\n", rangeCount);
    }
}
