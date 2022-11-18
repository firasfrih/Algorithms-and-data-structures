#include <stdio.h>
#include <stdlib.h>
#include "datastructure.h"
#include "datetime.h"
#include <string.h>
#include "tools.h"

//getDateFromString()
//replaces "." with \0
//covertes string to int
//return 1 if method 1
//return 0 if date invalid


int getTimeFromString(char *Input,TTime *time) {
    int i,len1,k,len2;
    for(i=0; i<8; i++) {
        if(Input[i]==':') {
            len1=i;
            break;
        }
    }
    if(Input[i]!=':') {
        return 0;
    }

    for(k=len1+1; k<8; k++) {
        if(Input[k]==':') {
            len2=k;
            break;
        }
    }
    char *pSeconds;
    char *pMinutes;
    char *pHours;


    if(Input[k]!=':') {
        Input[len1]='\0';
        pHours =NULL;
        pMinutes = &Input[0];
        pSeconds = &Input[len1+1];

    } else {
        Input[len1]='\0';
        Input[len2]='\0';
        pHours = &Input[0];
        pMinutes = &Input[len1+1];
        pSeconds = &Input[len2+1];

    }
    time->Seconds = atoi(pSeconds);
    time->Minutes = atoi(pMinutes);
    time->Hours = atoi(pHours);

    if(isTimeValid(time)==1) {
        return 1;
    }
    return 0;
}

int isLeapYear(sTime * Date) {
    if( Date->Year % 400 == 0 ) {
        return 1;
    }
    if( Date->Year % 4 == 0 ) {
        if(Date->Year % 100 == 0) {
            return 0;
        } else {
            printf("Schaltjahr\n");
            return 1;
        }
    }
    return 0;
}

int isTimeValid(TTime *Time) {
    if ((Time->Seconds)<0 || (Time->Seconds)>60)
        return 0;
    if ((Time->Minutes)<0 || (Time->Minutes)>60)
        return 0;
    return 1;
}

void printTime(TTime time) {
    if (time.Hours == 0)
        printf("%02d:%02d)",time.Minutes,time.Seconds);
    else printf("%02d:%02d:%02d)", time.Hours,time.Minutes,time.Seconds);
    return;
}

void printTimeInFile(TTime time, FILE *datei) {
    if (time.Hours == 0) {
        fprintf(datei,"   <Duration>%02d:%02d</Duration>\n",time.Minutes,time.Seconds);
    } else fprintf(datei,"   <Duration>%02d:%02d:%02d</Duration>\n", time.Hours,time.Minutes,time.Seconds);

    return;
}

TTime *inputTime ( TTime *time, char Input[20]) {
    //char Input[20];
    short stay = 1;
    int correct;
    //time = malloc(sizeof(TTime)); //(TTime*)
    // if(time==0){ return NULL;}
    do {
        printf("\tPlease give the duration in this form hh:mm:ss or mm:ss :\n\t-> ");
        *Input = '\0';
        scanf("%19[^\n]", Input);
        clearBuffer();
        if((*Input) == '\0')
            stay = 0;
        else {
            correct = getTimeFromString(Input,time);
            if(!correct)
                printf("Please enter a correct answer!\n");
            else
                return time;
        }
    } while(stay && !correct);

    //time = NULL;
    return time;
}

void printTotalTime(TTime time) {
    if (time.Hours == NULL)
        printf("\nGesamtlaufzeit : %02d:%02d",time.Minutes,time.Seconds);
    else printf("\nGesamtlaufzeit : %02d:%02d:%02d", time.Hours,time.Minutes,time.Seconds);
    return;
}

TTime addTime(TTime Time, TTime Duration)
{
    TTime EndTime;

    EndTime.Hours = Time.Hours + Duration.Hours;
   // if (EndTime.Hours >= 24)  EndTime.Hours -= 24;

    EndTime.Minutes = Time.Minutes + Duration.Minutes;
    if (EndTime.Minutes >= 60)
    {
        EndTime.Minutes -= 60;
        EndTime.Hours += 1;
    }
    EndTime.Seconds = Time.Seconds + Duration.Seconds;
    if (EndTime.Seconds >= 60)
    {
        EndTime.Seconds -= 60;
        EndTime.Minutes += 1;
    }
    return EndTime;
}
