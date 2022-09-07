#include "chkRanges.h"
#include "A2DConverter.h"

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
    int chrgSessions[7] = {3, 3, 4, 5, 10, 11, 12};
    int sizeOfchrgSess = sizeof(chrgSessions) / sizeof(chrgSessions[0]);
    countRange(chrgSessions, rangeCount, sizeOfchrgSess);
    assert(rangeCount[0] == 4);
    assert(rangeCount[1] == 3);
}

void testcheckRange()
{
    int chrgSession[7] = {3, 2, 5, 4, 12, 11, 10};
    int sizeOfchrgSess = sizeof(chrgSession) / sizeof(chrgSession[0]);
    int rangeCount[3] = {1, 1, 1};
    int sizeOfRngCnt = sizeof(rangeCount) / sizeof(rangeCount[0]);
    checkRange(chrgSession, sizeOfchrgSess, rangeCount, sizeOfRngCnt);
    assert((rangeCount[0] == 4) && (rangeCount[1] == 3));
    assert((chrgSession[2] == 4) && (chrgSession[6] == 12));
}

void testAddCurrentAmpList()
{
    int AmpArray[7] = {3, 2, 5, 4, 12, 11, 10};
    int AmpArrayOutLimit[8] = {3, 2, 5, 4, 6, 12, 11, 10};
    int status = INSIDE_RANGE;
    for (int index=0; index<7; index++) {
         status = AddCurrentAmpList(AmpArray[index]);
         if (status != INSIDE_RANGE)
             break;
    }
    assert(status != OUTOFF_RANGE);

    status = INSIDE_RANGE;
    for (int index=0; index<8; index++) {
         status = AddCurrentAmpList(AmpArrayOutLimit[index]);
         if (status != INSIDE_RANGE)
             break;
    }
    assert(status == OUTOFF_RANGE);
}

/*void testprocessADCSensorData()
{
    int Amp12bitArray[7] = {3, 2, 5, 4, 12, 11, 10};
    int Amp10bitArray[7] = {3, 2, 5, 4, 12, 11, 10};
    int status = INSIDE_RANGE;
    
    processADCSensorData(Amp10bitArray[0], TwelveBitADC,  
}*/

int main()
{
    testswapValues();
    testpartition();
    testsortRange();
    testcompareRange();
    testcountRange();
    testcheckRange();
    testAddCurrentAmpList();
    //testprocessADCSensorData();
    return 0;
}
