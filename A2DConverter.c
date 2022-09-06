#include "A2DConverter.h"
#include "chkRanges.h"

int ADCRangeCheck(int ADCData, ADCTypes ADCType) {
    if (ADCData > minRangeADC(ADCType) && ADCData <= maxRangeADC(ADCType)) {
	return INSIDE_RANGE;
    } else {
	return OUTOFF_RANGE;
    }
}

int A2D12bitConverter(int ADCData, ADCTypes ADCType) {
    return round((AMPRANGE * ADCData)/maxRangeADC(ADCType));
}

int A2D10bitConverter(int ADCData, ADCTypes ADCType) {
    int result = round((AMPRANGE * ADCData)/maxRangeADC(ADCType));
    if (ADCData < (maxRangeADC(ADCType)/2))
	result = 0 - result;
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
    alertType[0] = sendToController;
    alertType[1] = sendToEmail;
    (*alertType[alertType]) (A2DConvertData);
}

int createAmpRangeList(int A2DConvertData) {
    int data = A2DConvertData;
    int retStatus = OUTOFF_RANGE; // Out of index
    retStatus = AddCurrentAmpList(&data);
    return retStatus;
}

bool processADCSensorData(int ADCData, ADCTypes ADCType, int A2DConvertData, AlertTypes alertType) {
    int errorStatus;

    errorStatus = ADCRangeCheck(ADCData, ADCType);
    if (errorStatus == INSIDE_RANGE) {
    	A2DConvertData = A2DConverter(ADCData, ADCType);
        errorStatus = createAmpRangeList(A2DConvertData);
	if (errorStatus != INSIDE_RANGE) {
	    break;
	}
    } else {
	A2DConvertData = maxRangeADC(ADCType)+1;
	alarmOutOfRange(A2DConvertData);
	//(*alertType) (A2DConvertData);
    }
    return errorStatus;
} 
