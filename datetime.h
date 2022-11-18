#include <stdio.h>
#include <stdlib.h>
#include "datastructure.h"

#ifndef DATETIME_H_INCLUDED
#define DATETIME_H_INCLUDED

int isDateValid(sTime*);
int isLeapYear(sTime*);
int getTimeFromString(char*,TTime*);
int isLeapYear(sTime *) ;
int isTimeValid(TTime *);
TTime *inputTime(TTime * , char [20]);
void printTime (TTime);
void printTimeInFile(TTime , FILE *);
void printTotalTime(TTime time);
TTime addTime (TTime, TTime);

#endif // DATETIME_H_INCLUDED

