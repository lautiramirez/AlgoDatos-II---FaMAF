#ifndef WEATHER_H
#define WEATHER_H

#include <stdbool.h>
#include "array_helpers.h"

int menTempHist(int a[YEARS][MONTHS][DAYS][PHYS_QTTYS]);

void MaxTempAnual(int a[YEARS][MONTHS][DAYS][PHYS_QTTYS], int ouput[YEARS]);

void mesMaxPrec(int a[YEARS][MONTHS][DAYS][PHYS_QTTYS], int output[YEARS]); 

#endif

