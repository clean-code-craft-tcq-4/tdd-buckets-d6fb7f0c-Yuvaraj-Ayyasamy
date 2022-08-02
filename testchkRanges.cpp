#include "chkRanges.h"

int main()
{
    int testValue1 = 10, testValue2 = 20;
    int testArray[] = {30, 10, 20};
    int testArraySize = sizeof(testArray)/sizeof(testArray[0]);
    
    swapValues(&testValue1, &testValue2);
    assert((testValue1==20) && (testValue2==10));
    
    partition(testArray, 0, testArraySize);
    assert((testArray[0]==10) && (testArray[1]==20) && (testArray[2]==30));
    
    chkrange();
    assert(rangeCount[0] == 4);
    assert(rangeCount[1] == 3);
    assert(rangeCount[2] == 1);
    return 0;
}
