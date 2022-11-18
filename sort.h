#include <stdio.h>
#include <stdlib.h>
#include "datastructure.h"

#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

void QuickSort(sCD*, int, int (*cmpfct) (sCD *, sCD *));
void Qsort(sCD*, int , int , int (*cmpfct) (sCD *, sCD *));
int partition(sCD *CD, int ui, int oi, int (*cmpfct) (sCD *, sCD *));
void tausche(sCD *e1, sCD *e2);
void sortNumberOfSongs();
void sortYear();
void sortInterpret();
void sortTitle();

#endif // SORT_H_INCLUDED
