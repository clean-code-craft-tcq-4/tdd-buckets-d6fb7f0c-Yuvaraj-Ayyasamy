#include "A2DConverter.h"
#include "chkRanges.h"

void (*alertCall[2]) (int A2DConvertData);

int ADCRangeCheck(int ADCData, ADCTypes ADCType) {
    int result = OUTOFF_RANGE;
    if (ADCData > minRangeADC(ADCType) && ADCData <= maxRangeADC(ADCType)) {
	result = INSIDE_RANGE;
    }
    return result;
}

int A2D12bitConverter(int ADCData, ADCTypes ADCType) {
    return round((AMPRANGE * ADCData)/maxRangeADC(ADCType));
}

int A2D10bitConverter(int ADCData, ADCTypes ADCType) {
    int result = round((AMPRANGE * ADCData)/(maxRangeADC(ADCType)/4));
    printf("%d \n", result);
    if (ADCData < (maxRangeADC(ADCType)/2))
	result = 0 - result;
    printf("%d \n", result);
    return result;
}

int A2DConverter(int ADCData, ADCTypes ADCType) {
    int A2DConvertData;
    if (ADCType == TwelveBitADC) {
        A2DConvertData = A2D12bitConverter(ADCData, ADCType);
    } else {
        A2DConvertData = A2D10bitConverter(ADCData, ADCType);
    }
    return A2DConvertData;
}

void sendToController(int A2DConvertData) {
    THROW_CONTROLLERWARNING(A2DConvertData);
}

void sendToEmail(int A2DConvertData) {
    THROW_MAILWARNING(A2DConvertData);
}

void alarmOutOfRange(int A2DConvertData, AlertTypes alertType) 
{
    alertCall[0] = sendToController;
    alertCall[1] = sendToEmail;
    (*alertCall[alertType]) (A2DConvertData);
}

int createAmpRangeList(int A2DConvertData) {
    return AddCurrentAmpList(A2DConvertData);
}

bool processADCSensorData(int ADCData, ADCTypes ADCType, AlertTypes alertType) {
    int errorStatus;
    int A2DConvertData;
    errorStatus = ADCRangeCheck(ADCData, ADCType);
    if (errorStatus == INSIDE_RANGE) {
    	A2DConvertData = A2DConverter(ADCData, ADCType);
        errorStatus = createAmpRangeList(A2DConvertData);
    } else {
	A2DConvertData = maxRangeADC(ADCType)+1;
	alarmOutOfRange(A2DConvertData, alertType);
    }
    return errorStatus;
} 
