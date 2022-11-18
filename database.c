#include <stdio.h>
#include <stdlib.h>
#include "datastructure.h"
#include "datetime.h"
#include <string.h>
#include "tools.h"
#include "database.h"



void save() {
    FILE *datei = fopen("cds.xml", "wt");

    if(!datei) {
        printf("\nthe backup document cannot be opened!\n");
        exit(0);
    } else
        fprintf(datei, "<Data>\n");
    for (int i=0 ; i<countCDs ; i++) {
        saveCD(CDDATA + i, datei);
    }
    fprintf(datei, "</Data>");
    fclose(datei);
}

void saveCD(sCD *CD, FILE *datei) {
    int numberofsongs;

    fprintf(datei, " <CD>\n");
    fprintf(datei, "  <Title>%s</Title>\n", CD->title);
    if(CD->interpret) {
        fprintf(datei, "  <Interpret>%s</Interpret>\n", CD->interpret);
    }
    fprintf(datei, "  <YearOfAppearance>%d</YearOfAppearance>\n", CD->publishedin);
    numberofsongs=(CD->numberofsongs);
    for(int i = 0; i < numberofsongs; i++) {
        saveSong(CD->Songs[i], datei);
    }
    fprintf(datei, " </CD>\n");
}

void saveSong(sSong Song, FILE *datei) {
    TTime time;
    time=(Song.duration);
    fprintf(datei, "  <Song>\n");
    if(Song.interpret){
    fprintf(datei, "   <Title>%s</Title>\n", Song.title);
    fprintf(datei, "   <Interpret>%s</Interpret>\n", Song.interpret);
    printTimeInFile(time,datei);
    }else{
    fprintf(datei, "   <Title>%s</Title>\n", Song.title);
    printTimeInFile(time,datei);
    }
    //fprintf(datei, "\t\t\t<Duration>%02d:%02d:%02d</Duration>\n",(Song.duration)->Hours, (Song.duration)->Month, (Song.duration)->Year);
    fprintf(datei, "  </Song>\n");
}

void load() {
    char Zeile[100];
    char *Z;

    FILE* xmldatei = fopen ("cds.xml","rt");
    if (xmldatei) {
        do {
            fscanf(xmldatei,"%99[^\n\r]",Zeile);
            fclearBuffer(xmldatei);
            Z = Zeile;

            while((*Z == ' ') || (*Z == '\t'))
                Z++;

            if (strncmp(Z,"<Data>",6) == 0)
                printf("Anfang gefunden\n");
            else if (strncmp(Z,"<CD>",4) == 0) {
                printf("CD gefunden\n");
                loadCD(xmldatei);
                countCDs++;
            }
            if (feof(xmldatei)) {
                printf("Fehler gefunden oder Datei zu Ende!");
                break; // fclose(xmldatei);
            }
        } while(strncmp(Z,"</Data>",7) != 0);

        fclose(xmldatei);
    }

}

void loadsong(  FILE* xmldatei ) {
    char *Z;
    char Zeile[100];
    int len;
    sSong *Neu = (CDDATA + countCDs)->Songs + (CDDATA + countCDs)->numberofsongs;

    if (xmldatei) {
        do {
            fscanf(xmldatei,"%99[^\n\r]",Zeile);
            fclearBuffer(xmldatei);
            Z = Zeile;

            while((*Z == ' ') || (*Z == '\t'))
                Z++;

            if(strncmp(Z, "<Title>", 7) == 0) {
                Z = Z + 7;
                len = strlen(Z) - 8;
                Neu->title = calloc (len + 1, sizeof(char));
                if (Neu->title) {
                    strncpy(Neu->title, Z, len);
                    printf("Titel von Song gefunden: %s\n", Neu->title);
                }
            } else if (strncmp(Z,"<Interpret>",11) == 0) {
                Z = Z + 11;
                len = strlen(Z) - 12;
                Neu->interpret = calloc (len + 1, sizeof(char));
                if (Neu->interpret) {
                    strncpy(Neu->interpret, Z, len);
                    printf("Interpret von Song gefunden: %s\n", Neu->interpret);
                }
            } else if(strncmp(Z, "<Duration>", 10) == 0) {
                Z = Z + 10;
                printf("Duration found: %s\n", Z);
                if(getTimeFromString(Z, &(Neu->duration) ) == 0) {
                    CDDATA[countCDs].duration.Hours = 0;
                    CDDATA[countCDs].duration.Minutes= 0;
                    CDDATA[countCDs].duration.Seconds = 0;
                }
            }

            else
                printf("unknown: %s\n", Z);

            if (feof(xmldatei)) {
                printf("Fehler gefunden oder Datei zu Ende!");
                break; //fclose(xmldatei);
            }
        } while(strncmp(Z,"</Song>",7) != 0);
        ((CDDATA + countCDs)->numberofsongs)++;
    }
}

void loadCD(FILE *xmldatei) {
    char *Z;
    char Zeile[100];
    int len;
    sCD *Neu = CDDATA + countCDs;

    //FILE* xmldatei = fopen ("cds.xml","rt");
    if (xmldatei) {
        do {
            fscanf(xmldatei,"%99[^\n\r]",Zeile);
            fclearBuffer(xmldatei);
            Z = Zeile;

            while((*Z == ' ') || (*Z == '\t'))
                Z++;

            if (strncmp(Z,"<CD>",4) == 0) {
                printf("Anfang der CD gefunden: %s\n", Z);

            } else if (strncmp(Z,"<Title>",7) == 0) {
                Z = Z + 7;
                len = strlen(Z) - 8;
                Neu->title = calloc (len + 1, sizeof(char));
                if (Neu->title) {
                    strncpy(Neu->title, Z, len);
                    printf("Titel von CD gefunden: %s\n", Neu->title);
                }
            } else if (strncmp(Z,"<Interpret>",11) == 0) {
                Z = Z + 11;
                len = strlen(Z) - 12;
                Neu->interpret = calloc (len + 1, sizeof(char));
                if (Neu->interpret) {
                    strncpy(Neu->interpret, Z, len);
                    printf("Interpret von CD gefunden: %s\n", Neu->interpret);
                }
            } else if (strncmp(Z,"<YearOfAppearance>",18) == 0) {
                Z = Z + 18;
                len = strlen(Z) - 19;
                Neu->publishedin = atoi(Z);
                printf("Year of appearance: %i\n", Neu->publishedin);

            } else if (strncmp(Z,"<Song>", 6) == 0) {
                printf("Song gefunden\n");
                loadsong(xmldatei);
            } else
                printf("unbekannt: %s\n", Z);

            if (feof(xmldatei)) {
                printf("Fehler gefunden oder Datei zu Ende!");

                break; // fclose(xmldatei);
            }

        } while(strncmp(Z,"</CD>",5) != 0);
        //   printf( "datei gefunden ! ")
        // fclose(xmldatei);
    }

}
