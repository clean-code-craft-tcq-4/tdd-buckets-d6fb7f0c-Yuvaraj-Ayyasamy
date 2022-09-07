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
    int status = INSIDE_RANGE;
    for (int index=0; index<7; index++) {
         status = AddCurrentAmpList(AmpArray[index]);
         if (status != INSIDE_RANGE)
             break;
    }
    assert(status != OUTOFF_RANGE);
}

void testAddCurrentAmpListOutOfRange()
{
    int AmpArrayOutLimit[8] = {3, 2, 5, 4, 6, 12, 11, 10};
    int status = INSIDE_RANGE;
    for (int index=0; index<8; index++) {
         status = AddCurrentAmpList(AmpArrayOutLimit[index]);
         if (status != INSIDE_RANGE)
             break;
    }
    assert(status == OUTOFF_RANGE);
}

void testADCRangeCheck()
{
    assert(INSIDE_RANGE == ADCRangeCheck(0, TwelveBitADC));
    assert(INSIDE_RANGE == ADCRangeCheck(4094, TwelveBitADC));
    assert(OUTOFF_RANGE == ADCRangeCheck(4095, TwelveBitADC));
    assert(INSIDE_RANGE == ADCRangeCheck(0, TenBitADC));
    assert(INSIDE_RANGE == ADCRangeCheck(1022, TenBitADC));
    assert(OUTOFF_RANGE == ADCRangeCheck(1023, TenBitADC));
}

void testA2D12bitConverter()
{
    assert(3 == A2D12bitConverter(1146, TwelveBitADC));
    assert(10 == A2D12bitConverter(4094, TwelveBitADC));
}

void testA2D10bitConverter()
{
    assert(-15 == A2D10bitConverter(0, TenBitADC));
    assert(0 == A2D10bitConverter(511, TenBitADC));
    assert(15 == A2D10bitConverter(1022, TenBitADC));
}

void testA2DConverter()
{
    assert(3 == A2DConverter(1146, TwelveBitADC));
    assert(10 == A2DConverter(4094, TwelveBitADC));
    assert(-15 == A2DConverter(0, TenBitADC));
    assert(0 == A2DConverter(511, TenBitADC));
    assert(15 == A2DConverter(1022, TenBitADC));
}

void testcreateAmpRangeList()
{
    int AmpArrayOutLimit[8] = {3, 2, 5, 4, 6, 12, 11, 10};
    int status = INSIDE_RANGE;
    int index;
    for (index=0; index<7; index++) {
         status = createAmpRangeList(AmpArrayOutLimit[index]);
         if (status != INSIDE_RANGE)
             break;
    }
    assert(status != OUTOFF_RANGE);

    status = createAmpRangeList(AmpArrayOutLimit[index]);
    assert(status == OUTOFF_RANGE);
}

void testprocessADCSensorData()
{
    int Amp12bitArray[4] = {0, 1146, 4094, 4095};
    int Amp10bitArray[4] = {0, 511, 1022, 1023};
    int status = INSIDE_RANGE;
    int index;
    for (index=0; index<3; index++)
        assert(OUTOFF_RANGE != processADCSensorData(Amp12bitArray[index], TwelveBitADC, ToController));
    assert(OUTOFF_RANGE == processADCSensorData(Amp12bitArray[index], TwelveBitADC, ToController));
    for (index=0; index<3; index++)
        assert(OUTOFF_RANGE != processADCSensorData(Amp10bitArray[index], TenBitADC, ToMail));
    assert(OUTOFF_RANGE == processADCSensorData(Amp10bitArray[index], TenBitADC, ToMail)); 
}

int main()
{
    testswapValues();
    testpartition();
    testsortRange();
    testcompareRange();
    testcountRange();
    testcheckRange();
    testAddCurrentAmpList();
    testAddCurrentAmpListOutOfRange();
    testA2D12bitConverter();
    testA2D10bitConverter();
    testADCRangeCheck();
    testA2DConverter();
    testprocessADCSensorData();
    return 0;
}
