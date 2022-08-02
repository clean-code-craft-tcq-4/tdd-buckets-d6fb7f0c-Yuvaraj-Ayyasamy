#include "chkRanges.h"

int main()
{
    int testValue1 = 10, testValue2 = 20;
    int testArray[] = {30, 10, 20};
    int testArraySize = sizeof(testArray)/sizeof(testArray[0]);
    int testArray1[] = {30, 50, 40, 20};
    int testArray1Size = sizeof(testArray1)/sizeof(testArray1[0]);
    int chargeSession[] = {3, 3, 5, 4, 10, 11, 12, 11};
    int chargeSessionSize = sizeof(chargeSession)/sizeof(chargeSession[0]);

    swapValues(&testValue1, &testValue2);
    assert((testValue1==20) && (testValue2==10));

    partition(testArray, 0, testArraySize-1);
    assert((testArray[0]==10) && (testArray[1]==20));
    //printRange(testArray, testArraySize-1);

    sortRange(testArray1, 0, testArray1Size-1);
    assert((testArray1[0]==20) && (testArray1[1]==30) && (testArray1[2]==40) && (testArray1[3]==50));
    //printRange(testArray, testArraySize-1);

    checkRange(chargeSession, chargeSessionSize);
    //assert(rangeCount[0] == 4);
    //assert(rangeCount[1] == 4);
    printRange(rangeCount, 3);

    chkrange();
    //assert(rangeCount[0] == 4);
    //assert(rangeCount[1] == 3);
    //assert(rangeCount[2] == 1);
    printRange(rangeCount, 3);
    return 0;
}
