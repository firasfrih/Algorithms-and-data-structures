#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tools.h"
#include "menu.h"

int getmenu(char title[] , char menuoptions[7][50])
{
    int choose;
    int options=0;
    do{
            int i = 0 ; int j = 0 ; int k = 1;
            clearScreen();
            printf("%s \n", title);
            printLine('=', strlen(title));  // lenght of title statt 50
            printf("\n\n");

        while ( menuoptions[i][j]!= '\0' )
        {
            printf("%i. ", k);
            printf("%s \n", menuoptions[i]);
                i++;
                k++;

        }
        options = i + 1;
        printf("\n");
        printf("Ihre Wahl: ");
        scanf("%d", &choose);
        clearBuffer();
        clearScreen();

    }while ((choose < 1) || (choose > options));
    return choose;
}

