#include <assert.h>

int rangeCount[3] = {0};
int ranges = 0;
int chrgSession[] = {3, 3, 5, 4, 10, 11, 12};
int sizeOfchrgSess = sizeof(chrgSession) / sizeof(chrgSession[0]);

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

int main()
{
    assert(*(chkrange+4) == 3);
    assert(*(chkrange+5) == 5);
    assert(*(chkrange+6) == 4);
    assert(*(chkrange+11) == 2);  
    return 0;
}
