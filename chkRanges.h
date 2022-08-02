#include <stdio.h>
#include <assert.h>

int rangeCount[3] = {0};
int ranges = 0;
int chrgSession[] = {3, 3, 5, 4, 10, 11, 12};
int sizeOfchrgSess = sizeof(chrgSession) / sizeof(chrgSession[0]);

int *chkrange();
int *checkRange(int *array, int size);
void printRange();
