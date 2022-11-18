#include <stdio.h>
#include <stdlib.h>
#include "datastructure.h"

#ifndef DATABASE_H_INCLUDED
#define DATABASE_H_INCLUDED

void saveSong(sSong , FILE *datei);
void saveCD(sCD *, FILE *datei);
void save();
void loadSong(FILE *datei/*, sSong* */ );
void loadCD(FILE *datei/*, sCD * */);
void load();


#endif // DATABASE_H_INCLUDED

