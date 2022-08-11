#include "chkRanges.h"

int ranges = 0;
int chrgSession[] = {3, 3, 5, 4, 10, 11, 12};
int rangeCount[3] = {1, 1, 1};
struct data
{
    char range[10];
    int count;
}storedata;

void checkrange() {
    int sizeOfchrgSess = sizeof(chrgSession) / sizeof(chrgSession[0]);
    sortRange(chrgSession, 0, sizeOfchrgSess-1);
    countRange(chrgSession, sizeOfchrgSess);
    printRange(rangeCount, 2);
    addInExcel(rangeCount);
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

void countRange(int array[], int size)
{  
    int index;
    for(index=0; index<size; index++) {
        if (compareRange(array[index], array[index+1], (array[index]+1))) {
            rangeCount[ranges] += 1;
        }
        else {
            ranges++;
        }
    }
}

void addInExcel(int array[])
{
    FILE *fp;
    fp = fopen("Record.csv","w");
    fprintf(fp,"Range,\t Readings\n");
    fprintf(fp,"%d-%d,\t %d\n", chrgSession[0], chrgSession[3], array[0]);
    //storedata.count = array[0];
    //fwrite(&storedata, sizeof(storedata), 1, fp);
    fprintf(fp,"%d-%d,\t %d\n", chrgSession[3], chrgSession[6], array[1]);
    //storedata.count = array[1];
    //fwrite(&storedata, sizeof(storedata), 1, fp);
    fclose(fp);
}

void printRange(int array[], int size)
{  
    for(int index =0; index<=size; index++) {
        printf("count[%d] is %d\n", index, array[index]);
    }
}
