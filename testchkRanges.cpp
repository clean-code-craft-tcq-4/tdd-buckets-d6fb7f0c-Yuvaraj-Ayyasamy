#include "chkRanges.h"
void testswapValues()
{
    int testValue1 = 10, testValue2 = 20;
    swapValues(&testValue1, &testValue2);
    assert(testValue1==20);
    assert(testValue2==10);
}

void testpartition()
{
    int testArray[] = {30, 10, 20};
    int testArraySize = sizeof(testArray)/sizeof(testArray[0]);
    partition(testArray, 0, testArraySize-1);
    assert(testArray[0]==10);
    assert(testArray[1]==20);
}

void testsortRange()
{
    int testArray1[] = {30, 50, 20};
    int testArray1Size = sizeof(testArray1)/sizeof(testArray1[0]);
    sortRange(testArray1, 0, testArray1Size-1);
    assert(testArray1[0]==20);
    assert(testArray1[1]==30);
    assert(testArray1[2]==50);
}

void testcompareRange()
{
    int CurPosVal = 2;
    int IncPosVal = 3;
    assert(compareRange(CurPosVal, IncPosVal, (CurPosVal+1)) == true);
    CurPosVal = 2;
    IncPosVal = 5;
    assert(compareRange(CurPosVal, IncPosVal, (CurPosVal+1)) == false);
}

void testcountRange()
{
    int rangeCount[3] = {1, 1, 1};
    int chrgSessions[] = {3, 3, 4, 5, 10, 11, 12};
    int sizeOfchrgSess = sizeof(chrgSessions) / sizeof(chrgSessions[0]);
    countRange(chrgSessions, rangeCount, sizeOfchrgSess);
    assert(rangeCount[0] == 4);
    assert(rangeCount[1] == 3);
}

void testcheckRange()
{
    checkrange();
    assert((chrgSession[2] == 4) && (chrgSession[3] == 5));
}

int main()
{
    testswapValues();
    testpartition();
    testsortRange();
    testcompareRange();
    testcountRange();
    testcheckRange();
    return 0;
}
