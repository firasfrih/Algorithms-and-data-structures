#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datastructure.h"
#include "cds.h"
#include "tools.h"
#include "datetime.h"
#include "database.h"
#include "sort.h"

void QuickSort(sCD *CD, int Anzahl, int (*cmpfct) (sCD *, sCD *)){
   Qsort(CD, 0, Anzahl - 1, cmpfct);
}

void Qsort(sCD *CD, int ui, int oi, int (*cmpfct) (sCD *, sCD *)){
   int idx;

   if (ui >= oi)
      return;
   else
   {
      idx = partition(CD, ui, oi, cmpfct);
      Qsort(CD, ui, idx - 1, cmpfct);
      Qsort(CD, idx + 1, oi, cmpfct);
   }
}

int partition(sCD *CD, int ui, int oi, int (*cmpfct) (sCD *, sCD *)){
   int i = ui + 1, j = oi;

   while(i <= j)
   {
      while (i <= j && (cmpfct((CD+i), (CD+ui)) <= 0))
         i++;
      while (j >= i && (cmpfct((CD+j), (CD+ui)) >= 0))
         j--;

      if(i < j)
      {
         tausche((CD+i), (CD+j));
         i++;
         j--;
      }
   }
   i--;
   tausche((CD+ui), (CD+i));

   return i;
}

void tausche(sCD *e1, sCD *e2){
   sCD *temp = malloc(sizeof(sCD));

   if(temp)
   {
      *temp = *e1;
      *e1 = *e2;
      *e2 = *temp;
      free(temp);
   }
   else
      printf("\nKonnte kein Speicher fuer tausche-fkt reservieren.\n");
}

void sortTitle(){
   //int i=0;
   //sCD *CD = CDDATA + countCDs;
   //clearScreen();
   printf("Sort CDs by Title ... \n\n");
   QuickSort(CDDATA, countCDs, cmpCDsTitle);
   printf("ok\n");
   //waitForEnter();
   //while(CD)
  /* do
   {  if((CDDATA[i]).title){
      printf("Sort CDs from : %s ... ", (CDDATA[i]).title);
      QuickSort((CD+i), countCDs, cmpCDsTitle);
      printf("ok\n");
      }else{
      printf("Sort CDs from : CD was giving without title ... ");
      QuickSort(CD, CD->numberofsongs, cmpCDsTitle);
      printf("ok\n");
      }
      i++;
   }while(i<countCDs);*/
       //CD = CD->Next;
}

void sortInterpret(){

   printf("Sort CDs by Title ... \n\n");
   QuickSort(CDDATA, countCDs, cmpCDsInterpret);
   printf("ok\n");
   //waitForEnter();
  /* int i=0;
   sCD *CD = CDDATA + countCDs;
   printf("Sort CDs by Interpret ... \n\n");
   do
   {  if((CDDATA[i]).interpret){
      printf("Sort CDs by Interpret : %s ... ", (CDDATA[i]).interpret);
      QuickSort(CDDATA, countCDs, cmpCDsInterpret);
      printf("ok\n");
      }else{
      printf("Sort CDs by Interpret : CD was giving without Interpret ... ");
      QuickSort(CDDATA, countCDs, cmpCDsInterpret);
      printf("ok\n");
      }
      i++;
   }while(i<countCDs);*/
}

void sortYear(){

   printf("Sort CDs by Title ... \n\n");
   QuickSort(CDDATA, countCDs, cmpCDsYear);
   printf("ok\n");
   //waitForEnter();
   /*int i=0;
   sCD *CD = CDDATA + countCDs;
   printf("Sort CDs by release year ... \n\n");
   do
   {  if((CDDATA[i]).publishedin){
      printf("Sort CDs from : %d ... ", (CDDATA[i]).publishedin);
      QuickSort(CDDATA, countCDs, cmpCDsYear);
      printf("ok\n");
      }else{
      printf("Sort CDs from : CD was giving without release Year ... ");
      QuickSort(CDDATA, countCDs, cmpCDsYear);
      printf("ok\n");
      }
      i++;
   }while(i<countCDs);*/
}

void sortNumberOfSongs(){
   printf("Sort CDs by Title ... \n\n");
   QuickSort(CDDATA, countCDs, cmpNumberOfSongs);
   printf("ok\n");
 //  waitForEnter();
   /*int i=0;
   sCD *CD = CDDATA + countCDs;
   printf("Sort CDs by number of Songs ... \n\n");
   do
   {  if((CDDATA[i]).title){
      printf("Sort CDs from : %s ... ", (CDDATA[i]).title);
      QuickSort(CDDATA, countCDs, cmpNumberOfSongs);
      printf("ok\n");
      }else{
      printf("Sort CDs from : CD was giving without title ... ");
      //QuickSort(CD, CD->numberofsongs, cmpSongsTitle);
      printf("ok\n");
      }
      i++;
   }while(i<countCDs);*/
}
