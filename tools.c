#include <stdio.h>
#include <stdlib.h>
#include "tools.h"
#include "datetime.h"
#include <string.h>

/**********************************************************/
/**********************************************************/
void clearScreen(){
//   system("clear"); // Linux
   system("CLS");   // Windows
};

/**********************************************************/
/**********************************************************/
void clearBuffer(){
   char Dummy;

   do
   {
      scanf("%c", &Dummy);
   } while (Dummy != '\n');
};

/**********************************************************/
/**********************************************************/
void fclearBuffer(FILE *F){
   char Dummy;

   do
   {
      fscanf(F,"%c", &Dummy);
      if(feof(F))
         break;
   } while (Dummy != '\n');
};

/**********************************************************/
/**********************************************************/
void waitForEnter(){
   printf("\nBitte Eingabetaste druecken ...");
   clearBuffer();
};

/**********************************************************/
/**********************************************************/
int askYesOrNo(char *Question){
   char Input;

   do
   {
      printf("%s", Question);
      scanf("%c", &Input);
      if (Input != '\n')
         clearBuffer();
   } while ((Input != 'j') && (Input != 'J') && (Input != 'n') && (Input != 'N'));
   return ((Input == 'j') || (Input == 'J'));
};

void printLine(char line, int z){
   for(int a=0;a<=z;a++){
      printf("%c",line);
   }
};

int getText(char *pro, int maxLen, char * *pointer, int allowEmpty){

   char *input;
   char format[20];
   unsigned Len = 0;
   int ok = 0;

   if ( (pointer == NULL) || (maxLen == 0) )
      return 0;

   *pointer = NULL;
   getMemory((int**)&input, maxLen+1);

   if (input)
   {
      sprintf(format, "%%%i[^\n]", maxLen);
      do
      {
         printf(pro);
         *input = '\0';
         scanf(format, input);
         clearBuffer();
         Len = strlen(input);
         if (Len > 0)
         {
            *pointer = malloc(Len + 1);
            if (*pointer)
            {
               strncpy(*pointer, input, Len + 1);
               ok = 1;
            }
         }
         else if (allowEmpty)
            ok = 1;
      } while (ok != 1);
      //freeMemory((int**)&input);
      return 1;
   }
   else
      return 0;
}

int getNumber(char *pro, int *pointer, int from, int to, int allowEmpty){
   char *input = NULL;
   int ok = 0;
   unsigned Len = 0;

   if ( (pointer == NULL) )
      return 0;

   getMemory((int**)&input, 10*sizeof(char));
   if (input)
   {
      do
      {
         *input = '\0';
         printf(pro);
         scanf("%9[^\n]", input);
         clearBuffer();
         Len = strlen(input);
         if (Len > 0)
         {
            if (pointer)
            {
               *pointer = atoi(input);
               if (*pointer>=from && *pointer<=to)
                  ok = 1;
            }
         }
         else if (allowEmpty)
            ok = 1;
      } while (ok != 1);
     // freeMemory((int**)&input);
      return 1;
   }
   else
      return 0;
}

int getMemory(int **pPtr, int Size){
   if (pPtr == NULL)
      return 0;

   *pPtr = calloc(Size, 1);

   return (*pPtr != NULL);
}

void freeMemory(int **pPtr){
   if (pPtr)
   {
      free(*pPtr);
      *pPtr = NULL;
   }
}
