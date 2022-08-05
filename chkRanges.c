#include "chkRanges.h"

int ranges = 0;
int chrgSession[] = {3, 3, 5, 4, 10, 11, 12};
int rangeCount[3] = {1, 1, 1};
struct data
{
    int id;
    char range[10];
    int count;
}s;

void chkrange() {
    int sizeOfchrgSess = sizeof(chrgSession) / sizeof(chrgSession[0]);
    sortRange(chrgSession, 0, sizeOfchrgSess-1);
    checkRange(chrgSession, sizeOfchrgSess);
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
        // Separately sort elements before & after partition
        sortRange(array, lowIndex, pivot - 1);
        sortRange(array, pivot + 1, highIndex);
    }
} 

void checkRange(int array[], int size)
{  
    int index;
    for(index=0; index<size; index++) {
        if ((array[index+1] == (array[index] + 1)) || (array[index+1] == array[index])) {
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
    FILE *fp1;
    fp = fopen("Record.csv","w");
    s.id = 0;
    sprintf(s.range,"%d-%d\n", chrgSession[0], chrgSession[3]);
    s.count = array[0];
    fwrite(&s, sizeof(s), 1, fp);
    s.id = 1;
    sprintf(s.range,"%d-%d\n", chrgSession[3], chrgSession[6]);
    s.count = array[1];
    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);
    printf("Data Added Sucessfully");
}
void printRange(int array[], int size)
{  
    for(int index =0; index<=size; index++) {
        printf("count[%d] is %d\n", index, array[index]);
    }
}
