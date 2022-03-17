//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "moisture_sensor.h"

//=====[Declaration of private defines]========================================

#define NUMBER_OF_AVERAGED_SAMPLES    10

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration and initialization of private global objects]===============

static AnalogIn hl69(A3);
    
//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

static float hl69AveragedValue = 0.0;
static float hl69ReadingsArray[NUMBER_OF_AVERAGED_SAMPLES];

//=====[Implementations of public functions]===================================

void moistureSensorInit()
{
}

void moistureSensorUpdate()
{
    static int hl69SampleIndex = 0;
    int i;

    hl69ReadingsArray[hl69SampleIndex] = 1 - hl69.read();
    
    hl69AveragedValue = 0.0;
    for (i = 0; i < NUMBER_OF_AVERAGED_SAMPLES; i++) {
        hl69AveragedValue = hl69AveragedValue + hl69ReadingsArray[i];
    }
    hl69AveragedValue = hl69AveragedValue / NUMBER_OF_AVERAGED_SAMPLES;

    hl69SampleIndex++;
    if ( hl69SampleIndex >= NUMBER_OF_AVERAGED_SAMPLES) {
        hl69SampleIndex = 0;
    }
}

float moistureSensorRead()
{
    return hl69AveragedValue;
}