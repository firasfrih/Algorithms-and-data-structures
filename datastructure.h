#ifndef DATASTRUCTURE_H_INCLUDED
#define DATASTRUCTURE_H_INCLUDED

#define MAXSONGS 30
#define MAXCDS 100

typedef struct
{
   int Day;
   int Month;
   int Year;
}sTime;

typedef struct
{
   int Seconds;
   int Minutes;
   int Hours;
}TTime;


typedef struct
{
    char *title;
    char *interpret;
    TTime duration;

}sSong;

typedef struct
{
    char *title;
    char *interpret;
    int publishedin;
    int numberofsongs;
    sSong Songs[MAXSONGS];
    TTime duration;
}sCD;

extern int countCDs;
extern sCD CDDATA[];


#endif // DATASTRUCTURE_H_INCLUDED
