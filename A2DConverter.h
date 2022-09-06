#include <string.h>
#include <stdio.h>
#include <math.h>

typedef enum {
    TwelveBitADC = 12,
    TenBitADC = 10,
}ADCTypes;

typedef enum {
    ToController = 0,
    ToMail = 1,
}AlertTypes;

#define AMPARRAYSIZE          7
#define INSIDE_RANGE          1
#define OUTOFF_RANGE          0
#define minRangeADC(ADCType)  0
#define maxRangeADC(ADCType)  (pow(2, (int)ADCType)-2)
#define AMPRANGE              10

#define TWELVEBITMAXRANGE     (pow(2, TwelveBitADC)-2)
#define TENBITMINRANGE        0
#define TENBITMAXRANGE        (pow(2, TenBitADC)-2)

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

int ADCRangeCheck(int ADCData, ADCTypes ADCType);
int A2D12bitConverter(int ADCData, ADCTypes ADCType);
int A2D10bitConverter(int ADCData, ADCTypes ADCType);
int A2DConverter(int ADCData, ADCTypes ADCType);
int createAmpRangeList(int A2DConvertData);
void sendToController(int A2DConvertData);
void sendToEmail(int A2DConvertData);
void alarmOutOfRange(int A2DConvertData, AlertTypes alertType);
bool processADCSensorData(int ADCData, ADCTypes ADCType, int A2DConvertData, AlertTypes alertType);
