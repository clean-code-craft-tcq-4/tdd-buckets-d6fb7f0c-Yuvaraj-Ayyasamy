#include "A2DConverter.h"

int ADCRangeCheck(int ADCData, int ADCType) {
    if (ADCData > minRangeADC(ADCType) && ADCData <= maxRangeADC(ADCType)) {
	return INSIDE_RANGE;
    } else {
	return OUTOFF_RANGE;
    }
}

int A2D12bitConverter(int ADCData, int ADCType) {
    return round((AMPRANGE * ADCData)/maxRangeADC(ADCType));
}

int A2D10bitConverter(int ADCData, int ADCType) {
    int result = round((AMPRANGE * ADCData)/maxRangeADC(ADCType));
    if (ADCData < (maxRangeADC(ADCType)/2))
	result = 0 - result;
    return result;
}

int A2DConverter(int ADCData, int ADCType) {
    if (ADCType == TwelveBitADC) {
        A2D12bitConverter(ADCData, ADCType);
    } else {
        A2D10bitConverter(ADCData, ADCType);
    }
}

void sendToController(int A2DConvertData) {
    THROW_CONTROLLERWARNING(A2DConvertData);
}

void sendToEmail(int A2DConvertData) {
    THROW_MAILWARNING(A2DConvertData);
}

// void alarmOutOfRange(int A2DConvertData, void (*alertType) (int A2DConvertData)) 
// {
    // (*alertType) (A2DConvertData);	
// }

void find_convertedAmpere_RangeList(int convertedData) {
    int data = convertedData;
    find_currentRangeList(&data, 1);	
}

bool processADCSensorData(int ADCData, int ADCType, int A2DConvertData, void (*alertType) (int A2DConvertData)) {
    int errorStatus;

    errorStatus = ADCRangeCheck(ADCData, ADCType);
    if (errorStatus == INSIDE_RANGE) {
    	A2DConvertData = A2DConverter(ADCData, ADCType);
        find_convertedAmpere_RangeList(A2DConvertData);
    } else {
	A2DConvertData = maxRangeADC(ADCType)+1;
	// alarmOutOfRange(A2DConvertData);
	(*alertType) (A2DConvertData);
    }
    return errorStatus;
} 
