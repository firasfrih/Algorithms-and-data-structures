#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datastructure.h"
#include "cds.h"
#include "tools.h"
#include "datetime.h"
#include "database.h"
#include "sort.h"



int countCDs = 0;
sCD CDDATA[MAXCDS];


void createCD(/*int countCDs *//*, sCD CDDATA[MAXCDS]*/) {
    char str [] = "Erfassung einer neuen CD";
    //int countCDs=0;
    sCD *CD = CDDATA + countCDs; // (sCD*)malloc(sizeof(sCD));

    if(CD) {
        CD->title = NULL;
        CD->interpret = NULL;
    }
    clearScreen();
    printf("%s \n", str);
    printLine('-', strlen(str));
    getText("\n\nPlease give the title of the CD:\n->",50,&(CD->title),0);
    getText("Please give the Interpret\n(leave this field empty if the songs are not made by the same interpret)\n->",50,&(CD->interpret),1);
    getNumber("Please give the issue year:\n->",&(CD->publishedin),1980,2022,0);
    CD->numberofsongs = 0;
    do {
        //clearBuffer();
        printf("Please give song details:\n\tSong %d:\n\n",(CD->numberofsongs)+1);
        createSong(CD);
        ++(CD->numberofsongs);
    } while(askYesOrNo("Do you want to add an other song(j/n)\n"));
    // CDDATA[countCDs]=*CD ;
    listOneCD(CD);
    countCDs++;
    // }
    return;
}

void createSong(sCD *CD) {
    char pointer[20];
    if(CD->numberofsongs < MAXSONGS) {
        sSong *Song = CD->Songs + CD->numberofsongs;//(sSong*)malloc(sizeof(sSong));
        if(Song) {
            Song->title = NULL;
            Song->interpret = NULL;
        }
        getText("\tPlease give the title of the song: \n\t-> ",50,&(Song->title),0);
        getText("\n\tPlease give the interpret of the song: \n\t-> ",50,&(Song->interpret),0);
        inputTime (&(Song->duration), pointer);
    } else
        printf("\nMax number of Songs in a CD reached.\n");
    return;
}

void editCD() {
    printf("editCD \n");
    return ;
};

void deleteCD() {
    printf("deleteCD \n");
    return ;
};

void searchSong() {
    printf("searchSong \n");
    return ;
};

void sortCD() {
    int choix;
    char sorttitle[] = "CDs Sortieren";
    char Sortoptions[5][50]= {"Sortieren nach CD-Titel", "Sortieren nach CD-Interpret", "Sortieren nach Erscheinungsjahr", "Sortieren nach Anzahl Lieder","Zurueck zum Hauptmenue"};
    do {
        choix = getmenu(sorttitle,Sortoptions);
        switch (choix) {
        case 1 :
            sortTitle();
            waitForEnter();
            break;
        case 2 :
            sortInterpret();
            waitForEnter();
            break;
        case 3 :
            sortYear();
            waitForEnter();
            break;
        case 4 :
            sortNumberOfSongs();
            waitForEnter();
            break;
        case 5 :
            if (!askYesOrNo("Back to main menu?(j/n)\n"))
                choix = 0;
            break;
        default :
            printf("Sie haben was falsches gegeben!!");
            break;
        }
    } while (choix != 5);
    //waitForEnter();

    return ;
};

void listCD() {
    int i=0;
    TTime aux[countCDs];
    //sSong *s1,*s2;
    char str [] = "Liste der CDs";
    printf("%s \n", str);
    printLine('-', strlen(str));
    for (i=0 ; i<countCDs ; i++ ) {
        listOneCD(CDDATA + i);
        /*for (int j= 0 ; j<CDDATA->numberofsongs ; j++){
        int k=j+1;
        //sSong *s1=;
        // sSong *s2=;
        TTime EndTime=addTime((&(CDDATA->Songs[k]).duration) , (&(CDDATA->Songs[j]).duration));
        printTotalTime(EndTime);
        EndTime.Hours = 0 ;
        EndTime.Minutes = 0 ;
        EndTime.Seconds = 0 ;
        }*/
    }
    return;
};

void listOneCD(sCD *CD) {
    int numberofsongs;
    TTime Gesamtzeit = {0,0,0};
    printf("\n\nTitel            :%s \n",CD->title);
    if(CD->interpret) {
        printf("Interpret        :%s \n",CD->interpret);
    }
    printf("Year of release  :%d \n",CD->publishedin);
    printf("Number of Songs  :%d \n",CD->numberofsongs);
    printf("Songs");
    numberofsongs=(CD->numberofsongs);
    // printf("%d",numberofsongs);  zum test
    for ( int i=0 ; i<numberofsongs/*CD->numberofsongs*/ ; i++ ) {
        listOneSong(CD,i);
        Gesamtzeit = addTime((((CD->Songs)[i]).duration),Gesamtzeit);
    }
    printTotalTime(Gesamtzeit);
        Gesamtzeit.Hours = 0 ;
        Gesamtzeit.Minutes = 0 ;
        Gesamtzeit.Seconds = 0 ;
    return ;
};

void listOneSong(sCD *CD, int i) {
    TTime time;
    if((CD->Songs[i]).interpret)
        printf("\n\t %02d. %s (%s ; ", (i+1), ((CD->Songs[i]).title), ((CD->Songs[i]).interpret));
    else
        printf("\n\t %02d. %s ( ", (i+1), ((CD->Songs[i]).title));
    //if(Song.duration.Hours)
    //{
    //printf("; %d:%d:%d)",(CD->Songs[i].duration.Hours),(CD->Songs[i].duration.Minutes),(CD->Songs[i].duration.Seconds));
    //}
    time=(((CD->Songs)[i]).duration);
    printTime(time);
    //else printf("; %d:%d)\n", (Song.duration.Minutes),(Song.duration.Seconds));
    return ;
};

int cmpCDsTitle(sCD *cd1, sCD *cd2) {
    return strcmp(cd1->title, cd2->title);
}

int cmpCDsInterpret(sCD *cd1, sCD *cd2) {
   if (((cd1->interpret)!= NULL)&&((cd2->interpret)!=NULL))
      return strcmp(cd1->interpret, cd2->interpret);
   if (((cd1->interpret)== NULL)&&((cd2->interpret)==NULL))
      return 0;
   if ((cd1->interpret)== NULL)
      return -1;
   return 1;
}

int cmpCDsYear(sCD *cd1, sCD *cd2) {
    //int dif = cd1->publishedin - cd2->publishedin;

    /*if(!dif) {
        return cmpCDsTitle(cd1, cd2);
    }*/
    return cd1->publishedin - cd2->publishedin;
}

int cmpNumberOfSongs(sCD *cd1, sCD *cd2) {
    //int dif = cd1->numberofsongs - cd2->numberofsongs;

    /*if(!dif) {
        return cmpCDsTitle(cd1, cd2);
    }*/
    return cd1->numberofsongs - cd2->numberofsongs;
}

// int countCDs = 0; gibt conflicting types error



