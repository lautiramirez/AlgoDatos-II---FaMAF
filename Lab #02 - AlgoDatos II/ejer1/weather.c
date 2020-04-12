#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "array_helpers.h"

char *t_month_to_string(t_month month){
    switch (month){
        case january:
            return "Enero";
        case february:
            return "Febrero";
        case march:
            return "Marzo";
        case april:
            return "Abril";
        case may:
            return "Mayo";
        case june:
            return "Junio";
        case july:
            return "Julio";
        case august:
            return "Agosto";
        case september:
            return "Septiembre";
        case october:
            return "Octubre";
        case november:
            return "Noviembre";
        case december:
            return "Diciembre";
        default:
            return "Unknown month";
    }
}

int menTempHist(int a[YEARS][MONTHS][DAYS][PHYS_QTTYS]){
    int menTemp = a[0][0][0][temp_m];
    for (int year = 0; year < YEARS; year++){
        for (t_month month = january; month <= december; month++){
            for (int day = 0; day < DAYS; day++){
                if(menTemp > a[year][month][day][temp_m]){
                    menTemp =  a[year][month][day][temp_m];
                }
            } 
        }
    }
return menTemp;
}

void MaxTempAnual(int a[YEARS][MONTHS][DAYS][PHYS_QTTYS], int output[YEARS]){
    int maxTempAnual = a[0][0][0][temp_M];
    for (int year = 0; year < YEARS; year++){
        maxTempAnual = a[0][0][0][temp_M];
        for (t_month month = january; month <= december; month++){
            for (int day = 0; day < DAYS; day++){
                if(maxTempAnual < a[year][month][day][temp_M]){
                   maxTempAnual = a[year][month][day][temp_M];
                }   
            }      
        }
        output[year] = maxTempAnual;
        printf("La maxima temperatura del año %d fue de: %d\n", year+1980, output[year]);
    }   
}

void mesMaxPrec(int a[YEARS][MONTHS][DAYS][PHYS_QTTYS], t_month output[YEARS]){   
    for (int year = 0; year < YEARS; year++){   
        int maxPre = 0; 
        t_month maxMonth = january;
        for (t_month month = january; month <= december; month++){
            int countMonth = 0;
            for (int day = 0; day < DAYS; day++){
                countMonth = countMonth + a[year][month][day][precip];
            }
            if (countMonth > maxPre){
                maxMonth = month;
                maxPre = countMonth;
                output[year] = maxMonth;
            }  
        }        
        printf("\nEl mes con mas precipitaciones del %d fue en: %s", year+1980, t_month_to_string(output[year]));
    }
}

