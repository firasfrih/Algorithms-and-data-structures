#ifndef TOOLS_H_INCLUDED
#define TOOLS_H_INCLUDED


void clearScreen();
void clearBuffer();
void waitForEnter();
int askYesOrNo(char *);
void printLine(char, int);
int getNumber(char *, int *, int, int, int);
int getText(char *, int , char * *, int);
int getMemory(int **, int);
void freeMemory(int **);
void fclearBuffer(FILE*);

#endif // TOOLS_H_INCLUDED
