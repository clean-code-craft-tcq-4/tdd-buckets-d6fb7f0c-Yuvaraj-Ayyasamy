#include <string.h>
#include <stdio.h>
#include <math.h>

#define INSIDE_RANGE          1
#define OUTOFF_RANGE          0
#define minRangeADC(ADCType)  0
#define maxRangeADC(ADCType)  (pow(2, ADCType)-2)
#define AMPRANGE              10

#define TWELVEBITMAXRANGE     (pow(2, 12)-2)
#define TENBITMINRANGE        0
#define TENBITMAXRANGE        (pow(2, 10)-2)

enum ADCType {
	TwelveBitADC = 12,
	TenBitADC = 10,
};

#define RECEPIENT        "a.b@c.com"
#define ERROR_MSG        "Error: ADC out off Range:"
#define THROW_CONTROLLERWARNING(A2DConvertData)                                \
({                                                                             \
    printf("%s %d!!!\n", ERROR_MSG, A2DConvertData);                           \
})

#define THROW_MAILWARNING(A2DConvertData)                                      \
({                                                                             \
    printf("To: %s\n Hi, %s %d !!!\n", RECEPIENT, ERROR_MSG, A2DConvertData);  \
})

int ADCRangeCheck(int ADCData, int ADCType);
int A2D12bitConverter(int ADCData, int ADCType);
int A2D10bitConverter(int ADCData, int ADCType);
void find_convertedAmpere_RangeList(int convertedData);
void sendToController(int A2DConvertData);
void sendToEmail(int A2DConvertData);
bool processADCSensorData(int ADCData, int ADCType, int A2DConvertData, void (*alertType) (int A2DConvertData));
