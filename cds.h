#ifndef CDS_H_INCLUDED
#define CDS_H_INCLUDED
#include "datastructure.h"


void createCD();
void createSong(sCD *);
void editCD();
void deleteCD();
void searchSong();
void sortCD();
void listCD();
void listOneCD(sCD *);
void listOneSong(sCD *,int);
int cmpCDsTitle(sCD *, sCD *);
int cmpCDsInterpret(sCD *, sCD*);
int cmpCDsYear(sCD*, sCD*);
int cmpNumberOfSongs(sCD*,sCD*);

#endif
